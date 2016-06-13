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

#include <sailfishapp.h>
#include <QQmlEngine>
#include <QScopedPointer>
#include <QtQuick>

#include "transmissioncontrol.h"
#include "filesmodel.h"

int main(int argc, char *argv[])
{
    // Set up QML engine.
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> v(SailfishApp::createView());

    qmlRegisterType<TransmissionControl>("harbour.clutch.transmissioncontrol", 0, 1, "TransmissionControl");

    FilesModel::registerMetaTypes();
    qmlRegisterType<FilesModel>("harbour.clutch.selectors", 1, 0, "FilesModel");

    // Start the application.
    v->setSource(SailfishApp::pathTo("qml/harbour-clutch.qml"));
    v->show();
    return app->exec();
}

