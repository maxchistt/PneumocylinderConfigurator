#include "PneumocylinderConfigurator.h"

PneumocylinderConfigurator::PneumocylinderConfigurator(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	GraphicsSceneEnginePtr ptrEngine = std::make_shared<GraphicsSceneEngine>();
	OpenGLContextContainer* pContextContainer = new OpenGLContextContainer;

	QtVision::setSurfaceFormat();
	glWidget = new QtVision::QtOpenGLSceneWidget(ptrEngine, pContextContainer, this);

	setCentralWidget(glWidget);

	QtVision::createProcessesCameraControls(glWidget);

	prepareSceneBackground();

	//запуск создания сцены
	connect(ui.action_testscene, &QAction::triggered, this, &PneumocylinderConfigurator::makeTestSceneSlot);
	connect(ui.action_pneumocyl, &QAction::triggered, this, &PneumocylinderConfigurator::makeSceneSlot);
	connect(ui.action_clear, &QAction::triggered, this, &PneumocylinderConfigurator::clearSceneSlot);
}


void PneumocylinderConfigurator::makeTestSceneSlot()
{
	glWidget->sceneContent()->Clear();
	SceneSegment* rootSegment = glWidget->sceneContent()->GetRootSegment();
	Q_ASSERT(rootSegment != nullptr);

	addMathGeoms(createTestAssemblyModel(), rootSegment);

	fitScene();
}

void PneumocylinderConfigurator::makeSceneSlot()
{
	glWidget->sceneContent()->Clear();
	SceneSegment* rootSegment = glWidget->sceneContent()->GetRootSegment();
	Q_ASSERT(rootSegment != nullptr);

	addMathGeoms(CreatePneumocylinderAssembly(), rootSegment);

	fitScene();
}

void PneumocylinderConfigurator::clearSceneSlot()
{
	glWidget->sceneContent()->Clear();
}

void PneumocylinderConfigurator::prepareSceneBackground()
{
	glWidget->mainLight()->SetDoubleSided(true);
	glWidget->viewport()->SetGradientBackgroundColour(Color(0, 204, 255), Color(255, 255, 255));
}

void PneumocylinderConfigurator::fitScene()
{
	glWidget->sceneContent()->GetContainer()->SetUseVertexBufferObjects(true);
	glWidget->viewport()->GetCamera()->SetViewOrientation(VSN::IsoXYZ);
	//glWidget->viewport()->ZoomToFit(glWidget->sceneContent()->GetBoundingBox());
	glWidget->ZoomToFit();
}

NodeKeyVector PneumocylinderConfigurator::addMathGeoms(MbItem* item, VSN::SceneSegment* rootSceneSegment)
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


