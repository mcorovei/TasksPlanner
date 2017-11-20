#include "MainViewManager.h"

#include "ViewModels/TasksListViewModel.h"
#include "Model/SaveLoadManager.h"

#include <QDateTime>

MainViewManager::MainViewManager(QObject *parent) :
	QObject(parent),
	m_tasksListItems(*new TasksListViewModel())
{
	connect(this, SIGNAL(autoSave()), this, SLOT(onAutoSave()));


	QList<TaskItem*> taskListItems;

	SaveLoadManager::getInstance()->loadFromDefaultDatedFile(taskListItems);

	m_tasksListItems.addItems(taskListItems);
}

MainViewManager::~MainViewManager() {}

TasksListViewModel& MainViewManager::getTasks() const
{
	return m_tasksListItems;
}

void MainViewManager::addTask(const QString& title, const QString& description, int priority, const QDateTime& addedDate)
{
	static int id = 11;
	m_tasksListItems.addItem(*new TaskItem(id, title, description, priority, addedDate));
	id++;
	emit autoSave();
}

void MainViewManager::updateTask(int id, const QString& title, const QString& description, int priority, const QDateTime& addedDate)
{
	m_tasksListItems.updateItem(TaskItem(id, title, description, priority, addedDate));

	emit autoSave();
}

void MainViewManager::removeTask(int taskId)
{
	m_tasksListItems.removeItem(taskId);

	emit autoSave();
}

void MainViewManager::saveTasksList(const QUrl& filePath)
{
	SaveLoadManager::getInstance()->saveToFile(filePath, m_tasksListItems.getItems());
}

void MainViewManager::loadTasksList(const QUrl& filePath)
{
	QList<TaskItem*> taskListItems;

	SaveLoadManager::getInstance()->loadFromFile(filePath, taskListItems);

	m_tasksListItems.removeAllItems();

	m_tasksListItems.addItems(taskListItems);
}

void MainViewManager::onAutoSave()
{
	SaveLoadManager::getInstance()->saveToDefaultDatedFile(m_tasksListItems.getItems());
}
