import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import QtMultimedia 5.13


Window {
    id: idWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    SwipeView {

        id: view
        currentIndex: 1
        anchors.fill: parent

        // "property change" signals: QML types emit signal anytime a property changes. So if you know
        // the property name, you can create signal name: "on<Property_name>Changed"
        onCurrentIndexChanged: {
            if (view.currentItem == pageCamera)
            {
                componentCamera.aliasCameraState = Camera.ActiveState

            }
            else
            {
                componentCamera.aliasCameraState = Camera.LoadedState
            }
        }

        Item {
            id: firstPage
            ComponentTest {
                // We can set the direct properties of top element in the component:
                color: "blue"
                // But for setting the properties of items inside the component, we need "alias":
                textProperties.color: "green"
            }
        }
        Item {
            id: secondPage
            ComponentTest {
                color: "yellow"
                textProperties.color: "blue"
            }
        }
        Item {
            id: thirdPage
            ComponentTest {
                color: "red"
                textProperties.color: "cyan"
            }
        }
        Item {
            id: pageCamera
            ComponentCamera {
                id: componentCamera

            }
        }
    }

    PageIndicator {
        id: indicator
        count: view.count
        currentIndex: view.currentIndex

        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

}
