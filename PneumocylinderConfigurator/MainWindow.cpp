#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	unsetCurrentModel();

	viewer = ui.widget_viewer;
	paramsWidget = ui.widget_params;

	fileController = new FileController(this);

	//������ �������� �����
	connect(paramsWidget, &ParamsWidget::buildSignal, this, &MainWindow::makeCylinderMathGeomSlot);
	connect(ui.action_build_pneumocyl, &QAction::triggered, this, &MainWindow::makeCylinderMathGeomSlot);
	connect(ui.action_clear, &QAction::triggered, this, &MainWindow::clearModelAndSceneSlot);

	connect(ui.action_about, &QAction::triggered, this, &MainWindow::aboutSlot);
	connect(ui.action_aboutqt, &QAction::triggered, this, &MainWindow::aboutQtSlot);

	connect(ui.action_centralyze, &QAction::triggered, viewer, &Viewer::fitSceneSlot);
	connect(ui.action_nextOrientation, &QAction::triggered, viewer, &Viewer::nextOrientationSlot);

	connect(ui.action_params, &QAction::triggered, this, &MainWindow::showParams);

	connect(ui.action_save, &QAction::triggered, fileController, &FileController::saveFileSlot);
	connect(ui.action_open, &QAction::triggered, fileController, &FileController::openFileSlot);

	connect(fileController, &FileController::modelExportedSignal, this, &MainWindow::onModelExportedSlot);
	connect(fileController, &FileController::modelImportedSignal, this, &MainWindow::onModelImportedSlot);
	connect(fileController, &FileController::getModelSignal, this, &MainWindow::giveModelSlot);
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

void MainWindow::setNewMathGeoms(MbModel* mathModel)
{
	unsetCurrentModel();
	setCurrentModel(mathModel);
	drawMathScene();
}

void MainWindow::makeCylinderMathGeomSlot()
{
	BuildMathModel::BuildParams modelParams = paramsWidget->getParams();
	MbModel* newModelToShow = BuildMathModel::ParametricModelCreator::CreatePneymocylinderModel(modelParams);
	setNewMathGeoms(newModelToShow);
}

void MainWindow::clearModelAndSceneSlot()
{
	viewer->clearScene();
	unsetCurrentModel();
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

void MainWindow::aboutSlot()
{
	const QString GitRepo("https://github.com/maxchistt/PneumocylinderConfigurator");
	QString str;
	str += "<h3>" + QApplication::applicationName() + "</h3>";
	str += u8"<p>����������-������������ ��������������� ������ ��������������� ��������</p>";
	str += u8"�� ���� <a href=\"https://c3dlabs.com/ru/products/c3d-toolkit/\">C3D Toolkit</a> , Vision 2.6.4.6<br/>";
	str += u8"��� ��������� MIT license<br/>";
	str += u8"��������� �� �������� GitHub <a href=\"" + GitRepo + u8"\">�����������</a><br/>";
	str += u8"������: " + QApplication::applicationVersion() + "<hr/>";
	str += u8"������� � ������ ��������� ������������ <a href=\"" + QApplication::organizationDomain() + "\">" + u8"������� ����-���������� ����������� ��������" + "</a>";
	QMessageBox::about(this, "About", str);
}

void MainWindow::aboutQtSlot()
{
	QMessageBox::aboutQt(this);
}

void MainWindow::showParams()
{
	ui.dockWidget_params->setVisible(!ui.dockWidget_params->isVisible());
}

void MainWindow::giveModelSlot(MbModel*& modelPtrRef)
{
	modelPtrRef = currentMathModel;
}

void MainWindow::onModelImportedSlot(MbModel* modelPtr)
{
	setNewMathGeoms(modelPtr);
}

void MainWindow::onModelExportedSlot()
{
	drawMathScene();
}