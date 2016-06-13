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

import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page

    // PullDownMenu must be inside flickable element
    SilicaFlickable {
        anchors.fill: parent

        PullDownMenu {
            MenuItem {
                text: qsTr("Settings")
                onClicked: pageStack.push(Qt.resolvedUrl("SettingsPage.qml"))
            }
            MenuItem {
                text: qsTr("About")
                onClicked: pageStack.push(Qt.resolvedUrl("AboutPage.qml"))
            }
            MenuItem {
                text: qsTr("Remote")
                onClicked: pageStack.push(Qt.resolvedUrl("WebRemote.qml"))
            }
        }

        PageHeader {
            id: header
            title: qsTr("Clutch")
        }

        IconButton {
            id:button

            anchors {
                top: header.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }

            width: parent.width

            icon.source: "qrc:///clutch"

            icon.width: parent.width * 0.8
            icon.height: parent.height - header.height
            icon.fillMode: Image.PreserveAspectFit

            onClicked:
            {
                console.log("clicked!")
                led.toggleState()
            }
        }
    }
}


