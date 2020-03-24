#include "complex.hpp"
#include <iostream>     
#include <iomanip>
#include<cmath>
#include<String>
#include <Qtcore>
#include<QTWidgets>


Complex::Complex(QWidget * parent) : QWidget(parent), ui(new Ui::Complex)
{
	ui->setupUi(this);


	//connect(ui->close, SIGNAL(released()), this, SLOT(close()));
	connect(ui->plus, SIGNAL(released()), this, SLOT(dzialania()));
	connect(ui->minus, SIGNAL(released()), this, SLOT(dzialania()));
	connect(ui->podzielic, SIGNAL(released()), this, SLOT(dzialania()));
	connect(ui->razy, SIGNAL(released()), this, SLOT(dzialania()));
	connect(ui->modul, SIGNAL(released()), this, SLOT(dzialania()));
	connect(ui->argument, SIGNAL(released()), this, SLOT(dzialania()));


	ui->plus->setCheckable(true);
	ui->minus->setCheckable(true);
	ui->podzielic->setCheckable(true);
	ui->razy->setCheckable(true);
	ui->modul->setCheckable(true);
	ui->argument->setCheckable(true);

	ui->Re1->setValidator(new QIntValidator);
	ui->Im1->setValidator(new QIntValidator);
	ui->Re2->setValidator(new QIntValidator);
	ui->Im2->setValidator(new QIntValidator);
}

Complex::~Complex()
{
	delete ui;
}
void Complex::dzialania()
{
	/*Tutaj zapisywana jest liczba zespolona po obliczeniach przekonwertowana z typu String na typ QString*/
	QString qstr;
	/*Tutaj zapisywana jest liczba zespolona "c" na typ string
	wykorzystując metode klasy Zespolona .toString() */
	std::string line;
	/*Utworzenie wskaźnika na dowolny przycisk*/
	QPushButton *button = (QPushButton*)sender();
	if (!ui->Re1->text().isEmpty() | !ui->Im1->text().isEmpty() | !ui->Re2->text().isEmpty() | !ui->Im2->text().isEmpty())
	{
		/*Nowo utworzona licza zespolona z danych podanych przez użytkownika*/
		Zespolona a(ui->Im1->text().toDouble(), ui->Re1->text().toDouble());
		/*Nowo utworzona licza zespolona z danych podanych przez użytkownika*/
		Zespolona b(ui->Im2->text().toDouble(), ui->Re2->text().toDouble());
		/*Liczba zespolonona powstała w wyniku obliczeń na liczbach podanych przez użytkownika*/
		Zespolona c;
		
		if (ui->plus->isChecked())
		{
			c = a + b;
			line = c.toString();
			qstr = QString::fromStdString(line);			//Dodawanie liczb zespolnych
			ui->lineEdit->setText(qstr + "i");
			ui->plus->setChecked(false);

		}
		else if (ui->minus->isChecked())
		{
			c = a - b;
			line = c.toString();
			qstr = QString::fromStdString(line);			//Odejmowanie liczb zespolonych
			ui->lineEdit->setText(qstr + "i");
			ui->minus->setChecked(false);

		}
		else if (ui->razy->isChecked())
		{
			c = a * b;
			line = c.toString();
			qstr = QString::fromStdString(line);			//Mnożenie liczb zespolonych
			ui->lineEdit->setText(qstr + "i");
			ui->razy->setChecked(false);
		}
		else if (ui->podzielic->isChecked())
		{
			c = a / b;
			line = c.toString();
			qstr = QString::fromStdString(line);			//Dzielenie liczb zespolonych
			ui->lineEdit->setText(qstr + "i");
			ui->podzielic->setChecked(false);
		}

	}
	else
	{														//Jeżeli w którejś liczbie brakuje Re lub Im 
															//użytkownik zostaje powiadomiony
		QMessageBox::warning(this, "Argument", "Brak czesci rzeczywistej, badz urojonej");
		button->setChecked(false);
	}

	if (ui->modul->isChecked())
	{
		ui->lineEdit->clear();
		if (!ui->Re1->text().isEmpty() | !ui->Im1->text().isEmpty())
		{	//Jeżeli któraś część liczby rzeczywistej Re, bądz Im nie jest pusta zostanie obliczony moduł pierwszej liczby zespolonej 
			double mod1 = sqrt(ui->Re1->text().toDouble()*ui->Re1->text().toDouble() + ui->Im1->text().toDouble()* ui->Im1->text().toDouble());
			line = std::to_string(mod1);
			qstr = QString::fromStdString(line);
			ui->lineEdit->setText("1: " + qstr);
		}
		else
		{	// Jeżeli brakuje części Re lub Im w pierszej liczbie zespolonej użytkownik zostaje powiadomiony
			QMessageBox::warning(this, "Modul", "Brak czesci rzeczywistej, badz urojonej w pierwszej liczbie zespolonej");
		}

		if (!ui->Re2->text().isEmpty() | !ui->Im2->text().isEmpty())
		{	//Jeżeli któraś część liczby rzeczywistej Re, bądz Im nie jest pusta zostanie obliczony moduł drugiej liczby zespolonej
			double mod1 = sqrt(ui->Re2->text().toDouble()*ui->Re2->text().toDouble() + ui->Im2->text().toDouble()*ui->Im2->text().toDouble());
			line = std::to_string(mod1);
			qstr = QString::fromStdString(line);
			ui->lineEdit->setText(ui->lineEdit->text() + " ; " + "2: " + qstr);
		}
		else
		{	// Jeżeli brakuje części Re lub Im w drugiej liczbie zespolonej użytkownik zostaje powiadomiony
			QMessageBox::warning(this, "Modul", "Brak czesci rzeczywistej, badz urojonej w drugiej liczbie zespolonej");
		}

		ui->modul->setChecked(false);
	}
	else if (ui->argument->isChecked())	//Obliczenie argumntu liczb zespolonych
	{
		ui->lineEdit->clear();
		/*Tutaj wpisany zostaje argiment danej liczby zespolonej*/
		double arg;
		if (!ui->Re1->text().isEmpty() | !ui->Im1->text().isEmpty())
		{	//Jeżeli ani część  Re, ani Im nie jest pusta zostanie obliczony argument pierwszej liczby zespolonej
			arg = atan(ui->Re1->text().toDouble() / ui->Im1->text().toDouble());
			line = std::to_string(arg);
			qstr = QString::fromStdString(line);
			ui->lineEdit->setText("1:" + qstr);
		}
		else
		{	// Jeżeli brakuje części Re lub Im w drugiej liczbie zespolonej użytkownik zostaje powiadomiony
			QMessageBox::warning(this, "Argument", "Brak czesci rzeczywistej, badz urojonej w drugiej liczbie zespolonej");
		}

		if (!ui->Re2->text().isEmpty() | !ui->Im2->text().isEmpty())
		{	//Jeżeli ani część  Re, ani Im nie jest pusta zostanie obliczony argument drugiej liczby zespolonej
			arg = atan(ui->Re2->text().toDouble() / ui->Im2->text().toDouble());
			line = std::to_string(arg);
			qstr = QString::fromStdString(line);
			ui->lineEdit->setText(ui->lineEdit->text() + " ; " + "2:" + qstr);
		}
		else
		{	// Jeżeli brakuje części Re lub Im w drugiej liczbie zespolonej użytkownik zostaje powiadomiony
			QMessageBox::warning(this, "Argument", "Brak czesci rzeczywistej, badz urojonej w drugiej liczbie zespolonej");
		}
		ui->argument->setChecked(false);
	}
}

