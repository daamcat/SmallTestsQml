import QtQuick 2.4
import QtQuick.Controls 2.13

Item {
    width: 400
    height: 400

    Rectangle {
        id: rectangle
        color: "#c61d1d"
        radius: width * 0.5
        border.width: 3
        border.color: "#129b12"
        anchors.fill: parent

        RoundButton {
            id: roundButtonSave
            radius: parent.radius
            anchors.fill: parent
            opacity: 0.7
            display: AbstractButton.IconOnly
            anchors.centerIn: parent.Center
            icon.name: "save-image"
            icon.source: "icons/iconCamera.png"
            icon.color: "transparent" // In order to use an icon with the original colors, set the color to "transparent".
            icon.width: parent.width * 0.7
            icon.height: parent.height * 0.7
        }
    }
}

/*##^## Designer {
    D{i:1;anchors_height:200;anchors_width:200;anchors_x:116;anchors_y:111}
}
 ##^##*/
