#include "TasksListViewModel.h"

TasksListViewModel::TasksListViewModel(QObject *parent) :
	QAbstractListModel(parent),
	m_items(*new QList<TaskItem*>())
{

}

void TasksListViewModel::addItem(TaskItem& item)
{
	beginInsertRows(QModelIndex(), rowCount(), rowCount());
	m_items.append(&item);
	endInsertRows();
}

void TasksListViewModel::addItems(QList<TaskItem*>& listItems)
{
	for (auto item : listItems)
	{
		addItem(*item);
	}
}

void TasksListViewModel::updateItem(const TaskItem& item)
{
	int id = item.id();
	auto iter = std::find_if(m_items.begin(), m_items.end(),
							 [id](TaskItem* item) {	return item->id() == id; });

	if(iter != m_items.end())
	{
		int indx = m_items.indexOf(*iter);
		*(m_items[indx]) = item;
		dataChanged(index(indx), index(indx));
	}
}

void TasksListViewModel::removeItem(int id)
{

	auto iter = std::find_if(m_items.begin(), m_items.end(),
							 [id](TaskItem* item) { return item->id() == id; });

	if(iter != m_items.end())
	{
		int index = m_items.indexOf(*iter);
		beginRemoveRows(QModelIndex(), index, index);
		m_items.removeAt(index);
		endRemoveRows();
	}
}

void TasksListViewModel::removeAllItems()
{
	beginRemoveRows(QModelIndex(), 0, rowCount());
	m_items.clear();
	endRemoveRows();
}

QList<TaskItem*>& TasksListViewModel::getItems()
{
	return m_items;
}

int TasksListViewModel::rowCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return m_items.count();
}

QVariant TasksListViewModel::data(const QModelIndex& index, int role) const
{
	if (index.row() < 0 || index.row() >= m_items.count())
		return QVariant();

	TaskItem* const item = m_items[index.row()];

	switch(role) {
		case IdRole:
			return item->id();
		case TitleRole:
			return item->title();
		case DescriptionRole:
			return item->description();
		case PriorityRole:
			return item->priority();
		case AddedDateRole:
			return item->addedDate();
		default:
			return QVariant();
	}
}

QHash<int, QByteArray> TasksListViewModel::roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[IdRole] = "id";
	roles[TitleRole] = "title";
	roles[DescriptionRole] = "description";
	roles[PriorityRole] = "priority";
	roles[AddedDateRole] = "addedDate";
	return roles;
}
