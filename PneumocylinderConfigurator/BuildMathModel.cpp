#include "BuildMathModel.h"


using namespace c3d;
using namespace std;
using namespace BuildMathModel;

MbAssembly* pAsm = nullptr;


//Вспомогательные функции для создания деталей
void CreateSketch(RPArray<MbContour>& _arrContours)
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



}
void CreateSketch2(RPArray<MbContour>& _arrContours2)
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
	MbContour* pContourPolyline2 = nullptr;
	// Задание скругления с использованием функции FilletPolyContour
	::FilletPolyContour(pPolyline2, 10.5, false, arrPnts2[4], pContourPolyline2);

	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;

	pContourPolyline2->FilletTwoSegments(idxSideRight1, 0);
	pContourPolyline2->FilletTwoSegments(idxSideRight2, 0);
	pContourPolyline2->FilletTwoSegments(idxSideRight3, 0);

	_arrContours2.push_back(pContourPolyline2);
}
void CreateSketch3(RPArray<MbContour>& _arrContours3)
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
}
void CreateSketch4(RPArray<MbContour>& _arrContours4)
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
}
void CreateSketch5(RPArray<MbContour>& _arrContours5)
{
	//SecondScetch
	double SqureSize = 65.2;
	SArray<MbCartPoint> arrPnts(8);
	arrPnts.Add(MbCartPoint(39.9 / 2 + SqureSize / 2, 0));
	arrPnts.Add(MbCartPoint(39.9 / 2 + SqureSize / 2, -33.75));
	arrPnts.Add(MbCartPoint(-39.9 / 2 + SqureSize / 2, -33.75));
	arrPnts.Add(MbCartPoint(-39.9 / 2 + SqureSize / 2, 0));

	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
	MbContour* pContourPolyline = nullptr;
	// Задание скругления с использованием функции FilletPolyContour//16
	::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;

	pContourPolyline->FilletTwoSegments(idxSideRight1, 16);
	pContourPolyline->FilletTwoSegments(idxSideRight2, 16);
	pContourPolyline->FilletTwoSegments(idxSideRight3, 0);

	_arrContours5.push_back(pContourPolyline);
}
void CreateSketch6(RPArray<MbContour>& _arrContours6)
{
	//SecondScetch
	SArray<MbCartPoint> arrPnts(7);
	arrPnts.Add(MbCartPoint(25.1, 3 + 8.9));
	arrPnts.Add(MbCartPoint(25.1, 0));
	arrPnts.Add(MbCartPoint(25.1 + 15, 0));
	arrPnts.Add(MbCartPoint(25.1 + 15, 3));
	arrPnts.Add(MbCartPoint(25.1 + 4, 3));
	arrPnts.Add(MbCartPoint(25.1 + 4, 3 + 8.9));
	//arrPnts.Add(MbCartPoint(25.1+2, 3+8.9));


	MbPolyline* pPolyline = new MbPolyline(arrPnts, false);
	MbCartPoint arrcenter(25.1 + 2, 3 + 8.9);
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

	_arrContours6.push_back(pContourPolyline);
}
void CreateSketch7(RPArray<MbContour>& _arrContours7)
{
	double SqureSize = 65.2;
	//SecondScetch
	SArray<MbCartPoint> arrPnts(4);
	arrPnts.Add(MbCartPoint(SqureSize / 2 - 15 / 2, -5));
	arrPnts.Add(MbCartPoint(SqureSize / 2 - 15 / 2, 0));
	arrPnts.Add(MbCartPoint(SqureSize / 2 - 15 / 2 - 5, 0));
	//arrPnts.Add(MbCartPoint(SqureSize/2-15/2-5, -5));


	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
	MbCartPoint arrcenter(SqureSize / 2 - 15 / 2 - 5, -5);

	MbContour* pContourPolyline = new MbContour(*pPolyline, true);

	_arrContours7.push_back(pContourPolyline);
}
void CreateSketchDiana(RPArray<MbContour>& _arrContours)
{
	SArray<MbCartPoint> arrPnts(8);
	arrPnts.Add(MbCartPoint(12.5, 12.5));
	arrPnts.Add(MbCartPoint(12.5, -12.5));
	arrPnts.Add(MbCartPoint(-12.5, -12.5));
	arrPnts.Add(MbCartPoint(-12.5, 12.5));

	// Построение единой ломаной внешнего контура по точкам
	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
	MbContour* pContourPolyline = nullptr;

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
void CreateSketchEgor(RPArray<MbContour>& _arrContours)
{
	// Создание массива точек квадрата, к которому в дальнейшем добавятся скругления.
	// Размер массива - 8 точек для учета точек четырех сегментов скруглений.
	SArray<MbCartPoint> arrPnts(16);
	arrPnts.Add(MbCartPoint(0, 4));
	arrPnts.Add(MbCartPoint(0, 10));
	arrPnts.Add(MbCartPoint(27, 10));
	arrPnts.Add(MbCartPoint(28, 9.25));
	arrPnts.Add(MbCartPoint(32, 9.25));
	arrPnts.Add(MbCartPoint(32, 7));
	arrPnts.Add(MbCartPoint(9.5, 7));
	arrPnts.Add(MbCartPoint(8.5, 4));

	// Построение единой ломаной внешнего контура по точкам
	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);

	MbContour* pContourPolyline = nullptr;

	// Задание скругления с использованием функции FilletPolyContour
	::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

	// Задание индексов точек, в которых будет задаваться скругление с учетом
	// добавления новой точки при скруглении с использованием функции FilletTwoSegments
	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;

	// Добавление скруглений
	pContourPolyline->FilletTwoSegments(idxSideRight1, 0);
	pContourPolyline->FilletTwoSegments(idxSideRight2, 0);
	pContourPolyline->FilletTwoSegments(idxSideRight3, 0);

	_arrContours.push_back(pContourPolyline);
}
void CreateSketchEgor2(RPArray<MbContour>& _arrContours)
{
	// Создание массива точек квадрата, к которому в дальнейшем добавятся скругления.
	// Размер массива - 8 точек для учета точек четырех сегментов скруглений.
	SArray<MbCartPoint> arrPnts(12);
	const double DEG_TO_RAD1 = M_PI / 180.0;
	double R = 5.125;
	arrPnts.Add(MbCartPoint(R * cos(0 * DEG_TO_RAD1), R * sin(0 * DEG_TO_RAD1)));
	arrPnts.Add(MbCartPoint(R * cos(60 * DEG_TO_RAD1), R * sin(60 * DEG_TO_RAD1)));

	arrPnts.Add(MbCartPoint(R * cos(120 * DEG_TO_RAD1), R * sin(120 * DEG_TO_RAD1)));
	arrPnts.Add(MbCartPoint(R * cos(180 * DEG_TO_RAD1), R * sin(180 * DEG_TO_RAD1)));
	arrPnts.Add(MbCartPoint(R * cos(240 * DEG_TO_RAD1), R * sin(240 * DEG_TO_RAD1)));
	arrPnts.Add(MbCartPoint(R * cos(300 * DEG_TO_RAD1), R * sin(300 * DEG_TO_RAD1)));

	// Построение единой ломаной внешнего контура по точкам
	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);

	MbContour* pContourPolyline = nullptr;

	// Задание скругления с использованием функции FilletPolyContour
	::FilletPolyContour(pPolyline, 0, false, arrPnts[1], pContourPolyline);

	// Задание индексов точек, в которых будет задаваться скругление с учетом
	// добавления новой точки при скруглении с использованием функции FilletTwoSegments
	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;

	// Добавление скруглений
	pContourPolyline->FilletTwoSegments(idxSideRight1, 0);
	pContourPolyline->FilletTwoSegments(idxSideRight2, 0);
	pContourPolyline->FilletTwoSegments(idxSideRight3, 0);

	_arrContours.push_back(pContourPolyline);
}
void CreateSketchEgor3(RPArray<MbContour>& _arrContours, double length)
{
	// Создание массива точек квадрата, к которому в дальнейшем добавятся скругления.
	// Размер массива - 8 точек для учета точек четырех сегментов скруглений.
	SArray<MbCartPoint> arrPnts(20);
	arrPnts.Add(MbCartPoint(0, 0));
	arrPnts.Add(MbCartPoint(0, 3.5));
	arrPnts.Add(MbCartPoint(0.5, 4));
	arrPnts.Add(MbCartPoint(10, 4));
	arrPnts.Add(MbCartPoint(10, 3.5));
	arrPnts.Add(MbCartPoint(length + 70, 3.5));
	arrPnts.Add(MbCartPoint(length + 70, 4));
	arrPnts.Add(MbCartPoint(length + 79.5, 4));
	arrPnts.Add(MbCartPoint(length + 80, 3.5));
	arrPnts.Add(MbCartPoint(length + 80, 0));

	// Построение единой ломаной внешнего контура по точкам
	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
	MbContour* pContourPolyline = nullptr;

	// Задание скругления с использованием функции FilletPolyContour
	::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

	// Задание индексов точек, в которых будет задаваться скругление с учетом
	// добавления новой точки при скруглении с использованием функции FilletTwoSegments
	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;

	// Добавление скруглений
	pContourPolyline->FilletTwoSegments(idxSideRight1, 0);
	pContourPolyline->FilletTwoSegments(idxSideRight2, 0);
	pContourPolyline->FilletTwoSegments(idxSideRight3, 0);

	_arrContours.push_back(pContourPolyline);
}
void CreateSketchSASHA(RPArray<MbContour>& _arrContours)
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



}
void CreateSketchSASHA2(RPArray<MbContour>& _arrContours2)
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
}
void CreateSketchSASHA3(RPArray<MbContour>& _arrContours3)
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
}
void CreateSketchSASHA4(RPArray<MbContour>& _arrContours4)
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
}
void CreateSketchSASHA5(RPArray<MbContour>& _arrContours5)
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
}
void CreateSketchSergey1(RPArray<MbContour>& _arrContours)
{
	// Создание массива точек квадрата, к которому в дальнейшем добавятся скругления.
	// Размер массива - 8 точек для учета точек четырех сегментов скруглений.
	SArray<MbCartPoint> arrPnts(20);
	arrPnts.Add(MbCartPoint(0, 10.05));
	arrPnts.Add(MbCartPoint(0, 11));
	arrPnts.Add(MbCartPoint(3, 12.25));
	arrPnts.Add(MbCartPoint(32, 12.25));
	arrPnts.Add(MbCartPoint(32, 9.25));
	arrPnts.Add(MbCartPoint(27, 9.25));
	arrPnts.Add(MbCartPoint(27, 10.05));

	// Построение единой ломаной внешнего контура по точкам
	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
	MbContour* pContourPolyline = nullptr;

	// Задание скругления с использованием функции FilletPolyContour
	::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

	// Задание индексов точек, в которых будет задаваться скругление с учетом
	// добавления новой точки при скруглении с использованием функции FilletTwoSegments
	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;

	// Добавление скруглений
	pContourPolyline->FilletTwoSegments(idxSideRight1, 0);
	pContourPolyline->FilletTwoSegments(idxSideRight2, 0);
	pContourPolyline->FilletTwoSegments(idxSideRight3, 0);

	_arrContours.push_back(pContourPolyline);
}

