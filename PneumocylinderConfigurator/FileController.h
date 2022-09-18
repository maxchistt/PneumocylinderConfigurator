#pragma once

#include <model.h>
#include <conv_model_exchange.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QWidget>
#include "BuildParams.h"

class FileController
{
	QWidget* parentWidget = Q_NULLPTR;
public:
	FileController(QWidget* parent = Q_NULLPTR);
	~FileController();
	void setParentWidget(QWidget* parent);
	void saveModel(MbModel* ptrModel, BuildMathModel::BuildParams params);
	MbModel* openModel();
private:
	c3d::path_string getFilePath(bool save = true, QString modelname = "MyModel");
	void exportCurrentModel(c3d::path_string path, MbModel* ptrModel);
	MbModel* importCurrentModel(c3d::path_string path);
	QString getNameFromParams(BuildMathModel::BuildParams params);
};
