#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;

void CreateSketch(RPArray<MbContour>* ptrContours, double SqureSize ,double diamMain)
{
	// �������� ������� ����� ��������, � �������� � ���������� ��������� ����������.
	// ������ ������� - 8 ����� ��� ����� ����� ������� ��������� ����������.
	SArray<MbCartPoint> arrPnts(4);
	arrPnts.Add(MbCartPoint(0, 0));
	arrPnts.Add(MbCartPoint(SqureSize, 0));
	arrPnts.Add(MbCartPoint(SqureSize, SqureSize));
	arrPnts.Add(MbCartPoint(0, SqureSize));

	//���������� ����������
	int corner1;	
	if (diamMain <= 50) { corner1 = 6; }
	else if (diamMain <= 60) { corner1 = 8; }
	else { corner1 = 10; };

	// ���������� ������ ������� �������� ������� �� ������
	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
	MbContour* pContourPolyline = nullptr;
	::FilletPolyContour(pPolyline, corner1, false, arrPnts[0], pContourPolyline);

	
	// ������� �������� �����, � ������� ����� ���������� ���������� � ������
	// ���������� ����� ����� ��� ���������� � �������������� ������� FilletTwoSegments
	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;

	// ���������� ����������
	pContourPolyline->FilletTwoSegments(idxSideRight1, corner1);
	pContourPolyline->FilletTwoSegments(idxSideRight2, corner1);
	pContourPolyline->FilletTwoSegments(idxSideRight3, corner1);

	ptrContours->Add(pContourPolyline);

	::DeleteItem(pPolyline);

}
void CreateSketch2(RPArray<MbContour>* ptrContours2, double SqureSize , double diamMain, double ratio)
{
	//����������� ��������� ����������� �� �����

	double ratioSquare = 0.308;
	double SquareCenter = SqureSize* ratioSquare;
	double corner1 = 6;
	if (ratio >= 1) {
		SquareCenter = 20;
		corner1 = 10.5;
	}

	SArray<MbCartPoint> arrPnts2(4);
	arrPnts2.Add(MbCartPoint(SqureSize, SqureSize));
	arrPnts2.Add(MbCartPoint(SqureSize - SquareCenter, SqureSize));
	arrPnts2.Add(MbCartPoint(SqureSize - SquareCenter, SqureSize - SquareCenter));
	arrPnts2.Add(MbCartPoint(SqureSize, SqureSize - SquareCenter));

	MbPolyline* pPolyline2 = new MbPolyline(arrPnts2, true);
	MbContour* pContourPolyline2 = nullptr;

	//���������� ����������
	

	// ������� ���������� � �������������� ������� FilletPolyContour
	::FilletPolyContour(pPolyline2, corner1, false, arrPnts2[2], pContourPolyline2);


	ptrContours2->Add(pContourPolyline2);
	::DeleteItem(pPolyline2);
}
void CreateSketch3(RPArray<MbContour>* ptrContours3, double SqureSize , double diamMain)
{
	//SecondScetch
	double ratioSquareW = SqureSize * 0.23;
	double ratioSquareH = SqureSize * 0.19;
	SArray<MbCartPoint> arrPnts(4);
	arrPnts.Add(MbCartPoint((SqureSize / 2) + ratioSquareW / 2, -0));
	arrPnts.Add(MbCartPoint((SqureSize / 2) + ratioSquareW / 2, ratioSquareH));
	arrPnts.Add(MbCartPoint((SqureSize / 2) - ratioSquareW / 2, ratioSquareH));
	arrPnts.Add(MbCartPoint((SqureSize / 2) - ratioSquareW / 2, -0));

	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
	MbContour* pContourPolyline = nullptr;

	//���������� ����������
	int corner1;
	if (diamMain <= 50) { corner1 = 3; }
	else if (diamMain <= 60) { corner1 = 4; }
	else { corner1 = 5; };

	// ������� ���������� � �������������� ������� FilletPolyContour
	::FilletPolyContour(pPolyline, 0, false, arrPnts[3], pContourPolyline);

	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;

	pContourPolyline->FilletTwoSegments(idxSideRight1, corner1);
	pContourPolyline->FilletTwoSegments(idxSideRight2, corner1);
	//pContourPolyline->FilletTwoSegments(idxSideRight3, 0);

	ptrContours3->Add(pContourPolyline);
	::DeleteItem(pPolyline);
}
void CreateSketch4(RPArray<MbContour>* ptrContours4, double SqureSize, double diamMain)
{
	//SecondScetch
	double ratioSquareW = SqureSize * 0.23;
	double ratioSquareH = SqureSize * 0.19;
	SArray<MbCartPoint> arrPnts(4);
	arrPnts.Add(MbCartPoint(SqureSize, SqureSize / 2 - ratioSquareW / 2));
	arrPnts.Add(MbCartPoint(SqureSize, SqureSize / 2 + ratioSquareW / 2));
	arrPnts.Add(MbCartPoint(SqureSize - ratioSquareH, SqureSize / 2 + ratioSquareW / 2));
	arrPnts.Add(MbCartPoint(SqureSize - ratioSquareH, SqureSize / 2 - ratioSquareW / 2));

	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
	MbContour* pContourPolyline = nullptr;

	//���������� ����������
	int corner1;
	if (diamMain <= 50) { corner1 = 3; }
	else if (diamMain <= 60) { corner1 = 4; }
	else { corner1 = 5; };

	// ������� ���������� � �������������� ������� FilletPolyContour
	::FilletPolyContour(pPolyline, corner1, false, arrPnts[3], pContourPolyline);

	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;

	pContourPolyline->FilletTwoSegments(idxSideRight1, 0);
	pContourPolyline->FilletTwoSegments(idxSideRight2, corner1);
	//pContourPolyline->FilletTwoSegments(idxSideRight3, 0);

	ptrContours4->Add(pContourPolyline);
	::DeleteItem(pPolyline);
}
void CreateSketch5(RPArray<MbContour>* ptrContours5, double SqureSize, double diamMain , double ratio)
{
	double ratioSquareH = SqureSize * 0.19;
	double width = (SqureSize - ratioSquareH * 2) / 2;
	double high = 33.75 * ratio;
	//SecondScetch
	SArray<MbCartPoint> arrPnts(4);
	arrPnts.Add(MbCartPoint(width + SqureSize / 2, 0));
	arrPnts.Add(MbCartPoint(width + SqureSize / 2, -high));
	arrPnts.Add(MbCartPoint(-width + SqureSize / 2, -high));
	arrPnts.Add(MbCartPoint(-width + SqureSize / 2, 0));

	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
	MbContour* pContourPolyline = nullptr;

	//���������� ����������
	int corner1;
	if (diamMain <= 50) { corner1 = 16; }
	else if (diamMain <= 60) { corner1 = 16; }
	else { corner1 = 16; };

	// ������� ���������� � �������������� ������� FilletPolyContour//16
	::FilletPolyContour(pPolyline, 0, false, arrPnts[0], pContourPolyline);

	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;

	pContourPolyline->FilletTwoSegments(idxSideRight1, corner1);
	pContourPolyline->FilletTwoSegments(idxSideRight2, corner1);
	//pContourPolyline->FilletTwoSegments(idxSideRight3, 0);

	ptrContours5->Add(pContourPolyline);
	::DeleteItem(pPolyline);
}
void CreateSketch6(RPArray<MbContour>* ptrContours6, double SqureSize, double diamMain , double ratio)
{
	double ratioSquareW = SqureSize * 0.23;
	//SecondScetch
	SArray<MbCartPoint> arrPnts(6);

	arrPnts.Add(MbCartPoint(SqureSize / 2 - ratioSquareW / 2, (3 + 8.9) * ratio));
	arrPnts.Add(MbCartPoint(SqureSize / 2 - ratioSquareW / 2, 0));
	arrPnts.Add(MbCartPoint(SqureSize / 2 + ratioSquareW / 2, 0));
	arrPnts.Add(MbCartPoint(SqureSize / 2 + ratioSquareW / 2, 3 * ratio));
	arrPnts.Add(MbCartPoint(SqureSize / 2 - ratioSquareW / 2 + 4 * ratio, 3 * ratio));
	arrPnts.Add(MbCartPoint(SqureSize / 2 - ratioSquareW / 2 + 4 * ratio, (3 + 8.9) * ratio));
	//arrPnts.Add(MbCartPoint(25.1+2, 3+8.9));


	MbPolyline* pPolyline = new MbPolyline(arrPnts, false);
	MbCartPoint arrcenter(SqureSize / 2 - ratioSquareW / 2 + 2 * ratio, (3 + 8.9) * ratio);
	const double RAD = 2 * ratio;
	MbArc* pArc = new MbArc(arrcenter, RAD, arrPnts[5], arrPnts[0], 1);

	MbContour* pContourPolyline = new MbContour(*pPolyline, true);
	pContourPolyline->AddSegment(pArc);

	size_t segmentsCount = pContourPolyline->GetSegmentsCount(); // 2
	double tMin = pContourPolyline->GetTMin(); // 0.0
	double tMax = pContourPolyline->GetTMax(); // 10.14159
	// �������� IsSmoothConnected - ������ ��� ������������� ������� ����� �� �������
	bool isSmooth = pContourPolyline->IsSmoothConnected(0.001); // false
	double length = pContourPolyline->CalculateLength(tMin, tMax); // 302.83
	bool isClosed = pContourPolyline->IsClosedContinuousC0(); // true
	bool isCurvilinear = pContourPolyline->IsAnyCurvilinear(); // true

	ptrContours6->Add(pContourPolyline);
	::DeleteItem(pPolyline);
}
void CreateSketch7(RPArray<MbContour>* ptrContours7, double SqureSize, double diamMain, double ratio)
{
	//SecondScetch
	SArray<MbCartPoint> arrPnts(4);
	arrPnts.Add(MbCartPoint(SqureSize / 2 - 15 * ratio / 2, -5 * ratio));
	arrPnts.Add(MbCartPoint(SqureSize / 2 - 15 * ratio / 2, 0));
	arrPnts.Add(MbCartPoint(SqureSize / 2 - 15 * ratio / 2 - 5 * ratio, 0));
	//arrPnts.Add(MbCartPoint(SqureSize/2-15/2-5, -5));


	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
	MbCartPoint arrcenter(SqureSize / 2 - 15 * ratio / 2 - 5 * ratio, -5 * ratio);

	MbContour* pContourPolyline = new MbContour(*pPolyline, true);

	ptrContours7->Add(pContourPolyline);
	::DeleteItem(pPolyline);
}

