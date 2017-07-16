#ifndef MARIRE_H
#define MARIRE_H

#include <QtWidgets/QMainWindow>
#include "ui_marire.h"

class marire : public QMainWindow
{
	Q_OBJECT

public:
	marire(QWidget *parent = 0);
	~marire();

private:
	Ui::marireClass ui;
};

#endif // MARIRE_H
