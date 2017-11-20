#ifndef SAVELOADMANAGER_H
#define SAVELOADMANAGER_H

#include <QObject>

#include <Model/Data/TaskItem.h>

class SaveLoadManager : public QObject
{
	Q_OBJECT
public:
	static SaveLoadManager* getInstance();

	static void saveToFile(const QUrl& filePath, const QList<TaskItem*>& tasksList);
	static void loadFromFile(const QUrl& filePath,  QList<TaskItem*>& resultTasksList);

	static void saveToDefaultDatedFile(const QList<TaskItem*>& tasksList);
	static void loadFromDefaultDatedFile(QList<TaskItem*>& resultTasksList);

signals:

public slots:


private:
	static SaveLoadManager* m_pInstance;
	explicit SaveLoadManager(QObject *parent = nullptr);
};

#endif // SAVELOADMANAGER_H
