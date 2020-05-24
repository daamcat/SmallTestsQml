import QtQuick 2.12
import QtQuick.Window 2.2
import NamespaceTableModel 1.0
import QtQuick.Controls 1.4

Window {
    id: idWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Model-View in QML")

     TableModel{
         id: tableModel
     }

    TableView {
        anchors.fill: parent
        clip: true
        model: tableModel

        TableViewColumn
        {
            role: tableModel.getRole(0)
            title: tableModel.getRole(0)
        }
        TableViewColumn
        {
            role: tableModel.getRole(1)
            title: tableModel.getRole(1)
        }
        TableViewColumn
        {
            role: tableModel.getRole(2)
            title: tableModel.getRole(2)
        }
        TableViewColumn
        {
            role: tableModel.getRole(3)
            title: tableModel.getRole(3)
        }



    }


}
