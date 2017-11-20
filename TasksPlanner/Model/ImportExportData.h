#ifndef IMPORTEXPORTDATA_H
#define IMPORTEXPORTDATA_H

#include <QObject>
#include <QXmlStreamWriter>
#include <QUrl>

#include "Data/TaskItem.h"

class ImportExportData : public QObject
{
	Q_OBJECT
public:
	static ImportExportData* getInstance();

	static void exportTasksList(const QString& filePath, const QList<TaskItem*>& tasksList);
	static bool importTasksList(const QString& filePath,  QList<TaskItem*>& resultTasksList);

private:
	static void writeItem(QXmlStreamWriter& xmlWriter, TaskItem* item);
	static bool readXml_V1(QXmlStreamReader& xmlReader, QList<TaskItem*>& resultTasksList);

	static ImportExportData* m_pInstance;
	explicit ImportExportData(QObject *parent = nullptr);
};

#endif // IMPORTEXPORTDATA_H
