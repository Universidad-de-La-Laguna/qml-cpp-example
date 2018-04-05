// Elementos gráficos del mosaico

import QtQuick 2.0
import MosaicEngine 1.0

Item {
    id: root

    property int occupy: MosaicStatus.Free
    signal clicked

    Rectangle {
        anchors.fill: parent
        height: parent.height
        color: occupy == MosaicStatus.Free ? "black" : "red"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: parent.clicked()
    }
}
