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

c3d::path_string FileController::getFilePath(bool save)
{
	const QString defaultPath = "D:/C3D_files/MyModel.c3d";
	const QString fileFilter = "Geometric models (*.c3d *.stp *.step *.STEP *.IGES *.SAT *.X_T *.X_B *.STL *.VRML *.JT)";
	QString fileName = save
		? QFileDialog::getSaveFileName(parentWidget, u8"Сохранить в файл", defaultPath, fileFilter)
		: QFileDialog::getOpenFileName(parentWidget, u8"Открыть из файла", defaultPath, fileFilter);
	fileName.replace("/", "\\");
	fileName.replace(":", ":\\");
	c3d::path_string path = c3d::StdToPathstring(fileName.toStdString());
	return path;
}

void FileController::exportCurrentModel(c3d::path_string path, SPtr<MbItem> ptrModel)
{
	if (!ptrModel.is_null()) {
		MbeConvResType exportRes = c3d::ExportIntoFile(*ptrModel, path);
		if (exportRes != MbeConvResType::cnv_Success)
			QMessageBox::information(parentWidget, u8"Предупреждение", u8"Ошибка экспорта");
	}
	else {
		QMessageBox::information(parentWidget, u8"Предупреждение", u8"Нечего сохранять");
	}
}

SPtr<MbItem> FileController::importCurrentModel(c3d::path_string path)
{
#if 0
	// ImportFromFile работает некорректно с ItemSPtr
	SPtr<MbItem> importModel;
	MbeConvResType importRes = c3d::ImportFromFile(importModel, path);

	if (importRes == MbeConvResType::cnv_Success) {
		// Здесь, после успешного импорта, мы проверяем умный указатель importModel и обнаруживаем, что importModel.is_null() == true
		if (importModel.is_null())QMessageBox::information(parentWidget, u8"Предупреждение", u8"importModel.is_null");
		return importModel;
	}
	else {
		QMessageBox::information(parentWidget, u8"Предупреждение", u8"Ошибка импорта");
		importModel.reset();
		return importModel;
	}
#else
	// рабочий вариант с MbModel
	SPtr<MbItem> importModel;
	MbModel imMbModel;
	MbeConvResType importRes = c3d::ImportFromFile(imMbModel, path);

	if (importRes == MbeConvResType::cnv_Success) {
		RPArray<MbItem> subitems;
		SArray<MbMatrix3D> matrs;
		imMbModel.GetItems(MbeSpaceType::st_Item, subitems, matrs);

		if (subitems.Count() > 1) {
			MbAssembly* assembly = new MbAssembly();
			for (auto subitem : subitems) {
				assembly->AddItem(*subitem);
			}
			importModel.assign(assembly);
		}
		else if (subitems.Count() > 0) {
			importModel.assign(subitems[0]);
		}

		if (importModel.is_null())QMessageBox::information(parentWidget, u8"Предупреждение", u8"importModel.is_null");
		return importModel;
	}
	else {
		QMessageBox::information(parentWidget, u8"Предупреждение", u8"Ошибка импорта");
		importModel.reset();
		return importModel;
	}
#endif
}

void FileController::saveModel(SPtr<MbItem> ptrModel)
{
	c3d::path_string path = getFilePath();
	if (!path.empty()) exportCurrentModel(path, ptrModel);
}

SPtr<MbItem> FileController::openModel()
{
	SPtr<MbItem> ptrModel;
	c3d::path_string path = getFilePath(false);
	if (!path.empty()) ptrModel.assign(importCurrentModel(path));
	return ptrModel;
}
