import QtQuick

Window {
    width: 480
    height: 640
    visible: true
    title: qsTr("Series")

    Rectangle {
        id: topbar
        height: 100
        color: "#c0c0c0"

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }

    }

    Rectangle {
        id: mainsection
        anchors {
            top: topbar.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }
         color: "#222222"
    }
}
