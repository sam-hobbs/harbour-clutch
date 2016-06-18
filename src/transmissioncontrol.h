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

#ifndef TRANSMISSION_CONTROL_H
#define TRANSMISSION_CONTROL_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QSettings>
#include <QVariant>

#include <QJsonDocument>
#include <QProcess>

#include "settings.h"

class TransmissionControl : public QObject
{
    Q_OBJECT

public:
    TransmissionControl(); // can't have any arguments in constructor, because QML needs to be able to initialise it
    ~TransmissionControl();

    // property for allowing QML to read/write/track whether transmission is running
    Q_PROPERTY(bool leverOn READ isTransmissionOn WRITE setTransmissionRunning NOTIFY transmissionStateChanged)
    Q_PROPERTY(AppSettings* appSettings READ getAppSettings WRITE setAppSettings NOTIFY appSettingsChanged)

public slots:
    // methods for reading/writing transmission state
    Q_INVOKABLE bool isTransmissionOn(); // leverOn read
    void setTransmissionRunning(bool); // leverOn write
    void updateTransmissionState(QProcess::ProcessState);

    // methods for reading/writing app settings object
    Q_INVOKABLE AppSettings* getAppSettings(); // appSettings read
    void setAppSettings(AppSettings* settings); // appSettings write

signals:
    void transmissionStateChanged(); // leverOn notify
    void appSettingsChanged(); // appSettings notify

private:
    void startTransmission();
    void stopTransmission();

    QJsonDocument *transmissionSettings;
    AppSettings *appSettings;
    QProcess *transmission;
    bool transmissionOn;

};


#endif // TRANSMISSION_CONTROL_H
