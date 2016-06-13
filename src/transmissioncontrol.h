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

class TransmissionControl : public QObject
{
    Q_OBJECT

public:
    TransmissionControl(); // can't have any arguments in constructor, because QML needs to be able to initialise it
    ~TransmissionControl();

    // property for allowing QML to read/write/track whether transmission is running
    Q_PROPERTY(bool transmissionState READ isTransmissionRunning WRITE setTransmissionRunning NOTIFY transmissionStateChanged);

public slots:
    // methods for reading/writing transmission state
    Q_INVOKABLE bool isTransmissionRunning(); // transmissionState read
    void setTransmissionRunning(bool); // transmissionState write

signals:
    void transmissionStateChanged(bool); // transmissionState notify

private:

    QJsonDocument *transmissionSettings;
    QProcess *transmission;

};


#endif // TRANSMISSION_CONTROL_H
