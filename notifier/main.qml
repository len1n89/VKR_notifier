import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 1.4

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Notifier")


    TabView {
        id: mainTabView

        anchors.fill: parent

        Tab {
            id: dashTab
            title: "Dashboard"
            Dashview {id: dv}
        }

        Tab {
            id: setingsTab

            title: "Settings"
            TabView {

                id: setingsTabView
                anchors.fill: parent
                Tab {
                    title: "Users"
                    anchors.fill: parent
                    UsersView {id: usersView}
                }
                Tab {
                    title: "Watchers"
                }
                Tab {
                    title: "Servers"
                }
                Tab {
                    title: "DB"
                }
            }
        }
    }
}