//������� �� �������� ������� �����
void ParametricModelCreator::CreateBase(MbAssembly* pAsm, double ratio = 1)
{
	const double diamMain_STD = 50;
	double diamMain = diamMain_STD * ratio;

	const double shaftCollarRad_STD = 10;
	const double diamIn_STD = shaftCollarRad_STD * 2;
	double diamIn = diamIn_STD * ratio;

	// ��������� ��� �������������� ����� �� ��������� � ��������� ����.
	const double DEG_TO_RAD = M_PI / 180.0;
	const double SqureSize = diamMain + 15.2;
	double ratioSquareH = SqureSize * 0.19;
	double width = (SqureSize - ratioSquareH * 2);
	/*������������
	bo_Union - �����������
	bo_Difference - ��������
	*/
	// ��������� �� (�� ��������� ��������� � ������� ��)
	MbPlacement3D pl;
	// �������� ���������� ��� ���� ������������
	RPArray<MbContour>* ptrContours = new RPArray<MbContour>();
	CreateSketch(ptrContours, SqureSize , diamMain);

	RPArray<MbContour>* ptrContours2 = new RPArray<MbContour>();
	CreateSketch2(ptrContours2, SqureSize, diamMain, ratio);

	RPArray<MbContour>* ptrContours3 = new RPArray<MbContour>();
	CreateSketch3(ptrContours3, SqureSize, diamMain);

	RPArray<MbContour>* ptrContours4 = new RPArray<MbContour>();
	CreateSketch4(ptrContours4, SqureSize, diamMain);

	RPArray<MbContour>* ptrContours5 = new RPArray<MbContour>();
	CreateSketch5(ptrContours5, SqureSize, diamMain, ratio);

	RPArray<MbContour>* ptrContours6 = new RPArray<MbContour>();
	CreateSketch6(ptrContours6, SqureSize, diamMain, ratio);

	RPArray<MbContour>* ptrContours7 = new RPArray<MbContour>();
	CreateSketch7(ptrContours7, SqureSize, diamMain, ratio);
	
	//���������� ��� ������������
	MbBooleanFlags flagsBool;
	flagsBool.InitBoolean(true);
	flagsBool.SetMergingFaces(true);
	flagsBool.SetMergingEdges(true);
	MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone);
	// ����������� ���������� (� ��������� XY ���������� ��)
	//for (int i = 0; i<arrContours2.size(); i++)
		//show(Style(1, LIGHTRED), arrContours2[i], &pl2);
	//for (int i = 0; i<arrContours7.size(); i++)
	//    show(Style(1, BLUE), arrContours7[i], &pl);
	// ���������� ���� ������������
	// ���������� ����������� �� ��������� XY ���������� ��.
	// ������ ���������: ������-��������� ������ ����������� �����������,
	// ��������� �� ���������� �������������� � �������-������� ���� �����
	// ������ �� ������ �������.
	MbPlane* pPlaneXZ = new MbPlane(MbCartPoint3D(0, 0, 0),
		MbCartPoint3D(1, 0, 0),
		MbCartPoint3D(0, 0, 1));
	MbPlane* pPlaneYZ = new MbPlane(MbCartPoint3D(0, 0, 0),
		MbCartPoint3D(0, 1, 0),
		MbCartPoint3D(0, 0, 1));
	MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0),
		MbCartPoint3D(1, 0, 0),
		MbCartPoint3D(0, 1, 0));
	//��������� ��� ����� ����� MbPlane
	MbPlane* pPlaneYZCen = new MbPlane(
		MbCartPoint3D(ratioSquareH, 0, 0),
		MbCartPoint3D(ratioSquareH, 1, 0),
		MbCartPoint3D(ratioSquareH, 0, 1));
	MbPlane* pPlaneXZCen = new MbPlane(
		MbCartPoint3D(0, SqureSize/2 + (7.5 * ratio), 0),
		MbCartPoint3D(1, SqureSize/2 + (7.5 * ratio), 0),
		MbCartPoint3D(0, SqureSize/2 + (7.5 * ratio), 1));
	//�������� ���� ��� ��������������
	MbPlacement3D HorizPlane(
		MbVector3D(1, 0, 0), /* ��� X ��������� �� */
		MbVector3D(0, 0, 1), /* ��� Z ��������� �� */
		MbCartPoint3D(0, SqureSize/2, 0 /* ������ ��������� ��������� �� */));
	MbPlacement3D VerticalPlane(MbVector3D(0, 0, 1), /* ��� Z ��������� �� */
		MbVector3D(0, 1, 0), /* ��� Y ��������� �� */
		MbCartPoint3D(SqureSize/2, 0, 0 /* ������ ��������� ��������� �� */));
	// ������������ ������ ��� �������� ������������
	MbVector3D dirX(1, 0, 0);
	MbVector3D dirY(0, 1, 0);
	MbVector3D dirZ(0, 0, 1);
	// ������, �������� ��������� ����������
	//SweptData ��� 1 ������
	MbSweptData* sweptData;
	sweptData = new MbSweptData(*pPlaneXY, *ptrContours);
	//SweptData ��� 2 ������
	MbSweptData* sweptData2;
	sweptData2 = new MbSweptData(*pPlaneXY, *ptrContours2);
	//SweptData ��� 3 ������
	MbSweptData* sweptData3;
	sweptData3 = new MbSweptData(*pPlaneXY, *ptrContours3);
	//SweptData ��� 4 ������
	MbSweptData* sweptData4;
	sweptData4 = new MbSweptData(*pPlaneXY, *ptrContours4);
	//SweptData ��� 5 ������
	MbSweptData* sweptData5;
	sweptData5 = new MbSweptData(*pPlaneXZCen, *ptrContours5);
	//SweptData ��� 6 ������
	MbSweptData* sweptData6;
	sweptData6 = new MbSweptData(*pPlaneYZ, *ptrContours6);
	//SweptData ��� 7 ������
	MbSweptData* sweptData7;
	sweptData7 = new MbSweptData(*pPlaneYZCen, *ptrContours7);
	// ������������ ������ ��� �������� ������������
	// ��������� �������� ������������, �������� �������� ���� ��� ���������� � ������
	// � � �������� ����������� ����� (������� ������������ � �����).
	const double HEIGHT_FORWARD = 31, HEIGHT_BACKWARD = 0;
	const double HEIGHT_FORWARD2 = 0, HEIGHT_BACKWARD2 = -7.8 ;//31-23.2
	const double HEIGHT_FORWARD3 = 0, HEIGHT_BACKWARD3 = -24.5;//31-6.5
	const double HEIGHT_FORWARD4 = 15 * ratio / 2, HEIGHT_BACKWARD4 = 15 * ratio / 2;
	const double HEIGHT_FORWARD5 = 0, HEIGHT_BACKWARD5 = 15 * ratio;
	const double HEIGHT_FORWARD6 = ratioSquareH, HEIGHT_BACKWARD6 = 0;
	const double HEIGHT_FORWARD7 = width, HEIGHT_BACKWARD7 = 0;
	ExtrusionValues extrusionParams(HEIGHT_FORWARD, HEIGHT_BACKWARD);
	ExtrusionValues extrusionParams2(HEIGHT_FORWARD2, HEIGHT_BACKWARD2);
	ExtrusionValues extrusionParams3(HEIGHT_FORWARD3, HEIGHT_BACKWARD3);
	ExtrusionValues extrusionParams4(HEIGHT_FORWARD4, HEIGHT_BACKWARD4);
	ExtrusionValues extrusionParams5(HEIGHT_FORWARD5, HEIGHT_BACKWARD5);
	ExtrusionValues extrusionParams6(HEIGHT_FORWARD6, HEIGHT_BACKWARD6);
	ExtrusionValues extrusionParams7(HEIGHT_FORWARD7, HEIGHT_BACKWARD7);
	// �������� ������ ��� ������������ � ������ �����������


	// ����������� ��������� ������ �������� ���� � �������� ����������
	MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
	PArray<MbSNameMaker> cNames(0, 1, false);
	// ����������� �������� ���������� ������������� ����
	MbSNameMaker namesElSolid(ct_ElementarySolid, MbSNameMaker::i_SideNone, 0);
	MbSNameMaker namesDupl(ct_DuplicationSolid, MbSNameMaker::i_SideNone, 0);
	// �������� ���������� ��� ������� ���
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
	//4 ��������� � �����������
	MbSolid* pCyl5_Solid = NULL;
	MbSolid* pCyl6_Solid = NULL;
	MbSolid* pCyl7_Solid = NULL;
	MbSolid* pCyl8_Solid = NULL;
	//��������� ������
	MbSolid* pCyl9_Solid = NULL;
	MbSolid* pCyl10_Solid = NULL;
	//���������� ��� � �������
	// �������� ���� �1 - ������� ����� �������
	// ������� ����� ��� ������������� ���� - ��������
	SArray<MbCartPoint3D> cylPnts(3);
	cylPnts.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, 4.5));
	cylPnts.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, 40));
	cylPnts.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2 + diamMain/2, 4.5));
	// ���������� ������������� ���� - ��������
	MbResultType resCyl1 = ::ElementarySolid(cylPnts, et_Cylinder,
		namesElSolid, pCyl1_Solid);
	// �������� ���� �2 - ������� ����� ���������
	// ������� ����� ��� ������������� ���� - ��������
	SArray<MbCartPoint3D> cylPnts2(3);
	cylPnts2.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, 4.5));
	cylPnts2.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, 40));
	cylPnts2.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2 + diamMain/2/2, 4.5));
	// ���������� ������������� ���� - ��������
	MbResultType resCyl2 = ::ElementarySolid(cylPnts2, et_Cylinder,
		namesElSolid, pCyl2_Solid);
	// �������� ���� �3 - ������� � �����
	// ������� ����� ��� ������������� ���� - ��������
	SArray<MbCartPoint3D> cylPnts3(3);
	cylPnts3.Add(MbCartPoint3D(SqureSize / 2, 0, -18.75 * ratio));
	cylPnts3.Add(MbCartPoint3D(SqureSize / 2, 0 + SqureSize * ratio, -18.75 * ratio));
	cylPnts3.Add(MbCartPoint3D(SqureSize / 2, 0 + SqureSize * ratio, -18.75 * ratio + 13.5 * ratio / 2));
	// ���������� ������������� ���� - ��������
	MbResultType resCyl3 = ::ElementarySolid(cylPnts3, et_Cylinder,
		namesElSolid, pCyl3_Solid);
	// �������� ���� �4 - ������� �����
	// ������� ����� ��� ������������� ���� - ��������
	double offsetW = 38.8;
	double offsetW2 = 15.4;
	double offsetR = 12.5;
	double offsetR2 = 22;
	double offsetR3 = 11.4;
	if (ratio < 1) {
		offsetW = 38.8 * ratio;
		offsetW2 = 15.4 * ratio;
		offsetR = 12.5 * ratio;
		offsetR2 = 22 * ratio;
		offsetR3 = 11.4 * ratio;
	}else if (ratio > 1) {
		offsetW = 38.8 * ratio;
		offsetW2 = 15.4 * ratio;
		offsetR = 12.5;
		offsetR2 = 22;
		offsetR3 = 11.4;
	}
	SArray<MbCartPoint3D> cylPnts4(3);
	cylPnts4.Add(MbCartPoint3D(0, offsetW, 18.25));
	cylPnts4.Add(MbCartPoint3D(SqureSize / 2, offsetW, 18.25));
	cylPnts4.Add(MbCartPoint3D(SqureSize / 2, offsetW + offsetR / 2, 18.25));
	// ���������� ������������� ���� - ��������
	MbResultType resCyl4 = ::ElementarySolid(cylPnts4, et_Cylinder,
		namesElSolid, pCyl4_Solid);
	// �������� ���� �5 - ��������� � �����������
	// ������� ����� ��� ������������� ���� - ��������
	SArray<MbCartPoint3D> cylPnts5(3);
	cylPnts5.Add(MbCartPoint3D(9, 9, 0));
	cylPnts5.Add(MbCartPoint3D(9, 9, 31));
	cylPnts5.Add(MbCartPoint3D(9, 9 + 6, 31));
	// ���������� ������������� ���� - ��������
	MbResultType resCyl5 = ::ElementarySolid(cylPnts5, et_Cylinder,
		namesElSolid, pCyl5_Solid);
	// �������� ���� �6 - ������� �����(��������� ������)
	// ������� ����� ��� ������������� ���� - ��������
	SArray<MbCartPoint3D> cylPnts6(3);
	cylPnts6.Add(MbCartPoint3D(0, offsetW, 18.25));
	cylPnts6.Add(MbCartPoint3D(0.2, offsetW, 18.25));
	cylPnts6.Add(MbCartPoint3D(0.2, offsetW + offsetR2 / 2, 18.25));
	// ���������� ������������� ���� - ��������
	MbResultType resCyl6 = ::ElementarySolid(cylPnts6, et_Cylinder,
		namesElSolid, pCyl9_Solid);
	// �������� ���� �7 - �����(��������� ������)
	// ������� ����� ��� ������������� ���� - ��������
	SArray<MbCartPoint3D> cylPnts7(3);
	cylPnts7.Add(MbCartPoint3D(0, offsetW2, 22.7));
	cylPnts7.Add(MbCartPoint3D(1.2, offsetW2, 22.7));
	cylPnts7.Add(MbCartPoint3D(1.2, offsetW2 + offsetR3 / 2, 22.7));
	// ���������� ������������� ���� - ��������
	MbResultType resCyl7 = ::ElementarySolid(cylPnts7, et_Cylinder,
		namesElSolid, pCyl10_Solid);
	//�������� ���� ��� ������
	MbResultType res = ::ExtrusionSolid(*sweptData, dirZ, nullptr, nullptr, false, extrusionParams, operNames, cNames, pSolid);
	MbResultType res16 = ::BooleanResult(*pSolid, cm_Copy, *pCyl1_Solid, cm_Copy, bo_Union, flagsBool, operBoolNames, pSolid);
	MbResultType res17 = ::BooleanResult(*pSolid, cm_Copy, *pCyl2_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	//�������� �� ��� ����������� �� �����
	MbResultType res2 = ::ExtrusionSolid(*sweptData2, dirZ, nullptr, nullptr, false, extrusionParams2, operNames, cNames, pSolid2);
	//�������� �� ��� 3��������������� �� �����
	MbResultType res3 = ::ExtrusionSolid(*sweptData3, dirZ, nullptr, nullptr, false, extrusionParams3, operNames, cNames, pSolid7);
	MbResultType res12 = ::ExtrusionSolid(*sweptData4, dirZ, nullptr, nullptr, false, extrusionParams3, operNames, cNames, pSolid8);

	//�������������� ��������
	MbResultType res10 = ::MirrorSolid(*pSolid2, HorizPlane, operNames, pSolid4);
	MbResultType res4 = ::MirrorSolid(*pSolid2, VerticalPlane, operNames, pSolid5);
	MbResultType res5 = ::MirrorSolid(*pSolid4, VerticalPlane, operNames, pSolid6);
	MbResultType res11 = ::MirrorSolid(*pSolid7, HorizPlane, operNames, pSolid3);
	//�������������� ��������� � �����������
	MbResultType res24 = ::MirrorSolid(*pCyl5_Solid, HorizPlane, operNames, pCyl6_Solid);
	MbResultType res25 = ::MirrorSolid(*pCyl5_Solid, VerticalPlane, operNames, pCyl7_Solid);
	MbResultType res26 = ::MirrorSolid(*pCyl6_Solid, VerticalPlane, operNames, pCyl8_Solid);
	//������������ ����������� �� �����
	MbResultType res6 = ::BooleanResult(*pSolid, cm_Copy, *pSolid2, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res7 = ::BooleanResult(*pSolid, cm_Copy, *pSolid4, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res8 = ::BooleanResult(*pSolid, cm_Copy, *pSolid5, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res9 = ::BooleanResult(*pSolid, cm_Copy, *pSolid6, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	//������������ 3��������������� �� �����
	MbResultType res13 = ::BooleanResult(*pSolid, cm_Copy, *pSolid7, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res14 = ::BooleanResult(*pSolid, cm_Copy, *pSolid3, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res15 = ::BooleanResult(*pSolid, cm_Copy, *pSolid8, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	//�������� �����

	MbResultType res18 = ::ExtrusionSolid(*sweptData5, dirY, nullptr, nullptr, false, extrusionParams5, operNames, cNames, pSolid10);
	//END TEST
	MbResultType res19 = ::BooleanResult(*pSolid10, cm_Copy, *pCyl3_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid10);
	MbResultType res20 = ::BooleanResult(*pSolid, cm_Copy, *pSolid10, cm_Copy, bo_Union, flagsBool, operBoolNames, pSolid);
	MbResultType res21 = ::BooleanResult(*pSolid, cm_Copy, *pCyl4_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	//�������� ������ ����� ������ ��������
	MbResultType res22 = ::ExtrusionSolid(*sweptData6, dirX, nullptr, nullptr, false, extrusionParams6, operNames, cNames, pSolid12);
	MbResultType res23 = ::BooleanResult(*pSolid, cm_Copy, *pSolid12, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	//������������ ��������� � �����������
	MbResultType res27 = ::BooleanResult(*pSolid, cm_Copy, *pCyl5_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res28 = ::BooleanResult(*pSolid, cm_Copy, *pCyl6_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res29 = ::BooleanResult(*pSolid, cm_Copy, *pCyl7_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res30 = ::BooleanResult(*pSolid, cm_Copy, *pCyl8_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	//������������ ��������� ������� �����
	MbResultType res31 = ::BooleanResult(*pSolid, cm_Copy, *pCyl9_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	MbResultType res32 = ::BooleanResult(*pSolid, cm_Copy, *pCyl10_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	//FILLETS 
	MbResultType res33 = ::ExtrusionSolid(*sweptData7, dirX, nullptr, nullptr, false, extrusionParams7, operNames, cNames, pSolid13);
	MbResultType res34 = ::MirrorSolid(*pSolid13, HorizPlane, operNames, pSolid14);
	MbResultType res35 = ::BooleanResult(*pSolid, cm_Copy, *pSolid13, cm_Copy, bo_Union, flagsBool, operBoolNames, pSolid);
	MbResultType res36 = ::BooleanResult(*pSolid, cm_Copy, *pSolid14, cm_Copy, bo_Union, flagsBool, operBoolNames, pSolid);
	// ����������� ������������ ����
	//show(Style(1, LIGHTGRAY), pSolid);
	//show(Style(1, BLACK), pSolid2);

	//show(Style(1, BLACK), pSolid4);
	//show(Style(1, BLACK), pSolid5);
	pSolid->Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(-SqureSize / 2, -SqureSize / 2, -62)));//+( 31 - 31 * ratio) <-��� ��� �������������� (�������� � 62)
	//pSolid->Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, -SqureSize / 2, 0)));

	pSolid->SetColor(ParametricModelCreator::colorScheme ? RGB(210, 20, 20) : WHITE);
	pAsm->AddItem(*pSolid);
	//viewManager->AddObject(Style(1, LIGHTRED), pSolid);


	//show(Style(1, LIGHTGRAY), pSolid14);
	//show(Style(1, LIGHTGRAY), pCyl5_Solid);
	//show(Style(1, LIGHTGRAY), pCyl6_Solid);
	//show(Style(1, LIGHTGRAY), pCyl9_Solid);
	//show(Style(1, LIGHTGRAY), pCyl10_Solid);
	// ���������� ��������� ������ ����������� ��������� �������� ����
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
	::DeleteItem(pPlaneXY);
	::DeleteItem(pPlaneXZ);
	::DeleteItem(pPlaneXZCen);
	::DeleteItem(pPlaneYZ);
	::DeleteItem(pPlaneYZCen);
}