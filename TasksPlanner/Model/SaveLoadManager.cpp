#include "SaveLoadManager.h"

#include "ImportExportData.h"

#include <QDir>
#include <QDate>

SaveLoadManager* SaveLoadManager::m_pInstance = 0;

SaveLoadManager* SaveLoadManager::getInstance()
{
	if(!m_pInstance)
		m_pInstance = new SaveLoadManager();
	return m_pInstance;
}

void SaveLoadManager::saveToFile(const QUrl &filePath, const QList<TaskItem *> &tasksList)
{
	ImportExportData::getInstance()->exportTasksList(filePath.toLocalFile(), tasksList);
}

void SaveLoadManager::loadFromFile(const QUrl &filePath, QList<TaskItem *> &resultTasksList)
{
	ImportExportData::getInstance()->importTasksList(filePath.toLocalFile(), resultTasksList);
}

void SaveLoadManager::saveToDefaultDatedFile(const QList<TaskItem *> &tasksList)
{
	const QString autoSaveDirectory = QDir::currentPath() + "/AutoSave/";
	const QDir dir = QDir(autoSaveDirectory);

	if(!dir.exists())
		dir.mkdir(".");

	const QString dateString = QDate::currentDate().toString("dd-MM-yyyy");
	const QString filePath = autoSaveDirectory + dateString + ".xml";

	ImportExportData::getInstance()->exportTasksList(filePath, tasksList);
}

void SaveLoadManager::loadFromDefaultDatedFile(QList<TaskItem *> &resultTasksList)
{
	const QString autoSaveFile = QDir::currentPath()
								+ "/AutoSave/"
								+ QDate::currentDate().toString("dd-MM-yyyy")
								+ ".xml";

	ImportExportData::getInstance()->importTasksList(autoSaveFile, resultTasksList);

}

SaveLoadManager::SaveLoadManager(QObject *parent) : QObject(parent) { }
