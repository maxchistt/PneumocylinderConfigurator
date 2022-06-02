#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;

void ParametricModelCreator::CreateShaft(MbAssembly* pAsm, double start, double length, double radius) {
	// ����������� ������ ��� ����������
	MbSNameMaker names(1, MbSNameMaker::i_SideNone, 0);

	// ������ ������� ����� ��� ���������� ��������
	SArray<MbCartPoint3D> points(3);

	// ��������� �� �������� ������� �� 50 ������ �� ��� Y ������� ��
	points.Add(MbCartPoint3D(0, 0, start));
	// ����������� ��� Z ��������� �� ��������� � ������������
	// ��� Z ������� ��, ������ �������� ����� 10 ��������
	points.Add(MbCartPoint3D(0, 0, start + length));
	// ����������� ��� X ��������� �� ��������� � ������������ ��� X
	// ������� ��, ������ �������� ����� 10 ��������
	points.Add(MbCartPoint3D(radius, 0, start));
	// ���������� ������������� ���� � �������� - �� ���� ������
	MbSolid* pCyl = NULL;
	::ElementarySolid(points, et_Cylinder, names, pCyl);
	// ����������� ������������ ����
	if (pCyl) {
		///��������� � ������
		pCyl->SetColor(LIGHTBLUE);
		pAsm->AddItem(*pCyl);
	}

	// ���������� �������� ������ ����������� ���������� ������� ����
	::DeleteItem(pCyl);
}