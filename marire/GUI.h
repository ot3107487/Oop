#pragma once
#include "Controller.h"
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTableWidget>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
class GUI :public QWidget {
	Q_OBJECT
private:
	QHBoxLayout *mainLayout,*linie1,*linie2,*linie3;
	QFormLayout *firstLayout, *secondLayout;
	QTableWidget *tabel;
	QLineEdit *id, *tabla, *jucator, *stare;
	QLabel *iLabel, *tLabel, *jLabel, *sLabel;
	QPushButton *joc1, *joc2, *joc3, *joc4, *joc5, *joc6, *joc7, *joc8, *joc9;
	QPushButton *creeaza, *modifica,*select;
	Controller& ctr;
	Joc& j = Joc{ ctr.getAll()[0] };
public:
	//constructor
	GUI(Controller& c) :ctr{ c } {
		deseneaza();
		conectare();
	}
	//functii necesare
	void deseneaza();
	void conectare();
	void update();
};