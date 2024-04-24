import QtQuick
import QtQuick.Controls

Rectangle {
    id: root

    signal search(string value)

    border.width: 1
    border.color: "#000000"
    color:"#1e1e1e"
    TextInput {
        id: searchInput
        anchors.fill: parent

        font.pixelSize: 14
        color: "white"



        Image {
            anchors {
                left: parent.left
                leftMargin: 5
                verticalCenter: parent.verticalCenter
            }

            width: 16
            height: 16

            // mipmap: true
            // source: "assets/icons/search_icon.png"
            source: ""
        }
        onAccepted: {
            root.search(text)
        }
    }
}
