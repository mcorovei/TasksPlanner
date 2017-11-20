#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>

class QQmlApplicationEngine;
class MainViewManager;

class Startup : public QObject
{
	Q_OBJECT
public:
	explicit Startup(QObject *parent = 0);

private:
	QQmlApplicationEngine& m_engine;
	MainViewManager& m_mainViewManager;

	static void registerQMLTypes();

	explicit Startup(const Startup& rhs) = delete;
	Startup& operator= (const Startup& rhs) = delete;
};

#endif // STARTUP_H