//Функции по созданию деталей ребят
void CreateBase()
{
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
	CreateSketch(arrContours);
	RPArray<MbContour> arrContours2;
	CreateSketch2(arrContours2);
	RPArray<MbContour> arrContours3;
	CreateSketch3(arrContours3);
	RPArray<MbContour> arrContours4;
	CreateSketch4(arrContours4);
	RPArray<MbContour> arrContours5;
	CreateSketch5(arrContours5);
	RPArray<MbContour> arrContours6;
	CreateSketch6(arrContours6);
	RPArray<MbContour> arrContours7;
	CreateSketch7(arrContours7);
	//ПЕРЕМЕННЫЕ ДЛЯ ВЫДАВЛИВАНИЯ
	MbBooleanFlags flagsBool;
	flagsBool.InitBoolean(true);
	flagsBool.SetMergingFaces(true);
	flagsBool.SetMergingEdges(true);
	MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone);
	// Отображение образующей (в плоскости XY глобальной СК)
	//for (int i = 0; i<arrContours2.size(); i++)
		//show(Style(1, LIGHTRED), arrContours2[i], &pl2);
	//for (int i = 0; i<arrContours7.size(); i++)
	//    show(Style(1, BLUE), arrContours7[i], &pl);
	// ПОСТРОЕНИЕ ТЕЛА ВЫДАВЛИВАНИЯ
	// Образующая размещается на плоскости XY глобальной СК.
	// Важное замечание: объект-плоскость должен создаваться динамически,
	// поскольку он продолжает использоваться в объекте-твердом теле после
	// выхода из данной функции.
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
	MbSweptData sweptData5(*pPlaneXZCen, arrContours5);
	MbSweptData sweptData6(*pPlaneYZ, arrContours6);
	MbSweptData sweptData7(*pPlaneYZCen, arrContours7);
	// Направляющий вектор для операции выдавливания
	// Параметры операции выдавливания, задающие свойства тела для построения в прямом
	// и в обратном направлении вдоль (глубина выдавливания и уклон).
	const double HEIGHT_FORWARD = 31, HEIGHT_BACKWARD = 0;
	const double HEIGHT_FORWARD2 = 0, HEIGHT_BACKWARD2 = -7.8;//31-23.2
	const double HEIGHT_FORWARD3 = 0, HEIGHT_BACKWARD3 = -24.5;//31-6.5
	const double HEIGHT_FORWARD4 = 15 / 2, HEIGHT_BACKWARD4 = 15 / 2;
	const double HEIGHT_FORWARD5 = 0, HEIGHT_BACKWARD5 = 15;
	const double HEIGHT_FORWARD6 = 12.65, HEIGHT_BACKWARD6 = 0;
	const double HEIGHT_FORWARD7 = 39.9, HEIGHT_BACKWARD7 = 0;
	ExtrusionValues extrusionParams(HEIGHT_FORWARD, HEIGHT_BACKWARD);
	ExtrusionValues extrusionParams2(HEIGHT_FORWARD2, HEIGHT_BACKWARD2);
	ExtrusionValues extrusionParams3(HEIGHT_FORWARD3, HEIGHT_BACKWARD3);
	ExtrusionValues extrusionParams4(HEIGHT_FORWARD4, HEIGHT_BACKWARD4);
	ExtrusionValues extrusionParams5(HEIGHT_FORWARD5, HEIGHT_BACKWARD5);
	ExtrusionValues extrusionParams6(HEIGHT_FORWARD6, HEIGHT_BACKWARD6);
	ExtrusionValues extrusionParams7(HEIGHT_FORWARD7, HEIGHT_BACKWARD7);
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
	//FILLET
	MbSolid* pSolid13 = nullptr;
	MbSolid* pSolid14 = nullptr;
	MbSolid* pCyl1_Solid = NULL;
	MbSolid* pCyl2_Solid = NULL;
	MbSolid* pCyl3_Solid = NULL;
	MbSolid* pCyl4_Solid = NULL;
	//4 ОТВЕРСТИЯ В КВАДРАТИКАХ
	MbSolid* pCyl5_Solid = NULL;
	MbSolid* pCyl6_Solid = NULL;
	MbSolid* pCyl7_Solid = NULL;
	MbSolid* pCyl8_Solid = NULL;
	//МАЛЕНЬКИЕ ДЕТАЛИ
	MbSolid* pCyl9_Solid = NULL;
	MbSolid* pCyl10_Solid = NULL;
	//ПОСТРОЕНИЕ ТЕЛ В ФУНКЦИИ
	// ИСХОДНОЕ ТЕЛО №1 - ЦИЛИНДР ВНИЗУ БОЛЬШОЙ
	// Опорные точки для элементарного тела - цилиндра
	SArray<MbCartPoint3D> cylPnts(3);
	cylPnts.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, 4.5));
	cylPnts.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, 40));
	cylPnts.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2 + 25, 4.5));
	// Построение элементарного тела - цилиндра
	MbResultType resCyl1 = ::ElementarySolid(cylPnts, et_Cylinder,
		namesElSolid, pCyl1_Solid);
	// ИСХОДНОЕ ТЕЛО №2 - ЦИЛИНДР ВНИЗУ МАЛЕНЬКИЙ
	// Опорные точки для элементарного тела - цилиндра
	SArray<MbCartPoint3D> cylPnts2(3);
	cylPnts2.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, 4.5));
	cylPnts2.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, 40));
	cylPnts2.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2 + 13, 4.5));
	// Построение элементарного тела - цилиндра
	MbResultType resCyl2 = ::ElementarySolid(cylPnts2, et_Cylinder,
		namesElSolid, pCyl2_Solid);
	// ИСХОДНОЕ ТЕЛО №3 - ЦИЛИНДР В КРЮКЕ
	// Опорные точки для элементарного тела - цилиндра
	SArray<MbCartPoint3D> cylPnts3(3);
	cylPnts3.Add(MbCartPoint3D(SqureSize / 2, 25.1, -18.75));
	cylPnts3.Add(MbCartPoint3D(SqureSize / 2, 25.1 + 15, -18.75));
	cylPnts3.Add(MbCartPoint3D(SqureSize / 2, 25.1 + 15, -18.75 + 13.5 / 2));
	// Построение элементарного тела - цилиндра
	MbResultType resCyl3 = ::ElementarySolid(cylPnts3, et_Cylinder,
		namesElSolid, pCyl3_Solid);
	// ИСХОДНОЕ ТЕЛО №4 - ЦИЛИНДР СБОКУ
	// Опорные точки для элементарного тела - цилиндра
	SArray<MbCartPoint3D> cylPnts4(3);
	cylPnts4.Add(MbCartPoint3D(0, 38.8, 18.25));
	cylPnts4.Add(MbCartPoint3D(SqureSize / 2, 38.8, 18.25));
	cylPnts4.Add(MbCartPoint3D(SqureSize / 2, 38.8 + 12.5 / 2, 18.25));
	// Построение элементарного тела - цилиндра
	MbResultType resCyl4 = ::ElementarySolid(cylPnts4, et_Cylinder,
		namesElSolid, pCyl4_Solid);
	// ИСХОДНОЕ ТЕЛО №5 - ОТВЕРСТИЕ В КВАДРАТИКАХ
	// Опорные точки для элементарного тела - цилиндра
	SArray<MbCartPoint3D> cylPnts5(3);
	cylPnts5.Add(MbCartPoint3D(9, 9, 0));
	cylPnts5.Add(MbCartPoint3D(9, 9, 31));
	cylPnts5.Add(MbCartPoint3D(9, 9 + 6, 31));
	// Построение элементарного тела - цилиндра
	MbResultType resCyl5 = ::ElementarySolid(cylPnts5, et_Cylinder,
		namesElSolid, pCyl5_Solid);
	// ИСХОДНОЕ ТЕЛО №6 - ЦИЛИНДР СБОКУ(МАЛЕНЬКАЯ ДЕТАЛЬ)
	// Опорные точки для элементарного тела - цилиндра
	SArray<MbCartPoint3D> cylPnts6(3);
	cylPnts6.Add(MbCartPoint3D(0, 38.8, 18.25));
	cylPnts6.Add(MbCartPoint3D(0.2, 38.8, 18.25));
	cylPnts6.Add(MbCartPoint3D(0.2, 38.8 + 22 / 2, 18.25));
	// Построение элементарного тела - цилиндра
	MbResultType resCyl6 = ::ElementarySolid(cylPnts6, et_Cylinder,
		namesElSolid, pCyl9_Solid);
	// ИСХОДНОЕ ТЕЛО №7 - СБОКУ(МАЛЕНЬКАЯ ДЕТАЛЬ)
	// Опорные точки для элементарного тела - цилиндра
	SArray<MbCartPoint3D> cylPnts7(3);
	cylPnts7.Add(MbCartPoint3D(0, 15.4, 22.7));
	cylPnts7.Add(MbCartPoint3D(1.2, 15.4, 22.7));
	cylPnts7.Add(MbCartPoint3D(1.2, 15.4 + 11.4 / 2, 22.7));
	// Построение элементарного тела - цилиндра
	MbResultType resCyl7 = ::ElementarySolid(cylPnts7, et_Cylinder,
		namesElSolid, pCyl10_Solid);
	//СОЗДАНИЕ БАЗЫ ДЛЯ МОДЕЛИ
	MbResultType res = ::ExtrusionSolid(sweptData, dirZ, nullptr, nullptr, false, extrusionParams, operNames, cNames, pSolid);
	MbResultType res16 = ::BooleanResult(*pSolid, cm_Copy, *pCyl1_Solid, cm_Copy, bo_Union, flagsBool, operBoolNames, pSolid);
	MbResultType res17 = ::BooleanResult(*pSolid, cm_Copy, *pCyl2_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	//Создание ТТ ДЛЯ КВАДРАТИКОВ ПО УГЛАМ
	MbResultType res2 = ::ExtrusionSolid(sweptData2, dirZ, nullptr, nullptr, false, extrusionParams2, operNames, cNames, pSolid2);
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
	//ВЫДАВЛИВАНИЕ 3ПРЯМОУГОЛЬНИКОВ ПО КРАЯМ
	MbResultType res13 = ::BooleanResult(*pSolid, cm_Copy, *pSolid7, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res14 = ::BooleanResult(*pSolid, cm_Copy, *pSolid3, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res15 = ::BooleanResult(*pSolid, cm_Copy, *pSolid8, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	//СОЗДАНИЕ КРЮКА

	MbResultType res18 = ::ExtrusionSolid(sweptData5, dirY, nullptr, nullptr, false, extrusionParams5, operNames, cNames, pSolid10);
	//END TEST
	MbResultType res19 = ::BooleanResult(*pSolid10, cm_Copy, *pCyl3_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid10);
	MbResultType res20 = ::BooleanResult(*pSolid, cm_Copy, *pSolid10, cm_Copy, bo_Union, flagsBool, operBoolNames, pSolid);
	MbResultType res21 = ::BooleanResult(*pSolid, cm_Copy, *pCyl4_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	//СОЗДАНИЕ ВЫРЕЗА ВОЗЛЕ ВЫХОДА ДИАМЕТРА
	MbResultType res22 = ::ExtrusionSolid(sweptData6, dirX, nullptr, nullptr, false, extrusionParams6, operNames, cNames, pSolid12);
	MbResultType res23 = ::BooleanResult(*pSolid, cm_Copy, *pSolid12, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	//ВЫДАВЛИВАНИЕ ОТВЕРСТИЙ В КВАДРАТИКАХ
	MbResultType res27 = ::BooleanResult(*pSolid, cm_Copy, *pCyl5_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res28 = ::BooleanResult(*pSolid, cm_Copy, *pCyl6_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res29 = ::BooleanResult(*pSolid, cm_Copy, *pCyl7_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res30 = ::BooleanResult(*pSolid, cm_Copy, *pCyl8_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	//ВЫДАВЛИВАНИЕ МАЛЕНЬКИХ ДЕТАЛЕЙ СБОКУ
	MbResultType res31 = ::BooleanResult(*pSolid, cm_Copy, *pCyl9_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res32 = ::BooleanResult(*pSolid, cm_Copy, *pCyl10_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	//FILLETS 
	MbResultType res33 = ::ExtrusionSolid(sweptData7, dirX, nullptr, nullptr, false, extrusionParams7, operNames, cNames, pSolid13);
	MbResultType res34 = ::MirrorSolid(*pSolid13, HorizPlane, operNames, pSolid14);
	MbResultType res35 = ::BooleanResult(*pSolid, cm_Copy, *pSolid13, cm_Copy, bo_Union, flagsBool, operBoolNames, pSolid);
	MbResultType res36 = ::BooleanResult(*pSolid, cm_Copy, *pSolid14, cm_Copy, bo_Union, flagsBool, operBoolNames, pSolid);
	// Отображение построенного тела
	//show(Style(1, LIGHTGRAY), pSolid);
	//show(Style(1, BLACK), pSolid2);

	//show(Style(1, BLACK), pSolid4);
	//show(Style(1, BLACK), pSolid5);
	pSolid->Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(-SqureSize / 2, -SqureSize / 2, -62)));
	//pSolid->Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, -SqureSize / 2, 0)));

	pSolid->SetColor(LIGHTRED);
	pAsm->AddItem(*pSolid);
	//viewManager->AddObject(Style(1, LIGHTRED), pSolid);


	//show(Style(1, LIGHTGRAY), pSolid14);
	//show(Style(1, LIGHTGRAY), pCyl5_Solid);
	//show(Style(1, LIGHTGRAY), pCyl6_Solid);
	//show(Style(1, LIGHTGRAY), pCyl9_Solid);
	//show(Style(1, LIGHTGRAY), pCyl10_Solid);
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
	::DeleteItem(pCyl1_Solid);
	::DeleteItem(pCyl2_Solid);
	::DeleteItem(pCyl3_Solid);
	::DeleteItem(pCyl4_Solid);
	::DeleteItem(pCyl5_Solid);
	::DeleteItem(pCyl6_Solid);
	::DeleteItem(pCyl7_Solid);
	::DeleteItem(pCyl8_Solid);

}
void CreateShaftPivot(double position)
{
	//Построение параллелепипеда    
	MbPlacement3D pl;

	// Создание образующей для тела выдавливания
	RPArray<MbContour> arrContours;
	CreateSketchDiana(arrContours);

	// Отображение образующей (в плоскости XY глобальной СК)
	/*for (int i = 0; i<arrContours.size(); i++)
		show( Style(1, LIGHTRED), arrContours[i], &pl);
	*/
	// ПОСТРОЕНИЕ ТЕЛА ВЫДАВЛИВАНИЯ
	MbPlane* pPlaneXZ = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 0, 1));
	// Объект, хранящий параметры образующей
	MbSweptData sweptData(*pPlaneXZ, arrContours);
	// Направляющий вектор для операции выдавливания
	MbVector3D dir(0, 1, 0);

	// Параметры операции выдавливания, задающие свойства тела для построения в прямом и в обратном направлении вдоль (глубина выдавливания и уклон).
	const double HEIGHT_FORWARD = 0, HEIGHT_BACKWARD = 39;
	ExtrusionValues extrusionParams(HEIGHT_FORWARD, HEIGHT_BACKWARD);

	// Именователи элементов модели твердого тела и контуров образующей
	MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames(0, 1, false);

	// Вызов функции-утилиты для построения твердого тела выдавливания
	MbSolid* pSolid = nullptr;
	MbResultType res = ::ExtrusionSolid(sweptData, dir, nullptr, nullptr, false, extrusionParams, operNames, cNames, pSolid);


	//Построение отверстия
	MbSolid* pBlockHole = NULL;
	{
		MbSNameMaker holeNames(ct_HoleSolid, MbSNameMaker::i_SideNone, 0);
		const double DEG_TO_RAD = M_PI / 180.0;
		MbPlacement3D plHole(MbCartPoint3D(0, 0, 0));
		plHole.Rotate(MbAxis3D(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0))),
			90 * DEG_TO_RAD);
		plHole.Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, -39, 0)));
		BorerValues params;

		params.type = BorerValues::bt_SimpleCylinder;

		params.diameter = 13.835;

		params.depth = 32;

		params.down = true;

		::HoleSolid(pSolid, cm_Copy, plHole, params, holeNames, pBlockHole);


	}

	//Построение вверхней части
	MbPlacement3D pl1;

	SArray<MbCartPoint> arrPnts1(4);
	arrPnts1.Add(MbCartPoint(-12.5, 14.5));
	arrPnts1.Add(MbCartPoint(-12.5, 0));
	arrPnts1.Add(MbCartPoint(12.5, 0));
	arrPnts1.Add(MbCartPoint(12.5, 14.5));

	MbPolyline* pPolyline1 = new MbPolyline(arrPnts1, false);

	MbCartPoint arcCenter(0, 14.5);
	const double RADIUS = 12.5;
	MbArc* pArc = new MbArc(arcCenter, RADIUS, arrPnts1[3], arrPnts1[0], 1);
	MbContour* pContour1 = new MbContour(*pPolyline1, true);
	pContour1->AddSegment(pArc);
	// Вызовы информационных методов контура
	size_t segmentsCount = pContour1->GetSegmentsCount(); // 2
	double tMin = pContour1->GetTMin(); // 0.0
	double tMax = pContour1->GetTMax(); // 10.14159
	// Параметр IsSmoothConnected - допуск для классификации угловых точек    на контуре
	bool isSmooth = pContour1->IsSmoothConnected(0.001); // false
	double length = pContour1->CalculateLength(tMin, tMax); // 302.83
	bool isClosed = pContour1->IsClosedContinuousC0(); // true
	bool isCurvilinear = pContour1->IsAnyCurvilinear(); // true
	// ПОСТРОЕНИЕ ТЕЛА ВЫДАВЛИВАНИЯ
	MbSweptData sweptData1(pl1, *pContour1);
	MbVector3D dir1(0, 0, 1);
	const double HEIGHT_FORWARD1 = 5, HEIGHT_BACKWARD1 = 5;
	ExtrusionValues extrusionParam(HEIGHT_FORWARD1, HEIGHT_BACKWARD1);

	MbSNameMaker operNames1(ct_CurveExtrusionSolid, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames1(0, 1, false);

	MbSolid* pSolid1 = NULL;
	MbResultType resCode = ::ExtrusionSolid(sweptData1, dir1, NULL, NULL, false,
		extrusionParam, operNames1, cNames1, pSolid1);


	//Построение отверстия в вверхней части
	MbSolid* pHole = NULL;
	{
		MbSNameMaker hole1Names(ct_HoleSolid, MbSNameMaker::i_SideNone, 0);

		MbPlacement3D pl1Hole(MbCartPoint3D(0, 0, 0));
		pl1Hole.Rotate(MbAxis3D(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, 1, 0))), 0);
		pl1Hole.Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, 12.5, 5)));
		BorerValues params1;
		params1.type = BorerValues::bt_SimpleCylinder;

		params1.diameter = 15;

		params1.depth = 10;

		params1.down = true;

		::HoleSolid(pSolid1, cm_Copy, pl1Hole, params1, hole1Names, pHole);
	}

	//Объединение тел
	MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone, 0);
	MbBooleanFlags flagsBool;
	flagsBool.InitBoolean(true);
	flagsBool.SetMergingFaces(true);
	flagsBool.SetMergingEdges(true);

	MbSolid* pSolidd = NULL;
	::BooleanResult(*pBlockHole, cm_Copy, *pHole, cm_Copy, bo_Union,
		flagsBool, operBoolNames, pSolidd);

	//Сопряжения    
	MbSNameMaker filletNames(ct_FilletSolid, MbSNameMaker::i_SideNone, 0);

	//Указание значений параметров операции скругления ребер
	SmoothValues paramss;
	// Радиусы кривизны на двух скругляемых поверхностях
	paramss.distance1 = 3;
	paramss.distance2 = 3;
	// Тип сопряжения – скругление по двум радиусам
	paramss.form = st_Fillet;
	// Форма профиля сопряжения - окружность
	paramss.conic = 0;
	// Требуется скруглять только ребра, переданные во входном массиве
	paramss.prolong = false;
	// Способ скругления троек ребер
	paramss.smoothCorner = SmoothValues::ec_uniform;
	// Флаг сохранения кромки – режим сохранения поверхности
	paramss.keepCant = ts_negative;
	// Строгое скругление
	paramss.strict = true;

	//Формирование массива с ребрами для скругления.
	// Запрос всех ребер исходного тела
	RPArray<MbCurveEdge> allEdges(4, 1);
	pSolidd->GetEdges(allEdges);
	// В массив ребер для скругления помещается только одно ребро
	RPArray<MbCurveEdge> initCurves(4, 1);
	initCurves.Add(allEdges[16]);
	initCurves.Add(allEdges[20]);

	//Массив граней для обрезки – в данном примере пустой
	RPArray<MbFace> initBounds(0, 1);

	//Вызов функции скругления ребер.
	// В результате выполняется скругление одного ребра – окружности,
	// по которой в исходном теле соединены цилиндр и пластина.
	MbSolid* pResult = NULL;
	MbResultType ress = ::FilletSolid(*pSolidd, cm_Copy, initCurves, initBounds,
		paramss, filletNames, pResult);

	MbAxis3D axVert(MbVector3D(1, 0, 0));
	// 7) Отображение тела после скругления ребра
	if (ress == rt_Success)
		pResult->Rotate(axVert, M_PI / 2); // вращаем по оси
	pResult->Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, 0, position + 113.8)));

	pResult->SetColor(LIGHTGRAY);
	pAsm->AddItem(*pResult);
	//viewManager->AddObject(Style(1, LIGHTGRAY), pResult);


