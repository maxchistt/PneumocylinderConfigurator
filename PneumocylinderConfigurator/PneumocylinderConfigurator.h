#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PneumocylinderConfigurator.h"

#include <qt_openglwidget.h>
#include <vsn_segmentfeatures.h>
#include <vsn_vision.h>

#include "testmodelbuild.h"

VSN_USE_NAMESPACE

class PneumocylinderConfigurator : public QMainWindow
{
	Q_OBJECT

public:
	PneumocylinderConfigurator(QWidget* parent = Q_NULLPTR);

private:
	Ui::PneumocylinderConfiguratorClass ui;
	QtVision::QtOpenGLSceneWidget* glWidget = Q_NULLPTR;
	void prepareSceneBackground();
	void fitScene();
	NodeKeyVector addMathGeoms(MbItem* item, VSN::SceneSegment* rootSceneSegment);
private slots:
	void makeTestSceneSlot();
};
