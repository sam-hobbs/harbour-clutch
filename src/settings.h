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

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class QSettings;

class AppSettings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool autoStartDaemon READ autoStartDaemon WRITE setAutoStartDaemon NOTIFY autoStartDaemonChanged)
    Q_PROPERTY(bool autoOpenWebUI READ autoOpenWebUI WRITE setAutoOpenWebUI NOTIFY autoOpenWebUIChanged)

public:

    explicit AppSettings(QObject *parent = 0);

    bool autoStartDaemon() const;
    void setAutoStartDaemon(const bool autoStartDaemon);

    bool autoOpenWebUI() const;
    void setAutoOpenWebUI(const bool autoOpenWebUI);


signals:
    void autoStartDaemonChanged();
    void autoOpenWebUIChanged();

private:
    QSettings *m_settings;

    bool m_autoStartDaemon;
    bool m_autoOpenWebUI;
};

#endif // SETTINGS_H

