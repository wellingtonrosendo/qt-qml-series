import QtQuick

Item {
    id: root
    visible:true
    Rectangle {
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
        color:"#ffffff"

        Image {
            id: serieImage
            source: ""
            anchors{
                verticalCenter: parent.verticalCenter
            }
            width: 100
            height: parent.height
        }

        Text {
            id: serieName
            text: qsTr("Name Aqui")
            anchors {
                bottom: parent.verticalCenter
                left: serieImage.right
                margins: 20
                right: parent.right
            }
        }
        Text {
            id: serieRate
            text: qsTr("Nota Aqui")
            anchors {
                top: serieName.bottom
                bottom: parent.verticalCenter
                left: serieImage.right
                margins: 20
                right: parent.right
            }
        }
    }
}
