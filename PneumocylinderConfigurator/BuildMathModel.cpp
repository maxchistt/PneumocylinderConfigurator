#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;

// ������������� ����������� ���������� ������ - �����������
int ParametricModelCreator::colorScheme = 0;

MbItem* ParametricModelCreator::CreatePneymocylinderModel(BuildParams params)
{
	ParametricModelCreator::colorScheme = params.colorScheme;
	auto pneumocylinderAssembly = CreatePneumocylinderAssembly(params);
	return pneumocylinderAssembly;
}