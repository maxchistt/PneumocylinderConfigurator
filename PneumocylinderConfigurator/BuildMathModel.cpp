#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;

MbModel* ParametricModelCreator::CreatePneymocylinderModel(BuildParams params)
{
	MbModel* model = new MbModel();
	auto pneumocylinderAssembly = CreatePneumocylinderAssembly(params);
	model->AddItem(*pneumocylinderAssembly);
	::DeleteItem(pneumocylinderAssembly);
	return model;
}