#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;

MbAssembly* pAsm = nullptr;

void CreateSketchHookSection1(RPArray<MbSurface>& _arrSurfaces, RPArray<MbContour>& _arrContours, double angle, double OFS_X, double OFS_Y, double OFS_Z, double diam)
{
	//создаем положение в пространстве для плоскости эскиза по трем точкам
	// Положение создается по тем точкам. Первая точка создается относительно нулевой координате. 
	// При этом каждая точка имеет оступы OFS_X, OFS_Y, OFS_Z по соответсвующим координатам, задающие отступ в пространстве относительно начала координат. 
	// Вторая точка имеет отсупы std::cos(-angle * M_PI / 180) и std::sin(-angle * M_PI / 180) по X и Y осям соответственно относительно первой. Эти отступы задают наклон плоскости относительно оси Z. 
	// Третья точка имеет единичный отступ по оси Z, чтобы по этим тем точкам можно было построить плоскость, наклоненную относительно этой оси
  //  MbPlacement3D plSurf1(
  //      MbCartPoint3D(OFS_X - 20, OFS_Y , OFS_Z),
 //       MbCartPoint3D(OFS_X + std::cos(-angle * M_PI / 180), OFS_Y //+ std::sin(-angle * M_PI / 180), OFS_Z ),
 //       MbCartPoint3D(OFS_X - 1, OFS_Y + 1, OFS_Z)
 //   );

	MbPlacement3D plSurf1(
		MbCartPoint3D(OFS_X - 20, OFS_Y, OFS_Z - 1),
		MbCartPoint3D(OFS_X + std::cos(-angle * M_PI / 180), OFS_Y + std::sin(-angle * M_PI / 180), OFS_Z),
		MbCartPoint3D(OFS_X - 1, OFS_Y + 1, OFS_Z)
	);


	//создаем умный массив из 4 точек
	SArray<MbCartPoint>arrPnts1(4);

	//рассчитываем координты точек по которым построим эскиз сечения и добавляем точки в массив
	double l = diam * 0.4472138576667362;
	arrPnts1.Add(MbCartPoint(-l / 2, l));
	arrPnts1.Add(MbCartPoint(l / 2, l));
	arrPnts1.Add(MbCartPoint(-l / 2, -l));
	arrPnts1.Add(MbCartPoint(l / 2, -l));

	// отображение созданных точек


	//создаем прямые, соединяющие точки
	MbLineSegment* pS1 = new MbLineSegment(arrPnts1[0], arrPnts1[1]);
	MbLineSegment* pS2 = new MbLineSegment(arrPnts1[3], arrPnts1[2]);

	//создаем кривые, соединяющие точки
	MbArc* pArc1 = new MbArc(MbCartPoint(0, 0), arrPnts1[1], arrPnts1[3], 0);
	MbArc* pArc2 = new MbArc(MbCartPoint(0, 0), arrPnts1[2], arrPnts1[0], 0);

	//создаем новый котур
	MbContour* pContour1 = new MbContour();

	//добавляем созданные элементы в контур
	pContour1->AddSegment(pS1);
	pContour1->AddSegment(pArc1);
	pContour1->AddSegment(pS2);
	pContour1->AddSegment(pArc2);

	// отображение созданного контура

	//создаем плоскость для операции лофта
	MbSurface* pSurf1 = new MbPlane(plSurf1);

	//добавляем плоскость и контур эскиза в соответствующие массивы
	_arrSurfaces.push_back(pSurf1);
	_arrContours.push_back(pContour1);
}

////////////////////////////////////////////////////////////
//создаем эскиз сечения для операции заметания
//передаем ссылки на массивы поверхностей и контуров
//angle определяет наклон плоскости, вращение по оси Z
//следующие три переменных определяют местоположение плоскости эскиза
//последний параметр определяет диаметр эскиза - усеченного круга

void CreateSketchHookSection(RPArray<MbSurface>& _arrSurfaces, RPArray<MbContour>& _arrContours, double angle, double OFS_X, double OFS_Y, double OFS_Z, double diam)
{
	//создаем положение в пространстве для плоскости эскиза по трем точкам
	// Положение создается по тем точкам. Первая точка создается относительно нулевой координате. 
	// При этом каждая точка имеет оступы OFS_X, OFS_Y, OFS_Z по соответсвующим координатам, задающие отступ в пространстве относительно начала координат. 
	// Вторая точка имеет отсупы std::cos(-angle * M_PI / 180) и std::sin(-angle * M_PI / 180) по X и Y осям соответственно относительно первой. Эти отступы задают наклон плоскости относительно оси Z. 
	// Третья точка имеет единичный отступ по оси Z, чтобы по этим тем точкам можно было построить плоскость, наклоненную относительно этой оси
	MbPlacement3D plSurf(
		MbCartPoint3D(OFS_X, OFS_Y, OFS_Z),
		MbCartPoint3D(OFS_X + std::cos(-angle * M_PI / 180), OFS_Y + std::sin(-angle * M_PI / 180), OFS_Z),
		MbCartPoint3D(OFS_X, OFS_Y, OFS_Z + 1)
	);

	//создаем умный массив из 4 точек
	SArray<MbCartPoint>arrPnts(5);

	//рассчитываем координты точек по которым построим эскиз сечения и добавляем точки в массив
	double l = diam * 0.4472138576667362;
	arrPnts.Add(MbCartPoint(-l / 2, l));
	arrPnts.Add(MbCartPoint(l / 2, l));
	arrPnts.Add(MbCartPoint(-l / 2, -l));
	arrPnts.Add(MbCartPoint(l / 2, -l));


	// отображение созданных точек


	//создаем прямые, соединяющие точки
	MbLineSegment* pS1 = new MbLineSegment(arrPnts[0], arrPnts[1]);
	MbLineSegment* pS2 = new MbLineSegment(arrPnts[3], arrPnts[2]);

	//создаем кривые, соединяющие точки
	MbArc* pArc1 = new MbArc(MbCartPoint(0, 0), arrPnts[1], arrPnts[3], 0);
	MbArc* pArc2 = new MbArc(MbCartPoint(0, 0), arrPnts[2], arrPnts[0], 0);

	//создаем новый котур
	MbContour* pContour = new MbContour();

	//добавляем созданные элементы в контур
	pContour->AddSegment(pS1);
	pContour->AddSegment(pArc1);
	pContour->AddSegment(pS2);
	pContour->AddSegment(pArc2);

	// отображение созданного контура
	//создаем плоскость для операции лофта
	MbSurface* pSurf = new MbPlane(plSurf);

	//добавляем плоскость и контур эскиза в соответствующие массивы
	_arrSurfaces.push_back(pSurf);
	_arrContours.push_back(pContour);
}

