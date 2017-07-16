#pragma once
#include "Controller.h"
#include <qwidget.h>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
class GUI : public QWidget,Observable {
	Q_OBJECT
private:
	QHBoxLayout *mainLayout;
	QFormLayout *tabelLayout;
	QFormLayout *secondLayout;
	QLineEdit *id, *descriere, *stare, *programatori,*filtru;
	QLabel *iLab, *dLab, *sLab, *pLab,*fLab;
	QTableWidget *tabel;
	QPushButton *adauga, *filtreaza;
	QFormLayout *fer;
	Controller& ctr;
public:
	GUI(Controller& ctr) :ctr{ ctr } {
		ctr.reg(this);
		deseneaza();
		conectare();
	};
	void deseneaza();
	void conectare();
	void update() override {
		tabel->setRowCount(ctr.getAll().size());
		tabel->setColumnCount(4);
		QStringList header;
		header << "Id" << "Descriere" << "Stare" << "Nr. Programatori";
		tabel->setHorizontalHeaderLabels(header);
		int i = 0;
		for (const auto& p : ctr.getAll()) {
			tabel->setItem(i, 0, new QTableWidgetItem(QString::number(p.getId())));
			tabel->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(p.getDescriere())));
			tabel->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(p.getStare())));
			tabel->setItem(i, 3, new QTableWidgetItem(QString::number(ctr.program(p.getProgramatori()))));
			i++;
		}
	}

};
class tabela :public QWidget, Observable {
	QHBoxLayout *mainLayout;
	QFormLayout *tabelLayout;
	QTableWidget *tabel;
	Controller& ctr;
public:
	tabela(Controller& ctr) :ctr{ ctr } {
		ctr.reg(this);
		deseneaza();
	};
	void update() override {
		tabel->setRowCount(ctr.getAll().size());
		tabel->setColumnCount(4);
		QStringList header;
		header << "Id" << "Descriere" << "Stare" << "Nr. Programatori";
		tabel->setHorizontalHeaderLabels(header);
		int i = 0;
		for (const auto& p : ctr.getAll()) {
			tabel->setItem(i, 0, new QTableWidgetItem(QString::number(p.getId())));
			tabel->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(p.getDescriere())));
			tabel->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(p.getStare())));
			tabel->setItem(i, 3, new QTableWidgetItem(QString::number(ctr.program(p.getProgramatori()))));
			i++;
		}
	}
	void deseneaza() {
		mainLayout = new QHBoxLayout(this);
		tabelLayout = new QFormLayout();
		tabel = new QTableWidget();
		update();
		tabelLayout->addWidget(tabel);
		mainLayout->addLayout(tabelLayout);
	}

};