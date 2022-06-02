#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;

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
	::DeleteItem(pPolyline);
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
	::DeleteItem(pPolyline);
}

void ParametricModelCreator::CreateSocketHeadCollar(MbAssembly* pAsm)
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