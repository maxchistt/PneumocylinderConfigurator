#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

#include "Viewer.h"

#include <model.h>
#include <conv_model_exchange.h>

#include "BuildTestMathModel.h"
#include "BuildMathModel.h"

#include <QFileDialog>
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
	Viewer* viewer = Q_NULLPTR;

	void drawMathScene();

	c3d::path_string getFilePath(bool save = true);
	void exportCurrentModel(c3d::path_string path);
	void importCurrentModel(c3d::path_string path);

private slots:
	void makeTestMathGeomSlot();
	void makeCylinderMathGeomSlot();
	void clearModelAndSceneSlot();
	void saveFileSlot();
	void openFileSlot();
};
