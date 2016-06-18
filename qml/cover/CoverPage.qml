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

Cover {
    id: cover

    transparent: true

    Image {
        id: coverIcon
        source: ( transmission.leverOn ) ? "qrc:///lever_on" : "qrc:///lever_off"

        fillMode: Image.PreserveAspectFit
        cache: true
        anchors.centerIn: parent
        width: parent.width * 0.8
        x: Theme.paddingSmall
    }

    Label {
        id: label

        anchors.centerIn: parent
        anchors.verticalCenterOffset: -parent.height/3

        // text displayed on cover
        text: qsTr("Clutch")
        font.pixelSize: Theme.fontSizeLarge
    }


    CoverActionList {
        id: coverAction

        CoverAction {
            iconSource: ( transmission.leverOn ) ? "image://theme/icon-cover-pause" : "image://theme/icon-cover-play"

            onTriggered:
            {
                console.log("cover action clicked!")
                transmission.setTransmissionRunning(!transmission.leverOn)
            }

        }
    }
}


