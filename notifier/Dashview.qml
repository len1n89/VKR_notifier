import QtQuick 2.6
import QtQuick.Controls 1.4

Item {

    ListModel {
        id: model

         ListElement {
             name: "Server1"
             ip: "localhost:6547"
             status: "CONNECTED"
         }
         ListElement {
             name: "Server2"
             ip: "10.10.0.5:6547"
             status: "DBERROR"
         }
         ListElement {
             name: "Server3"
             ip: "localhost:6547"
             status: "DISCONNECTED"
         }
         ListElement {
             name: "Server4"
             ip: "192.168.1.1:6547"
             status: "CONNECTED"
         }
     }

    Component {
        id: delegate

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
            Rectangle{
                border.width: 1
                width: 110
                height: 20
                radius: 3
                color: {
                    if(model.status !==  "CONNECTED")
                        return "red"
                    else
                        return "green"
                }
                Text {
                    anchors.centerIn: parent
                    text: model.status
                }
            }
            Button {
                width: 60
                height: 20
                visible: model.status !==  "CONNECTED"
                text: "Confirm"
            }
        }
    }

    ListView {
        anchors.fill: parent
        model: model
        delegate: delegate
    }
}
