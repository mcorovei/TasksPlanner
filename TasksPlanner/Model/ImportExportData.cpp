#include "ImportExportData.h"

#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QUrl>

#define XML_EL_TASK "task"
#define XML_EL_ID "id"
#define XML_EL_TITLE "title"
#define XML_EL_DESCRIPTION "description"
#define XML_EL_PRIO "prio"
#define XML_EL_ADDEDDATE "addedDate"

ImportExportData* ImportExportData::m_pInstance = 0;

ImportExportData* ImportExportData::getInstance()
{
	if(!m_pInstance)
		m_pInstance = new ImportExportData();
	return m_pInstance;
}

void ImportExportData::exportTasksList(const QString& filePath, const QList<TaskItem*>& tasksList)
{
	QFile exportFile(filePath);

	if (!exportFile.open(QFile::WriteOnly | QFile::Truncate))
	{
		return;
	}

	QXmlStreamWriter xmlWriter(&exportFile);

	xmlWriter.writeStartDocument();
	xmlWriter.writeDTD("<!DOCTYPE xml>");
	xmlWriter.writeStartElement("xml");
	xmlWriter.writeAttribute("version", "1.0");
	xmlWriter.writeAttribute("encoding", "UTF-8");
	for (auto iter : tasksList)
	{
		writeItem(xmlWriter, iter);
	}

	xmlWriter.writeEndDocument();
}

bool ImportExportData::importTasksList(const QString& filePath,  QList<TaskItem*>& resultTasksList)
{
	QFile importFile(filePath);

	if (!importFile.open(QFile::ReadOnly))
	{
		return 0;
	}

	QXmlStreamReader xmlReader(&importFile);

	if (xmlReader.readNextStartElement()) {
		if (xmlReader.name() == "xml" && xmlReader.attributes().value("version") == "1.0")
			return readXml_V1(xmlReader, resultTasksList);
		else
			return false;
	}

	return false;
}

void ImportExportData::writeItem(QXmlStreamWriter& xmlWriter, TaskItem* item)
{
	xmlWriter.writeStartElement(XML_EL_TASK);
	xmlWriter.writeAttribute(XML_EL_ID, QString::number(item->id()));
	xmlWriter.writeAttribute(XML_EL_TITLE, item->title());
	xmlWriter.writeAttribute(XML_EL_DESCRIPTION, item->description());
	xmlWriter.writeAttribute(XML_EL_PRIO, QString::number(item->priority()));
	xmlWriter.writeAttribute(XML_EL_ADDEDDATE, item->addedDate().toString());
	xmlWriter.writeEndElement();
}

bool ImportExportData::readXml_V1(QXmlStreamReader &xmlReader, QList<TaskItem *>& resultTasksList)
{
	while (!xmlReader.atEnd() && !xmlReader.hasError())
	{
		TaskItem* task = new TaskItem();
		xmlReader.readNext();
		if(xmlReader.isStartElement())
		{
			task->setId(xmlReader.attributes().value(XML_EL_ID).toInt());
			task->setTitle(xmlReader.attributes().value(XML_EL_TITLE).toString());
			task->setDescription(xmlReader.attributes().value(XML_EL_DESCRIPTION).toString());
			task->setPriority(xmlReader.attributes().value(XML_EL_PRIO).toInt());
			task->setAddedDate(QDateTime::fromString(xmlReader.attributes().value(XML_EL_ADDEDDATE).toString()));

			resultTasksList.append(task);
		}
	}
	return false;
}

ImportExportData::ImportExportData(QObject *parent) : QObject(parent) { }
