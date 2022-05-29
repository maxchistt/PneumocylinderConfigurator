#include "ParamsWidget.h"

ParamsWidget::ParamsWidget(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setupForm();
	connect(ui.pushButton_build, &QPushButton::clicked, this, &ParamsWidget::applyAndBuild);
	connect(ui.pushButton_reset, &QPushButton::clicked, this, &ParamsWidget::reset);
}

ParamsWidget::~ParamsWidget()
{
}

ParamsWidget::BuildParams ParamsWidget::getParams()
{
	updateParams();
	return modelParams;
}

void ParamsWidget::updateParams()
{
	modelParams.diam = ui.doubleSpinBox_diam->value();
	modelParams.length = ui.doubleSpinBox_length->value();
}

void ParamsWidget::setupForm()
{
	ui.doubleSpinBox_diam->setValue(modelParams.diam);
	ui.doubleSpinBox_length->setValue(modelParams.length);
}

void ParamsWidget::applyAndBuild()
{
	updateParams();
	emit buildSignal();
}

void ParamsWidget::reset()
{
	modelParams = BuildParams();
	setupForm();
}
