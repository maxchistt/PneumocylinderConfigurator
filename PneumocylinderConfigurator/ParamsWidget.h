#pragma once

#include <QWidget>
#include "ui_ParamsWidget.h"

class ParamsWidget : public QWidget
{
	Q_OBJECT

public:
	ParamsWidget(QWidget* parent = Q_NULLPTR);
	~ParamsWidget();

	struct BuildParams
	{
		double diam = 23.6;
		double length = 316.05;
	};

	BuildParams getParams();

private:
	Ui::ParamsWidget ui;
	BuildParams modelParams;
	void updateParams();
	void setupForm();

private slots:
	void applyAndBuild();
	void reset();

signals:
	void buildSignal();
};
