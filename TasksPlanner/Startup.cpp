#include "Startup.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QThread>

#include "ViewManager/MainViewManager.h"
#include "Model/InputSelectionTask.h"

Startup::Startup(QObject *parent) :
	QObject(parent),
	m_engine(*new QQmlApplicationEngine()),
	m_mainViewManager(*new MainViewManager())
{
	registerQMLTypes();

	auto rootContext = m_engine.rootContext();
	rootContext->setContextProperty("MainViewManager",&m_mainViewManager);
	rootContext->setContextProperty("TasksListModel", &m_mainViewManager.getTasks());

	m_engine.load(QUrl(QStringLiteral("qrc:/Views/main.qml")));

	QThread *thread = new QThread( );
	InputSelectionTask *task = new InputSelectionTask();
	task->moveToThread(thread);
	connect(thread, SIGNAL(started()), task, SLOT(doWork()));
	connect(task, SIGNAL(textSelected(QString)), &m_mainViewManager, SIGNAL(textSelected(QString)));

	connect(thread, SIGNAL(finished()), task, SLOT(deleteLater()));
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

	thread->start();
}

void Startup::registerQMLTypes()
{
}
