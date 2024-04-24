import QtQuick 2.15
import QtQuick.Controls 2.15
import SeriesSearch

Page {
    Rectangle {
        anchors.fill: parent
        color: "#111111"

        Rectangle {
            id: topbar
            height: 100
            color: "#c0c0c0"
            opacity: 0.5
            z:4

            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
            }
            SearchField {
                visible: true
                height: 30
                anchors {
                    left: parent.left
                    right: parent.right
                    verticalCenter: parent.verticalCenter
                    margins: 10
                }
                onSearch: value =>{
                              SeriesSearch.searchSeriesByName(value)
                              title.text = "Resultado"
                          }

            }


        }

        Rectangle {
            id:titleContainer
            height: 50
            color: "#111111"
            z:2
            width: 460
            anchors {
                top: topbar.bottom
                left: parent.left
                right: parent.right
                margins: 10
            }
            Text {
                id: title
                text: qsTr("Em alta")
                width: 460
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
                color:"white"
                anchors{
                    horizontalCenter: parent.horizontalCenter
                }
            }

        }
        Rectangle {
            id: mainsection
            color: "#111111"
            height: 700
            z:0
            anchors {
                top: titleContainer.bottom
                left: parent.left
                right: parent.right
                margins: 10
            }
            ScrollView {
                anchors.fill: parent
                z:0
                ScrollBar.vertical.policy: ScrollBar.AlwaysOn

                ListView {
                    width: 460
                    height: parent.height
                    spacing: 10
                    model: SeriesSearch

                    interactive: false

                    delegate: Rectangle {
                        id: delegate
                        required property string name
                        required property string url
                        required property double rating
                        required property string desc
                        required property string genre
                        required property int index

                        width: parent.width / 2 + 120
                        height: 60
                        anchors{
                            horizontalCenter: parent.horizontalCenter
                        }

                        signal openSecondView()

                        Rectangle {
                            color:"#c0c0c0"

                            anchors {
                                top: parent.top
                                left: parent.left
                                right: parent.right
                                bottom: parent.bottom

                            }


                            Image {
                                id: serieImage
                                source: delegate.url
                                anchors{
                                    verticalCenter: parent.verticalCenter
                                }
                                width: 60
                                height: parent.height
                            }
                            Text {
                                id: serieName
                                text: qsTr(delegate.name)
                                horizontalAlignment: Text.AlignLeft
                                wrapMode: Text.WordWrap
                                font.pixelSize: 18
                                font.bold: true
                                anchors {
                                    margins: 5
                                    horizontalCenter: parent.horizontalCenter
                                    left: serieImage.right
                                    right: parent.right
                                }

                            }
                            Text {
                                id: serieRate
                                text: qsTr("Nota: " + delegate.rating.toString())
                                horizontalAlignment: Text.AlignLeft
                                font.pixelSize: 15
                                anchors {
                                    margins: 5
                                    top: serieName.bottom
                                    horizontalCenter: parent.horizontalCenter
                                    left: serieImage.right
                                    right: parent.right
                                }
                            }
                        }
                        Loader { id: pageLoader }

                        MouseArea{
                            id:delegateMouseArea
                            anchors.fill: parent
                            onClicked: {
                                stackView.push("SerieInfo.qml", { nameSerie: name, urlSerie: url, ratingSerie: rating, descSerie: desc, genreSerie: genre })

                            }
                        }

                        Component.onCompleted: {
                                if (serieName.text.length > 25) {
                                    serieName.text = serieName.text.substring(0, 20) + "..."
                                }
                            }
                    }
                }
            }
        }
    }
}

