#pragma once
#include "Controller.h"
#include <QAbstractTableModel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QTableView>
#include <QSlider>
#include <QMessageBox>
#include <QLabel>
#include <QTableWidget>
class Model :public QAbstractTableModel {
private:
	Controller& ctr;
public:
	Model(Controller& c, QObject* parent = {}) :ctr{ c }, QAbstractTableModel { parent } {};
	int rowCount(const QModelIndex &parent /* = QModelIndex() */)const override {
		 
		 return ctr.getAll().size();
	}
	int columnCount(const QModelIndex &parent /* = QModelIndex() */)const override {
		return 4;
	}
	QVariant data(const QModelIndex &index, int role /* = Qt::DisplayRole */)const override {
		if (role != Qt::DisplayRole&&role != Qt::EditRole&& role!=Qt::BackgroundColorRole)
			return QVariant();
		const auto& produs = ctr.getAll()[index.row()];
		switch (index.column()) {
		case 0:
			return produs.getId();
		case 1:
			return QString::fromStdString(produs.getNume());
		case 2:
			return QString::fromStdString(produs.getTip());
		case 3:
			return produs.getPret();
		default:
			return QVariant();
		}
		
	}
	QVariant headerData(int section, Qt::Orientation orientation, int role /* = Qt::DisplayRole */)const override {
		if (orientation != Qt::Vertical&&role != Qt::DisplayRole)
			return{};
		switch (section) {
		case 0:
			return "Id";
		case 1:
			return "Nume";
		case 2:
			return "Tip";
		case 3:
			return "Pret";
		default:
			return{};
		}
	}
};
class GUI :public QWidget {
	Q_OBJECT
private:
	Controller ctr;
	QHBoxLayout *mainLayout;
	QFormLayout *first, *second;
	QTableWidget *tabel;
	QSlider *slider;
	QLineEdit *id, *nume, *tip, *pret;
	QPushButton *adauga;
	QLabel *vSlider;
	Model m{ ctr };
public:
	GUI(Controller& ctr) :ctr{ ctr } {
		deseneaza();
		conectare();
	};
	void deseneaza();
	void conectare();
	void update();
};