#include "BuildTestMathModel.h"

void CreateTestSketch(RPArray<MbContour>& _arrContours)
{
	// �������� ������� ����� ��������, � �������� � ���������� ��������� ����������.
	// ������ ������� - 8 ����� ��� ����� ����� ������� ��������� ����������.
	SArray<MbCartPoint> arrPnts(8);
	arrPnts.Add(MbCartPoint(0, 0));
	arrPnts.Add(MbCartPoint(50, 0));
	arrPnts.Add(MbCartPoint(50, 50));
	arrPnts.Add(MbCartPoint(0, 50));
	// ���������� ������ ������� �������� ������� �� ������
	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
	MbContour* pContourPolyline = NULL;
	// ������� ���������� � �������������� ������� FilletPolyContour
	::FilletPolyContour(pPolyline, 5, false, arrPnts[4], pContourPolyline);
	// ������� �������� �����, � ������� ����� ���������� ���������� � ������
	// ���������� ����� ����� ��� ���������� � �������������� ������� FilletTwoSegments
	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;
	// ���������� ����������
	pContourPolyline->FilletTwoSegments(idxSideRight1, 5);
	pContourPolyline->FilletTwoSegments(idxSideRight2, 5);
	pContourPolyline->FilletTwoSegments(idxSideRight3, 5);
	_arrContours.push_back(pContourPolyline);
}

MbAssembly* createTestAssemblyModel()
{
	// ��������� �� (�� ��������� ��������� � ������� ��)
	MbPlacement3D pl;
	// �������� ���������� ��� ���� ������������
	RPArray<MbContour> arrContours;
	CreateTestSketch(arrContours);
	// ����������� ���������� (� ��������� XY ���������� ��)

	// ���������� ���� ������������
	// ���������� ����������� �� ��������� XY ���������� ��.
	// ������ ���������: ������-��������� ������ ����������� �����������,
	// ��������� �� ���������� �������������� � �������-������� ���� �����
	// ������ �� ������ �������.
	MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0),
		MbCartPoint3D(1, 0, 0),
		MbCartPoint3D(0, 1, 0));
	// ������, �������� ��������� ����������
	MbSweptData sweptData(*pPlaneXY, arrContours);
	// ������������ ������ ��� �������� ������������
	MbVector3D dir(0, 0, -1);
	// ��������� �������� ������������, �������� �������� ���� ��� ���������� � ������
	// � � �������� ����������� ����� (������� ������������ � �����).
	const double HEIGHT_FORWARD = 60.0, HEIGHT_BACKWARD = 30.0;
	const double ANGLE_FORWARD_DEGREE = 15.0;
	ExtrusionValues extrusionParams(HEIGHT_FORWARD, HEIGHT_BACKWARD);
	// �������� ������ ��� ������������ � ������ �����������
	extrusionParams.side1.rake = ANGLE_FORWARD_DEGREE * M_PI / 180.0;
	// ����������� ��������� ������ �������� ���� � �������� ����������
	MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames(0, 1, false);
	// ����� �������-������� ��� ���������� �������� ���� ������������
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

	// ���������� ��������� ������ ����������� ��������� �������� ����
	::DeleteItem(pPlaneXY);
	::DeleteItem(pSolid);
	::DeleteItem(pSolid2);

	return pAsm;
}
