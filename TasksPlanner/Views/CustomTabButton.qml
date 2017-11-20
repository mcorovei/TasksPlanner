import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.XmlListModel 2.0

TabButton {
    property string imageSource
    property double iconSize: height * 0.8
    property string tooltip
    property bool selectable: false
    property var buttonHandle: function() { console.log("button pushed! (default handle)") }

    id: customButtonId
    background: Rectangle {
        anchors.fill: parent
        color: "transparent"
        border.color: (customButtonId.checked && selectable) ? "gray" : "transparent"
        border.width: 2
    }
    anchors {
        top: parent.top
        bottom: parent.bottom
    }

    Image {
        id: imageId
        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
        }
        source: imageSource
        sourceSize.height: iconSize
        sourceSize.width: iconSize
        fillMode: Image.PreserveAspectFit
    }

    hoverEnabled: true
    onHoveredChanged:
    {
        if (hovered)
            ToolTip.show(tooltip, 1000)
        else
            ToolTip.hide()
    }
    onClicked: buttonHandle.call()
}
