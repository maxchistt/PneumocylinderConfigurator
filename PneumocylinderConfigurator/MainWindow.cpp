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

	//запуск создания сцены
	connect(ui.action_testscene, &QAction::triggered, this, &MainWindow::makeTestSceneSlot);
	connect(ui.action_pneumocyl, &QAction::triggered, this, &MainWindow::makeCylinderSceneSlot);
	connect(ui.action_clear, &QAction::triggered, this, &MainWindow::clearSceneSlot);
}

void MainWindow::drawMathScene()
{
	SceneSegment* rootSegment = glWidget->sceneContent()->GetRootSegment();
	Q_ASSERT(rootSegment != nullptr);

	if (currentMathItem)addMathGeoms(currentMathItem, rootSegment);

	fitScene();
}


void MainWindow::makeTestSceneSlot()
{
	clearSceneSlot();
	currentMathItem = createTestAssemblyModel();
	drawMathScene();
}

void MainWindow::makeCylinderSceneSlot()
{
	clearSceneSlot();
	currentMathItem = CreatePneumocylinderAssembly();
	drawMathScene();
}

void MainWindow::clearSceneSlot()
{
	glWidget->sceneContent()->Clear();
	::DeleteItem(currentMathItem);
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
	//glWidget->viewport()->ZoomToFit(glWidget->sceneContent()->GetBoundingBox());
	glWidget->ZoomToFit();
}

NodeKeyVector MainWindow::addMathGeoms(MbItem* item, VSN::SceneSegment* rootSceneSegment)
{
	NodeKeyVector keys;

	if (item->Type() == MbeSpaceType::st_Assembly) {
		//разделение сборки на составные элементы, тк MbAssembly отображается бесцветной
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




