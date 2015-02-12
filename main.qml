import QtQuick 2.2
import QtQuick.Window 2.1
import dk.winkler.qml.NameCounter 1.0

Window {
    id: root
    visible: true
    width: 360
    height: 360

    NameCounter
    {
        id: andres
        name: "andres";
    }

    Text {
        id: label

        text: morten.name + " and " + andres.name + ": The Dynamic Duo"
        anchors.left: parent.left
        anchors.top: parent.top

    }



    ListView
    {
        id: listview
        anchors.top: label.bottom;
        height: parent.height - label.height
        width: parent.width


        model: myModel
        delegate: Text {
            text: type + ": " + size
        }


    }

}
