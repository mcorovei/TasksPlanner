import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.XmlListModel 2.0

TabButton {
    height: parent.height
    background: Rectangle {
        anchors.fill: parent
        color: "transparent"
    }

    Rectangle{
        anchors {
            left: parent.left
            right: parent.right
            verticalCenter: parent.verticalCenter
        }
        height: parent.height - 6
        radius: width / 2
        gradient: Gradient {
            GradientStop { position: 0.0; color: "white" }
            GradientStop { position: 0.5; color: "black" }
            GradientStop { position: 1.0; color: "black" }
        }
    }
}
