#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

#include <model.h>

#include <QMessageBox>

#include "Viewer.h"
#include "ParamsWidget.h"
#include "BuildParams.h"
#include "BuildMathModel.h"
#include "FileController.h"

VSN_USE_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = Q_NULLPTR);
	~MainWindow();

private:
	FileController* fileController = Q_NULLPTR;
	MbModel* currentMathModel = nullptr;
	Ui::MainWindowClass ui;
	Viewer* viewer = Q_NULLPTR;
	ParamsWidget* paramsWidget = Q_NULLPTR;

	void drawMathScene();
	void setNewMathGeoms(MbModel* mathModel);

	void setCurrentModel(MbModel* model);
	void unsetCurrentModel();

private slots:
	void makeCylinderMathGeomSlot();
	void clearModelAndSceneSlot();
	void aboutSlot();
	void aboutQtSlot();
	void showParams();

	void giveModelSlot(MbModel*& modelPtrRef);
	void onModelImportedSlot(MbModel* modelPtr);
	void onModelExportedSlot();
};
