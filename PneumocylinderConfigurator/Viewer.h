#pragma once

#include <qt_openglwidget.h>
#include <vsn_vision.h>
#include <vsn_segmentfeatures.h>
#include <model.h>
#include "SceneParams.h"

class Viewer : public QtVision::QtOpenGLSceneWidget
{
	Q_OBJECT

public:
	Viewer(QWidget* parent = Q_NULLPTR);
	~Viewer();

	NodeKeyVector addMathGeoms(MbItem* item, VSN::SceneSegment* sceneSegment = nullptr);
	NodeKeyVector addMathGeoms(MbModel* model, VSN::SceneSegment* sceneSegment = nullptr);
	void clearScene();
	void setSceneParams(SceneParams params);

public slots:
	void fitSceneSlot();
	void nextOrientationSlot();
	void toggleSectionSlot();

private:
	SectionPlaneId m_sectionPlaneId = 0;
	SceneParams sceneParams;
	VSN::Orientation orientation = VSN::Orientation::IsoXYZ;
	VSN::SceneSegment* rootSceneSegment = nullptr;
	void prepareSceneBackground();
	void prepareSectionPlane();
};
