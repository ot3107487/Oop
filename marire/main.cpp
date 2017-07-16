#include "marire.h"
#include <QtWidgets/QApplication>
#include "GUI.h"
int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	Joc::teste();
	Repo::teste();
	Controller::teste();
	Repo r{ "Jocuri.txt" };
	Controller ctr{ r };
	GUI g{ ctr };
	g.show();
	return a.exec();
}
