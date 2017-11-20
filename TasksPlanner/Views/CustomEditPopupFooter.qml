import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.XmlListModel 2.0
import QtQuick.Window 2.3

TabBar {
    id: tabBarId
    height: 25
    background: Rectangle {
        gradient: Gradient {
            GradientStop { position: 0.0; color: "white" }
            GradientStop { position: 1.0; color: "lightgray" }
        }
    }
    
    CustomTabButton {
        imageSource: "qrc:/Images/okButton.png"
        tooltip: (addTask) ? "Add Task" : "Edit Task"
        height: parent.height
        buttonHandle: function () {
            if (titleTextEditId.text === "")
            {
                editItemPopupDialogId.close()
                return
            }

            if(addTask)
                MainViewManager.addTask(titleTextEditId.text, descriptionTextEditId.text, priorityTabBarId.currentIndex, itemAddedDate)
            else
                MainViewManager.updateTask(itemId, titleTextEditId.text, descriptionTextEditId.text, priorityTabBarId.currentIndex, itemAddedDate)
            
            timerId.running = false
            editItemPopupDialogId.close()
        }
    }

    TabSeparator {
        width: 3
    }

    CustomTabButton {
        imageSource: "qrc:/Images/cancelButton.png"
        tooltip: "Cancel"
        height: parent.height
        buttonHandle: function () {
            timerId.running = false
            editItemPopupDialogId.close()
        }
    }
}
