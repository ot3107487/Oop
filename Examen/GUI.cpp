#include "GUI.h"
void GUI::deseneaza() {
	mainLayout = new QHBoxLayout(this);
	tabelLayout = new QFormLayout();
	tabel = new QTableWidget();
	update();
	tabelLayout->addWidget(tabel);
	mainLayout->addLayout(tabelLayout);
	secondLayout = new QFormLayout();
	id = new QLineEdit();
	iLab = new QLabel("Id:");
	secondLayout->addRow(iLab, id);
	descriere = new QLineEdit();
	dLab = new QLabel("Descriere:");
	secondLayout->addRow(dLab, descriere);
	stare = new QLineEdit();
	sLab = new QLabel("Stare:");
	secondLayout->addRow(sLab, stare);
	programatori = new QLineEdit();
	pLab = new QLabel("P:");
	secondLayout->addRow(pLab, programatori);
	adauga = new QPushButton("Adauga");
	secondLayout->addRow(adauga);
	filtru = new QLineEdit();
	fLab = new QLabel("Filtru:");
	secondLayout->addRow(fLab, filtru);
	filtreaza = new QPushButton("Filtreaza");
	secondLayout->addRow(filtreaza);
	mainLayout->addLayout(secondLayout);
}
void GUI::conectare() {
	QObject::connect(adauga, &QPushButton::clicked, [&]() {
		int i = id->text().toInt();
		string des = descriere->text().toStdString();
		string pr = programatori->text().toStdString();
		string st = stare->text().toStdString();
		if (st == "open" || st == "inprogress" || st == "closed"&&ctr.program(pr)<=4) {
			ctr.add(Task{ i,des,pr,st });
			//update();
		}
		else
			QMessageBox::critical(this, "Eroare", "Datele introduse nu sunt corecte");

	});
	QObject::connect(filtreaza, &QPushButton::clicked, [&]() {
		string pr = filtru->text().toStdString();
		tabel->setRowCount(ctr.getAll().size());
		tabel->setColumnCount(4);
		tabel->clear();
		QStringList header;
		header << "Id" << "Descriere" << "Stare" << "Nr. Programatori";
		tabel->setHorizontalHeaderLabels(header);

		int i = 0;
		for (const auto& p : ctr.filtru(pr)) {
			tabel->setItem(i, 0, new QTableWidgetItem(QString::number(p.getId())));
			tabel->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(p.getDescriere())));
			tabel->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(p.getStare())));
			tabel->setItem(i, 3, new QTableWidgetItem(QString::number(ctr.program(p.getProgramatori()))));
			i++;
		}});
}