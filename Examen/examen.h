#ifndef EXAMEN_H
#define EXAMEN_H

#include <QtWidgets/QMainWindow>
#include "ui_examen.h"

class Examen : public QMainWindow
{
	Q_OBJECT

public:
	Examen(QWidget *parent = 0);
	~Examen();

private:
	Ui::ExamenClass ui;
};

#endif // EXAMEN_H
