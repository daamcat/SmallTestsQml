import QtQuick 2.9
import QtQml 2.0
import Qt.labs.platform 1.0

ButtonCaptureImageForm {

    width: parent.width * 0.1
    height: width
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.bottomMargin: parent.height * 0.05
    anchors.bottom: parent.bottom

    property string stringDateTime

    // Make the button clickable:
    MouseArea {
        anchors.fill: parent

        onClicked: {
            stringDateTime = StandardPaths.writableLocation(StandardPaths.PicturesLocation).toString();
            stringDateTime = stringDateTime.replace("file:///","");
            stringDateTime += "/" + new Date().toLocaleString().split(":").join("-");
            // To print a message in console:
            console.log(stringDateTime);
            camera.imageCapture.captureToLocation(stringDateTime);

        }
    }

}


