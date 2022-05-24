#include "BuildTestMathModel.h"

void CreateTestSketch(RPArray<MbContour>& _arrContours)
{
	// Создание массива точек квадрата, к которому в дальнейшем добавятся скругления.
	// Размер массива - 8 точек для учета точек четырех сегментов скруглений.
	SArray<MbCartPoint> arrPnts(8);
	arrPnts.Add(MbCartPoint(0, 0));
	arrPnts.Add(MbCartPoint(50, 0));
	arrPnts.Add(MbCartPoint(50, 50));
	arrPnts.Add(MbCartPoint(0, 50));
	// Построение единой ломаной внешнего контура по точкам
	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
	MbContour* pContourPolyline = NULL;
	// Задание скругления с использованием функции FilletPolyContour
	::FilletPolyContour(pPolyline, 5, false, arrPnts[4], pContourPolyline);
	// Задание индексов точек, в которых будет задаваться скругление с учетом
	// добавления новой точки при скруглении с использованием функции FilletTwoSegments
	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;
	// Добавление скруглений
	pContourPolyline->FilletTwoSegments(idxSideRight1, 5);
	pContourPolyline->FilletTwoSegments(idxSideRight2, 5);
	pContourPolyline->FilletTwoSegments(idxSideRight3, 5);
	_arrContours.push_back(pContourPolyline);
}

MbAssembly* createTestAssemblyModel()
{
	// Локальная СК (по умолчанию совпадает с мировой СК)
	MbPlacement3D pl;
	// Создание образующей для тела выдавливания
	RPArray<MbContour> arrContours;
	CreateTestSketch(arrContours);
	// Отображение образующей (в плоскости XY глобальной СК)

	// ПОСТРОЕНИЕ ТЕЛА ВЫДАВЛИВАНИЯ
	// Образующая размещается на плоскости XY глобальной СК.
	// Важное замечание: объект-плоскость должен создаваться динамически,
	// поскольку он продолжает использоваться в объекте-твердом теле после
	// выхода из данной функции.
	MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0),
		MbCartPoint3D(1, 0, 0),
		MbCartPoint3D(0, 1, 0));
	// Объект, хранящий параметры образующей
	MbSweptData sweptData(*pPlaneXY, arrContours);
	// Направляющий вектор для операции выдавливания
	MbVector3D dir(0, 0, -1);
	// Параметры операции выдавливания, задающие свойства тела для построения в прямом
	// и в обратном направлении вдоль (глубина выдавливания и уклон).
	const double HEIGHT_FORWARD = 60.0, HEIGHT_BACKWARD = 30.0;
	const double ANGLE_FORWARD_DEGREE = 15.0;
	ExtrusionValues extrusionParams(HEIGHT_FORWARD, HEIGHT_BACKWARD);
	// Указание уклона для выдавливания в прямом направлении
	extrusionParams.side1.rake = ANGLE_FORWARD_DEGREE * M_PI / 180.0;
	// Именователи элементов модели твердого тела и контуров образующей
	MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames(0, 1, false);
	// Вызов функции-утилиты для построения твердого тела выдавливания
	MbSolid* pSolid = NULL;
	MbResultType res = ::ExtrusionSolid(sweptData, dir, NULL, NULL, false,
		extrusionParams, operNames, cNames, pSolid);

	MbSolid* pSolid2 = NULL;
	MbResultType res2 = ::ExtrusionSolid(sweptData, dir, NULL, NULL, false,
		extrusionParams, operNames, cNames, pSolid2);


	pSolid->Move(MbVector3D(50, 100, 20));
	pSolid->SetColor(LIGHTBLUE);

	pSolid2->Move(MbVector3D(0, 0, 0));
	pSolid2->SetColor(LIGHTGREEN);

	MbAssembly* pAsm = new MbAssembly();
	pAsm->AddItem(*pSolid);
	pAsm->AddItem(*pSolid2);

	// Уменьшение счетчиков ссылок динамически созданных объектов ядра
	::DeleteItem(pPlaneXY);
	::DeleteItem(pSolid);
	::DeleteItem(pSolid2);

	return pAsm;
}
