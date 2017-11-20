import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.XmlListModel 2.0
import QtQuick.Window 2.3

Window {
    id: editItemPopupDialogId
    width: 400
    height: 450

    x: addFromSelection ? Screen.desktopAvailableWidth - width - 20 : mainWindowId.x + 100
    y: addFromSelection ? Screen.desktopAvailableHeight - height - 20 : mainWindowId.y + 50

    property int itemId
    property string itemTitle
    property string itemDescription
    property int itemPriority
    property date itemAddedDate

    property bool addTask: true
    property bool addFromSelection: false

    flags: Qt.WindowStaysOnTopHint

    Timer {
        id: timerId
        interval: 3000; running: false;
        onTriggered: {
            if (addTask)
            {
                if (titleTextEditId.text !== "")
                {
                    MainViewManager.addTask(titleTextEditId.text, descriptionTextEditId.text, priorityTabBarId.currentIndex, itemAddedDate)
                }

                editItemPopupDialogId.close();
            }
        }
    }

    onVisibleChanged: {
        if (addFromSelection && visible)
        {
            timerId.running = true
            timerId.interval = 3000
        }

        if (titleTextEditId.text === "")
            return
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            timerId.running = false
        }
    }

    ColumnLayout {
        anchors {
            left:  parent.left
            right: parent.right
            top: parent.top
            bottom: footerTabBarId.top
        }
        anchors.margins: 5

        TextField {
            id: titleTextEditId
            Layout.fillHeight: true
            Layout.fillWidth: true
            placeholderText: " Title "
            text: itemTitle
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            verticalAlignment: TextInput.AlignTop
            selectionColor: "gray"
            selectByMouse: true
            font {
                pointSize: 16
            }
            onFocusChanged: {
                timerId.running = false
            }
        }

        TextField {
            id: descriptionTextEditId
//            Layout.preferredHeight: 50
//            Layout.fillWidth: true
            visible: false
            placeholderText: " Description ..."
            text: itemDescription
            onFocusChanged: {
                timerId.running = false
            }
        }

        PriorityTabBar {
            id: priorityTabBarId
        }
    }

    CustomEditPopupFooter {
        id: footerTabBarId
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
    }
}
