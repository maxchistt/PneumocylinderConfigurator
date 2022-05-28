#include "ParamsWidget.h"

ParamsWidget::ParamsWidget(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton_build, &QPushButton::clicked, this, &ParamsWidget::applyAndBuild);
	connect(ui.pushButton_reset, &QPushButton::clicked, this, &ParamsWidget::reset);
}

ParamsWidget::~ParamsWidget()
{
}

void ParamsWidget::applyAndBuild()
{
	emit buildSignal();
}

void ParamsWidget::reset()
{
	ui.lineEdit->setText("310");
	ui.lineEdit_2->setText("30");
}
