#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;

MbAssembly* ParametricModelCreator::CreatePneumocylinderAssembly(BuildParams params)
{
	MbAssembly* pAsm = new MbAssembly();

	double param_length = params.length;

	double diamMain = params.diam;
	const double diamMain_STD = 50;
	//calculate offsets
	//������� ������������ � ��������� ���������
	double diamMainOffset = diamMain - diamMain_STD;
	//����������� ������������ � ��������� ���������
	double diamDifRatio = diamMain / diamMain_STD;

	double radMainOffset = diamMainOffset / 2;


	//double diamShaft = diamMain - 30 * diamMainDifRatio;
	//const double diamShaft_STD = 20;
	//calculate offsets
	//������� ������������ � ��������� ���������
	//double diamShaftOffset = diamShaft - diamShaft_STD;
	//����������� ������������ � ��������� ���������
	//double diamShaftDifRatio = diamShaft / diamShaft_STD; // = diamDifRatio

	//double radShaftOffset = diamShaftOffset / 2;
	
	// �������� ������
	double len_dif = param_length - 132.95;

	//pAsm->AddItem(*pSolid);

	// ���������� ��� �������������� ���� 
	double start = 0;
	double length = 0;
	double radius = 0;

	double DD = 23.6 + radMainOffset;//ClampingBar and bolts offset from 0 coord

	//����
	CreateShaft(pAsm,len_dif, diamDifRatio);


	// ��������� ������� �� ����
	CreateShaftPivot(pAsm, len_dif, diamDifRatio); // ���������

	// ������ ��������������
	CreateBase(pAsm, diamDifRatio); // �������
	CreateTopGuide(pAsm, len_dif, diamDifRatio); // ������

	// ������
	if (create_frame) CreateMainBody(pAsm, len_dif, diamDifRatio); // ���������

	// ������� � ������ �� ���
	CreateSealHousing(pAsm, diamDifRatio); // ������
	CreateORing(pAsm, -19, diamDifRatio); // 
	CreateORing(pAsm, -8.5, diamDifRatio); // 

	// ����� ������ �� �����
	CreateSocketHeadCollar(pAsm, diamDifRatio); // ���������
	CreateBrassCollar(pAsm, diamDifRatio); // ������

	// �����
	CreateClampingBar(pAsm, DD, DD, len_dif); // ��������� 
	CreateClampingBar(pAsm, DD, -DD, len_dif); // 
	CreateClampingBar(pAsm, -DD, -DD, len_dif); // 
	CreateClampingBar(pAsm, -DD, DD, len_dif); // 

	CreateBolt(pAsm, DD, DD, -32.6); // ������
	CreateBolt(pAsm, DD, -DD, -32.6); //
	CreateBolt(pAsm, -DD, -DD, -32.6); //
	CreateBolt(pAsm, -DD, DD, -32.6); //
	CreateBolt(pAsm, -DD, DD, len_dif + 16.05, 1); //
	CreateBolt(pAsm, DD, DD, len_dif + 16.05, 1); //
	CreateBolt(pAsm, DD, -DD, len_dif + 16.05, 1); //
	CreateBolt(pAsm, -DD, -DD, len_dif + 16.05, 1); //

	return pAsm;
}
