#pragma once

#include <model.h>
#include <conv_model_exchange.h>
#include <QObject>
#include <QFileDialog>
#include <QMessageBox>

class FileController : public QObject
{
	Q_OBJECT

public:
	FileController(QObject* parent = Q_NULLPTR);
	~FileController();
private:
	QWidget* parentWidget();
	c3d::path_string getFilePath(bool save = true);
	void exportCurrentModel(c3d::path_string path);
	void importCurrentModel(c3d::path_string path);
public slots:
	void saveFileSlot();
	void openFileSlot();
signals:
	void modelImportedSignal(MbModel* modelPtr);
	void getModelSignal(MbModel*& modelPtrRef);
	void modelExportedSignal();
};
