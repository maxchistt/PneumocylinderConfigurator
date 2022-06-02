#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

#include "Viewer.h"
#include "ParamsWidget.h"
#include "BuildMathModel.h"

#include <model.h>
#include <conv_model_exchange.h>

#include <QFileDialog>
#include <QMessageBox>

#include "BuildParams.h"

VSN_USE_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = Q_NULLPTR);
	~MainWindow();

private:
	MbModel* currentMathModel = nullptr;
	Ui::MainWindowClass ui;
	Viewer* viewer = Q_NULLPTR;
	ParamsWidget* paramsWidget = Q_NULLPTR;

	void drawMathScene();
	void setNewMathGeoms(MbModel* mathModel);

	c3d::path_string getFilePath(bool save = true);
	void exportCurrentModel(c3d::path_string path);
	void importCurrentModel(c3d::path_string path);

	void setCurrentModel(MbModel* model);
	void unsetCurrentModel();

private slots:
	void makeCylinderMathGeomSlot();
	void clearModelAndSceneSlot();
	void saveFileSlot();
	void openFileSlot();
	void aboutSlot();
	void aboutQtSlot();
	void showParams();
};
