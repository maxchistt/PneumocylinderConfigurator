#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PneumocylinderConfigurator.h"

#include <qt_openglwidget.h>
#include <vsn_segmentfeatures.h>
#include <vsn_vision.h>
#include <model_item.h>

#include "BuildTestMathModel.h"
#include "BuildMathModel.h"

VSN_USE_NAMESPACE

class PneumocylinderConfigurator : public QMainWindow
{
	Q_OBJECT

public:
	PneumocylinderConfigurator(QWidget* parent = Q_NULLPTR);

private:
	MbItem* currentMathItem = nullptr;
	Ui::PneumocylinderConfiguratorClass ui;
	QtVision::QtOpenGLSceneWidget* glWidget = Q_NULLPTR;
	void prepareSceneBackground();
	void fitScene();
	NodeKeyVector addMathGeoms(MbItem* item, VSN::SceneSegment* rootSceneSegment);
	void drawMathScene();
private slots:
	void makeTestSceneSlot();
	void makeCylinderSceneSlot();
	void clearSceneSlot();
};
