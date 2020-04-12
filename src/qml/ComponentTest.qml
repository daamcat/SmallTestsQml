// Ref: https://wiki.qt.io/QML_Application_Structuring_Approaches
import QtQuick 2.0

// "object declaration".
Rectangle // "object type".
{ // Everything between these curly braces are 1.attributes and 2.children of the object of type "Rectangle".

    // "attributes" can be id, properties, signals, signal handlers, methods, attached properties nd
    // attached signal handlers, and enumerations.

    width: parent.width
    height: parent.height
    color: "red"

    // We want to be able to adjust some properties of the object of this component type.
    // For that we need to make these properties visible for the top level. How? By using alias:
    property alias textProperties: textComponentTest

    Text {
        id: textComponentTest
        width: parent.width / 4
        height: parent.height / 4
        font.pointSize: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        color: "yellow"
        text: qsTr("Component text")
    }

}
