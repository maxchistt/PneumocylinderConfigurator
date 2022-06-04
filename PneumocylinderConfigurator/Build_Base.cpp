#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;

//��������������� ������� ��� �������� �������
void CreateSketch(RPArray<MbContour>& _arrContours)
{
	// �������� ������� ����� ��������, � �������� � ���������� ��������� ����������.
	// ������ ������� - 8 ����� ��� ����� ����� ������� ��������� ����������.
	SArray<MbCartPoint> arrPnts(8);
	arrPnts.Add(MbCartPoint(0, 0));
	arrPnts.Add(MbCartPoint(65.2, 0));
	arrPnts.Add(MbCartPoint(65.2, 65.2));
	arrPnts.Add(MbCartPoint(0, 65.2));

	// ���������� ������ ������� �������� ������� �� ������
	MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
	MbContour* pContourPolyline = nullptr;
	::FilletPolyContour(pPolyline, 6, false, arrPnts[4], pContourPolyline);


	// ������� �������� �����, � ������� ����� ���������� ���������� � ������
	// ���������� ����� ����� ��� ���������� � �������������� ������� FilletTwoSegments
	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;

	// ���������� ����������
	pContourPolyline->FilletTwoSegments(idxSideRight1, 6);
	pContourPolyline->FilletTwoSegments(idxSideRight2, 6);
	pContourPolyline->FilletTwoSegments(idxSideRight3, 6);

	_arrContours.push_back(pContourPolyline);

	::DeleteItem(pPolyline);

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
	// ������� ���������� � �������������� ������� FilletPolyContour
	::FilletPolyContour(pPolyline2, 10.5, false, arrPnts2[4], pContourPolyline2);

	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;

	pContourPolyline2->FilletTwoSegments(idxSideRight1, 0);
	pContourPolyline2->FilletTwoSegments(idxSideRight2, 0);
	pContourPolyline2->FilletTwoSegments(idxSideRight3, 0);

	_arrContours2.push_back(pContourPolyline2);
	::DeleteItem(pPolyline2);
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
	// ������� ���������� � �������������� ������� FilletPolyContour
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
	// ������� ���������� � �������������� ������� FilletPolyContour
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
	// ������� ���������� � �������������� ������� FilletPolyContour//16
	::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

	ptrdiff_t idxSideRight1 = 0;
	ptrdiff_t idxSideRight2 = 2;
	ptrdiff_t idxSideRight3 = 4;

	pContourPolyline->FilletTwoSegments(idxSideRight1, 16);
	pContourPolyline->FilletTwoSegments(idxSideRight2, 16);
	pContourPolyline->FilletTwoSegments(idxSideRight3, 0);

	_arrContours5.push_back(pContourPolyline);
	::DeleteItem(pPolyline);
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
	// �������� IsSmoothConnected - ������ ��� ������������� ������� ����� �� �������
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

//������� �� �������� ������� �����
void ParametricModelCreator::CreateBase(MbAssembly* pAsm)
{
	// ��������� ��� �������������� ����� �� ��������� � ��������� ����.
	const double DEG_TO_RAD = M_PI / 180.0;
	const double SqureSize = 65.2;

	/*������������
	bo_Union - �����������
	bo_Difference - ��������
	*/
	// ��������� �� (�� ��������� ��������� � ������� ��)
	MbPlacement3D pl;
	// �������� ���������� ��� ���� ������������
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
	MbPlane* pPlaneYZCen = new MbPlane(MbCartPoint3D(12.65, 0, 0),
		MbCartPoint3D(12.65, 1, 0),
		MbCartPoint3D(12.65, 0, 1));
	MbPlane* pPlaneXZCen = new MbPlane(MbCartPoint3D(0, 32.6 + 7.5, 0),
		MbCartPoint3D(1, 32.6 + 7.5, 0),
		MbCartPoint3D(0, 32.6 + 7.5, 1));
	//�������� ���� ��� ��������������
	MbPlacement3D HorizPlane(MbVector3D(1, 0, 0), /* ��� X ��������� �� */
		MbVector3D(0, 0, 1), /* ��� Z ��������� �� */
		MbCartPoint3D(0, 32.6, 0 /* ������ ��������� ��������� �� */));
	MbPlacement3D VerticalPlane(MbVector3D(0, 0, 1), /* ��� Z ��������� �� */
		MbVector3D(0, 1, 0), /* ��� Y ��������� �� */
		MbCartPoint3D(32.6, 0, 0 /* ������ ��������� ��������� �� */));
	// ������������ ������ ��� �������� ������������
	MbVector3D dirX(1, 0, 0);
	MbVector3D dirY(0, 1, 0);
	MbVector3D dirZ(0, 0, 1);
	// ������, �������� ��������� ����������
	MbSweptData sweptData(*pPlaneXY, arrContours);
	MbSweptData sweptData2(*pPlaneXY, arrContours2);
	MbSweptData sweptData3(*pPlaneXY, arrContours3);
	MbSweptData sweptData4(*pPlaneXY, arrContours4);
	MbSweptData sweptData5(*pPlaneXZCen, arrContours5);
	MbSweptData sweptData6(*pPlaneYZ, arrContours6);
	MbSweptData sweptData7(*pPlaneYZCen, arrContours7);
	// ������������ ������ ��� �������� ������������
	// ��������� �������� ������������, �������� �������� ���� ��� ���������� � ������
	// � � �������� ����������� ����� (������� ������������ � �����).
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
	cylPnts.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2 + 25, 4.5));
	// ���������� ������������� ���� - ��������
	MbResultType resCyl1 = ::ElementarySolid(cylPnts, et_Cylinder,
		namesElSolid, pCyl1_Solid);
	// �������� ���� �2 - ������� ����� ���������
	// ������� ����� ��� ������������� ���� - ��������
	SArray<MbCartPoint3D> cylPnts2(3);
	cylPnts2.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, 4.5));
	cylPnts2.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2, 40));
	cylPnts2.Add(MbCartPoint3D(SqureSize / 2, SqureSize / 2 + 13, 4.5));
	// ���������� ������������� ���� - ��������
	MbResultType resCyl2 = ::ElementarySolid(cylPnts2, et_Cylinder,
		namesElSolid, pCyl2_Solid);
	// �������� ���� �3 - ������� � �����
	// ������� ����� ��� ������������� ���� - ��������
	SArray<MbCartPoint3D> cylPnts3(3);
	cylPnts3.Add(MbCartPoint3D(SqureSize / 2, 25.1, -18.75));
	cylPnts3.Add(MbCartPoint3D(SqureSize / 2, 25.1 + 15, -18.75));
	cylPnts3.Add(MbCartPoint3D(SqureSize / 2, 25.1 + 15, -18.75 + 13.5 / 2));
	// ���������� ������������� ���� - ��������
	MbResultType resCyl3 = ::ElementarySolid(cylPnts3, et_Cylinder,
		namesElSolid, pCyl3_Solid);
	// �������� ���� �4 - ������� �����
	// ������� ����� ��� ������������� ���� - ��������
	SArray<MbCartPoint3D> cylPnts4(3);
	cylPnts4.Add(MbCartPoint3D(0, 38.8, 18.25));
	cylPnts4.Add(MbCartPoint3D(SqureSize / 2, 38.8, 18.25));
	cylPnts4.Add(MbCartPoint3D(SqureSize / 2, 38.8 + 12.5 / 2, 18.25));
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
	cylPnts6.Add(MbCartPoint3D(0, 38.8, 18.25));
	cylPnts6.Add(MbCartPoint3D(0.2, 38.8, 18.25));
	cylPnts6.Add(MbCartPoint3D(0.2, 38.8 + 22 / 2, 18.25));
	// ���������� ������������� ���� - ��������
	MbResultType resCyl6 = ::ElementarySolid(cylPnts6, et_Cylinder,
		namesElSolid, pCyl9_Solid);
	// �������� ���� �7 - �����(��������� ������)
	// ������� ����� ��� ������������� ���� - ��������
	SArray<MbCartPoint3D> cylPnts7(3);
	cylPnts7.Add(MbCartPoint3D(0, 15.4, 22.7));
	cylPnts7.Add(MbCartPoint3D(1.2, 15.4, 22.7));
	cylPnts7.Add(MbCartPoint3D(1.2, 15.4 + 11.4 / 2, 22.7));
	// ���������� ������������� ���� - ��������
	MbResultType resCyl7 = ::ElementarySolid(cylPnts7, et_Cylinder,
		namesElSolid, pCyl10_Solid);
	//�������� ���� ��� ������
	MbResultType res = ::ExtrusionSolid(sweptData, dirZ, nullptr, nullptr, false, extrusionParams, operNames, cNames, pSolid);
	MbResultType res16 = ::BooleanResult(*pSolid, cm_Copy, *pCyl1_Solid, cm_Copy, bo_Union, flagsBool, operBoolNames, pSolid);
	MbResultType res17 = ::BooleanResult(*pSolid, cm_Copy, *pCyl2_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	//�������� �� ��� ����������� �� �����
	MbResultType res2 = ::ExtrusionSolid(sweptData2, dirZ, nullptr, nullptr, false, extrusionParams2, operNames, cNames, pSolid2);
	//�������� �� ��� 3��������������� �� �����
	MbResultType res3 = ::ExtrusionSolid(sweptData3, dirZ, nullptr, nullptr, false, extrusionParams3, operNames, cNames, pSolid7);
	MbResultType res12 = ::ExtrusionSolid(sweptData4, dirZ, nullptr, nullptr, false, extrusionParams3, operNames, cNames, pSolid8);

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

	MbResultType res18 = ::ExtrusionSolid(sweptData5, dirY, nullptr, nullptr, false, extrusionParams5, operNames, cNames, pSolid10);
	//END TEST
	MbResultType res19 = ::BooleanResult(*pSolid10, cm_Copy, *pCyl3_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid10);
	MbResultType res20 = ::BooleanResult(*pSolid, cm_Copy, *pSolid10, cm_Copy, bo_Union, flagsBool, operBoolNames, pSolid);
	MbResultType res21 = ::BooleanResult(*pSolid, cm_Copy, *pCyl4_Solid, cm_Copy, bo_Difference, flagsBool, operBoolNames, pSolid);
	//�������� ������ ����� ������ ��������
	MbResultType res22 = ::ExtrusionSolid(sweptData6, dirX, nullptr, nullptr, false, extrusionParams6, operNames, cNames, pSolid12);
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
	MbResultType res33 = ::ExtrusionSolid(sweptData7, dirX, nullptr, nullptr, false, extrusionParams7, operNames, cNames, pSolid13);
	MbResultType res34 = ::MirrorSolid(*pSolid13, HorizPlane, operNames, pSolid14);
	MbResultType res35 = ::BooleanResult(*pSolid, cm_Copy, *pSolid13, cm_Copy, bo_Union, flagsBool, operBoolNames, pSolid);
	MbResultType res36 = ::BooleanResult(*pSolid, cm_Copy, *pSolid14, cm_Copy, bo_Union, flagsBool, operBoolNames, pSolid);
	// ����������� ������������ ����
	//show(Style(1, LIGHTGRAY), pSolid);
	//show(Style(1, BLACK), pSolid2);

	//show(Style(1, BLACK), pSolid4);
	//show(Style(1, BLACK), pSolid5);
	pSolid->Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(-SqureSize / 2, -SqureSize / 2, -62)));
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