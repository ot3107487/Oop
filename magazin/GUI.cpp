#include "GUI.h"

void GUI::deseneaza()
{
	mainLayout = new QHBoxLayout(this);
	first = new QFormLayout();
	tabel = new QTableWidget();
	update();
	slider = new QSlider();
	slider->setOrientation(Qt::Horizontal);
	slider->setMinimum(1);
	slider->setMaximum(100);
	slider->setValue(1);
	tabel->setSelectionBehavior(QAbstractItemView::SelectRows);
	tabel->resizeColumnsToContents();
	first->addRow(tabel);
	vSlider = new QLabel(QString::number(slider->value()));
	first->addRow(vSlider,slider);
	mainLayout->addLayout(first);
	second = new QFormLayout();
	id = new QLineEdit();
	second->addRow(new QLabel("ID:"), id);
	nume = new QLineEdit();
	second->addRow(new QLabel("Nume:"), nume);
	tip = new QLineEdit();
	second->addRow(new QLabel("Tip:"), tip);
	pret = new QLineEdit();
	second->addRow(new QLabel("Pret:"), pret);
	adauga = new QPushButton("Adauga");
	second->addRow(adauga);
	mainLayout->addLayout(second);
}

void GUI::conectare()
{
	QObject::connect(adauga, &QPushButton::clicked, [&]() {
		try {
			ctr.add(Produs{ id->text().toInt(),nume->text().toStdString(),tip->text().toStdString(),pret->text().toDouble() });
			update();
		}
		catch (ValEx& ex) {
			QMessageBox::critical(this, "Eroare", ex.what());

		}
		catch (RepoEx& ex) {
			QMessageBox::critical(this, "Eroare", ex.what());
		}
	});
	QObject::connect(slider, &QSlider::valueChanged, [&]() {
		vSlider->setText(QString::number(slider->value()));
		update();
	});
	QObject::connect(slider, &QSlider::sliderReleased, [&](){
		
	});
}

void GUI::update()
{
	tabel->setRowCount(ctr.getAll().size());
	tabel->setColumnCount(4);
	QStringList header;
	header << "Id" << "Nume" << "Tip" << "Pret";
	tabel->setHorizontalHeaderLabels(header);
	int i = 0;
	for (const auto& p : ctr.getAll()) {
		tabel->setItem(i, 0, new QTableWidgetItem(QString::number(p.getId())));
		tabel->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(p.getNume())));
		tabel->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(p.getTip())));
		tabel->setItem(i, 3, new QTableWidgetItem(QString::number(p.getPret())));
		if (p.getPret() <= (*slider).value())
			for (int j = 0; j < 4; j++) {
				auto it = tabel->item(i, j);
				it->setBackgroundColor(QColor(112,123,j*50));
			}
		i++;
	}

}