// Уменьшение счетчиков ссылок динамически созданных объектов ядра
	::DeleteItem(pSolid);
	::DeleteItem(pSolid1);
	::DeleteItem(pHole);
	::DeleteItem(pBlockHole);
	::DeleteItem(pResult);

}
void CreateMainBody(double length)
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

	//show(Style( 1, RGB(255,255,255) ), pSolid6);
	//show( Style( 1, RGB(255,255,255) ), pSolid5);
	//show( Style( 1, RGB(0,0,0) ), pSolid4);
	//show( Style( 1, RGB(0,0,0) ), pSolid3);

	//show( Style( 1, RGB(0,0,0) ), pSolid2);
	pSolid->Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, 0, -31.5)));

	pSolid->SetColor(BLACK);
	pAsm->AddItem(*pSolid);
	//viewManager->AddObject(Style(1, RGB(0, 0, 0)), pSolid);

	//show( Style( 1, RGB(0,0,0) ), pSolid1);


}
void CreateSealHousing()
{
	// Множитель для преобразования угловых значений из градусов в радианы
	const double DEG_TO_RAD = M_PI / 180.0;

	//Создание двумерные точки на осях X и Y
	MbCartPoint p1(7.25 + 8.75, 7);
	MbCartPoint p2(7.75 + 8.75, 7.5);
	MbCartPoint p3(7.75 + 8.75, 17.5);
	MbCartPoint p4(8.75 + 8.75, 17.5);
	MbCartPoint p5(8.75 + 8.75, 23.975);
	MbCartPoint p6(7.75 + 8.75, 24.875);
	MbCartPoint p7(6.85 + 8.75, 24.875);
	MbCartPoint p8(6.85 + 8.75, 20.995);
	MbCartPoint p9(3.25 + 8.75, 20.995);
	MbCartPoint p10(3.25 + 8.75, 24.875);
	MbCartPoint p11(2.25 + 8.75, 24.875);
	MbCartPoint p12(2.25 + 8.75, 22.495);

	MbCartPoint p13(-2.25 + 8.75, 22.495);
	MbCartPoint p14(-2.25 + 8.75, 24.875);
	MbCartPoint p15(-3.25 + 8.75, 24.875);
	MbCartPoint p16(-3.25 + 8.75, 20.995);
	MbCartPoint p17(-6.85 + 8.75, 20.995);
	MbCartPoint p18(-6.85 + 8.75, 24.875);
	MbCartPoint p19(-7.75 + 8.75, 24.875);
	MbCartPoint p20(-8.75 + 8.75, 23.975);
	MbCartPoint p21(-8.75 + 8.75, 17.5);
	MbCartPoint p22(-7.75 + 8.75, 17.5);
	MbCartPoint p23(-7.75 + 8.75, 7.5);
	MbCartPoint p24(-7.25 + 8.75, 7);

	//Динамическое создание объектов отрезков
	MbLineSegment* Seg1 = new MbLineSegment(p1, p2);
	MbLineSegment* Seg2 = new MbLineSegment(p2, p3);
	MbLineSegment* Seg3 = new MbLineSegment(p3, p4);
	MbLineSegment* Seg4 = new MbLineSegment(p4, p5);
	MbLineSegment* Seg5 = new MbLineSegment(p5, p6);
	MbLineSegment* Seg6 = new MbLineSegment(p6, p7);
	MbLineSegment* Seg7 = new MbLineSegment(p7, p8);
	MbLineSegment* Seg8 = new MbLineSegment(p8, p9);
	MbLineSegment* Seg9 = new MbLineSegment(p9, p10);
	MbLineSegment* Seg10 = new MbLineSegment(p10, p11);
	MbLineSegment* Seg11 = new MbLineSegment(p11, p12);
	MbLineSegment* Seg12 = new MbLineSegment(p12, p13);
	MbLineSegment* Seg13 = new MbLineSegment(p13, p14);
	MbLineSegment* Seg14 = new MbLineSegment(p14, p15);
	MbLineSegment* Seg15 = new MbLineSegment(p15, p16);
	MbLineSegment* Seg16 = new MbLineSegment(p16, p17);
	MbLineSegment* Seg17 = new MbLineSegment(p17, p18);
	MbLineSegment* Seg18 = new MbLineSegment(p18, p19);
	MbLineSegment* Seg19 = new MbLineSegment(p19, p20);
	MbLineSegment* Seg20 = new MbLineSegment(p20, p21);
	MbLineSegment* Seg21 = new MbLineSegment(p21, p22);
	MbLineSegment* Seg22 = new MbLineSegment(p22, p23);
	MbLineSegment* Seg23 = new MbLineSegment(p23, p24);
	MbLineSegment* Seg24 = new MbLineSegment(p24, p1);

	//Динамическое создание контура
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
	ptrContour->AddSegment(Seg15);
	ptrContour->AddSegment(Seg16);
	ptrContour->AddSegment(Seg17);
	ptrContour->AddSegment(Seg18);
	ptrContour->AddSegment(Seg19);
	ptrContour->AddSegment(Seg20);
	ptrContour->AddSegment(Seg21);
	ptrContour->AddSegment(Seg22);
	ptrContour->AddSegment(Seg23);
	ptrContour->AddSegment(Seg24);

	// Создание плоскости - она совпадает с плоскостью XY локальной СК
	MbPlacement3D* place = new MbPlacement3D();
	MbPlane* ptrSurface = new MbPlane(*place);

	//Создание образующей для тела вращения
	RPArray<MbContour>* ptrContours = new RPArray<MbContour>();
	ptrContours->Add(ptrContour);

	//объект, в котором хранятся сведения об образующей
	MbSweptData* pCurves;
	pCurves = new MbSweptData(*ptrSurface, *ptrContours);

	// Объект параметров для построения тел вращения.
	RevolutionValues revParms(360 * DEG_TO_RAD, 0, 0);

	//Именователи для операции построения тела вращения и для контуров образующей
	MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames(0, 1, false);

	//Ось вращения для построения тела
	MbAxis3D axis(place->GetAxisX());

	// Вызов функции-утилиты для построения твердого тела вращения
	MbSolid* m_pResSolid = nullptr;
	MbResultType m_bResult = RevolutionSolid(*pCurves, axis, revParms, operNames, cNames, m_pResSolid);

	MbAxis3D axVert(MbVector3D(0, 1, 0));
	// отображение построенного тела
	if (m_bResult == rt_Success)
		m_pResSolid->Rotate(axVert, M_PI / 2);
	m_pResSolid->Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, 0, -5)));

	m_pResSolid->SetColor(BLACK);
	pAsm->AddItem(*m_pResSolid);
	//viewManager->AddObject(Style(1, BLACK), m_pResSolid);


}
void CreateBolt(double X, double Y, double Z = -31.1, int ANGLE = -1)
{
	MbSolid* pCyl = NULL;

	MbSNameMaker namesCyl(1, MbSNameMaker::i_SideNone, 0);

	SArray<MbCartPoint3D> points(3);
	points.Add(MbCartPoint3D(0, 0, 0));
	points.Add(MbCartPoint3D(0, 19.6, 0));
	points.Add(MbCartPoint3D(5.75, 0, 0));

	ElementarySolid(points, et_Cylinder, namesCyl, pCyl);



	//второй цилиндр

	MbSolid* pCyl1 = NULL;
	MbSNameMaker namesCyl1(1, MbSNameMaker::i_SideNone, 0);

	SArray<MbCartPoint3D> points1(3);
	points1.Add(MbCartPoint3D(0, 19.6, 0));
	points1.Add(MbCartPoint3D(0, 27.5, 0));
	points1.Add(MbCartPoint3D(8.1, 19.6, 0));

	ElementarySolid(points1, et_Cylinder, namesCyl1, pCyl1);




	// 2) Построение отверстия в исходном теле
	MbSolid* pBlockHole = NULL;
	{
		// Объект-именователь для операции построения отверстия
		MbSNameMaker holeNames(ct_HoleSolid, MbSNameMaker::i_SideNone, 0);


		// Локальная СК, задающая положение вспомогательного тела - образа отверстия.
		const double DEG_TO_RAD = M_PI / 180.0;
		MbPlacement3D plHole(MbCartPoint3D(0, 0, 0));
		plHole.Rotate(MbAxis3D(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0))),
			90 * DEG_TO_RAD);

		BorerValues params;

		params.type = BorerValues::bt_SimpleCylinder;

		params.diameter = 8;

		params.depth = 28;

		params.down = true;

		::HoleSolid(pCyl, cm_Copy, plHole, params, holeNames, pBlockHole);


	}

	MbSolid* pBlockHole1 = NULL;
	{
		// Объект-именователь для операции построения отверстия
		MbSNameMaker holeNames(ct_HoleSolid, MbSNameMaker::i_SideNone, 0);


		// Локальная СК, задающая положение вспомогательного тела - образа отверстия.
		const double DEG_TO_RAD = M_PI / 180.0;
		MbPlacement3D plHole1(MbCartPoint3D(0, 0, 0));
		plHole1.Rotate(MbAxis3D(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0))),
			90 * DEG_TO_RAD);
		plHole1.Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, 19.6, 0)));
		BorerValues params;

		params.type = BorerValues::bt_SimpleCylinder;

		params.diameter = 8;

		params.depth = 7.9;

		params.down = true;

		::HoleSolid(pCyl1, cm_Copy, plHole1, params, holeNames, pBlockHole1);
	}

	// show(Style(1, LIGHTGRAY), pBlockHole); 
	// show(Style(1, LIGHTGRAY), pBlockHole1); 


	MbPlane* pPlaneXZ = new MbPlane(MbCartPoint3D(0, 27.6, 0), MbVector3D(1, 0, 0),
		MbVector3D(0, 0, 1));


	// Трехмерная кривая "контур на плоскости", которая будет использоваться в качестве
	// образующей для операции выдавливания
	MbSolid* pSh = NULL;

	MbSNameMaker elNames(1, MbSNameMaker::i_SideNone, 0);
	SArray<MbCartPoint3D> pnts(7);
	pnts.Add(MbCartPoint3D(0, 23.6, 4.763));
	pnts.Add(MbCartPoint3D(4.125, 23.6, 2.382));
	pnts.Add(MbCartPoint3D(4.125, 23.6, -2.382));
	pnts.Add(MbCartPoint3D(0, 23.6, -4.763));
	pnts.Add(MbCartPoint3D(-4.125, 23.6, -2.382));
	pnts.Add(MbCartPoint3D(-4.125, 23.6, 2.382));
	pnts.Add(MbCartPoint3D(-4.125, 27.6, 2.382));

	ElementarySolid(pnts, et_Prism, elNames, pSh);

	MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone);

	// Флаги булевой операции: построение замкнутого тела с объединением
	// подобных граней и ребер.
	MbBooleanFlags flagsBool;
	flagsBool.InitBoolean(false);
	flagsBool.SetMergingFaces(true);
	flagsBool.SetMergingEdges(true);

	// Результирующее тело
	MbSolid* pSolid = NULL;
	// Вызов булевой операции для выполнения объединения.
	// Для выполнения вычитания надо вместо типа операции bo_Union указать
	// значение bo_Difference, для пересечения - значение bo_Intersect.
	MbResultType res = ::BooleanResult(*pBlockHole1, cm_Copy, *pBlockHole, cm_Copy, bo_Union, flagsBool, operBoolNames, pSolid);

	// Отображение результирующего тела
	//if ( res == rt_Success )
	  // show(pSolid); 


	MbSNameMaker operBoolNames1(ct_BooleanSolid, MbSNameMaker::i_SideNone, 0);


	// Результирующее тело
	MbSolid* pSolidSh = NULL;
	// Вызов булевой операции для выполнения объединения.
	// Для выполнения вычитания надо вместо типа операции bo_Union указать
	// значение bo_Difference, для пересечения - значение bo_Intersect.
	MbResultType res1 = ::BooleanSolid(*pSolid, cm_Copy, *pSh, cm_Copy, bo_Difference, operBoolNames1, pSolidSh);

	// Отображение результирующего тела
  //  if ( res == rt_Success )
   //     show(pSolidSh); 
 //   show(RED, pSolid); 





	MbSNameMaker chamferNames(ct_FilletSolid, MbSNameMaker::i_SideNone, 0);

	// 3) Указание значений параметров операции построения фасок
	SmoothValues params;
	// Длины катетов фаски
	params.distance1 = 0.5;
	params.distance2 = 0.5;
	// Тип фаски - построение фаски с заданными катетами
	params.form = st_Chamfer;
	// Режим автоматического скругления ребер, гладко стыкующиеся с ребрами
	// из входного массива
	params.prolong = false;
	// Способ скругления троек ребер
	params.smoothCorner = SmoothValues::ec_uniform;

	// 4) Формирование массива с ребрами для скругления.
	// Запрос всех ребер исходного тела
	RPArray<MbCurveEdge> allEdges;
	pSolidSh->GetEdges(allEdges);
	// Массив ребер для скругления
	RPArray<MbCurveEdge> initCurves;

	initCurves.Add(allEdges[22]);

	// 5) Массив граней для обрезки при неоднозначном выполнении метода - пустой
	RPArray<MbFace> initBounds(0, 1);

	// 6) Вызов функции построения фасок
	MbSolid* pResult = NULL;
	MbResultType res5 = ::ChamferSolid(*pSolidSh, cm_Copy, initCurves,
		params, chamferNames, pResult);
	//   if (res5 == rt_Success)
	   //    show(Style(1, LIGHTGRAY), pResult); 



	MbSNameMaker chamferNames1(ct_FilletSolid, MbSNameMaker::i_SideNone, 0);

	// 3) Указание значений параметров операции построения фасок
	SmoothValues params1;
	// Длины катетов фаски
	params1.distance1 = 2;
	params1.distance2 = 2;
	// Тип фаски - построение фаски с заданными катетами
	params1.form = st_Chamfer;
	// Режим автоматического скругления ребер, гладко стыкующиеся с ребрами
	// из входного массива
	params1.prolong = false;
	// Способ скругления троек ребер
	params1.smoothCorner = SmoothValues::ec_uniform;

	// 4) Формирование массива с ребрами для скругления.
	// Запрос всех ребер исходного тела
	RPArray<MbCurveEdge> allEdges1;
	pResult->GetEdges(allEdges1);
	// Массив ребер для скругления
	RPArray<MbCurveEdge> initCurves1;

	initCurves1.Add(allEdges1[24]);

	// 5) Массив граней для обрезки при неоднозначном выполнении метода - пустой
	RPArray<MbFace> initBounds1(0, 1);

	// 6) Вызов функции построения фасок
	MbSolid* pResult1 = NULL;
	MbResultType res6 = ::ChamferSolid(*pResult, cm_Copy, initCurves1,
		params1, chamferNames1, pResult1);
	MbAxis3D axVert(MbVector3D(1, 0, 0));
	pResult1->Rotate(axVert, M_PI / 2 * ANGLE);
	pResult1->Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(X, Y, Z)));

	if (res6 == rt_Success)
		//pResult1->Rotate(axVert, M_PI / 2 );

		pResult1->SetColor(LIGHTGRAY);
	pAsm->AddItem(*pResult1);
	//viewManager->AddObject(Style(1, LIGHTGRAY), pResult1);


	::DeleteItem(pCyl);
	::DeleteItem(pCyl1);
	::DeleteItem(pBlockHole);
	::DeleteItem(pBlockHole1);
	::DeleteItem(pSh);
	::DeleteItem(pSolid);
	::DeleteItem(pSolidSh);
	::DeleteItem(pResult1);
	::DeleteItem(pResult);

}
void CreateSocketHeadLockingCollarInsert()
{
	// Множитель для преобразования угловых значений из градусов в радианы
	const double DEG_TO_RAD = M_PI / 180.0;

	// Локальная СК (по умолчанию совпадает с мировой СК)
	MbPlacement3D pl;

	// Вызов функции для построения образующей (из примера 6)
	RPArray<MbContour> arrContours;
	CreateSketchEgor(arrContours);

	// Отображение образующей (в плоскости XY глобальной СК)


	// Подготовка параметров для вызова функции построения тела вращения.
	// sweptData - объект, в котором хранятся сведения об образующей.
	MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0),
		MbCartPoint3D(0, 1, 0));
	MbSweptData sweptData(*pPlaneXY, arrContours);

	// Объект параметров для операции построения тела вращения.
	// Первые два параметра конструктора задают углы вращения в прямом и обратном
	// направлении (по нормали к образующей или противоположно этой нормали).
	// В данном примере вращение осуществляется на 120 градусов в прямом направлении.
	// Третий параметр задает форму топологии твердого тела.
	// При s = 0 строится тело с топологией сферы, при s = 1 - с топологией тора.
	// Если образующая - незамкнутая кривая, и ось вращения лежит в плоскости кривой,
	// то при s = 0 при построении образующая будет автоматически продлена до оси
	// вращения. В данном примере различий между значениями s нет, т.к. образующая
	// имеет вид замкнутого контура.
	RevolutionValues revParms(360 * DEG_TO_RAD, 0, 0);

	// Следующая строка задает построение тела с незамкнутой оболочкой ("пустого").
	// revParms.shellClosed = false;
	// Задание толщины стенки тела
	// revParms.thickness1 = 8;

	// Именователи для операции построения тела вращения и для контуров образующей
	MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames(0, 1, false);

	// Ось вращения для построения тела:
	// ось Y мировой СК смещается на -50 единиц вдоль оси X.
	MbAxis3D axis(pl.GetAxisX());


	// Вызов функции-утилиты для построения твердого тела вращения
	MbSolid* pSolid = nullptr;
	MbResultType res = ::RevolutionSolid(sweptData, axis, revParms,
		operNames, cNames, pSolid);

	// Отображение построенного тела

	MbPlacement3D pl1;
	RPArray<MbContour> arrContours1;
	CreateSketchEgor2(arrContours1);

	//КОНТУР ЭСКИЗА НЕ НУЖЕН В СБОРКЕ
	//for (int i = 0; i < arrContours1.size(); i++)
		//viewManager->AddObject(Style(1, RGB(0, 0, 255)), arrContours1[i], &pl1);

	MbPlane* pPlaneYZ = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, 0, 1), MbCartPoint3D(0, 1, 0));
	// Объект, хранящий параметры образующей
	MbSweptData sweptData1(*pPlaneYZ, arrContours1);
	// Направляющий вектор для операции выдавливания
	MbVector3D dir(1, 0, 0);

	const double HEIGHT_FORWARD = 10, HEIGHT_BACKWARD = 0;
	const double ANGLE_FORWARD_DEGREE = 0;
	ExtrusionValues extrusionParams(HEIGHT_FORWARD, HEIGHT_BACKWARD);
	// Указание уклона для выдавливания в прямом направлении
	extrusionParams.side1.rake = ANGLE_FORWARD_DEGREE * M_PI / 180;

	MbSNameMaker operNames1(1, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames1(0, 1, false);

	MbSolid* pSolid1 = nullptr;
	MbResultType res1 = ::ExtrusionSolid(sweptData1, dir, nullptr, nullptr, false, extrusionParams, operNames1, cNames1, pSolid1);

	// Отображение построенного тела
   // Уменьшение счетчиков ссылок динамически созданных объектов ядра



	// Именователь граней для построения тела с помощью булевой операции 
	MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone);

	// Флаги булевой операции: построение замкнутого тела с объединением
	// подобных граней и ребер.
	MbBooleanFlags flagsBool;
	flagsBool.InitBoolean(true);
	flagsBool.SetMergingFaces(true);
	flagsBool.SetMergingEdges(true);

	// Результирующее тело
	MbSolid* pSolid2 = NULL;
	// Вызов булевой операции для выполнения объединения.
	// Для выполнения вычитания надо вместо типа операции bo_Union указать
	// значение bo_Difference, для пересечения - значение bo_Intersect.
	MbResultType res2 = ::BooleanResult(*pSolid, cm_Copy, *pSolid1, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid2);

	MbAxis3D axVert(MbVector3D(0, 1, 0));
	MbAxis3D axVertX(MbVector3D(1, 0, 0));
	// Отображение результирующего тела
	if (res2 == rt_Success) {
		pSolid2->Rotate(axVert, M_PI / 2);
		pSolid2->Rotate(axVertX, M_PI);
		pSolid2->Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, 0, -54)));

		pSolid2->SetColor(LIGHTGRAY);
		pAsm->AddItem(*pSolid2);
		//viewManager->AddObject(Style(1, LIGHTGRAY), pSolid2);
	}
	// Уменьшение счетчиков ссылок динамических объектов ядра
	::DeleteItem(pSolid1);

	::DeleteItem(pSolid);
	::DeleteItem(pSolid2);
}
void CreateClampingBar(double X, double Y, double length)
{
	// Множитель для преобразования угловых значений из градусов в радианы
	const double DEG_TO_RAD = M_PI / 180.0;

	// Локальная СК (по умолчанию совпадает с мировой СК)
	MbPlacement3D pl;

	// Вызов функции для построения образующей (из примера 6)
	RPArray<MbContour> arrContours;
	CreateSketchEgor3(arrContours, length);

	// Подготовка параметров для вызова функции построения тела вращения.
	// sweptData - объект, в котором хранятся сведения об образующей.
	MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, 0, 1),
		MbCartPoint3D(0, 1, 0));
	MbSweptData sweptData(*pPlaneXY, arrContours);

	// Объект параметров для операции построения тела вращения.
	// Первые два параметра конструктора задают углы вращения в прямом и обратном
	// направлении (по нормали к образующей или противоположно этой нормали).
	// В данном примере вращение осуществляется на 120 градусов в прямом направлении.
	// Третий параметр задает форму топологии твердого тела.
	// При s = 0 строится тело с топологией сферы, при s = 1 - с топологией тора.
	// Если образующая - незамкнутая кривая, и ось вращения лежит в плоскости кривой,
	// то при s = 0 при построении образующая будет автоматически продлена до оси
	// вращения. В данном примере различий между значениями s нет, т.к. образующая
	// имеет вид замкнутого контура.
	RevolutionValues revParms(360 * DEG_TO_RAD, 0, 0);

	// Следующая строка задает построение тела с незамкнутой оболочкой ("пустого").
	// revParms.shellClosed = false;
	// Задание толщины стенки тела
	// revParms.thickness1 = 8;

	// Именователи для операции построения тела вращения и для контуров образующей
	MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames(0, 1, false);

	// Ось вращения для построения тела:
	// ось Y мировой СК смещается на -50 единиц вдоль оси X.
	MbAxis3D axis(pl.GetAxisZ());


	// Вызов функции-утилиты для построения твердого тела вращения
	MbSolid* pSolid = nullptr;
	MbResultType res = ::RevolutionSolid(sweptData, axis, revParms,
		operNames, cNames, pSolid);

	// Отображение построенного тела
	MbAxis3D axVert(MbVector3D(0, 1, 0));
	//pSolid->Rotate(axVert, -M_PI / 2);
	pSolid->Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(X, Y, -49.525)));
	if (res == rt_Success) {
		pSolid->SetColor(BROWN);
		pAsm->AddItem(*pSolid);
		//viewManager->AddObject(Style(1, BROWN), pSolid);
	}


	// Уменьшение счетчиков ссылок динамических объектов ядра
	::DeleteItem(pSolid);

}
void CreateTopGuide(double position) {

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
	CreateSketchSASHA(arrContours);
	RPArray<MbContour> arrContours2;
	CreateSketchSASHA2(arrContours2);
	RPArray<MbContour> arrContours3;
	CreateSketchSASHA3(arrContours3);
	RPArray<MbContour> arrContours4;
	CreateSketchSASHA4(arrContours4);
	RPArray<MbContour> arrContours5;
	CreateSketchSASHA5(arrContours5);
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
}
void CreateBrassCollar() {
	// Множитель для преобразования угловых значений из градусов в радианы
	const double DEG_TO_RAD = M_PI / 180.0;

	// Локальная СК (по умолчанию совпадает с мировой СК)
	MbPlacement3D pl;

	// Вызов функции для построения образующей (из примера 6)
	RPArray<MbContour> arrContours;
	CreateSketchSergey1(arrContours);


	// Подготовка параметров для вызова функции построения тела вращения.
	// sweptData - объект, в котором хранятся сведения об образующей.
	MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0),
		MbCartPoint3D(0, 1, 0));
	MbSweptData sweptData(*pPlaneXY, arrContours);

	// Объект параметров для операции построения тела вращения.
	// Первые два параметра конструктора задают углы вращения в прямом и обратном
	// направлении (по нормали к образующей или противоположно этой нормали).
	// В данном примере вращение осуществляется на 120 градусов в прямом направлении.
	// Третий параметр задает форму топологии твердого тела.
	// При s = 0 строится тело с топологией сферы, при s = 1 - с топологией тора.
	// Если образующая - незамкнутая кривая, и ось вращения лежит в плоскости кривой,
	// то при s = 0 при построении образующая будет автоматически продлена до оси
	// вращения. В данном примере различий между значениями s нет, т.к. образующая
	// имеет вид замкнутого контура.
	RevolutionValues revParms(360 * DEG_TO_RAD, 0, 0);

	// Следующая строка задает построение тела с незамкнутой оболочкой ("пустого").
	// revParms.shellClosed = false;
	// Задание толщины стенки тела
	// revParms.thickness1 = 8;

	// Именователи для операции построения тела вращения и для контуров образующей
	MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames(0, 1, false);

	// Ось вращения для построения тела:
	// ось Y мировой СК смещается на -50 единиц вдоль оси X.
	MbAxis3D axis(pl.GetAxisX());


	// Вызов функции-утилиты для построения твердого тела вращения
	MbSolid* pSolid = nullptr;
	MbResultType res = ::RevolutionSolid(sweptData, axis, revParms,
		operNames, cNames, pSolid);

	// Отображение построенного тела
	MbAxis3D axVert(MbVector3D(0, 1, 0));
	pSolid->Rotate(axVert, M_PI / 2);
	pSolid->Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, 0, 27)));
	if (res == rt_Success) {
		pSolid->SetColor(LIGHTGRAY);
		pAsm->AddItem(*pSolid);
		//viewManager->AddObject(Style(1, LIGHTGRAY), pSolid);
	}



	// Уменьшение счетчиков ссылок динамических объектов ядра
	::DeleteItem(pSolid);
}
void CreateORing(double Z) {

	MbPlacement3D pl;

	// Центр окружностей и дуг в локальной СК
	MbCartPoint cnt(0, 22.575);
	// Построение окружности по центру и радиусу
	const double RAD1 = 1.325;
	MbArc* circle1 = new MbArc(cnt, RAD1);
	MbContour* pContour = new MbContour();
	pContour->AddSegment(circle1);
	// Множитель для преобразования угловых значений из градусов в радианы
	const double DEG_TO_RAD = M_PI / 180.0;

	RPArray<MbContour> arrContours;
	arrContours.push_back(pContour);
	// Подготовка параметров для вызова функции построения тела вращения.

	MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));
	MbSweptData sweptData(*pPlaneXY, arrContours);

	// Объект параметров для операции построения тела вращения.
	// Первые два параметра конструктора задают углы вращения в прямом и обратном
	// направлении (по нормали к образующей или противоположно этой нормали).
	// В данном примере вращение осуществляется на 120 градусов в прямом направлении.
	// Третий параметр задает форму топологии твердого тела.
	// При s = 0 строится тело с топологией сферы, при s = 1 - с топологией тора.
	// Если образующая - незамкнутая кривая, и ось вращения лежит в плоскости кривой,
	// то при s = 0 при построении образующая будет автоматически продлена до оси
	// вращения. В данном примере различий между значениями s нет, т.к. образующая
	// имеет вид замкнутого контура.
	RevolutionValues revParms(360 * DEG_TO_RAD, 0, 0);



	// Именователи для операции построения тела вращения и для контуров образующей
	MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames(0, 1, false);

	// Ось вращения для построения тела:
	// ось Y мировой СК смещается на -50 единиц вдоль оси X.
	MbAxis3D axis(pl.GetAxisX());

	// Вызов функции-утилиты для построения твердого тела вращения
	MbSolid* pSolid = nullptr;
	MbResultType res = ::RevolutionSolid(sweptData, axis, revParms, operNames, cNames, pSolid);

	// Отображение построенного тела
	MbAxis3D axVert(MbVector3D(0, 1, 0));
	pSolid->Rotate(axVert, -M_PI / 2);
	pSolid->Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, 0, Z)));

	pSolid->SetColor(LIGHTGRAY);
	pAsm->AddItem(*pSolid);
	//viewManager->AddObject(Style(1, LIGHTGRAY), pSolid);


	::DeleteItem(circle1);
	::DeleteItem(pSolid);
}

