#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>

#include <Startup.h>

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);
	app.setWindowIcon(QIcon(":/Images/AppIcon.ico"));

	Startup startUp;

	return app.exec();
}
