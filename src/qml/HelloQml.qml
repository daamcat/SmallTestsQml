import QtQuick 2.9
import QtQuick.Window 2.2


Window {
    id: idWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle
    {
        id: idRectangle
        anchors.centerIn: parent
        anchors.margins: 10

        Text {
            id: idText
            text: qsTr("HelloQml! :)")
            anchors.centerIn: parent
            font.pointSize: 24
            font.bold: true
        }
    }
}
