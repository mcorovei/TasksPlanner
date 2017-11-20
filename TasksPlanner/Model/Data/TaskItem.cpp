#include "TaskItem.h"

TaskItem::TaskItem(QObject *parent) : QObject(parent)
{

}

TaskItem::TaskItem(const int id, const QString& title, const QString& description, const int priority, const QDateTime& addedDate,QObject *parent) :
	QObject(parent),
	m_id(id),
	m_title(title),
	m_description(description),
	m_priority(priority),
	m_addedDate(addedDate)
{

}

const TaskItem &TaskItem::operator=(const TaskItem &other)
{
	m_id = other.m_id;
	m_title = other.m_title;
	m_description = other.m_description;
	m_priority = other.m_priority;
	m_addedDate = other.m_addedDate;

	return *this;
}

int TaskItem::id() const
{
	return m_id;
}

void TaskItem::setId(int id)
{
	m_id = id;
}

QString TaskItem::title() const
{
	return m_title;
}

void TaskItem::setTitle(const QString& title)
{
	m_title = title;
}

QString TaskItem::description() const
{
	return m_description;
}

QDateTime TaskItem::addedDate() const
{
	return m_addedDate;
}

void TaskItem::setDescription(const QString& description)
{
	m_description = description;
}

int TaskItem::priority() const
{
	return m_priority;
}

void TaskItem::setPriority(int priority)
{
	m_priority = priority;
}

void TaskItem::setAddedDate(const QDateTime &addedDate)
{
	m_addedDate = addedDate;
}
