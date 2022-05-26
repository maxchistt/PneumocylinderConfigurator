#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

#include <qt_openglwidget.h>
#include <vsn_segmentfeatures.h>
#include <vsn_vision.h>
#include <model_item.h>

#include "BuildTestMathModel.h"
#include "BuildMathModel.h"

#include <QFileDialog>
#include <model.h>
#include <conv_model_exchange.h>

#include <QMessageBox>

VSN_USE_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = Q_NULLPTR);

private:
	MbModel* currentMathModel = nullptr;
	Ui::MainWindowClass ui;
	QtVision::QtOpenGLSceneWidget* glWidget = Q_NULLPTR;
	void prepareSceneBackground();
	void fitScene();
	NodeKeyVector addMathGeoms(MbItem* item, VSN::SceneSegment* rootSceneSegment);
	NodeKeyVector addMathGeoms(MbModel* model, VSN::SceneSegment* rootSceneSegment);
	void drawMathScene();

	c3d::path_string getFilePath(bool save = true);
	void exportCurrentModel(c3d::path_string path);
	void importCurrentModel(c3d::path_string path);

private slots:
	void makeTestMathGeomSlot();
	void makeCylinderMathGeomSlot();
	void clearSceneSlot();
	void saveFileSlot();
	void openFileSlot();
};
