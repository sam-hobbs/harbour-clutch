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

    transmission = new QProcess;
}

TransmissionControl::~TransmissionControl() {

}

bool TransmissionControl::isTransmissionRunning() {
    return 1;
}

void TransmissionControl::setTransmissionRunning(bool state) {

}


