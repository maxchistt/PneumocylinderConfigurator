#include "Viewer.h"

Viewer::Viewer(QWidget* parent) : QtVision::QtOpenGLSceneWidget(parent)
{
	rootSceneSegment = this->sceneContent()->GetRootSegment();
	Q_ASSERT(rootSceneSegment != nullptr);

	QtVision::createProcessesCameraControls(this);

	prepareSceneBackground();
}

Viewer::~Viewer()
{
}

NodeKeyVector Viewer::addMathGeoms(MbItem* item, VSN::SceneSegment* sceneSegment)
{
	if (!sceneSegment) sceneSegment = rootSceneSegment;

	NodeKeyVector keys;

	if (item->Type() == MbeSpaceType::st_Assembly) {
		//���������� ������ �� ��������� ��������, �� MbAssembly ������������ ����������
		RPArray<MbItem> subitems;
		SArray<MbMatrix3D> matrs;
		MbMatrix3D matrFrom;
		item->GetMatrixFrom(matrFrom);
		item->GetItems(MbeSpaceType::st_Item, matrFrom, subitems, matrs);

		for (auto subitem : subitems) {
			NodeKeyVector subkeys = addMathGeoms(subitem, sceneSegment);
			keys.insert(keys.cend(), subkeys.cbegin(), subkeys.cend());
		}
	}
	else {
		SceneSegment* segSinSurface = new SceneSegment(SceneGenerator::Instance()->CreateMathRep(item, CommandType::Synchronous), sceneSegment);
		keys.push_back(segSinSurface->GetUniqueKey());
	}

	return keys;
}

NodeKeyVector Viewer::addMathGeoms(MbModel* model, VSN::SceneSegment* sceneSegment)
{
	if (!sceneSegment) sceneSegment = rootSceneSegment;

	NodeKeyVector keys;
	RPArray<MbItem> subitems;
	SArray<MbMatrix3D> matrs;
	model->GetItems(MbeSpaceType::st_SpaceItem, subitems, matrs);

#if 1 //two ways to add model to view
	for (auto subitem : subitems) {
		NodeKeyVector subkeys = addMathGeoms(subitem, sceneSegment);
		keys.insert(keys.cend(), subkeys.cbegin(), subkeys.cend());
	}
#else
	MbAssembly* assemblyToView = new MbAssembly;
	for (auto subitem : subitems) {
		assemblyToView->AddItem(*subitem);
	}
	NodeKeyVector subkeys = addMathGeoms(assemblyToView, sceneSegment);
	keys.insert(keys.cend(), subkeys.cbegin(), subkeys.cend());
#endif

	return keys;
}

void Viewer::clearScene()
{
	this->sceneContent()->Clear();
	this->update();
}

void Viewer::setSceneParams(SceneParams params)
{
	sceneParams = params;
	prepareSceneBackground();
	update();
}

void Viewer::fitSceneSlot()
{
	this->sceneContent()->GetContainer()->SetUseVertexBufferObjects(true);
	this->viewport()->GetCamera()->SetViewOrientation(orientation);
	this->ZoomToFit();
	this->update();
}

void Viewer::nextOrientationSlot()
{
	int val = int(orientation) - 1;
	if (val < 0 || val > 6) val = 6;
	orientation = VSN::Orientation(val);
	this->fitSceneSlot();
}

void Viewer::prepareSceneBackground()
{
	this->graphicsView()->SetRenderMode(sceneParams.edges ? RenderMode::rm_ShadedWithEdges : RenderMode::rm_Shaded);
	this->mainLight()->SetType((Light::LightTypes)(sceneParams.lightType));
	this->mainLight()->SetDoubleSided(sceneParams.doubleSided);
	this->viewport()->SetGradientBackgroundColour(Color(2, 204, 255), Color(232, 234, 255));
}