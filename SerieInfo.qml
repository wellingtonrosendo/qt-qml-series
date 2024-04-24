import QtQuick
import QtQuick.Controls 2.5
import QtQuick.Layouts
import SeriesSearch

Page {
    id: root
    property string nameSerie
    property string urlSerie
    property string descSerie
    property string genreSerie
    property double ratingSerie

    header: ToolBar {
        id:tolbar
        ToolButton {
            text: qsTr("Voltar")
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                SeriesSearch.searchSeries()
                root.StackView.view.pop()
            }
        }
    }

    Rectangle{
        color: "#111111"
        anchors.fill: parent



        Rectangle{
            id:infoSerie
            height: parent.height / 2 + 500
            anchors{
                top: tolbar.bottom
                left: parent.left
                right: parent.right
                margins: 20

            }

            color: "#ffffff"

            Image {
                id: imageSerie
                Layout.fillWidth: true
                source: root.urlSerie
                width: 400
                height: 400
                anchors{
                    horizontalCenter: parent.horizontalCenter
                }

            }

            Text {
                id: nameSerieInfo
                text: qsTr(root.nameSerie)
                font.pixelSize: 22
                width: 400
                horizontalAlignment: Text.AlignLeft
                anchors{
                    top: imageSerie.bottom
                    horizontalCenter: parent.horizontalCenter
                }

            }

            Text {
                id: genreSerieInfo
                text: qsTr(root.genreSerie)
                font.pixelSize: 14
                width: 400
                anchors{
                    top:nameSerieInfo.bottom
                    horizontalCenter: parent.horizontalCenter
                }
            }


            Text {
                id: ratingSerieInfo
                text: qsTr("Nota: "+root.ratingSerie.toString()+"/10")
                width: 400
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 20
                anchors{
                    top:genreSerieInfo.bottom
                    horizontalCenter: parent.horizontalCenter
                }
            }

            Text {
                id: descSerieInfo
                text: qsTr(root.descSerie)
                wrapMode: Text.WordWrap
                width: 400
                height: 200
                horizontalAlignment: Text.AlignJustify
                font.pixelSize: 18
                anchors{
                    top:ratingSerieInfo.bottom
                    horizontalCenter: parent.horizontalCenter
                }
            }
        }

        Component.onCompleted: {
                if (descSerieInfo.text.length > 790) {
                    descSerieInfo.text = descSerieInfo.text.substring(0, 787) + "..."
                }
            }

    }
}
