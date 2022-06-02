#include "FileController.h"

FileController::FileController(QObject* parent)
	: QObject(parent)
{
}

FileController::~FileController()
{
}

QWidget* FileController::parentWidget()
{
	QWidget* parentW = this->parent()->isWidgetType()
		? (QWidget*)(this->parent())
		: (QWidget*)Q_NULLPTR;
	return parentW;
}

c3d::path_string FileController::getFilePath(bool save)
{
	const QString defaultPath = "D:/C3D_files/MyModel.c3d";
	const QString fileFilter = "Geometric models (*.c3d *.stp *.step *.STEP *.IGES *.SAT *.X_T *.X_B *.STL *.VRML *.JT)";
	QString fileName = save
		? QFileDialog::getSaveFileName(parentWidget(), u8"Сохранить в файл", defaultPath, fileFilter)
		: QFileDialog::getOpenFileName(parentWidget(), u8"Открыть из файла", defaultPath, fileFilter);
	fileName.replace("/", "\\");
	fileName.replace(":", ":\\");
	c3d::path_string path = c3d::StdToPathstring(fileName.toStdString());
	return path;
}

void FileController::exportCurrentModel(c3d::path_string path)
{
	if (!path.empty()) {
		MbModel* ptrModel = nullptr;
		emit getModelSignal(ptrModel);
		if (ptrModel) {
			c3d::ExportIntoFile(*ptrModel, path);
			emit modelExportedSignal();
		}
		else {
			QMessageBox::information(parentWidget(), u8"Предупреждение", u8"Нечего сохранять");
		}
	}
}

void FileController::importCurrentModel(c3d::path_string path)
{
	MbModel* importModel = new MbModel();
	MbeConvResType importRes = c3d::ImportFromFile(*importModel, path);

	if (importRes == MbeConvResType::cnv_Success) {
		emit modelImportedSignal(importModel);
	}
	else {
		QMessageBox::information(parentWidget(), u8"Предупреждение", u8"Ошибка импорта");
	}
}

void FileController::saveFileSlot()
{
	c3d::path_string path = getFilePath();
	if (!path.empty()) exportCurrentModel(path);
}

void FileController::openFileSlot()
{
	c3d::path_string path = getFilePath(false);
	if (!path.empty()) importCurrentModel(path);
}
