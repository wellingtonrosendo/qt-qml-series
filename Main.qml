import QtQuick
import QtQuick.Controls 2.5
import SeriesSearch

Window {

    maximumWidth: 480
    maximumHeight: 900
    minimumWidth: 480
    minimumHeight: 900

    visible: true
    title: qsTr("WellingFlix")


    StackView {
        id: stackView
        initialItem: "HighLights.qml"
        anchors.fill: parent

    }

}

