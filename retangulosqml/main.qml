import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    id: father
    property int size: 400
    height: father.size
    width: father.size
    color: "blue"

    Rectangle{
        visible: true
        id: son
        property int size: father.size * 0.8
        height: son.size
        width: son.size
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        color: "red"

        Rectangle{
            visible: true
            id: gson
            property int size: son.size * 0.6
            height: gson.size
            width: gson.size
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            color: "green"

            Rectangle{
                visible: true
                id: ggson1
                property int size: gson.size/2
                height: gson.size
                width: ggson1.size
                color: "white"
            }
            Rectangle{
                visible: true
                id: ggson2
                height: gson.size/2
                width: ggson1.size
                y: ggson1.y
                x: ggson1.y
                color: "black"
            }
        }
    }
}

