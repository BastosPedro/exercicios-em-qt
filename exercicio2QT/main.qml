import QtQuick 2.5
import QtQuick.Window 2.2


Window {
    function mm(value){
        return value*Screen.pixelDensity
    }
    visible: true
    height: mm(150)
    width: mm(150)
    color: "#262626"

    Rectangle{
        id: father
        color: "#FAFAFA"
        anchors.fill: parent
        anchors.margins: 20
        Rectangle{
            id: son
            visible:true
            color:parent.color
            width:(parent.height)*0.9
            height:(parent.width)*0.3
            anchors.centerIn: parent
            Rectangle{
                id:gsonRED
                visible: true
                color:"#C80000"
                width:(parent.width)/9
                height:(parent.height)/3
                anchors.top:parent.top
                anchors.left: parent.left
            }
            Rectangle{
                id:gsonGREEN
                visible: true
                color:"#00C800"
                height:gsonRED.height
                width: (gsonRED.width) * 6
                anchors.top: gsonRED.bottom
                anchors.left:gsonRED.right
            }
            Rectangle{
                id:gsonBLUE
                visible: true
                color:"#0000C8"
                height:gsonRED.height
                width: (gsonRED.width) * 2
                anchors.bottom: parent.bottom
                anchors.right: parent.right
            }
        }
    }
}

