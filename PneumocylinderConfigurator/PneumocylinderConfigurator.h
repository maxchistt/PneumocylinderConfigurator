#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PneumocylinderConfigurator.h"

class PneumocylinderConfigurator : public QMainWindow
{
    Q_OBJECT

public:
    PneumocylinderConfigurator(QWidget *parent = Q_NULLPTR);

private:
    Ui::PneumocylinderConfiguratorClass ui;
};
