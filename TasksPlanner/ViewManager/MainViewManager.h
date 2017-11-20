#ifndef MAINVIEWMANAGER_H
#define MAINVIEWMANAGER_H

#include <QObject>

#include "ViewModels/TasksListViewModel.h"

class MainViewManager : public QObject
{
	Q_OBJECT
public:
	explicit MainViewManager(QObject *parent = nullptr);
	~MainViewManager();

	TasksListViewModel& getTasks() const;

signals:
	void textSelected(const QString& text);
	void autoSave() const;

public slots:
	void addTask(const QString& title, const QString& description, int priority, const QDateTime& addedDate);
	void updateTask(int id, const QString &title, const QString &description, int priority, const QDateTime& addedDate);
	void removeTask(int taskId);

	void saveTasksList(const QUrl& filePath);
	void loadTasksList(const QUrl& filePath);

private slots:
	void onAutoSave();

private:
	TasksListViewModel& m_tasksListItems;
};

#endif // MAINVIEWMANAGER_H
