#pragma once
#include "Controller.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QAbstractTableModel>
#include <QPainter>
#include <QLabel>
#include <QVariant>
#include <QMessageBox>
class Model :public QAbstractTableModel {
private:
	Controller& ctr;
public:
	Model(Controller& ctr, QObject *parent = {}) :ctr{ ctr }, QAbstractTableModel{ parent } {};
	int rowCount(const QModelIndex &parent /* = QModelIndex() */)const override {
		return this->ctr.getAll().size();
	}
	int columnCount(const QModelIndex &parent /* = QModelIndex() */)const override {
		return 6;
	}
	QVariant data(const QModelIndex &index, int role /* = Qt::DisplayRole */)const override{
		if (role != Qt::DisplayRole && role != Qt::EditRole)
			return QVariant{};
		int row = index.row();
		const auto& c = this->ctr.getAll()[row];
		switch (index.column()) {
		case 0:
			return c.getId();
		case 1:
			return QString::fromStdString(c.getTitlu());
		case 2:
			return QString::fromStdString(c.getAutor());
		case 3:
			return QString::fromStdString(c.getGen());
		case 4:
			return ctr.nrAutor(c.getAutor());
		case 5:
			return ctr.nrGen(c.getGen());
		default:
			return QVariant{};
		}
	}
	QVariant headerData(int section, Qt::Orientation orientation, int role /* = Qt::DisplayRole */)const override {
		if (orientation != Qt::Vertical&&role != Qt::DisplayRole)
			return QVariant{};
		switch (section) {
		case 0:
			return "Id";
		case 1:
			return "Titlu";
		case 2:
			return "Autor";
		case 3:
			return "Gen";
		case 4:
			return "Ac. Autor";
		case 5:
			return "Ac. Gen";
		default:
			return QVariant{};
		}
	}
};
class GUI : public QWidget {
	Q_OBJECT
private:
	QHBoxLayout *mainLayout;
	QFormLayout *tableLayout, *dreapta;
	QTableView *tabel;
	Controller& ctr;
	Model m{ ctr };
	Carte carteSelectata;
	QLineEdit *titlu, *autor, *gen;
	QLabel *tLabel, *aLabel, *gLabel;
	QPushButton *adauga, *sterge;
public:
	GUI(Controller& c) :ctr{ c } {
		deseneaza();
		conectare();
	}
	void deseneaza();
	void conectare();
protected:
	void paintEvent(QPaintEvent *ev)override {
		QPainter p(this);
		vector<string> s = { "poezii","novela","roman","stiintific" };
		p.drawEllipse(0, 0, ctr.nrGen(s[0]) * 10, ctr.nrGen(s[0]) * 10);
		p.drawEllipse(width()-20, 0, ctr.nrGen(s[1]) * 10, ctr.nrGen(s[1]) * 10);
		p.drawEllipse(0, height()-20, ctr.nrGen(s[2]) * 10, ctr.nrGen(s[2]) * 10);
		p.drawEllipse(width()-20, height()-20, ctr.nrGen(s[3]) * 10, ctr.nrGen(s[3]) * 10);
	}
};