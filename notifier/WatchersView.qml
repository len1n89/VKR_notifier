import QtQuick 2.6
import QtQuick.Controls 1.4

Item {

    Button {
        id: addButton
        width: 100
        height: 20
        text: "Add Watcher"
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
    }

    ListView {
        anchors.top: addButton.bottom
        width: 300
        height: 500
        model: watcherModel
        delegate: watcherDelegate
    }

    Component {
        id: watcherDelegate

        Row {
            spacing: 5
            topPadding: 10
            leftPadding: 10
            Rectangle{
                border.width: 1
                width: 60
                height: 20
                radius: 3
                Text {
                    anchors.centerIn: parent
                    text: model.name
                }
            }
            Button {
                width: 60
                height: 20
                text: "Edit"
            }
            Button {
                width: 60
                height: 20
                text: "Delete"
            }
        }
    }

    ListModel {
        id: watcherModel

         ListElement {
             name: "Watcher1"
         }
         ListElement {
             name: "Watcher2"
         }
         ListElement {
             name: "Watcher3"
         }
     }

}
