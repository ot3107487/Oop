#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <QtWidgets/QMainWindow>
#include "ui_biblioteca.h"

class Biblioteca : public QMainWindow
{
	Q_OBJECT

public:
	Biblioteca(QWidget *parent = 0);
	~Biblioteca();

private:
	Ui::BibliotecaClass ui;
};

#endif // BIBLIOTECA_H
