#pragma once
#include "colorDef.h"

#include <vsn_vision.h>

#include <cur_polyline.h>
#include <alg_curve_fillet.h>
#include <cur_contour.h>
#include <op_swept_parameter.h>
#include <action_solid.h>
#include <assembly.h>


void CreateTestSketch(RPArray<MbContour>& _arrContours);

MbAssembly* createTestAssemblyModel();

