#include "ParamsWidget.h"

ParamsWidget::ParamsWidget(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.comboBox_doublesided->addItem("false", QVariant(0));
	ui.comboBox_doublesided->addItem("true", QVariant(1));
	ui.comboBox_edges->addItem("false", QVariant(0));
	ui.comboBox_edges->addItem("true", QVariant(1));
	ui.comboBox_lighttype->addItem("point", QVariant(0));
	ui.comboBox_lighttype->addItem("direction", QVariant(1));
	ui.comboBox_lighttype->addItem("spot", QVariant(2));
	ui.comboBox_colorScheme->addItem("White/Gray", QVariant(0));
	ui.comboBox_colorScheme->addItem("Red/Blue", QVariant(1));

	setupForm_model();
	setupForm_scene();
	ui.doubleSpinBox_diam->setDisabled(true);// в связи с незавершенностью параметризации
	connect(ui.pushButton_build, &QPushButton::clicked, this, &ParamsWidget::applyAndBuild);
	connect(ui.pushButton_reset, &QPushButton::clicked, this, &ParamsWidget::reset);
	connect(ui.pushButton_sceneset, &QPushButton::clicked, this, &ParamsWidget::sceneset);
}

ParamsWidget::~ParamsWidget()
{
}

BuildMathModel::BuildParams ParamsWidget::getParams_model()
{
	updateParams_model();
	return modelParams;
}

SceneParams ParamsWidget::getParams_scene()
{
	updateParams_scene();
	return sceneParams;
}

void ParamsWidget::updateParams_model()
{
	modelParams.diam = ui.doubleSpinBox_diam->value();
	modelParams.length = ui.doubleSpinBox_length->value();
	modelParams.frame = ui.checkBox_frame->checkState() == Qt::CheckState::Checked;
	modelParams.colorScheme = ui.comboBox_colorScheme->currentIndex();
}

void ParamsWidget::setupForm_model()
{
	ui.doubleSpinBox_diam->setValue(modelParams.diam);
	ui.doubleSpinBox_length->setValue(modelParams.length);
	ui.checkBox_frame->setCheckState(modelParams.frame ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
	ui.comboBox_colorScheme->setCurrentIndex(modelParams.colorScheme ? 1 : 0);
}

void ParamsWidget::updateParams_scene()
{
	sceneParams.doubleSided = ui.comboBox_doublesided->currentIndex();
	sceneParams.edges = ui.comboBox_edges->currentIndex();
	sceneParams.lightType = ui.comboBox_lighttype->currentIndex();
}

void ParamsWidget::setupForm_scene()
{
	ui.comboBox_doublesided->setCurrentIndex(sceneParams.doubleSided ? 1 : 0);
	ui.comboBox_edges->setCurrentIndex(sceneParams.edges ? 1 : 0);
	ui.comboBox_lighttype->setCurrentIndex(sceneParams.lightType);
}

void ParamsWidget::applyAndBuild()
{
	updateParams_model();
	emit buildSignal();
}

void ParamsWidget::reset()
{
	modelParams = BuildMathModel::BuildParams();
	setupForm_model();
}

void ParamsWidget::sceneset()
{
	updateParams_model();
	emit setupSceneSignal();
}
