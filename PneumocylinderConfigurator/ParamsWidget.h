#pragma once

#include <QWidget>
#include "ui_ParamsWidget.h"
#include "BuildParams.h"

class ParamsWidget : public QWidget
{
	Q_OBJECT

public:
	ParamsWidget(QWidget* parent = Q_NULLPTR);
	~ParamsWidget();

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
