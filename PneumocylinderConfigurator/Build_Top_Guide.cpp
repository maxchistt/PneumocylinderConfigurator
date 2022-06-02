#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;

void CreateSketchTopGuide(RPArray<MbContour>& _arrContours)
{
	// Создание массива точек квадрата, к которому в дальнейшем добавятся скругления.
	// Размер массива - 8 точек для учета точек четырех сегментов скруглений.
	SArray<MbCartPoint> arrPnts(8);
	arrPnts.Add(MbCartPoint(0, 0));
	arrPnts.Add(MbCartPoint(65.2, 0));
	arrPnts.Add(MbCartPoint(65.2, 65.2));
	arrPnts.Add(MbCartPoint(0, 65.2));

	// Построение единой ломаной внешнего контура по точкам
	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
	MbContour* pContourPolyline = nullptr;
	::FilletPolyContour(pPolyline, 6, false, arrPnts[4], pContourPolyline);


	// Задание индексов точек, в которых будет задаваться скругление с учетом
	// добавления новой точки при скруглении с использованием функции FilletTwoSegments
	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;

	// Добавление скруглений
	pContourPolyline->FilletTwoSegments(idxSideRight1, 6);
	pContourPolyline->FilletTwoSegments(idxSideRight2, 6);
	pContourPolyline->FilletTwoSegments(idxSideRight3, 6);

	_arrContours.push_back(pContourPolyline);

	::DeleteItem(pPolyline);

}
void CreateSketchTopGuide2(RPArray<MbContour>& _arrContours2)
{
	//SecondScetch
	double SqureSize = 65.2;
	double SquareCenter = 20;
	SArray<MbCartPoint> arrPnts2(8);
	arrPnts2.Add(MbCartPoint(SqureSize, SqureSize));
	arrPnts2.Add(MbCartPoint(SqureSize - SquareCenter, SqureSize));
	arrPnts2.Add(MbCartPoint(SqureSize - SquareCenter, SqureSize - SquareCenter));
	arrPnts2.Add(MbCartPoint(SqureSize, SqureSize - SquareCenter));

	MbPolyline* pPolyline2 = new MbPolyline(arrPnts2, true);

	///// ИСПРАВИТЬ

	MbContour* pContourPolyline2 = nullptr;
	// Задание скругления с использованием функции FilletPolyContour
	::FilletPolyContour(pPolyline2, 10.5, false, arrPnts2[2], pContourPolyline2);

	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;

	pContourPolyline2->FilletTwoSegments(idxSideRight1, 0);
	pContourPolyline2->FilletTwoSegments(idxSideRight2, 0);
	pContourPolyline2->FilletTwoSegments(idxSideRight3, 0);
	//*/

	///// ИСПРАВИТЬ
	/*
	MbContour* pContourPolyline2 = new MbContour();
	pContourPolyline2->AddSegment(pPolyline2);
	*/
	///// 

	_arrContours2.push_back(pContourPolyline2);
	::DeleteItem(pPolyline2);
}
void CreateSketchTopGuide3(RPArray<MbContour>& _arrContours3)
{
	//SecondScetch
	double SqureSize = 65.2;
	double Square = 15;
	SArray<MbCartPoint> arrPnts(8);
	arrPnts.Add(MbCartPoint((SqureSize / 2) + Square / 2, -0));
	arrPnts.Add(MbCartPoint((SqureSize / 2) + Square / 2, 12.65));
	arrPnts.Add(MbCartPoint((SqureSize / 2) - Square / 2, 12.65));
	arrPnts.Add(MbCartPoint((SqureSize / 2) - Square / 2, -0));

	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
	MbContour* pContourPolyline = nullptr;
	// Задание скругления с использованием функции FilletPolyContour
	::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;

	pContourPolyline->FilletTwoSegments(idxSideRight1, 3);
	pContourPolyline->FilletTwoSegments(idxSideRight2, 3);
	pContourPolyline->FilletTwoSegments(idxSideRight3, 0);

	_arrContours3.push_back(pContourPolyline);
	::DeleteItem(pPolyline);
}
void CreateSketchTopGuide4(RPArray<MbContour>& _arrContours4)
{
	//SecondScetch
	double SqureSize = 65.2;
	double Square = 15;
	SArray<MbCartPoint> arrPnts(8);
	arrPnts.Add(MbCartPoint(SqureSize, SqureSize / 2 - Square / 2));
	arrPnts.Add(MbCartPoint(SqureSize, SqureSize / 2 + Square / 2));
	arrPnts.Add(MbCartPoint(SqureSize - 12.65, SqureSize / 2 + Square / 2));
	arrPnts.Add(MbCartPoint(SqureSize - 12.65, SqureSize / 2 - Square / 2));

	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
	MbContour* pContourPolyline = nullptr;
	// Задание скругления с использованием функции FilletPolyContour
	::FilletPolyContour(pPolyline, 3, false, arrPnts[4], pContourPolyline);

	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;

	pContourPolyline->FilletTwoSegments(idxSideRight1, 0);
	pContourPolyline->FilletTwoSegments(idxSideRight2, 3);
	pContourPolyline->FilletTwoSegments(idxSideRight3, 0);

	_arrContours4.push_back(pContourPolyline);
	::DeleteItem(pPolyline);
}
void CreateSketchTopGuide5(RPArray<MbContour>& _arrContours5)
{
	//SecondScetch
	SArray<MbCartPoint> arrPnts(7);
	arrPnts.Add(MbCartPoint(29.1, -12.4));
	arrPnts.Add(MbCartPoint(29.1, -3));
	arrPnts.Add(MbCartPoint(40.1, -3));
	arrPnts.Add(MbCartPoint(40.1, 0));
	arrPnts.Add(MbCartPoint(40.1 - 15, 0));
	arrPnts.Add(MbCartPoint(25.1, -12.4));
	//arrPnts.Add(MbCartPoint(25.1+2, 3+8.9));


	MbPolyline* pPolyline = new MbPolyline(arrPnts, false);
	MbCartPoint arrcenter(25.1 + 2, -12.4);
	const double RAD = 2;
	MbArc* pArc = new MbArc(arrcenter, RAD, arrPnts[5], arrPnts[0], 1);

	MbContour* pContourPolyline = new MbContour(*pPolyline, true);
	pContourPolyline->AddSegment(pArc);

	size_t segmentsCount = pContourPolyline->GetSegmentsCount(); // 2
	double tMin = pContourPolyline->GetTMin(); // 0.0
	double tMax = pContourPolyline->GetTMax(); // 10.14159
	// Параметр IsSmoothConnected - допуск для классификации угловых точек на контуре
	bool isSmooth = pContourPolyline->IsSmoothConnected(0.001); // false
	double length = pContourPolyline->CalculateLength(tMin, tMax); // 302.83
	bool isClosed = pContourPolyline->IsClosedContinuousC0(); // true
	bool isCurvilinear = pContourPolyline->IsAnyCurvilinear(); // true

	_arrContours5.push_back(pContourPolyline);
	::DeleteItem(pPolyline);
	::DeleteItem(pArc);
	//::DeleteItem(pContourPolyline);
}

