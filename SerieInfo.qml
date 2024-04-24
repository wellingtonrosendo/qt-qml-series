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
            }

            color: "#ffffff"

            Image {
                id: imageSerie
                Layout.fillWidth: true

                source: root.urlSerie
                width: 100
                height: 100

            }

            Text {
                id: nameSerieInfo
                text: qsTr(root.nameSerie)

            }


            // Text {
            //     id: ratingSerieInfo
            //     text: qsTr(root.ratingSerie.toString())
            //     width: 400
            //     anchors{
            //         top:nameSerieInfo.bottom
            //     }
            // }

            // Text {
            //     id: descSerieInfo
            //     text: qsTr(root.descSerie)
            //     anchors{
            //         top:ratingSerieInfo.bottom
            //     }
            // }

            // Text {
            //     id: genreSerieInfo
            //     text: qsTr(root.genreSerie)
            //     anchors{
            //         top:descSerieInfo.bottom
            //     }
            // }
        }
    }
}
