#ifndef TASKITEM_H
#define TASKITEM_H

#include <QObject>
#include <QDateTime>

class TaskItem : public QObject
{
		Q_OBJECT
	public:
		explicit TaskItem(QObject *parent = nullptr);
		explicit TaskItem(const int id, const QString& title, const QString& description, const int priority, const QDateTime& addedDate, QObject *parent = nullptr);

		const TaskItem& operator=(const TaskItem& other);

		int id() const;
		void setId(int id);
		QString title() const;
		void setTitle(const QString& title);
		QString description() const;
		QDateTime addedDate() const;

		void setDescription(const QString& description);
		int priority() const;
		void setPriority(int priority);
		void setAddedDate(const QDateTime& dateAdded);



	private:
		int m_id;
		QString m_title;
		QString m_description;
		int m_priority;
		QDateTime m_addedDate;
};

#endif // TASKITEM_H
