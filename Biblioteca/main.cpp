#include "biblioteca.h"
#include <QtWidgets/QApplication>
#include "Carturest.h"
#include <crtdbg.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repo r{ "t.txt" };
	Controller c{ r };
	GUI g{ c };
	g.show();
	return a.exec();
}
