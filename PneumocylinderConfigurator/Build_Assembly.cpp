#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;

MbAssembly* ParametricModelCreator::CreatePneumocylinderAssembly(BuildParams params)
{
	MbAssembly* pAsm = new MbAssembly();

	double param_length = params.length;
	bool create_frame = params.frame;

	double diamMain = params.diam;
	const double diamMain_STD = 50;
	//calculate offsets
	//Разница стандартного и заданного диаметров
	double diamMainOffset = diamMain - diamMain_STD;
	//Соотношение стандартного и заданного диаметров
	double diamDifRatio = diamMain / diamMain_STD;

	double radMainOffset = diamMainOffset / 2;


	//double diamShaft = diamMain - 30 * diamMainDifRatio;
	//const double diamShaft_STD = 20;
	//calculate offsets
	//Разница стандартного и заданного диаметров
	//double diamShaftOffset = diamShaft - diamShaft_STD;
	//Соотношение стандартного и заданного диаметров
	//double diamShaftDifRatio = diamShaft / diamShaft_STD; // = diamDifRatio

	//double radShaftOffset = diamShaftOffset / 2;
	
	// странный расчет
	double len_dif = param_length - 132.95;

	//pAsm->AddItem(*pSolid);

	// Переменные для параметризации вала 
	double start = 0;
	double length = 0;
	double radius = 0;

	double DD = 23.6 + radMainOffset;//ClampingBar and bolts offset from 0 coord

	//Шток
	CreateShaft(pAsm,len_dif, diamDifRatio);

	// Вращающая насадка на шток
	CreateShaftPivot(pAsm, len_dif, diamDifRatio); // Васинкина

	// крышки пневмоцилиндра
	CreateBase(pAsm, diamDifRatio, diamMain); // Зарубин
	CreateTopGuide(pAsm, len_dif); // Фукина

	// корпус
	if (create_frame) CreateMainBody(pAsm, len_dif, diamDifRatio); // Балобанов

	// поршень и кольца на нем
	CreateSealHousing(pAsm, diamDifRatio); // Гарник
	CreateORing(pAsm, -19, diamDifRatio); // 
	CreateORing(pAsm, -8.5, diamDifRatio); // 

	// Упоры поршня на штоке
	CreateSocketHeadCollar(pAsm, diamDifRatio); // Приходько
	CreateBrassCollar(pAsm, diamDifRatio); // Козырь

	// штыри
	CreateClampingBar(pAsm, DD, DD, len_dif); // Приходько 
	CreateClampingBar(pAsm, DD, -DD, len_dif); // 
	CreateClampingBar(pAsm, -DD, -DD, len_dif); // 
	CreateClampingBar(pAsm, -DD, DD, len_dif); // 

	CreateBolt(pAsm, DD, DD, -32.6); // Фукина
	CreateBolt(pAsm, DD, -DD, -32.6); //
	CreateBolt(pAsm, -DD, -DD, -32.6); //
	CreateBolt(pAsm, -DD, DD, -32.6); //
	CreateBolt(pAsm, -DD, DD, len_dif + 16.05, 1); //
	CreateBolt(pAsm, DD, DD, len_dif + 16.05, 1); //
	CreateBolt(pAsm, DD, -DD, len_dif + 16.05, 1); //
	CreateBolt(pAsm, -DD, -DD, len_dif + 16.05, 1); //

	return pAsm;
}
