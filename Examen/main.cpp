#include "examen.h"
#include <QtWidgets/QApplication>
#include "GUI.h"
int main(int argc, char *argv[])
{
		QApplication a(argc, argv);
		Task::testeDomeniu();
		Repo::testeRepo();
		//Controller::testeCtr();
		Repo r{ "taskList.txt" };
		Controller c{ r };
		GUI* g=new GUI{ c };
		tabela* g1=new tabela{ c };
		g->show(); 
		g1->show();
		return a.exec(); 
}
