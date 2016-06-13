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
    objectName: "AboutPage"
    PageHeader {
        id: header
        title: qsTr("About Clutch")
    }

    SilicaFlickable {
        id: flickable

        anchors {
            top: header.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }

        contentHeight: content.height

        Column {
            id: content
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: Theme.paddingMedium
            anchors.rightMargin: Theme.paddingMedium

            Item {
                width: 1
                height: Theme.paddingLarge
            }
            Image {
                width: parent.width / 3
                height: parent.width / 3
                anchors.horizontalCenter: parent.horizontalCenter
                source: "qrc:///clutch"
                smooth: true
                asynchronous: true
            }
            Item {
                width: 1
                height: Theme.paddingLarge
            }
            Label {
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Theme.fontSizeMedium
                color: Theme.primaryColor
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                text: qsTr("A Silica frontend for the Transmission Torrent Client")
            }
            Item {
                width: 1
                height: Theme.paddingLarge
            }

            Label {
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Theme.fontSizeExtraSmall
                color: Theme.secondaryColor
                text: "Copyright © 2016 Sam Hobbs"
            }
            Label {
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Theme.fontSizeExtraSmall
                color: Theme.secondaryColor
                text: "(Feathers McGraw)"
            }
            Item {
                width: 1
                height: 2 * Theme.paddingLarge
            }
            Label {
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Theme.fontSizeSmall
                color: Theme.secondaryColor
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                text: qsTr("Both Clutch and Transmission are open source software licensed under the terms of the GNU General Public License v2+ ")
            }
            Item {
                width: 1
                height: 2 * Theme.paddingLarge
            }

            Button {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("License")
                onClicked: {
                    pageStack.push(Qt.openUrlExternally("http://www.gnu.org/licenses/gpl.html"));
                }
            }

            Item {
                width: 1
                height: 2 * Theme.paddingLarge
            }

            Button {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Source (Clutch)")
                onClicked: {
                    pageStack.push(Qt.openUrlExternally("https://github.com/sam-hobbs/harbour-clutch"));
                }
            }

            Item {
                width: 1
                height: 2 * Theme.paddingLarge
            }

            Button {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Source (Transmission)")
                onClicked: {
                    pageStack.push(Qt.openUrlExternally("https://trac.transmissionbt.com/browser/trunk?order=name"));
                }
            }

            Item {
                width: 1
                height: 2 * Theme.paddingLarge
            }

            Label {
                anchors.horizontalCenter: parent.horizontalCenter
                color: Theme.secondaryColor
                font.pixelSize: Theme.fontSizeTiny
                text: "v0.1"
            }
        }

        VerticalScrollDecorator{}
    }

}


