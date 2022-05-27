#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	viewer = new Viewer(this);
	setCentralWidget(viewer);

	//запуск создания сцены
	connect(ui.action_testscene, &QAction::triggered, this, &MainWindow::makeTestMathGeomSlot);
	connect(ui.action_pneumocyl, &QAction::triggered, this, &MainWindow::makeCylinderMathGeomSlot);
	connect(ui.action_clear, &QAction::triggered, this, &MainWindow::clearModelAndSceneSlot);

	connect(ui.action_save, &QAction::triggered, this, &MainWindow::saveFileSlot);
	connect(ui.action_open, &QAction::triggered, this, &MainWindow::openFileSlot);
}

void MainWindow::drawMathScene()
{
	viewer->clearScene();
	if (currentMathModel) viewer->addMathGeoms(currentMathModel);
	viewer->fitScene();
}

void MainWindow::setNewMathGeoms(MbItem& asmItem)
{
	MbModel* newModelToShow = new MbModel();
	newModelToShow->AddItem(asmItem);
	setCurrentModel(newModelToShow);
	drawMathScene();
}

void MainWindow::makeTestMathGeomSlot()
{
	setNewMathGeoms(*createTestAssemblyModel());
}

void MainWindow::makeCylinderMathGeomSlot()
{
	setNewMathGeoms(*CreatePneumocylinderAssembly());
}

void MainWindow::clearModelAndSceneSlot()
{
	viewer->clearScene();
	unsetCurrentModel();
}

c3d::path_string MainWindow::getFilePath(bool save)
{
	const QString defaultPath = "D:/C3D_files/MyModel.c3d";
	const QString fileFilter = "CAD Models (*.c3d *.stp *.step *.STEP *.IGES *.SAT *.X_T *.X_B *.STL *.VRML *.JT)";
	QString fileName = save
		? QFileDialog::getSaveFileName(this, "Save File", defaultPath, fileFilter)
		: QFileDialog::getOpenFileName(this, "Open File", defaultPath, fileFilter);
	fileName.replace("/", "\\");
	fileName.replace(":", ":\\");
	c3d::path_string path = c3d::StdToPathstring(fileName.toStdString());
	return path;
}

void MainWindow::exportCurrentModel(c3d::path_string path)
{
	c3d::ExportIntoFile(*currentMathModel, path);
	drawMathScene();
}

void MainWindow::importCurrentModel(c3d::path_string path)
{
	MbModel* importModel = new MbModel();
	MbeConvResType importRes = c3d::ImportFromFile(*importModel, path);

	if (importRes == MbeConvResType::cnv_Success) setCurrentModel(importModel);

	drawMathScene();
}

void MainWindow::setCurrentModel(MbModel* model)
{
	unsetCurrentModel();
	if (model) currentMathModel = model;
}

void MainWindow::unsetCurrentModel()
{
	::DeleteItem(currentMathModel);
}

void MainWindow::saveFileSlot()
{
	if (currentMathModel) {
		c3d::path_string path = getFilePath();
		if (!path.empty()) exportCurrentModel(path);
	}
	else {
		QMessageBox::information(this, "Warning", "Nothing to save");
	}
}

void MainWindow::openFileSlot()
{
	c3d::path_string path = getFilePath(false);
	if (!path.empty()) importCurrentModel(path);
}
