#include "MainWindow.h"

#include <QApplication>
#include <QtWidgets/QApplication>
#include <QStyleFactory>
#include <vsn_application.h>
#include <qlogging.h>
#include <last.h>

VSN_USE_NAMESPACE

int main(int argc, char* argv[])
{
#if defined(WIN32) /*&& defined(HUNT_FOR_MEM_LEAKS)*/
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	QApplication app(argc, argv);
	QApplication::setStyle(QStyleFactory::create("Fusion"));
	app.setApplicationName("Конфигуратор пневмоцилиндра");
	app.setOrganizationName("Центр САПР-разработки Московского Политеха");

	if (!QtVision::activateLicense())
		return 0;

	Application vapp;

	MainWindow mainWindow;
	QtVision::setWindowPosition(mainWindow);
	mainWindow.show();

	return app.exec();
}
