#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;

void ParametricModelCreator::CreateMainBody(MbAssembly* pAsm, double length)
{
	MbCartPoint p0(16.489, 22.63);
	MbCartPoint p1(20, 30.5);
	MbCartPoint p2(32.25, 30.5);
	MbCartPoint p3(32.25, -30.5);
	MbCartPoint p4(20, -30.5);
	MbCartPoint p5(16.489, -22.63);
	MbCartPoint p6(0, -34.644);
	MbCartPoint p7(-16.489, -22.63);
	MbCartPoint p8(-20, -30.5);
	MbCartPoint p9(-32.25, -30.5);
	MbCartPoint p10(-32.25, 30.5);
	MbCartPoint p11(-20, 30.5);
	MbCartPoint p12(-16.489, 22.63);
	MbCartPoint p13(0, 34.644);

	MbLineSegment* Seg1 = new MbLineSegment(p0, p1);
	MbLineSegment* Seg2 = new MbLineSegment(p1, p2);
	MbLineSegment* Seg3 = new MbLineSegment(p2, p3);
	MbLineSegment* Seg4 = new MbLineSegment(p3, p4);
	MbLineSegment* Seg5 = new MbLineSegment(p4, p5);
	MbLineSegment* Seg6 = new MbLineSegment(p5, p6);
	MbLineSegment* Seg7 = new MbLineSegment(p6, p7);
	MbLineSegment* Seg8 = new MbLineSegment(p7, p8);
	MbLineSegment* Seg9 = new MbLineSegment(p8, p9);
	MbLineSegment* Seg10 = new MbLineSegment(p9, p10);
	MbLineSegment* Seg11 = new MbLineSegment(p10, p11);
	MbLineSegment* Seg12 = new MbLineSegment(p11, p12);
	MbLineSegment* Seg13 = new MbLineSegment(p12, p13);
	MbLineSegment* Seg14 = new MbLineSegment(p13, p0);

	MbContour* ptrContour = new MbContour();

	//Добавление в контур сегментов
	ptrContour->AddSegment(Seg1);
	ptrContour->AddSegment(Seg2);
	ptrContour->AddSegment(Seg3);
	ptrContour->AddSegment(Seg4);
	ptrContour->AddSegment(Seg5);
	ptrContour->AddSegment(Seg6);
	ptrContour->AddSegment(Seg7);
	ptrContour->AddSegment(Seg8);
	ptrContour->AddSegment(Seg9);
	ptrContour->AddSegment(Seg10);
	ptrContour->AddSegment(Seg11);
	ptrContour->AddSegment(Seg12);
	ptrContour->AddSegment(Seg13);
	ptrContour->AddSegment(Seg14);

	MbContour* pFillets = NULL;
	::FilletPolyContour(ptrContour, 9, false, p3, pFillets);
	::FilletPolyContour(ptrContour, 9, false, p9, pFillets);
	::FilletPolyContour(ptrContour, 9, false, p10, pFillets);
	::FilletPolyContour(ptrContour, 28, false, p13, pFillets);
	::FilletPolyContour(ptrContour, 28, false, p6, pFillets);
	::FilletPolyContour(ptrContour, 9, false, p2, pFillets);

	MbPlacement3D* place = new MbPlacement3D();
	MbPlane* ptrSurface = new MbPlane(*place);

	//Создание образующей для тела вращения
	RPArray<MbContour>* ptrContours = new RPArray<MbContour>();
	ptrContours->Add(ptrContour);

	MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));
	MbSweptData* pCurves;
	pCurves = new MbSweptData(*ptrSurface, *ptrContours);
	MbVector3D dir(0, 0, 1);

	// Параметры операции выдавливания, задающие свойства тела для построения в прямом и в обратном направлении вдоль (глубина выдавливания и уклон).
	const double HEIGHT_FORWARD = length + 43.95, HEIGHT_BACKWARD = 0;
	const double ANGLE_FORWARD_DEGREE = 0;
	ExtrusionValues extrusionParams(HEIGHT_FORWARD, HEIGHT_BACKWARD);

	// Именователи элементов модели твердого тела и контуров образующей
	MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames(0, 1, false);

	// Вызов функции-утилиты для построения твердого тела выдавливания
	MbSolid* pSolid = nullptr;
	MbResultType res = ::ExtrusionSolid(*pCurves, dir, nullptr, nullptr, false, extrusionParams, operNames, cNames, pSolid);

	MbCartPoint cnt(0, 0);
	// Построение окружности по центру и радиусу
	const double RAD1 = 25;
	MbArc* pc1 = new MbArc(cnt, RAD1);

	MbContour* ptrContour1 = new MbContour();
	ptrContour1->AddSegment(pc1);

	MbPlacement3D* place1 = new MbPlacement3D();
	MbPlane* ptrSurface1 = new MbPlane(*place1);

	//Создание образующей для тела вращения
	RPArray<MbContour>* ptrContours1 = new RPArray<MbContour>();
	ptrContours1->Add(ptrContour1);

	MbPlane* pPlaneXY1 = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));
	MbSweptData* pCurves1;
	pCurves1 = new MbSweptData(*ptrSurface1, *ptrContours1);
	MbVector3D dir1(0, 0, 1);

	// Именователи элементов модели твердого тела и контуров образующей
	MbSNameMaker operNames1(1, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames1(0, 1, false);

	// Вызов функции-утилиты для построения твердого тела выдавливания
	MbSolid* pSolid1 = nullptr;
	MbResultType res1 = ::ExtrusionSolid(*pCurves1, dir1, nullptr, nullptr, false, extrusionParams, operNames1, cNames1, pSolid1);

	MbCartPoint p14(18.37, 21.2);
	MbCartPoint p15(21.249, 28.1);
	MbCartPoint p16(29.85, 28.1);
	MbCartPoint p17(29.85, -16.693);
	MbCartPoint p18(27.855, 2.844);
	MbCartPoint p19(26.73, 13.864);

	MbLineSegment* Seg15 = new MbLineSegment(p14, p15);
	MbLineSegment* Seg16 = new MbLineSegment(p15, p16);
	MbLineSegment* Seg17 = new MbLineSegment(p16, p17);
	MbLineSegment* Seg18 = new MbLineSegment(p17, p18);
	MbLineSegment* Seg19 = new MbLineSegment(p18, p19);
	MbLineSegment* Seg20 = new MbLineSegment(p19, p14);


	MbContour* ptrContour2 = new MbContour();

	//Добавление в контур сегментов
	ptrContour2->AddSegment(Seg15);
	ptrContour2->AddSegment(Seg16);
	ptrContour2->AddSegment(Seg17);
	ptrContour2->AddSegment(Seg18);
	ptrContour2->AddSegment(Seg19);
	ptrContour2->AddSegment(Seg20);

	MbContour* pFillets2 = NULL;
	::FilletPolyContour(ptrContour2, 6.6, false, p16, pFillets2);
	::FilletPolyContour(ptrContour2, 1, false, p17, pFillets2);
	::FilletPolyContour(ptrContour2, 28, false, p19, pFillets2);

	MbPlacement3D* place2 = new MbPlacement3D();
	MbPlane* ptrSurface2 = new MbPlane(*place2);

	//Создание образующей для тела вращения
	RPArray<MbContour>* ptrContours2 = new RPArray<MbContour>();
	ptrContours2->Add(ptrContour2);

	MbPlane* pPlaneXY2 = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));
	MbSweptData* pCurves2;
	pCurves2 = new MbSweptData(*ptrSurface2, *ptrContours2);
	MbVector3D dir2(0, 0, 1);

	// Именователи элементов модели твердого тела и контуров образующей
	MbSNameMaker operNames2(1, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames2(0, 1, false);

	// Вызов функции-утилиты для построения твердого тела выдавливания
	MbSolid* pSolid2 = nullptr;
	MbResultType res2 = ::ExtrusionSolid(*pCurves2, dir2, nullptr, nullptr, false, extrusionParams, operNames2, cNames2, pSolid2);

	MbCartPoint p20(-18.37, 21.132);
	MbCartPoint p21(-21.249, 28.1);
	MbCartPoint p22(-29.85, 28.1);
	MbCartPoint p23(-29.85, -16.693);
	MbCartPoint p24(-27.855, 2.844);
	MbCartPoint p25(-26.73, 13.864);

	MbLineSegment* Seg21 = new MbLineSegment(p20, p21);
	MbLineSegment* Seg22 = new MbLineSegment(p21, p22);
	MbLineSegment* Seg23 = new MbLineSegment(p22, p23);
	MbLineSegment* Seg24 = new MbLineSegment(p23, p24);
	MbLineSegment* Seg25 = new MbLineSegment(p24, p25);
	MbLineSegment* Seg26 = new
		MbLineSegment(p25, p20);

	MbContour* ptrContour3 = new MbContour();

	ptrContour3->AddSegment(Seg21);
	ptrContour3->AddSegment(Seg22);
	ptrContour3->AddSegment(Seg23);
	ptrContour3->AddSegment(Seg24);
	ptrContour3->AddSegment(Seg25);
	ptrContour3->AddSegment(Seg26);

	MbContour* pFillets3 = NULL;
	::FilletPolyContour(ptrContour3, 6.6, false, p22, pFillets3);
	::FilletPolyContour(ptrContour3, 1, false, p23, pFillets3);
	::FilletPolyContour(ptrContour3, 28, false, p25, pFillets3);

	MbPlacement3D* place3 = new MbPlacement3D();
	MbPlane* ptrSurface3 = new MbPlane(*place3);

	//Создание образующей для тела вращения
	RPArray<MbContour>* ptrContours3 = new RPArray<MbContour>();
	ptrContours3->Add(ptrContour3);

	MbPlane* pPlaneXY3 = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));
	MbSweptData* pCurves3;
	pCurves3 = new MbSweptData(*ptrSurface3, *ptrContours3);
	MbVector3D dir3(0, 0, 1);

	// Именователи элементов модели твердого тела и контуров образующей
	MbSNameMaker operNames123(1, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames3(0, 1, false);

	// Вызов функции-утилиты для построения твердого тела выдавливания
	MbSolid* pSolid3 = nullptr;
	MbResultType res3 = ::ExtrusionSolid(*pCurves3, dir3, nullptr, nullptr, false, extrusionParams, operNames123, cNames3, pSolid3);


	MbCartPoint p26(-18.37, -21.132);
	MbCartPoint p27(-21.249, -28.1);
	MbCartPoint p28(-29.85, -28.1);
	MbCartPoint p29(-29.85, 16.693);
	MbCartPoint p30(-27.855, -2.844);
	MbCartPoint p31(-26.73, -13.864);

	MbLineSegment* Seg27 = new MbLineSegment(p26, p27);
	MbLineSegment* Seg28 = new MbLineSegment(p27, p28);
	MbLineSegment* Seg29 = new MbLineSegment(p28, p29);
	MbLineSegment* Seg30 = new MbLineSegment(p29, p30);
	MbLineSegment* Seg31 = new MbLineSegment(p30, p31);
	MbLineSegment* Seg32 = new MbLineSegment(p31, p26);

	MbContour* ptrContour4 = new MbContour();

	//Добавление в контур сегментов
	ptrContour4->AddSegment(Seg27);
	ptrContour4->AddSegment(Seg28);
	ptrContour4->AddSegment(Seg29);
	ptrContour4->AddSegment(Seg30);
	ptrContour4->AddSegment(Seg31);
	ptrContour4->AddSegment(Seg32);

	MbContour* pFillets4 = NULL;
	::FilletPolyContour(ptrContour4, 6.6, false, p28, pFillets2);
	::FilletPolyContour(ptrContour4, 1, false, p29, pFillets2);
	::FilletPolyContour(ptrContour4, 28, false, p31, pFillets2);

	MbPlacement3D* place4 = new MbPlacement3D();
	MbPlane* ptrSurface4 = new MbPlane(*place4);

	//Создание образующей для тела вращения
	RPArray<MbContour>* ptrContours4 = new RPArray<MbContour>();
	ptrContours4->Add(ptrContour4);

	MbPlane* pPlaneXY4 = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));
	MbSweptData* pCurves4;
	pCurves4 = new MbSweptData(*ptrSurface4, *ptrContours4);
	MbVector3D dir4(0, 0, 1);

	// Именователи элементов модели твердого тела и контуров образующей
	MbSNameMaker operNames4(1, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames4(0, 1, false);

	// Вызов функции-утилиты для построения твердого тела выдавливания
	MbSolid* pSolid4 = nullptr;
	MbResultType res4 = ::ExtrusionSolid(*pCurves4, dir4, nullptr, nullptr, false, extrusionParams, operNames4, cNames4, pSolid4);

	MbCartPoint
		p32(18.37, -21.132);
	MbCartPoint p33(21.249, -28.1);
	MbCartPoint p34(29.85, -28.1);
	MbCartPoint p35(29.85, 16.693);
	MbCartPoint p36(27.855, -2.844);
	MbCartPoint p37(26.73, -13.864);


	MbLineSegment* Seg33 = new MbLineSegment(p32, p33);
	MbLineSegment* Seg34 = new MbLineSegment(p33, p34);
	MbLineSegment* Seg35 = new MbLineSegment(p34, p35);
	MbLineSegment* Seg36 = new MbLineSegment(p35, p36);
	MbLineSegment* Seg37 = new MbLineSegment(p36, p37);
	MbLineSegment* Seg38 = new MbLineSegment(p37, p32);

	MbContour* ptrContour5 = new MbContour();

	//Добавление в контур сегментов
	ptrContour5->AddSegment(Seg33);
	ptrContour5->AddSegment(Seg34);
	ptrContour5->AddSegment(Seg35);
	ptrContour5->AddSegment(Seg36);
	ptrContour5->AddSegment(Seg37);
	ptrContour5->AddSegment(Seg38);

	MbContour* pFillets5 = NULL;
	::FilletPolyContour(ptrContour5, 6.6, false, p34, pFillets5);
	::FilletPolyContour(ptrContour5, 1, false, p35, pFillets5);
	::FilletPolyContour(ptrContour5, 28, false, p37, pFillets5);

	MbPlacement3D* place5 = new MbPlacement3D();
	MbPlane* ptrSurface5 = new MbPlane(*place5);

	//Создание образующей для тела вращения
	RPArray<MbContour>* ptrContours5 = new RPArray<MbContour>();
	ptrContours5->Add(ptrContour5);

	MbPlane* pPlaneXY5 = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));
	MbSweptData* pCurves5;
	pCurves5 = new MbSweptData(*ptrSurface5, *ptrContours5);
	MbVector3D dir5(0, 0, 1);

	// Именователи элементов модели твердого тела и контуров образующей
	MbSNameMaker operNames5(1, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames5(0, 1, false);

	// Вызов функции-утилиты для построения твердого тела выдавливания
	MbSolid* pSolid5 = nullptr;
	MbResultType res5 = ::ExtrusionSolid(*pCurves5, dir5, nullptr, nullptr, false, extrusionParams, operNames5, cNames5, pSolid5);


	MbSolid* pSolid6 = nullptr;

	MbBooleanFlags flagsBool;
	flagsBool.InitBoolean(true);
	flagsBool.SetMergingFaces(true);
	flagsBool.SetMergingEdges(true);
	MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone);
	//ВЫДАВЛИВАНИЕ КВАДРАТИКОВ ПО УГЛАМ
	MbResultType res6 = ::BooleanResult(*pSolid, cm_Copy, *pSolid1, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res7 = ::BooleanResult(*pSolid, cm_Copy, *pSolid2, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res8 = ::BooleanResult(*pSolid, cm_Copy, *pSolid3, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res9 = ::BooleanResult(*pSolid, cm_Copy, *pSolid4, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res10 = ::BooleanResult(*pSolid, cm_Copy, *pSolid5, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);

	pSolid->Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, 0, -31.5)));
	pSolid->SetColor(ParametricModelCreator::colorScheme ? BLACK : RGB(10,20,20));

	auto addedItem = pAsm->AddItem(*pSolid);
	addedItem->SetItemName(SimpleName(std::uint32_t("Pneumocylinder case")));
}