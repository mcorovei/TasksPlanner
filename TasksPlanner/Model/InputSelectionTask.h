#ifndef INPUTSELECTIONTASK_H
#define INPUTSELECTIONTASK_H

#include <QObject>

class InputSelectionTask : public QObject
{
		Q_OBJECT
	public:
		explicit InputSelectionTask(QObject *parent = nullptr);

	signals:
		void textSelected(const QString& text) const;

	public slots:
		void doWork();
};

#endif // INPUTSELECTIONTASK_H
