#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;

void ParametricModelCreator::CreateShaft(MbAssembly* pAsm, double start, double length, double radius) {
	// Именователь граней «по умолчанию»
	MbSNameMaker names(1, MbSNameMaker::i_SideNone, 0);

	// Массив опорных точек для построения цилиндра
	SArray<MbCartPoint3D> points(3);

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
	}

	// Уменьшение счетчика ссылок динамически созданного объекта ядра
	::DeleteItem(pCyl);
}