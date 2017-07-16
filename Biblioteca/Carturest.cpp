#include "Carturest.h"

void GUI::deseneaza()
{
	mainLayout = new QHBoxLayout(this);
	tableLayout = new QFormLayout();
	tabel = new QTableView();
	tabel->setSelectionBehavior(QAbstractItemView::SelectRows);
	tabel->setModel(&this->m);
	tableLayout->addWidget(tabel);
	tableLayout->setContentsMargins(50, 50, 0, 50);
	mainLayout->addLayout(tableLayout);
	dreapta = new QFormLayout();
	dreapta->setContentsMargins(0, 50, 50, 50);
	titlu = new QLineEdit();
	tLabel = new QLabel();
	tLabel->setText("Titlu:");
	dreapta->addRow(tLabel, titlu);
	autor = new QLineEdit();
	aLabel = new QLabel();
	aLabel->setText("Autor");
	dreapta->addRow(aLabel, autor);
	gen = new QLineEdit();
	gLabel = new QLabel("Gen:");
	dreapta->addRow(gLabel, gen);
	adauga = new QPushButton();
	adauga->setText("&Adauga");
	sterge=new QPushButton("&Sterge");
	dreapta->addRow(adauga, sterge);
	mainLayout->addLayout(dreapta);
}

void GUI::conectare()
{
	QObject::connect(tabel, &QTableView::clicked, [&]() {
		if (tabel->selectionModel()->selection().indexes().size() > 0)
			this->carteSelectata = ctr.getAll()[tabel->selectionModel()->selection().indexes().at(0).row()];
	});
	QObject::connect(sterge, &QPushButton::clicked, [&]() {
		ctr.dilit(carteSelectata);
		tabel->reset();
		repaint();
	});
	QObject::connect(adauga, &QPushButton::clicked, [&]() {
		string g = gen->text().toStdString();
		if (g != "roman"&&g != "poezii"&&g != "novela"&&g != "stiintific")
			QMessageBox::critical(this, "Eroare", "Gen incorect");
		else {
			int sz = ctr.getAll().size()+1;
			ctr.add(Carte{sz,titlu->text().toStdString(),autor->text().toStdString(),g });
			Model* m = new Model{ ctr };
			tabel->setModel(m);
			repaint();
		}
	});
}