#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	unsetCurrentModel();

	viewer = new Viewer();
	setCentralWidget(viewer);

	params = ui.widget_params;

	//запуск создания сцены
	connect(params, &ParamsWidget::buildSignal, this, &MainWindow::makeCylinderMathGeomSlot);
	connect(ui.action_build_pneumocyl, &QAction::triggered, this, &MainWindow::makeCylinderMathGeomSlot);
	connect(ui.action_clear, &QAction::triggered, this, &MainWindow::clearModelAndSceneSlot);

	connect(ui.action_save, &QAction::triggered, this, &MainWindow::saveFileSlot);
	connect(ui.action_open, &QAction::triggered, this, &MainWindow::openFileSlot);

	connect(ui.action_about, &QAction::triggered, this, &MainWindow::aboutSlot);
	connect(ui.action_aboutqt, &QAction::triggered, this, &MainWindow::aboutQtSlot);

	connect(ui.action_centralyze, &QAction::triggered, viewer, &Viewer::fitSceneSlot);
	connect(ui.action_nextOrientation, &QAction::triggered, viewer, &Viewer::nextOrientationSlot);
}

MainWindow::~MainWindow()
{
	::DeleteMatItem(currentMathModel);
}

void MainWindow::drawMathScene()
{
	viewer->clearScene();
	if (currentMathModel) viewer->addMathGeoms(currentMathModel);
	viewer->fitSceneSlot();
}

void MainWindow::setNewMathGeoms(MbItem& asmItem)
{
	unsetCurrentModel();
	MbModel* newModelToShow = new MbModel();
	newModelToShow->AddItem(asmItem);
	setCurrentModel(newModelToShow);
	drawMathScene();
}

void MainWindow::makeCylinderMathGeomSlot()
{
	auto item = CreatePneumocylinderAssembly();
	setNewMathGeoms(*item);
	::DeleteItem(item);
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
	::DeleteMatItem(currentMathModel);
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

void MainWindow::aboutSlot()
{
	QString str;
	str += "<h3>Pneumatic cylinder parametric model configurator</h3>";
	str += "Based on <a href=\"https://c3dlabs.com/ru/products/c3d-toolkit/\">C3D Toolkit</a> , Vision 2.6.4.6<br/>";
	str += "Licensed under MIT license<br/>";
	str += "For more info see GitHub <a href=\"https://github.com/maxchistt/PneumocylinderConfigurator\">page</a> (can be private)<hr/>";
	str += "Created as part of project activities by the <a href=\"https://vk.com/mpu_cloud\">CAD Development Center of the Moscow Polytech</a>";
	QMessageBox::about(this, "About", str);
}

void MainWindow::aboutQtSlot()
{
	QMessageBox::aboutQt(this);
}
