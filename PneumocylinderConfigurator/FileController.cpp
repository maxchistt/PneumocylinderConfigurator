#include "FileController.h"

FileController::FileController(QWidget* parent)
{
	setParentWidget(parent);
}

FileController::~FileController()
{
}

void FileController::setParentWidget(QWidget* parent)
{
	parentWidget = parent;
}

c3d::path_string FileController::getFilePath(bool save, QString modelname)
{
	const QString defaultPath = "D:/C3D_files/";
	const QString fileFilter = "Geometric models (*.c3d *.stp *.step *.STEP *.IGES *.SAT *.X_T *.X_B *.STL *.VRML *.JT)";
	const QString savePath = defaultPath + modelname + ".c3d";

	QString fileName = save
		? QFileDialog::getSaveFileName(parentWidget, u8"��������� � ����", savePath, fileFilter)
		: QFileDialog::getOpenFileName(parentWidget, u8"������� �� �����", defaultPath, fileFilter);
	fileName.replace("/", "\\");
	fileName.replace(":", ":\\");
	c3d::path_string path = c3d::StdToPathstring(fileName.toStdString());
	return path;
}

void FileController::exportCurrentModel(c3d::path_string path, MbModel* ptrModel)
{
	if (ptrModel) {
		MbeConvResType exportRes = c3d::ExportIntoFile(*ptrModel, path);
		if (exportRes != MbeConvResType::cnv_Success)
			QMessageBox::information(parentWidget, u8"��������������", u8"������ ��������");
	}
	else {
		QMessageBox::information(parentWidget, u8"��������������", u8"������ ���������");
	}
}

MbModel* FileController::importCurrentModel(c3d::path_string path)
{
	MbModel* importModel = new MbModel();
	MbeConvResType importRes = c3d::ImportFromFile(*importModel, path);

	if (importRes == MbeConvResType::cnv_Success) {
		return importModel;
	}
	else {
		QMessageBox::information(parentWidget, u8"��������������", u8"������ �������");
		delete importModel;
		return nullptr;
	}
}

QString FileController::getNameFromParams(BuildMathModel::BuildParams params)
{
	QString name = "Pneumocylinder";
	name += " L" + QString::number(params.length);
	name += " D" + QString::number(params.diam);
	name += " " + (QString)(params.colorScheme ? "Red" : "White");
	return name;
}

void FileController::saveModel(MbModel* ptrModel, BuildMathModel::BuildParams params)
{
	c3d::path_string path = getFilePath(true, getNameFromParams(params));
	if (!path.empty()) exportCurrentModel(path, ptrModel);
}

MbModel* FileController::openModel()
{
	MbModel* ptrModel = nullptr;
	c3d::path_string path = getFilePath(false);
	if (!path.empty()) ptrModel = importCurrentModel(path);
	return ptrModel;
}
