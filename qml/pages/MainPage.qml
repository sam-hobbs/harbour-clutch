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
                text: qsTr("Web UI")
                onClicked: pageStack.push(Qt.resolvedUrl("WebRemote.qml"))
            }
        }

        PageHeader {
            id: header
            title: qsTr("Clutch")
        }

        IconButton {
            id:button

            anchors.centerIn: parent

            width: parent.width
            height: width

            icon.source: ( transmission.leverOn ) ? "qrc:///lever_on" : "qrc:///lever_off"

            icon.width: ( parent.width < parent.height ) ? parent.width * 0.8 : parent.height * 0.8
            icon.height: icon.width

            icon.fillMode: Image.PreserveAspectFit

            onClicked:
            {
                console.log("Lever icon clicked!")
                // if transmission is on, turn it off and vice versa
                transmission.setTransmissionRunning(!transmission.leverOn)
            }
        }

        Item {
            width: 1
            height: Theme.paddingLarge
        }

        Label {
            id: stateLabel

            anchors {
                top: button.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }

            width: parent.width
            horizontalAlignment: Text.AlignHCenter

            text: ( transmission.leverOn ) ? "Transmission daemon running" : "Transmission daemon stopped"
        }
    }

    // if this is the first time the page has been loaded and transmission is already running, push the webremote page
    property bool firstLoad: true

    onStatusChanged: {
        if (status == PageStatus.Active && firstLoad) {
            firstLoad = false
            if ( transmission.appSettings.autoOpenWebUI ) {
                if ( transmission.leverOn) {
                    pageStack.push(Qt.resolvedUrl("WebRemote.qml"));
                }
            }
        }
    }

//    Component.onCompleted: {
//        if ( transmission.appSettings.autoOpenWebUI ) {
//            if ( transmission.leverOn) {
//                pageStack.push(Qt.resolvedUrl("pages/WebRemote.qml"));
//            }
//        }
//    }
}


