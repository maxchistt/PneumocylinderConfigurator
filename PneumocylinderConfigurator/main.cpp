#include "PneumocylinderConfigurator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PneumocylinderConfigurator w;
    w.show();
    return a.exec();
}
