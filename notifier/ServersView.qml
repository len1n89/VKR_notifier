import QtQuick 2.6
import QtQuick.Controls 1.4

Item {

    Button {
        id: addButton
        width: 100
        height: 20
        text: "Add Server"
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
    }

    ListView {
        anchors.top: addButton.bottom
        width: 300
        height: 500
        model: serverModel
        delegate: serverDelegate
    }

    Component {
        id: serverDelegate

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
            Rectangle{
                border.width: 1
                width: 110
                height: 20
                radius: 3
                Text {
                    anchors.centerIn: parent
                    text: model.ip
                }
            }
            Button {
                width: 60
                height: 20
                text: "Disable"
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
        id: serverModel

        ListElement {
            name: "Server1"
            ip: "localhost:6547"
        }
        ListElement {
            name: "Server2"
            ip: "10.10.0.5:6547"
        }
        ListElement {
            name: "Server3"
            ip: "localhost:6548"
        }
        ListElement {
            name: "Server4"
            ip: "192.168.1.1:6547"
        }
     }

}
