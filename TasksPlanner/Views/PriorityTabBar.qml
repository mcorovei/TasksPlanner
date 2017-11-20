import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.XmlListModel 2.0
import QtQuick.Window 2.3

TabBar{
    id: priorityTabBarId
    
    Layout.preferredHeight: 50
    Layout.fillWidth: true
    
    onCurrentIndexChanged: {
        timerId.running = false
    }
    
    CustomTabButton {
        imageSource: "qrc:/Images/priority_0.png"
        tooltip: "Prio 0"
        height: parent.height
        selectable: true
        buttonHandle: function () {
            itemPriority = 0;
            priorityTabBarId.currentIndex = 0;
        }
    }
    
    CustomTabButton {
        imageSource: "qrc:/Images/priority_1.png"
        tooltip: "Prio 1"
        height: parent.height
        selectable: true
        buttonHandle: function () {
            itemPriority = 1;
            priorityTabBarId.currentIndex = 1;
        }
    }
    
    CustomTabButton {
        imageSource: "qrc:/Images/priority_2.png"
        tooltip: "Prio 2"
        height: parent.height
        selectable: true
        buttonHandle: function () {
            itemPriority = 2;
            priorityTabBarId.currentIndex = 2;
        }
    }
    
    CustomTabButton {
        imageSource: "qrc:/Images/priority_3.png"
        tooltip: "Prio 3"
        height: parent.height
        selectable: true
        buttonHandle: function () {
            itemPriority = 3;
            priorityTabBarId.currentIndex = 3;
        }
    }
    
    CustomTabButton {
        imageSource: "qrc:/Images/priority_4.png"
        tooltip: "Prio 4"
        height: parent.height
        selectable: true
        buttonHandle: function () {
            itemPriority = 4;
            priorityTabBarId.currentIndex = 4;
        }
    }
    
    CustomTabButton {
        imageSource: "qrc:/Images/priority_5.png"
        tooltip: "Prio 5"
        height: parent.height
        selectable: true
        buttonHandle: function () {
            itemPriority = 5;
            priorityTabBarId.currentIndex = 5;
        }
    }
}
