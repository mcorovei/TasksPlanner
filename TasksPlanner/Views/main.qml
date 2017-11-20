import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.XmlListModel 2.0
import QtQuick.Dialogs 1.2
import "qrc:/Views"

ApplicationWindow {
    id: mainWindowId
    visible: true
    width: 640
    height: 480
    title: qsTr("Tasks Planner")
    minimumWidth: 640
    minimumHeight: 400

    header: CustomHeader {
        id: headerTabBarId
    }

    SwipeView {
        id: swipeViewId
        anchors.fill: parent
        currentIndex: headerTabBarId.currentIndex < 2 ? 0 : headerTabBarId.currentIndex

        TasksListPage {

        }

        SettingsPage {
        }
    }

    Connections {
        target: MainViewManager
        onTextSelected: {
            showEditTaskPopup(true, true, 0, text, "", 0, new Date());
        }
    }

    function showEditTaskPopup(addTask, addFromSelection, itemId, titleText, descriptionText, priority, addedDate) {

        var component = Qt.createComponent("EditPopUpDialog.qml")
        var win = component.createObject(mainWindowId);

        win.addTask = addTask
        win.addTask = addTask
        win.addFromSelection = addFromSelection
        win.itemId = itemId
        win.itemTitle = titleText
        win.itemDescription = descriptionText
        win.itemPriority = priority
        win.itemAddedDate = addedDate

        win.show()
    }
    function saveOrLoadFileDialogPopup(save) {
        var component = Qt.createComponent("SaveOrLoadFileDialog.qml")
        var win = component.createObject(mainWindowId);

        win.save = save

        win.open()
    }
}
