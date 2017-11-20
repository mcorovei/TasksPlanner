import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.XmlListModel 2.0

Rectangle{
    property int itemId
    property string titleText
    property string descriptionText
    property int priority
    property date addedDate

    readonly property color backgroundColor: "white"

    readonly property int itemRectangleRadius: 5
    readonly property int marginsSpacing: 10

    readonly property string priorityIconSource: "qrc:/Images/priority_" + priority + ".png"
    readonly property int priorityIconSize: 35
    readonly property string viewButtonImageSource: "qrc:/Images/viewButton.png"
    readonly property int viewButtonSize: 20
    readonly property string editButtonImageSource: "qrc:/Images/editButton.png"
    readonly property int editButtonSize: 20
    readonly property string removeButtonImageSource: "qrc:/Images/removeButton.png"
    readonly property int removeButtonSize: 20

    readonly property int titleTextSize: 20
    readonly property int descriptionTextSize: 16

    radius: itemRectangleRadius
    color: backgroundColor
    anchors.fill: parent

    RowLayout {
        id: rowLayoutId
        anchors {
            fill: parent
            leftMargin: marginsSpacing
            rightMargin: marginsSpacing
        }

        // Priority icon
        Image {
            Layout.preferredWidth: priorityIconSize
            Layout.preferredHeight: priorityIconSize
            Layout.topMargin: marginsSpacing
            Layout.bottomMargin: marginsSpacing
            Layout.alignment: Qt.AlignTop

            source: priorityIconSource
            sourceSize {
                height: priorityIconSize
                width: priorityIconSize
            }
            fillMode: Image.PreserveAspectFit
        }

        // Task title and date
        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.topMargin: marginsSpacing
            Layout.bottomMargin: marginsSpacing

            spacing: marginsSpacing

            // Title
            Text {
                Layout.fillWidth: true
                Layout.fillHeight: true

                font {
                    pixelSize: titleTextSize
                }
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                elide: Text.ElideRight
                text: titleText
            }

            // Date Added
            Text {
                Layout.fillWidth: true
                Layout.preferredHeight: contentHeight

                font {
                    pixelSize: descriptionTextSize
                }
                text: "Added: " + addedDate.toLocaleString();
            }
        }

        // View item button
        //        Image {
        //            Layout.preferredWidth: viewButtonSize
        //            Layout.preferredHeight: viewButtonSize
        //            Layout.topMargin: marginsSpacing
        //            Layout.bottomMargin: marginsSpacing
        //            Layout.alignment: Qt.AlignTop

        //            source: viewButtonImageSource
        //            sourceSize {
        //                height: viewButtonSize
        //                width: viewButtonSize
        //            }
        //            fillMode: Image.PreserveAspectFit

        //            MouseArea {
        //                anchors.fill: parent
        //                onClicked: {
        //                   print("viewItem")
        //                }
        //                hoverEnabled: true
        //                onHoveredChanged:
        //                {
        //                    if (hovered)
        //                        ToolTip.show("View", 1000)
        //                    else
        //                        ToolTip.hide()
        //                }
        //            }
        //        }

        // Edit item button
        Image {
            Layout.preferredWidth: editButtonSize
            Layout.preferredHeight: editButtonSize
            Layout.topMargin: marginsSpacing
            Layout.bottomMargin: marginsSpacing
            Layout.alignment: Qt.AlignTop

            source: editButtonImageSource
            sourceSize {
                height: editButtonSize
                width: editButtonSize
            }
            fillMode: Image.PreserveAspectFit

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    showEditTaskPopup(false, false, itemId, titleText, descriptionText, priority, addedDate)
                }

                hoverEnabled: true
                onHoveredChanged:
                {
                    if (hovered)
                        ToolTip.show("Edit", 1000)
                    else
                        ToolTip.hide()
                }
            }
        }

        // Remove item button
        Image {
            Layout.preferredWidth: removeButtonSize
            Layout.preferredHeight: removeButtonSize
            Layout.topMargin: marginsSpacing
            Layout.bottomMargin: marginsSpacing
            Layout.alignment: Qt.AlignTop

            source: removeButtonImageSource
            sourceSize {
                height: removeButtonSize
                width: removeButtonSize
            }
            fillMode: Image.PreserveAspectFit

            MouseArea {
                anchors.fill: parent
                onClicked: {
                   MainViewManager.removeTask(itemId)
                }

                hoverEnabled: true
                onHoveredChanged:
                {
                    if (hovered)
                        ToolTip.show("Remove", 1000)
                    else
                        ToolTip.hide()
                }
            }
        }
    }
}
