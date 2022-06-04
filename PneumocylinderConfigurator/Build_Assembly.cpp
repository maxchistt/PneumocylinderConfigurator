#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;

MbAssembly* ParametricModelCreator::CreatePneumocylinderAssembly(BuildParams params)
{
	MbAssembly* pAsm = new MbAssembly();

	double param_length = params.length;
	double param_diam = params.diam;
	bool create_frame = params.frame;

	double lendif = param_length - 132.95;
	double raddif = param_diam / 2.0 - 10.0;

	double diamCaseInside = param_diam + 30;

	//pAsm->AddItem(*pSolid);

	// Переменные для параметризации вала 
	double start = 0;
	double length = 0;
	double radius = 0;

	double DD = 23.6;

	//Shaft
	CreateShaft(pAsm, start = 0, length = lendif + 66.8, radius = 10 + raddif);
	CreateShaft(pAsm, start = lendif + 66.8, length = 9, radius = 9.4 + raddif);
	CreateShaft(pAsm, start = lendif + 75.8, length = 3.5, radius = 6.9 + raddif);
	CreateShaft(pAsm, start = lendif + 79.3, length = 28, radius = 8 + raddif);
	// zero x , y , z 
	CreateShaft(pAsm, start = 0, length = -5, radius = 9.2 + raddif);
	CreateShaft(pAsm, start = -5, length = -17.5, radius = 7 + raddif);
	CreateShaft(pAsm, start = -22.5, length = -3.2, radius = 6.15 + raddif);
	CreateShaft(pAsm, start = -25.7, length = -16, radius = 7 + raddif);
	//Shaft

	CreateBase(pAsm); // Зарубин
	CreateShaftPivot(pAsm, lendif); // Васинкина
	if (create_frame) CreateMainBody(pAsm, lendif, diamCaseInside); // Балобанов
	CreateSealHousing(pAsm); // Гарник
	CreateBolt(pAsm, DD, DD, -32.6); // Фукина
	CreateBolt(pAsm, DD, -DD, -32.6); // 
	CreateBolt(pAsm, -DD, -DD, -32.6); // 
	CreateBolt(pAsm, -DD, DD, -32.6); //
	CreateBolt(pAsm, -DD, DD, lendif + 16.05, 1); // 
	CreateBolt(pAsm, DD, DD, lendif + 16.05, 1); // 
	CreateBolt(pAsm, DD, -DD, lendif + 16.05, 1); //
	CreateBolt(pAsm, -DD, -DD, lendif + 16.05, 1); // 
	CreateSocketHeadCollar(pAsm); // Приходько
	CreateClampingBar(pAsm, DD, DD, lendif); // Приходько 
	CreateClampingBar(pAsm, DD, -DD, lendif); // 
	CreateClampingBar(pAsm, -DD, -DD, lendif); // 
	CreateClampingBar(pAsm, -DD, DD, lendif); // 
	CreateTopGuide(pAsm, lendif); // Фукина
	CreateBrassCollar(pAsm); // Козырь
	CreateORing(pAsm, -19); // 
	CreateORing(pAsm, -8.5); // 

	return pAsm;
}
