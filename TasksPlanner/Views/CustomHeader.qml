import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.XmlListModel 2.0

TabBar {
    height: 50
    background: Rectangle {
        gradient: Gradient {
            GradientStop { position: 0.0; color: "white" }
            GradientStop { position: 1.0; color: "lightgray" }
        }
    }

    CustomTabButton {
        imageSource: "qrc:/Images/tasksListButton.png"
        tooltip: "Tasks List"
        buttonHandle: function () {
            swipeViewId.currentIndex = 0
        }
    }
    CustomTabButton {
        imageSource: "qrc:/Images/settingsButton.png"
        tooltip: "Settings"
        buttonHandle: function () {
            swipeViewId.currentIndex = 1
        }
    }
    TabSeparator {
        width: 3
    }
    CustomTabButton {
        imageSource: "qrc:/Images/addButton.png"
        tooltip: "Add New Task"
        buttonHandle: function () {
            swipeViewId.currentIndex = 0
            showEditTaskPopup(true, false, 0, "", "", 0, new Date())
        }
    }
    CustomTabButton {
        imageSource: "qrc:/Images/saveButton.png"
        tooltip: "Save Tasks List"
        buttonHandle: function () {
            swipeViewId.currentIndex = 0
            saveOrLoadFileDialogPopup(true)
        }
    }
    CustomTabButton {
        imageSource: "qrc:/Images/loadButton.png"
        tooltip: "Load Tasks List"
        buttonHandle: function () {
            swipeViewId.currentIndex = 0
            saveOrLoadFileDialogPopup(false)
        }
    }
    CustomTabButton {
        imageSource: "qrc:/Images/closeButton.png"
        tooltip: "Close"
        buttonHandle: function () {
            Qt.quit()
        }
    }
}
