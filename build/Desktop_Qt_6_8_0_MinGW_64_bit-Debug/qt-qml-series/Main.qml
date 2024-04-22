import QtQuick
import SeriesSearch

Window {
    width: 480
    height: 640
    visible: true
    title: qsTr("WellingFlix")

    Rectangle {
        id: topbar
        height: 100
        color: "#c0c0c0"
        opacity: 0.5

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
        id: mainsection
        z:4
        anchors {
            top: topbar.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }
        color: "#222222"
        Text {
            id: teste4
            text: qsTr("aaaaaaaaaaaaaaaaaaaa")
            color:"#ffffff"
        }
        ListView {
            width: 200; height: 250

            model: SeriesSearch

            delegate: Text {
                required property string name

                text: "serie: " + name
            }
        }

    //     ListView {
    //         id: listView

    //         anchors {
    //             top: topbar.bottom
    //             margins: 20
    //         }



    //         spacing: 10
    //         clip: true

    //         model: SeriesSearch
    //         visible: true
    //         delegate: Rectangle {
    //             id: delegate
    //             required property string name
    //             required property string url
    //             required property double rating
    //             required property int index


    //             width: parent.width
    //             height: 50

    //             color: "#1e1e1e"
    //             Image {
    //                 id: serieImage
    //                 anchors {
    //                     left: parent.left
    //                     leftMargin: 5
    //                     verticalCenter: parent.verticalCenter
    //                 }

    //                 width: 32
    //                 height: 32

    //                 source: delegate.url
    //             }
    //         }

    //     }

    }
}

