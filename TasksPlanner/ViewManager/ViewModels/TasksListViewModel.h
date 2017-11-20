#ifndef TASKSLISTVIEWMODEL_H
#define TASKSLISTVIEWMODEL_H

#include <QObject>
#include <QAbstractListModel>

#include "Model/Data/TaskItem.h"

class TasksListViewModel : public QAbstractListModel
{
		Q_OBJECT
	public:
		enum TaskItemRoles {
			IdRole = 500,
			TitleRole,
			DescriptionRole,
			PriorityRole,
			AddedDateRole
		};

		explicit TasksListViewModel(QObject *parent = nullptr);

		void addItem(TaskItem& item);
		void addItems(QList<TaskItem*>& listItems);
		void removeItem(int id);
		void removeAllItems();
		void updateItem(const TaskItem& item);
		QList<TaskItem*>& getItems();

		int rowCount(const QModelIndex& parent = QModelIndex()) const;
		QVariant data(const QModelIndex& index, int role) const;

	protected:
		QHash<int, QByteArray> roleNames() const;

	signals:

	public slots:

	private:
		QList<TaskItem*> m_items;
};

#endif // TASKSLISTVIEWMODEL_H