void CreateShaft(double start, double length, double radius) {
	// Именователь граней «по умолчанию»
	MbSNameMaker names(1, MbSNameMaker::i_SideNone, 0);

	// Массив опорных точек для построения цилиндра
	SArray<MbCartPoint3D> points(3);

	//double start = 0;
	//double lenght = 366.8;
	//double radius = 10;

	// Локальная СК цилиндра смещена на 50 единиц по оси Y мировой СК
	points.Add(MbCartPoint3D(0, 0, start));
	// Направление оси Z локальной СК совпадает с направлением
	// оси Z мировой СК, высота цилиндра равна 10 единицам
	points.Add(MbCartPoint3D(0, 0, start + length));
	// Направление оси X локальной СК совпадает с направлением оси X
	// мировой СК, радиус цилиндра равен 10 единицам
	points.Add(MbCartPoint3D(radius, 0, start));
	// Построение элементарного тела – цилиндра - по трем точкам
	MbSolid* pCyl = NULL;
	::ElementarySolid(points, et_Cylinder, names, pCyl);
	// Отображение построенного тела
	if (pCyl) {
		///непонятки с цветом
		pCyl->SetColor(LIGHTBLUE);
		pAsm->AddItem(*pCyl);
		//viewManager->AddObject(TestVariables::SOLID_Style, pCyl);
	}

	// Уменьшение счетчика ссылок динамически созданного объекта ядра
	//::DeleteItem(pCyl);
}








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
	CreateShaft(start = 0, length = lendif + 66.8, radius = 10 + raddif);
	CreateShaft(start =  lendif + 66.8, length = 9, radius = 9.4 + raddif);
	CreateShaft(start = lendif + 75.8, length = 3.5, radius = 6.9 + raddif);
	CreateShaft(start =  lendif + 79.3, length = 28, radius = 8 + raddif);
	// zero x , y , z 
	CreateShaft(start = 0, length = -5, radius = 9.2 + raddif);
	CreateShaft(start = -5, length = -17.5, radius = 7 + raddif);
	CreateShaft(start = -22.5, length = -3.2, radius = 6.15 + raddif);
	CreateShaft(start = -25.7, length = -16, radius = 7 + raddif);
	//Shaft

	CreateBase(); // Зарубин
	CreateShaftPivot(lendif); // Васинкина
	//CreateMainBody(lendif); // Балобанов
	CreateSealHousing(); // Гарник
	CreateBolt(DD, DD); // Фукина
	CreateBolt(DD, -DD); // 
	CreateBolt(-DD, -DD); // 
	CreateBolt(-DD, DD); //
	CreateBolt(-DD, DD, lendif + 16.05, 1); // 
	CreateBolt(DD, DD, lendif + 16.05, 1); // 
	CreateBolt(DD, -DD, lendif + 16.05, 1); //
	CreateBolt(-DD, -DD, lendif + 16.05, 1); // 
	CreateSocketHeadLockingCollarInsert(); // Приходько
	CreateClampingBar(DD, DD, lendif); // Приходько 
	CreateClampingBar(DD, -DD, lendif); // 
	CreateClampingBar(-DD, -DD, lendif); // 
	CreateClampingBar(-DD, DD, lendif); // 
	CreateTopGuide(lendif); // Фукина
	CreateBrassCollar(); // Козырь
	CreateORing(-19); // 
	CreateORing(-8.5); // 

	return pAsm;
}
