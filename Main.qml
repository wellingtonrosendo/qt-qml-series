import QtQuick
import QtQuick.Controls 2.5
import SeriesSearch

Window {

    maximumWidth: 480
    maximumHeight: 800
    minimumWidth: 480
    minimumHeight: 800

    visible: true
    title: qsTr("WellingFlix")


    StackView {
        id: stackView
        initialItem: "HighLights.qml"
        anchors.fill: parent

    }

}