void BuildMathModel::CreateTopGuide(MbAssembly* pAsm, double position) {

	// Множитель для преобразования углов из градусной в радианную меру.
	const double DEG_TO_RAD = M_PI / 180.0;
	const double SqureSize = 65.2;

	/*ВЫДАВЛИВАНИЕ
	bo_Union - объединение
	bo_Difference - удаление
	*/
	// Локальная СК (по умолчанию совпадает с мировой СК)
	MbPlacement3D pl;
	// Создание образующей для тела выдавливания
	RPArray<MbContour> arrContours;
	CreateSketchTopGuide(arrContours);
	RPArray<MbContour> arrContours2;
	CreateSketchTopGuide2(arrContours2);
	RPArray<MbContour> arrContours3;
	CreateSketchTopGuide3(arrContours3);
	RPArray<MbContour> arrContours4;
	CreateSketchTopGuide4(arrContours4);
	RPArray<MbContour> arrContours5;
	CreateSketchTopGuide5(arrContours5);
	//ПЕРЕМЕННЫЕ ДЛЯ ВЫДАВЛИВАНИЯ
	MbBooleanFlags flagsBool;
	flagsBool.InitBoolean(true);
	flagsBool.SetMergingFaces(true);
	flagsBool.SetMergingEdges(true);
	MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone);

	MbPlane* pPlaneXZ = new MbPlane(MbCartPoint3D(0, 0, 0),
		MbCartPoint3D(1, 0, 0),
		MbCartPoint3D(0, 0, 1));
	MbPlane* pPlaneYZ = new MbPlane(MbCartPoint3D(0, 0, 0),
		MbCartPoint3D(0, 1, 0),
		MbCartPoint3D(0, 0, 1));
	MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0),
		MbCartPoint3D(1, 0, 0),
		MbCartPoint3D(0, 1, 0));
	MbPlane* pPlaneYZCen = new MbPlane(MbCartPoint3D(12.65, 0, 0),
		MbCartPoint3D(12.65, 1, 0),
		MbCartPoint3D(12.65, 0, 1));
	MbPlane* pPlaneXZCen = new MbPlane(MbCartPoint3D(0, 32.6 + 7.5, 0),
		MbCartPoint3D(1, 32.6 + 7.5, 0),
		MbCartPoint3D(0, 32.6 + 7.5, 1));

	//СОЗДАНИЕ ПЛСК ДЛЯ ЗЕРКАЛИРОВАНИЯ
	MbPlacement3D HorizPlane(MbVector3D(1, 0, 0), /* Ось X локальной СК */
		MbVector3D(0, 0, 1), /* Ось Z локальной СК */
		MbCartPoint3D(0, 32.6, 0 /* Начало координат локальной СК */));
	MbPlacement3D VerticalPlane(MbVector3D(0, 0, 1), /* Ось Z локальной СК */
		MbVector3D(0, 1, 0), /* Ось Y локальной СК */
		MbCartPoint3D(32.6, 0, 0 /* Начало координат локальной СК */));
	// Направляющий вектор для операции выдавливания
	MbVector3D dirX(1, 0, 0);
	MbVector3D dirY(0, 1, 0);
	MbVector3D dirZ(0, 0, 1);
	// Объект, хранящий параметры образующей
	MbSweptData sweptData(*pPlaneXY, arrContours);
	MbSweptData sweptData2(*pPlaneXY, arrContours2);
	MbSweptData sweptData3(*pPlaneXY, arrContours3);
	MbSweptData sweptData4(*pPlaneXY, arrContours4);
	MbSweptData sweptData5(*pPlaneYZ, arrContours5);
	// Направляющий вектор для операции выдавливания
	// Параметры операции выдавливания, задающие свойства тела для построения в прямом
	// и в обратном направлении вдоль (глубина выдавливания и уклон).
	const double HEIGHT_FORWARD = 0, HEIGHT_BACKWARD = 31;
	const double HEIGHT_FORWARD2 = 0, HEIGHT_BACKWARD2 = 7.8;//31-23.2
	const double HEIGHT_FORWARD3 = 0, HEIGHT_BACKWARD3 = 24.5;//31-6.5
	const double HEIGHT_FORWARD4 = 15 / 2, HEIGHT_BACKWARD4 = 15 / 2;
	const double HEIGHT_FORWARD5 = 12.65, HEIGHT_BACKWARD5 = 0;
	ExtrusionValues extrusionParams(HEIGHT_FORWARD, HEIGHT_BACKWARD);
	ExtrusionValues extrusionParams2(HEIGHT_FORWARD2, HEIGHT_BACKWARD2);
	ExtrusionValues extrusionParams3(HEIGHT_FORWARD3, HEIGHT_BACKWARD3);
	ExtrusionValues extrusionParams4(HEIGHT_FORWARD4, HEIGHT_BACKWARD4);
	ExtrusionValues extrusionParams5(HEIGHT_FORWARD5, HEIGHT_BACKWARD5);
	// Указание уклона для выдавливания в прямом направлении


	// Именователи элементов модели твердого тела и контуров образующей
	MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames(0, 1, false);
	// Именователь операции построения элементарного тела
	MbSNameMaker namesElSolid(ct_ElementarySolid, MbSNameMaker::i_SideNone, 0);
	MbSNameMaker namesDupl(ct_DuplicationSolid, MbSNameMaker::i_SideNone, 0);
	// СОЗДАНИЕ ПЕРЕМЕННЫЕ ДЛЯ ТВЕРДЫХ ТЕЛ
	MbSolid* pSolid = nullptr;
	MbSolid* pSolid2 = nullptr;
	MbSolid* pSolid3 = nullptr;
	MbSolid* pSolid4 = nullptr;
	MbSolid* pSolid5 = nullptr;
	MbSolid* pSolid6 = nullptr;
	MbSolid* pSolid7 = nullptr;
	MbSolid* pSolid8 = nullptr;
	MbSolid* pSolid9 = nullptr;
	MbSolid* pSolid10 = nullptr;
	MbSolid* pSolid11 = nullptr;
	MbSolid* pSolid12 = nullptr;

	//4 ОТВЕРСТИЯ В КВАДРАТИКАХ
	MbSolid* pCyl5_Solid = NULL;
	MbSolid* pCyl6_Solid = NULL;
	MbSolid* pCyl7_Solid = NULL;
	MbSolid* pCyl8_Solid = NULL;
	//МАЛЕНЬКИЕ ДЕТАЛИ
	MbSolid* pCyl9_Solid = NULL;
	MbSolid* pCyl10_Solid = NULL;
	MbSolid* pCyl11_Solid = NULL;
	MbSolid* pCyl12_Solid = NULL;

	//FILLET
	MbSolid* pSolid13 = nullptr;
	MbSolid* pSolid14 = nullptr;
	MbSolid* pCyl1_Solid = NULL;
	MbSolid* pCyl2_Solid = NULL;
	MbSolid* pCyl3_Solid = NULL;
	MbSolid* pCyl4_Solid = NULL;





	//Создание ТТ ДЛЯ КВАДРАТИКОВ ПО УГЛАМ
	MbResultType res2 = ::ExtrusionSolid(sweptData2, dirZ, nullptr, nullptr, false, extrusionParams2, operNames, cNames, pSolid2);

	// ИСХОДНОЕ ТЕЛО №1 - ЦИЛИНДР ВНИЗУ БОЛЬШОЙ
   // Опорные точки для элементарного тела - цилиндра
	SArray<MbCartPoint3D> cylPnts(3);
	cylPnts.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, -4.5));
	cylPnts.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, -40));
	cylPnts.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2 + 25, -4.5));
	// Построение элементарного тела - цилиндра
	MbResultType resCyl1 = ::ElementarySolid(cylPnts, et_Cylinder,
		namesElSolid, pCyl1_Solid);


	// ИСХОДНОЕ ТЕЛО №3 - ЦИЛИНДР ВНИЗУ МАЛЕНЬКИЙ
  // Опорные точки для элементарного тела - цилиндра
	SArray<MbCartPoint3D> cylPnts2(3);
	cylPnts2.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, -4.5));
	cylPnts2.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, -40));
	cylPnts2.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2 + 13, -4.5));
	// Построение элементарного тела - цилиндра
	MbResultType resCyl2 = ::ElementarySolid(cylPnts2, et_Cylinder,
		namesElSolid, pCyl2_Solid);

	// ИСХОДНОЕ ТЕЛО №3 - ЦИЛИНДР БОЛЬШОЙ НАВЕРХУ
  // Опорные точки для элементарного тела - цилиндра
	SArray<MbCartPoint3D> cylPnts3(3);
	cylPnts3.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, 0));
	cylPnts3.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, 25.3));
	cylPnts3.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2 - 19.2, 0));
	// Построение элементарного тела - цилиндра
	MbResultType resCyl3 = ::ElementarySolid(cylPnts3, et_Cylinder,
		namesElSolid, pCyl3_Solid);


	// ИСХОДНОЕ ТЕЛО №4 - ЦИЛИНДР СБОКУ
	// Опорные точки для элементарного тела - цилиндра
	SArray<MbCartPoint3D> cylPnts4(3);
	cylPnts4.Add(MbCartPoint3D(0, 38.8, -18.25));
	cylPnts4.Add(MbCartPoint3D(SqureSize / 2, 38.8, -18.25));
	cylPnts4.Add(MbCartPoint3D(SqureSize / 2, 38.8 - 12.5 / 2, -18.25));
	// Построение элементарного тела - цилиндра
	MbResultType resCyl4 = ::ElementarySolid(cylPnts4, et_Cylinder,
		namesElSolid, pCyl4_Solid);

	// ИСХОДНОЕ ТЕЛО №5 - ОТВЕРСТИЕ В КВАДРАТИКАХ
	 // Опорные точки для элементарного тела - цилиндра
	SArray<MbCartPoint3D> cylPnts5(3);
	cylPnts5.Add(MbCartPoint3D(9, 9, 0));
	cylPnts5.Add(MbCartPoint3D(9, 9, -31));
	cylPnts5.Add(MbCartPoint3D(9, 9 + 6, -31));
	// Построение элементарного тела - цилиндра
	MbResultType resCyl5 = ::ElementarySolid(cylPnts5, et_Cylinder,
		namesElSolid, pCyl5_Solid);

	// ИСХОДНОЕ ТЕЛО №6 - ЦИЛИНДР СВЕРХУ МАЛЕНЬКИЙ
  // Опорные точки для элементарного тела - цилиндра
	SArray<MbCartPoint3D> cylPnts6(3);
	cylPnts6.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, 25.3));
	cylPnts6.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, -4.5));
	cylPnts6.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2 - 10, 25.3));
	// Построение элементарного тела - цилиндра
	MbResultType resCyl6 = ::ElementarySolid(cylPnts6, et_Cylinder,
		namesElSolid, pCyl11_Solid);

	// ИСХОДНОЕ ТЕЛО №7 - ЦИЛИНДР БОЛЬШОЙ НАВЕРХУ
	   // Опорные точки для элементарного тела - цилиндра
	SArray<MbCartPoint3D> cylPnts7(3);
	cylPnts7.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, 0));
	cylPnts7.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, 3.6));
	cylPnts7.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2 - 19.2 - 0.5, 0));
	// Построение элементарного тела - цилиндра
	MbResultType resCyl666 = ::ElementarySolid(cylPnts7, et_Cylinder,
		namesElSolid, pCyl12_Solid);

	// ИСХОДНОЕ ТЕЛО №8 - ЦИЛИНДР СБОКУ(МАЛЕНЬКАЯ ДЕТАЛЬ)
  // Опорные точки для элементарного тела - цилиндра
	SArray<MbCartPoint3D> cylPnts8(3);
	cylPnts8.Add(MbCartPoint3D(0, 38.8, -18.25));
	cylPnts8.Add(MbCartPoint3D(0.2, 38.8, -18.25));
	cylPnts8.Add(MbCartPoint3D(0.2, 38.8 - 22 / 2, -18.25));
	// Построение элементарного тела - цилиндра
	MbResultType resCyl8 = ::ElementarySolid(cylPnts8, et_Cylinder,
		namesElSolid, pCyl9_Solid);

	// ИСХОДНОЕ ТЕЛО №9 - СБОКУ(МАЛЕНЬКАЯ ДЕТАЛЬ)
	// Опорные точки для элементарного тела - цилиндра
	SArray<MbCartPoint3D> cylPnts9(3);
	cylPnts9.Add(MbCartPoint3D(0, 15.4, -22.7));
	cylPnts9.Add(MbCartPoint3D(1.2, 15.4, -22.7));
	cylPnts9.Add(MbCartPoint3D(1.2, 15.4 - 11.4 / 2, -22.7));
	// Построение элементарного тела - цилиндра
	MbResultType resCyl9 = ::ElementarySolid(cylPnts9, et_Cylinder,
		namesElSolid, pCyl10_Solid);
	//СОЗДАНИЕ БАЗЫ ДЛЯ МОДЕЛИ
	MbResultType res = ::ExtrusionSolid(sweptData, dirZ, nullptr, nullptr, false, extrusionParams, operNames, cNames, pSolid);
	MbResultType res16 = ::BooleanResult(*pSolid, cm_Copy, *pCyl1_Solid, cm_Copy, bo_Union, flagsBool, operBoolNames, pSolid);
	MbResultType res32 = ::BooleanResult(*pSolid, cm_Copy, *pCyl3_Solid, cm_Copy, bo_Union, flagsBool, operBoolNames, pSolid);
	MbResultType res33 = ::BooleanResult(*pSolid, cm_Copy, *pCyl12_Solid, cm_Copy, bo_Union, flagsBool, operBoolNames, pSolid);
	MbResultType res17 = ::BooleanResult(*pSolid, cm_Copy, *pCyl2_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res35 = ::BooleanResult(*pSolid, cm_Copy, *pCyl11_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);

	//СОЗДАНИЕ ТТ ДЛЯ 3ПРЯМОУГОЛЬНИКОВ ПО КРАЯМ
	MbResultType res3 = ::ExtrusionSolid(sweptData3, dirZ, nullptr, nullptr, false, extrusionParams3, operNames, cNames, pSolid7);
	MbResultType res12 = ::ExtrusionSolid(sweptData4, dirZ, nullptr, nullptr, false, extrusionParams3, operNames, cNames, pSolid8);


	//ЗЕРКАЛИРОВАНИЕ ОБЪЕКТОВ
	MbResultType res10 = ::MirrorSolid(*pSolid2, HorizPlane, operNames, pSolid4);
	MbResultType res4 = ::MirrorSolid(*pSolid2, VerticalPlane, operNames, pSolid5);
	MbResultType res5 = ::MirrorSolid(*pSolid4, VerticalPlane, operNames, pSolid6);
	MbResultType res11 = ::MirrorSolid(*pSolid7, HorizPlane, operNames, pSolid3);

	//ЗЕРКАЛИРОВАНИЕ ОТВЕРСТИЙ В КВАДРАТИКАХ
	MbResultType res24 = ::MirrorSolid(*pCyl5_Solid, HorizPlane, operNames, pCyl6_Solid);
	MbResultType res25 = ::MirrorSolid(*pCyl5_Solid, VerticalPlane, operNames, pCyl7_Solid);
	MbResultType res26 = ::MirrorSolid(*pCyl6_Solid, VerticalPlane, operNames, pCyl8_Solid);



	//ВЫДАВЛИВАНИЕ КВАДРАТИКОВ ПО УГЛАМ
	MbResultType res6 = ::BooleanResult(*pSolid, cm_Copy, *pSolid2, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res7 = ::BooleanResult(*pSolid, cm_Copy, *pSolid4, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res8 = ::BooleanResult(*pSolid, cm_Copy, *pSolid5, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res9 = ::BooleanResult(*pSolid, cm_Copy, *pSolid6, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);


	//ВЫДАВЛИВАНИЕ ОТВЕРСТИЙ В КВАДРАТИКАХ
	MbResultType res27 = ::BooleanResult(*pSolid, cm_Copy, *pCyl5_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res28 = ::BooleanResult(*pSolid, cm_Copy, *pCyl6_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res29 = ::BooleanResult(*pSolid, cm_Copy, *pCyl7_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res30 = ::BooleanResult(*pSolid, cm_Copy, *pCyl8_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);


	//ВЫДАВЛИВАНИЕ 3ПРЯМОУГОЛЬНИКОВ ПО КРАЯМ
	MbResultType res13 = ::BooleanResult(*pSolid, cm_Copy, *pSolid7, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res14 = ::BooleanResult(*pSolid, cm_Copy, *pSolid3, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res15 = ::BooleanResult(*pSolid, cm_Copy, *pSolid8, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);


	MbResultType res21 = ::BooleanResult(*pSolid, cm_Copy, *pCyl4_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);

	MbResultType res36 = ::BooleanResult(*pSolid, cm_Copy, *pCyl9_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);

	MbResultType res37 = ::BooleanResult(*pSolid, cm_Copy, *pCyl10_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);


	//СОЗДАНИЕ ВЫРЕЗА ВОЗЛЕ ВЫХОДА ДИАМЕТРА
	MbResultType res22 = ::ExtrusionSolid(sweptData5, dirX, nullptr, nullptr, false, extrusionParams5, operNames, cNames, pSolid12);
	MbResultType res39 = ::BooleanResult(*pSolid, cm_Copy, *pSolid12, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	//show(Style(1, BLACK), pSolid4);
	//show(Style(1, BLACK), pSolid5);
	pSolid->Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(-SqureSize / 2, -SqureSize / 2, position + 43.45)));


	pSolid->SetColor(LIGHTRED);
	pAsm->AddItem(*pSolid);

	// Уменьшение счетчиков ссылок динамически созданных объектов ядра
	::DeleteItem(pSolid);
	::DeleteItem(pSolid2);
	::DeleteItem(pSolid3);
	::DeleteItem(pSolid4);
	::DeleteItem(pSolid5);
	::DeleteItem(pSolid6);
	::DeleteItem(pSolid7);
	::DeleteItem(pSolid8);
	::DeleteItem(pSolid9);
	::DeleteItem(pSolid10);
	::DeleteItem(pSolid11);
	::DeleteItem(pSolid12);
	::DeleteItem(pSolid13);
	::DeleteItem(pSolid14);

	::DeleteItem(pCyl1_Solid);
	::DeleteItem(pCyl2_Solid);
	::DeleteItem(pCyl3_Solid);
	::DeleteItem(pCyl4_Solid);
	::DeleteItem(pCyl5_Solid);
	::DeleteItem(pCyl6_Solid);
	::DeleteItem(pCyl7_Solid);
	::DeleteItem(pCyl8_Solid);
	::DeleteItem(pCyl9_Solid);
	::DeleteItem(pCyl10_Solid);
	::DeleteItem(pCyl11_Solid);
	::DeleteItem(pCyl12_Solid);

	::DeleteItem(pPlaneXY);
	::DeleteItem(pPlaneXZ);
	::DeleteItem(pPlaneXZCen);
	::DeleteItem(pPlaneYZ);
	::DeleteItem(pPlaneYZCen);
}