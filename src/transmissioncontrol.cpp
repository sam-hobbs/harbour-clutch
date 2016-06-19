/*

Clutch

Copyright (C) 2015 Sam Hobbs

This file is part of Clutch, a Silica frontend for the Transmission torrent client.

Clutch is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

Clutch is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Clutch.  If not, see <http://www.gnu.org/licenses/>

*/

#include "transmissioncontrol.h"

#include <QDebug>

#include <QFile>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QStringList>

TransmissionControl::TransmissionControl() {

    // transmission settings are $HOME/.config/transmission-daemon/settings.json
    QFile tmp;
    QJsonParseError *error = new QJsonParseError();
    //tmp.setFileName("$HOME/.config/transmission-daemon/settings.json");
    tmp.setFileName("/home/nemo/.config/transmission-daemon/settings.json");

    if (tmp.exists()) {
        qDebug() << "Transmission settings file " << tmp.fileName() << " exists";
        tmp.open(QIODevice::ReadOnly | QIODevice::Text);
        transmissionSettings = new QJsonDocument(QJsonDocument::fromJson(tmp.readAll(),error));
        tmp.close();
    } else {
        qWarning() << "Transmission settings file " << tmp.fileName() << " does not exist";
        transmissionSettings = new QJsonDocument;
    }

    if (transmissionSettings->isNull() || transmissionSettings->isEmpty()) {
        qDebug() << "Error: " << error->errorString() << error->offset;
    } else {
        qDebug() << "File " << tmp.fileName() << " has been parsed without error.";
    }



    // initialise transmission object
    transmission = new QProcess(this);

    // when state of transmission process changes, update the transmissionOn variable using the updateTransmissionState slot
    this->connect(
                transmission, SIGNAL(stateChanged(QProcess::ProcessState)),
                this, SLOT(updateTransmissionState(QProcess::ProcessState))
                );

    transmission->setProgram("transmission-daemon");
    transmission->setArguments(QStringList() << "-f"); // transmission must be run in foreground mode (-f flag) or it cannot be killed by qprocess

    // create application settings object and use it to decide whether to start the daemon
    appSettings = new AppSettings;
    if (appSettings->autoStartDaemon()) {
        qDebug() << "Autostarting daemon due to user setting";
        startTransmission();
    } else {
        qDebug() << "Not autostarting daemon due to user setting";
    }


}



TransmissionControl::~TransmissionControl() {

    qDebug() << "Destroying TransmissionControl object";
    stopTransmission();

}


bool TransmissionControl::isTransmissionOn() {
    return transmissionOn;
}

void TransmissionControl::updateTransmissionState(QProcess::ProcessState state) {
    qDebug() << "update transmission state called";
    if (state == QProcess::Running)
        transmissionOn = true;
    else
        transmissionOn = false;
    emit transmissionStateChanged();
}

void TransmissionControl::setTransmissionRunning(bool state) {

    if (state) {
        qDebug() << "Setting transmission running";
    } else {
        qDebug() << "Stopping transmission";
    }

    if (state == 1) {
        startTransmission();
    } else {
        stopTransmission();
    }
}


void TransmissionControl::startTransmission() {

    qDebug() << "startTransmission called";

    // get current state
    QProcess::ProcessState state = transmission->state();

    // check if transmission is already running
    if (state == QProcess::Running) {
        qDebug() << "Transmission is already running, doing nothing.";
    } else if (state == QProcess::Starting) {
        qDebug() << "Transmission is already starting up, doing nothing.";
    } else  if (state == QProcess::NotRunning) {
        qDebug() << "Transmission is not running. Starting...";
        transmission->start();
        if (!transmission->waitForStarted()) {
            qWarning() << "Transmission failed to start";
        } else {

        }
    }
}


void TransmissionControl::stopTransmission() {

    qDebug() << "stopTransmission called";
    // get current state
    QProcess::ProcessState state = transmission->state();

    // check if transmission is already running
    if (state == QProcess::NotRunning) {
        qDebug() << "Transmission is not running, doing nothing.";
    } else if (state == QProcess::Starting || state == QProcess::Running) {
        qDebug() << "Transmission is running, stopping....";
        transmission->terminate();
        if (!transmission->waitForFinished()) {
            qWarning() << "couldn't kill process, sending SIGKILL";
            transmission->kill(); // send SIGKILL
            if (!transmission->waitForFinished()) {
                qCritical() << "still couldn't kill process. Transmission may still be running!";
            }
        }
    }
}

AppSettings* TransmissionControl::getAppSettings() {
    qDebug() << "Reading appSettings member object of transmission control from QML";
    return appSettings;
}

void TransmissionControl::setAppSettings(AppSettings *settings) {
    qDebug() << "Writing appSettings member object of transmission control from QML";
    appSettings = settings;
    emit appSettingsChanged();
}
