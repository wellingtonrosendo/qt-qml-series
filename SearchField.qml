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

        onAccepted: {
            root.search(text)
        }
    }
}
