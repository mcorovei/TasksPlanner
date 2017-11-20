import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.XmlListModel 2.0
import QtQml.Models 2.1

Page {
    readonly property int listItemsSpacing: 5
    readonly property color background_Color: "lightgray"
    readonly property int taskItemHeight: 180

    Rectangle {
        anchors.fill: parent
        color: background_Color
    }

    ListView {
        id: listViewId
        anchors.fill: parent

        displaced: Transition {
            NumberAnimation { properties: "x,y"; easing.type: Easing.OutQuad }
        }

        model: DelegateModel {
            id: visualModel
            model: TasksListModel
            delegate: MouseArea {
                id: delegateRootId

                property int visualIndex: DelegateModel.itemsIndex

                width: parent.width
                height: taskItemHeight

                drag.target: itemRectangleId

                Rectangle {
                    id: itemRectangleId
                    height: taskItemHeight - 2 * listItemsSpacing
                    radius: taskId.radius
                    anchors {
                        left: parent.left
                        right: parent.right
                        leftMargin: listItemsSpacing
                        rightMargin: listItemsSpacing
                        verticalCenter: parent.verticalCenter
                    }

                    Drag.active: delegateRootId.drag.active
                    Drag.source: delegateRootId
                    Drag.hotSpot.x: taskItemHeight / 2
                    states: [
                        State {
                            when: itemRectangleId.Drag.active
                            ParentChange {
                                target: itemRectangleId
                                parent: listViewId
                            }

                            AnchorChanges {
                                target: itemRectangleId;
                                anchors.horizontalCenter: undefined;
                                anchors.verticalCenter: undefined
                            }
                        }
                    ]

                    TaskItem {
                        id: taskId
                        itemId: model.id
                        titleText: model.title
                        descriptionText: model.description
                        priority: model.priority
                        addedDate: model.addedDate
                    }
                }

                DropArea {
                    anchors.fill: parent
                    onEntered: visualModel.items.move(drag.source.visualIndex, delegateRootId.visualIndex)
                }
            }
        }
    }
}
