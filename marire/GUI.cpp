#include "GUI.h"
void GUI::deseneaza() {
	mainLayout = new QHBoxLayout(this);
	//first layout
	
	//tabelul
	firstLayout = new QFormLayout();
	tabel = new QTableWidget();
	update();
	firstLayout->addRow(tabel);
	//jocul
	joc1 = new QPushButton();
	joc2 = new QPushButton();
	joc3 = new QPushButton();
	joc4 = new QPushButton();
	joc5 = new QPushButton();
	joc6 = new QPushButton();
	joc7 = new QPushButton();
	joc8= new QPushButton();
	joc9= new QPushButton();
	//linie1
	linie1 = new QHBoxLayout();
	linie1->addWidget(joc1);
	linie1->addWidget(joc2);
	linie1->addWidget(joc3);
	firstLayout->addRow(linie1);
	//linie2
	linie2 = new QHBoxLayout();
	linie2->addWidget(joc4);
	linie2->addWidget(joc5);
	linie2->addWidget(joc6); 
	firstLayout->addRow(linie2);
	//linie3
	linie3 = new QHBoxLayout();
	linie3->addWidget(joc7);
	linie3->addWidget(joc8);
	linie3->addWidget(joc9);
	firstLayout->addRow(linie3);
	select = new QPushButton("&Selecteaza joc");
	firstLayout->addRow(select);
	mainLayout->addLayout(firstLayout);
	
	// SecondLayout   partea din dreapta
	secondLayout = new QFormLayout();
	tLabel = new QLabel("Tabla:");
	tabla = new QLineEdit();
	secondLayout->addRow(tLabel, tabla);
	jLabel = new QLabel("Jucator:");
	jucator = new QLineEdit();
	secondLayout->addRow(jLabel, jucator);
	creeaza = new QPushButton("&Creeaza");
	secondLayout->addRow(creeaza);
	iLabel = new QLabel("Id");
	id = new QLineEdit();
	secondLayout->addRow(iLabel, id);
	sLabel = new QLabel("Stare");
	stare = new QLineEdit();
	secondLayout->addRow(sLabel, stare);
	modifica = new QPushButton("&Modifica");
	secondLayout->addRow(modifica);
	//
	mainLayout->addLayout(secondLayout);

}
void GUI::update() {
	//repopularea tabelului
	tabel->setRowCount(ctr.getAll().size());
	tabel->setColumnCount(4);
	QStringList header;
	header << "Id" << "Tabla" << "Jucator" << "Stare";
	tabel->setHorizontalHeaderLabels(header);
	int i = 0;
	for (const auto& j : ctr.getAll()) {
		tabel->setItem(i, 0, new QTableWidgetItem(QString::number(j.getId())));
		tabel->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(j.getTabla())));
		tabel->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(j.getJucator())));
		tabel->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(j.getStare())));
		i++;
	}
}
void GUI::conectare() {
	//creeaza joc
	connect(this->creeaza, &QPushButton::clicked, [&]() {
		string tab = tabla->text().toStdString();
		int ok = 1;
		if (tab.length() == 9) {
			for (int i = 0; i < tab.length(); i++)
				if (tab[i] != 'X' && tab[i] != 'O' && tab[i] != '-') {
					ok = 0;
				}
		}
		else
			ok = 0;
		string j = jucator->text().toStdString();
		if (j.length() == 1) {
			if (j[0] != 'X' && j[0] != 'O')
				ok = 0;
		}
		else
			ok = 0;
		if (ok) {
			int ident = ctr.getAll().size();
			ctr.add(Joc{ ident+2 ,tab,j,"Neinceput" });
			update();
		}});
	//modifica joc existent
	connect(this->modifica, &QPushButton::clicked, [&]() {
		string tab = tabla->text().toStdString();
		int ok = 1;
		if (tab.length() == 9) {
			for (int i = 0; i < tab.length(); i++)
				if (tab[i] != 'X' && tab[i] != 'O' && tab[i] != '-') {
					ok = 0;
				}
		}
		else
			ok = 0;
		string j = jucator->text().toStdString();
		if (j.length() == 1) {
			if (j[0] != 'X' && j[0] != 'O')
				ok = 0;
		}
		else
			ok = 0;
		int ident = id->text().toInt();
		string st = stare->text().toStdString();
		if (st != "Terminat"&&st != "InDerulare"&&st != "Neinceput")
			ok = 0;
		if(ok)
			ctr.modify(Joc{ ident,tab,j,st });
			update();
	});
	//selecteaza joc
	connect(this->select, &QPushButton::clicked, [&]() {
		this->j = ctr.findIt(id->text().toInt());
		string tabela = j.getTabla();
		string val = "";
		val = val + tabela[0];
		joc1->setText(QString::fromStdString(val));
		val = "";
		val = val + tabela[1];
		joc2->setText(QString::fromStdString(val));
		val = "";
		val = val + tabela[2];
		joc3->setText(QString::fromStdString(val));
		val = "";
		val = val + tabela[3];
		joc4->setText(QString::fromStdString(val));
		val = "";
		val = val + tabela[4];
		joc5->setText(QString::fromStdString(val));
		val = "";
		val = val + tabela[5];
		joc6->setText(QString::fromStdString(val));
		val = "";
		val = val + tabela[6];
		joc7->setText(QString::fromStdString(val));
		val = "";
		val = val + tabela[7];
		joc8->setText(QString::fromStdString(val));
		val = "";
		val = val + tabela[8];
		joc9->setText(QString::fromStdString(val));
	});
	//joaca
	connect(this->joc1, &QPushButton::clicked, [&]() {
		if (joc1->text().toStdString()[0] == '-') {
			string juc = j.getJucator();
			joc1->setText(QString::fromStdString(juc));
			string jtabla = j.getTabla();
			jtabla[0] = juc[0];
			if (juc == "X") {
				j.setTabla(jtabla);
				j.setJucator("O");
				ctr.modify(j);
			}
			if (juc == "O") {
				j.setTabla(jtabla);
				j.setJucator("X");
				ctr.modify(j);
			}
			update();
		}
		});
	connect(this->joc2, &QPushButton::clicked, [&]() {
		if (joc2->text().toStdString()[0] == '-') {
			string juc = j.getJucator();
			joc2->setText(QString::fromStdString(juc));
			string jtabla = j.getTabla();
			jtabla[1] = juc[0];
			if (juc == "X") {
				j.setTabla(jtabla);
				j.setJucator("O");
				ctr.modify(j);
			}
			if (juc == "O") {
				j.setTabla(jtabla);
				j.setJucator("X");
				ctr.modify(j);
			}
			update();
		}
	});
	connect(this->joc3, &QPushButton::clicked, [&]() {
		if (joc3->text().toStdString()[0] == '-') {
			string juc = j.getJucator();
			joc3->setText(QString::fromStdString(juc));
			string jtabla = j.getTabla();
			jtabla[2] = juc[0];
			if (juc == "X") {
				j.setTabla(jtabla);
				j.setJucator("O");
				ctr.modify(j);
			}
			if (juc == "O") {
				j.setTabla(jtabla);
				j.setJucator("X");
				ctr.modify(j);
			}
			update();
		}
	});
	connect(this->joc4, &QPushButton::clicked, [&]() {
		if (joc4->text().toStdString()[0] == '-') {
			string juc = j.getJucator();
			joc4->setText(QString::fromStdString(juc));
			string jtabla = j.getTabla();
			jtabla[3] = juc[0];
			if (juc == "X") {
				j.setTabla(jtabla);
				j.setJucator("O");
				ctr.modify(j);
			}
			if (juc == "O") {
				j.setTabla(jtabla);
				j.setJucator("X");
				ctr.modify(j);
			}
			update();
		}
	});
	connect(this->joc5, &QPushButton::clicked, [&]() {
		if (joc5->text().toStdString()[0] == '-') {
			string juc = j.getJucator();
			joc5->setText(QString::fromStdString(juc));
			string jtabla = j.getTabla();
			jtabla[4] = juc[0];
			if (juc == "X") {
				j.setTabla(jtabla);
				j.setJucator("O");
				ctr.modify(j);
			}
			if (juc == "O") {
				j.setTabla(jtabla);
				j.setJucator("X");
				ctr.modify(j);
			}
			update();
		}
	});
	connect(this->joc6, &QPushButton::clicked, [&]() {
		if (joc6->text().toStdString()[0] == '-') {
			string juc = j.getJucator();
			joc6->setText(QString::fromStdString(juc));
			string jtabla = j.getTabla();
			jtabla[5] = juc[0];
			if (juc == "X") {
				j.setTabla(jtabla);
				j.setJucator("O");
				ctr.modify(j);
			}
			if (juc == "O") {
				j.setTabla(jtabla);
				j.setJucator("X");
				ctr.modify(j);
			}
			update();
		}
	});
	connect(this->joc7, &QPushButton::clicked, [&]() {
		if (joc7->text().toStdString()[0] == '-') {
			string juc = j.getJucator();
			joc7->setText(QString::fromStdString(juc));
			string jtabla = j.getTabla();
			jtabla[6] = juc[0];
			if (juc == "X") {
				j.setTabla(jtabla);
				j.setJucator("O");
				ctr.modify(j);
			}
			if (juc == "O") {
				j.setTabla(jtabla);
				j.setJucator("X");
				ctr.modify(j);
			}
			update();
		}
	});
	connect(this->joc8, &QPushButton::clicked, [&]() {
		if (joc8->text().toStdString()[0] == '-') {
			string juc = j.getJucator();
			joc8->setText(QString::fromStdString(juc));
			string jtabla = j.getTabla();
			jtabla[7] = juc[0];
			if (juc == "X") {
				j.setTabla(jtabla);
				j.setJucator("O");
				ctr.modify(j);
			}
			if (juc == "O") {
				j.setTabla(jtabla);
				j.setJucator("X");
				ctr.modify(j);
			}
			update();
		}
	});
	connect(this->joc9, &QPushButton::clicked, [&]() {
		if (joc9->text().toStdString()[0] == '-') {
			string juc = j.getJucator();
			joc9->setText(QString::fromStdString(juc));
			string jtabla = j.getTabla();
			jtabla[8] = juc[0];
			if (juc == "X") {
				j.setTabla(jtabla);
				j.setJucator("O");
				ctr.modify(j);
			}
			if (juc == "O") {
				j.setTabla(jtabla);
				j.setJucator("X");
				ctr.modify(j);
			}
			update();
		}
	});


}