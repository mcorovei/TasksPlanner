import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.XmlListModel 2.0
import Qt.labs.platform 1.0


import "qrc:/Views"

FileDialog {
    property bool save: true

    id: saveOrLoadFileDialogId
    title: save ? "Save Tasks List" : "Load Tasks List"
    fileMode: save ? FileDialog.SaveFile : FileDialog.OpenFile
    nameFilters: ["XML files (*.xml)"]

    onAccepted: {
        if(save)
            MainViewManager.saveTasksList(saveOrLoadFileDialogId.file)
        else
            MainViewManager.loadTasksList(saveOrLoadFileDialogId.file)
    }
}
