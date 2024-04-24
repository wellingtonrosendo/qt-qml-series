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
                          }
            }


        }

        Rectangle {
            id:titleContainer
            height: 50
            color: "#111111"
            z:2
            anchors {
                top: topbar.bottom
                left: parent.left
                right: parent.right
            }
            Text {
                id: title
                text: qsTr("Em alta")
                font.pixelSize: 22
                color:"white"
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
                                width: 50
                                height: parent.height
                            }
                            Text {
                                id: serieName
                                text: delegate.name
                                anchors {
                                    bottom: parent.verticalCenter
                                    left: serieImage.right
                                    right: parent.right
                                }

                            }
                            Text {
                                id: serieRate
                                text: qsTr(delegate.rating.toString())
                                anchors {
                                    top: serieName.bottom
                                    bottom: parent.verticalCenter
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
                    }
                }
            }
        }
    }
}

