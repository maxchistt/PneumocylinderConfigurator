#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QtVision::setSurfaceFormat();
	glWidget = new QtVision::QtOpenGLSceneWidget(this);
	setCentralWidget(glWidget);

	QtVision::createProcessesCameraControls(glWidget);

	prepareSceneBackground();

	//������ �������� �����
	connect(ui.action_testscene, &QAction::triggered, this, &MainWindow::makeTestMathGeomSlot);
	connect(ui.action_pneumocyl, &QAction::triggered, this, &MainWindow::makeCylinderMathGeomSlot);
	connect(ui.action_clear, &QAction::triggered, this, &MainWindow::clearSceneSlot);

	connect(ui.action_save, &QAction::triggered, this, &MainWindow::saveFileSlot);
	connect(ui.action_open, &QAction::triggered, this, &MainWindow::openFileSlot);
}

void MainWindow::drawMathScene()
{
	SceneSegment* rootSegment = glWidget->sceneContent()->GetRootSegment();
	Q_ASSERT(rootSegment != nullptr);

	if (currentMathModel)addMathGeoms(currentMathModel, rootSegment);

	fitScene();
}


void MainWindow::makeTestMathGeomSlot()
{
	MbModel* newModelToShow = new MbModel();
	newModelToShow->AddItem(*createTestAssemblyModel());

	clearSceneSlot();
	currentMathModel = newModelToShow;
	drawMathScene();
}

void MainWindow::makeCylinderMathGeomSlot()
{
	MbModel* newModelToShow = new MbModel();
	newModelToShow->AddItem(*CreatePneumocylinderAssembly());

	clearSceneSlot();
	currentMathModel = newModelToShow;
	drawMathScene();
}

void MainWindow::clearSceneSlot()
{
	glWidget->sceneContent()->Clear();
	::DeleteItem(currentMathModel);
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

	glWidget->sceneContent()->Clear();
	drawMathScene();
}

void MainWindow::importCurrentModel(c3d::path_string path)
{
	MbModel* importModel = new MbModel();
	MbeConvResType importRes = c3d::ImportFromFile(*importModel, path);

	if (importRes == MbeConvResType::cnv_Success) {
		clearSceneSlot();
		currentMathModel = importModel;
	}

	drawMathScene();
}

void MainWindow::saveFileSlot()
{
	if (currentMathModel) {
		c3d::path_string path = getFilePath();
		if (!path.empty()) {
			exportCurrentModel(path);
		}
	}
	else {
		QMessageBox::information(this, "Warning", "Nothing to save");
	}
}

void MainWindow::openFileSlot()
{
	c3d::path_string path = getFilePath(false);
	if (!path.empty()) {
		clearSceneSlot();
		importCurrentModel(path);
	}
}

void MainWindow::prepareSceneBackground()
{
	glWidget->mainLight()->SetDoubleSided(true);
	glWidget->viewport()->SetGradientBackgroundColour(Color(0, 204, 255), Color(255, 255, 255));
}

void MainWindow::fitScene()
{
	glWidget->sceneContent()->GetContainer()->SetUseVertexBufferObjects(true);
	glWidget->viewport()->GetCamera()->SetViewOrientation(VSN::IsoXYZ);
	glWidget->ZoomToFit();
}

NodeKeyVector MainWindow::addMathGeoms(MbItem* item, VSN::SceneSegment* rootSceneSegment)
{
	NodeKeyVector keys;

	if (item->Type() == MbeSpaceType::st_Assembly) {
		//���������� ������ �� ��������� ��������, �� MbAssembly ������������ ����������
		RPArray<MbItem> subitems;
		SArray<MbMatrix3D> matrs;
		MbMatrix3D matrFrom;
		item->GetMatrixFrom(matrFrom);
		item->GetItems(MbeSpaceType::st_Item, matrFrom, subitems, matrs);

		for (auto subitem : subitems) {
			NodeKeyVector subkeys = addMathGeoms(subitem, rootSceneSegment);
			keys.insert(keys.cend(), subkeys.cbegin(), subkeys.cend());
		}
	}
	else {
		SceneSegment* segSinSurface = new SceneSegment(SceneGenerator::Instance()->CreateMathRep(item, CommandType::Synchronous), rootSceneSegment);
		segSinSurface->AddFeature(new Features::DoubleSidedLighting());
		keys.push_back(segSinSurface->GetUniqueKey());
	}

	return keys;
}

NodeKeyVector MainWindow::addMathGeoms(MbModel* model, VSN::SceneSegment* rootSceneSegment)
{
	NodeKeyVector keys;
	RPArray<MbItem> subitems;
	SArray<MbMatrix3D> matrs;
	model->GetItems(MbeSpaceType::st_Item, subitems, matrs);

#if 1 //two ways to add model to view
	for (auto subitem : subitems) {
		NodeKeyVector subkeys = addMathGeoms(subitem, rootSceneSegment);
		keys.insert(keys.cend(), subkeys.cbegin(), subkeys.cend());
	}
#else
	MbAssembly* assemblyToView = new MbAssembly;
	for (auto subitem : subitems) {
		assemblyToView->AddItem(*subitem);
	}
	NodeKeyVector subkeys = addMathGeoms(assemblyToView, rootSceneSegment);
	keys.insert(keys.cend(), subkeys.cbegin(), subkeys.cend());
#endif

	return keys;
}




