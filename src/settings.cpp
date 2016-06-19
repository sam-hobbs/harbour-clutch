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

#include "settings.h"

#include <QSettings>
#include <QDebug>

AppSettings::AppSettings(QObject *parent) :
    QObject(parent), m_settings(new QSettings(this))
{
    qDebug() << "Initialising AppSettings object";
    m_autoStartDaemon = m_settings->value("autoStartDaemon", false).toBool();
    m_autoOpenWebUI = m_settings->value("autoOpenWebUI", true).toBool();
}




bool AppSettings::autoStartDaemon() const
{
    qDebug() << "getting autoStartDaemon";
    return m_autoStartDaemon;
}

void AppSettings::setAutoStartDaemon(const bool autoStartDaemon)
{
    qDebug() << "setting autoStartDaemon";
    if (m_autoStartDaemon != autoStartDaemon) {
        m_autoStartDaemon = autoStartDaemon;
        m_settings->setValue("autoStartDaemon", m_autoStartDaemon);
        emit autoStartDaemonChanged();
    }
}

bool AppSettings::autoOpenWebUI() const
{
    qDebug() << "getting autoOpenWebUI";
    return m_autoOpenWebUI;
}

void AppSettings::setAutoOpenWebUI(const bool autoOpenWebUI)
{
    qDebug() << "setting autoOpenWebUI";
    if (m_autoOpenWebUI != autoOpenWebUI) {
        m_autoOpenWebUI = autoOpenWebUI;
        m_settings->setValue("autoOpenWebUI", m_autoOpenWebUI);
        emit autoOpenWebUIChanged();
    }
}
