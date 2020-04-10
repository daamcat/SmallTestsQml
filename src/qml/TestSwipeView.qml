import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.1

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
    }

    PageIndicator {
        id: indicator
        count: view.count
        currentIndex: view.currentIndex

        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

}