////////////////////////////////////////////////////////////

void CreateSketchHookSection2(RPArray<MbSurface>& _arrSurfaces, RPArray<MbContour>& _arrContours, double angle, double OFS_X, double OFS_Y, double OFS_Z, double diam)
{
	//создаем положение в пространстве для плоскости эскиза по трем точкам
	// Положение создается по тем точкам. Первая точка создается относительно нулевой координате. 
	// При этом каждая точка имеет оступы OFS_X, OFS_Y, OFS_Z по соответсвующим координатам, задающие отступ в пространстве относительно начала координат. 
	// Вторая точка имеет отсупы std::cos(-angle * M_PI / 180) и std::sin(-angle * M_PI / 180) по X и Y осям соответственно относительно первой. Эти отступы задают наклон плоскости относительно оси Z. 
	// Третья точка имеет единичный отступ по оси Z, чтобы по этим тем точкам можно было построить плоскость, наклоненную относительно этой оси
	MbPlacement3D plSurf2(
		MbCartPoint3D(OFS_X, OFS_Y, OFS_Z),
		MbCartPoint3D(OFS_X + std::cos(-angle * M_PI / 180), OFS_Y + std::sin(-angle * M_PI / 180), OFS_Z),
		MbCartPoint3D(OFS_X, OFS_Y, OFS_Z + 1)
	);

	//создаем умный массив из 4 точек
	SArray<MbCartPoint>arrPnts3(5);

	//рассчитываем координты точек по которым построим эскиз сечения и добавляем точки в массив
	double l = diam * 0.4472138576667362;
	arrPnts3.Add(MbCartPoint(-l / 2, l));
	arrPnts3.Add(MbCartPoint(l / 2, l));
	arrPnts3.Add(MbCartPoint(-l / 2, -l));
	arrPnts3.Add(MbCartPoint(l / 2, -l));



	//создаем прямые, соединяющие точки
	MbLineSegment* pS1 = new MbLineSegment(arrPnts3[0], arrPnts3[1]);
	MbLineSegment* pS2 = new MbLineSegment(arrPnts3[3], arrPnts3[2]);

	//создаем кривые, соединяющие точки
	MbArc* pArc1 = new MbArc(MbCartPoint(0, 0), arrPnts3[1], arrPnts3[3], 0);
	MbArc* pArc2 = new MbArc(MbCartPoint(0, 0), arrPnts3[2], arrPnts3[0], 0);

	//создаем новый котур
	MbContour* pContour2 = new MbContour();

	//добавляем созданные элементы в контур
	pContour2->AddSegment(pS1);
	pContour2->AddSegment(pArc1);
	pContour2->AddSegment(pS2);
	pContour2->AddSegment(pArc2);

	// отображение созданного контура


	//создаем плоскость для операции лофта
	MbSurface* pSurf2 = new MbPlane(plSurf2);

	//добавляем плоскость и контур эскиза в соответствующие массивы
	_arrSurfaces.push_back(pSurf2);
	_arrContours.push_back(pContour2);
}


MbAssembly* BuildMathModel::CreatePneumocylinderAssembly(double param_length, double param_diam)
{
	double lendif = param_length;
	double raddif = param_diam / 2.0 - 10.0;

	pAsm = new MbAssembly();

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
	//CreateMainBody(pAsm, lendif); // Балобанов
	CreateSealHousing(pAsm); // Гарник
	CreateBolt(pAsm, DD, DD); // Фукина
	CreateBolt(pAsm, DD, -DD); // 
	CreateBolt(pAsm, -DD, -DD); // 
	CreateBolt(pAsm, -DD, DD); //
	CreateBolt(pAsm, -DD, DD, lendif + 16.05, 1); // 
	CreateBolt(pAsm, DD, DD, lendif + 16.05, 1); // 
	CreateBolt(pAsm, DD, -DD, lendif + 16.05, 1); //
	CreateBolt(pAsm, -DD, -DD, lendif + 16.05, 1); // 
	CreateSocketHeadLockingCollarInsert(pAsm); // Приходько
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
