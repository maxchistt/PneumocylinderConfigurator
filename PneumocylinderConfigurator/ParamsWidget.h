#pragma once

#include <QWidget>
#include "ui_ParamsWidget.h"

class ParamsWidget : public QWidget
{
	Q_OBJECT

public:
	ParamsWidget(QWidget* parent = Q_NULLPTR);
	~ParamsWidget();

private:
	Ui::ParamsWidget ui;

private slots:
	void applyAndBuild();
	void reset();

signals:
	void buildSignal();
};
