#include "tomek.hpp"
#include <map>
#include <string>

Tomek::Tomek(QWidget * parent) : QWidget(parent), ui(new Ui::Tomek) {
	ui->setupUi(this);

	//connect(ui->pushButton, SIGNAL(released()), this, SLOT(close()));
	connect(ui->Przelicz, SIGNAL(released()), this, SLOT(dzialania()));
	connect(ui->przecinek, SIGNAL(released()), this, SLOT(clickBackspace()));

	ui->lineEdit_przeliczone->setMaxLength(20);

	jednostki["mm"] = 1;
	jednostki["cm"] = 2;
	jednostki["dm"] = 3;		// Wpisanie do drzewa jednostek oraz odpowiadających im wartością int w celu wykorzystania 
	jednostki["m"] = 4;			// ich w operacji "switch case", która operuje na liczbach całkowitych
	jednostki["km"] = 5;
}

Tomek::~Tomek() {
	delete ui;
}
void Tomek::clickBackspace()
{
	/**
	Przechowanie testu z lineEdita
	*/
	QString text = ui->lineEdit->text(); 
	text.chop(1);  //Usunięcie ostatniego znaku ze zmiennej text
	if (text.isEmpty()) 
	{
		text = "0";			//Jeżeli text jest pusty uzupełnij go zerem
	}
	ui->lineEdit->setText(text);
}
void Tomek::dzialania()
{
	/**
	Jednostka z której użytkownik chce zamienić
	*/
	QString linee = ui->walutaz->currentText();
	/**
	Jednostka na którą użytkownik chce zamienić
	*/
	QString line = ui->walutana->currentText();
	/**
	Tutaj zapiywana jest liczba po obliczeniach zamiany
	*/
	double wartosc;
	/**
	Tutaj wpisywana jest wartość po obliczeniach przekonwertowana na typ string 
	*/
	std::string przeliczone;
	/**
	Tutaj wpisana jest zamieniona wartość string na typ QString w celu 
	wpisania oblicznoej wartości do lineEdita
	*/
	QString odsylane;
	/**
	Jednostka na jaką użytkownik chce zamienić wpisaną liczbę
	zamieniona już na jej odpowiednik w typie int
	*/
	int na = jednostki[line];
	/**
	Jednostka z jakiej użytkownik chce zamienić wpisaną liczbę
	zamieniona już na jej odpowiednik w typie int
	*/
	int z = jednostki[linee];
	wartosc = ui->lineEdit->text().toDouble();
	switch (z)
	{
	case 1: //Użytkownik wpisał mm
	{
		switch (na) // Chce zamienic na:
		{
		case 1: //mm
			wartosc = ui->lineEdit->text().toDouble(); break;
		case 2: //cm
			wartosc = wartosc * 0.1; break;
		case 3: //dm
			wartosc = wartosc * 0.01; break;
		case 4: //m
			wartosc = wartosc * 0.001; break;
		case 5: //km
			wartosc = wartosc * 0.000001; break;
		}
		break;
	}
	case 2: //Użytkownik wpisał cm
	{
		switch (na) //Chce zamienić na:
		{
		case 1: //mm
			wartosc = wartosc * 10; break;
		case 2: //cm
			wartosc = wartosc; break;
		case 3: //dm
			wartosc = wartosc * 0.1; break;
		case 4: //m
			wartosc = wartosc * 0.01; break;
		case 5: //km
			wartosc = wartosc * 0.00001; break;
		}
		break;
	}
	case 3: //Użytkownik wpisał dm
	{
		switch (na) //Chce zamienić na:
		{
		case 1: //mm
			wartosc = wartosc * 100; break;
		case 2: //cm
			wartosc = wartosc * 10; break;
		case 3: //dm
			wartosc = wartosc; break;
		case 4: //m
			wartosc = wartosc * 0.1; break;
		case 5: //km
			wartosc = wartosc * 0.0001; break;
		}
		break;
	}
	case 4: //Użytkownik wpisał m
		switch (na) //Chce zamienić na:
		{
		case 1: //mm
			wartosc = wartosc * 1000; break;
		case 2: //cm
			wartosc = wartosc * 100;break;
		case 3: //dm
			wartosc = wartosc * 10; break;
		case 4: //m
			wartosc = wartosc;break;
		case 5: //km
			wartosc = wartosc* 0.001; break;
			
		}
		break;
	case 5: //Użytkownik wpisał m
		switch (na) //Chce zamienić na:
		{
		case 1: //mm
			wartosc = wartosc * 1000000; break;
		case 2: //cm
			wartosc = wartosc * 100000; break;
		case 3: //dm
			wartosc = wartosc * 10000; break;
		case 4: //m
			wartosc = wartosc * 1000; break;
		case 5: //km
			wartosc = wartosc; break;
		}
		break;
	}
	// tutaj przeliczona wartosc zamieniana jest na typ QString i wyswietlana w oknie lineEdit_przeliczone
	//przeliczone = std::to_string(wartosc);
	//odsylane = QString::fromStdString(przeliczone);
	odsylane = QString::number(wartosc, 'g', 15);
	//newLine = QString::number(liczbaButtonow, 'g', 15);
	//ui->textEdit->setText(odsylane);
	ui->lineEdit_przeliczone->setText(odsylane);


	//std::string line = linee.toStdString();




}
void Tomek::keyPressEvent(QKeyEvent * event)
{

	if (ui->lineEdit->text() == '0')
	{
		ui->lineEdit->clear();					// Jeżeli lineEdit jest pusty wstaw "0"
	}

	if (event->key() == Qt::Key_Period && !ui->lineEdit->text().contains(".")) 
	{	// Jeżeli klasisz naciśnięty przez użytkownika to "." oraz aktualny tekst 
		// w lineEdicie nie zawiera już kropki wstaw kropkę
		QString line = ui->lineEdit->text();
		if (ui->lineEdit->text().isEmpty())
		{
			line += "0.";
		}
		else
		{
			line += ".";
		}
		ui->lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_0) //Dodaj na koniec lineEdita "0"
	{
		QString line = ui->lineEdit->text();
		line += '0';
		ui->lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_1) //Dodaj na koniec lineEdita "1"
	{
		QString line = ui->lineEdit->text();
		line += '1';
		ui->lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_2) //Dodaj na koniec lineEdita "2"
	{
		QString line = ui->lineEdit->text();
		line += '2';
		ui->lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_3) //Dodaj na koniec lineEdita "3"
	{
		QString line = ui->lineEdit->text();
		line += '3';
		ui->lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_4) //Dodaj na koniec lineEdita "4"
	{
		QString line = ui->lineEdit->text();
		line += '4';
		ui->lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_5) //Dodaj na koniec lineEdita "5"
	{
		QString line = ui->lineEdit->text();
		line += '5';
		ui->lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_6) //Dodaj na koniec lineEdita "6"
	{
		QString line = ui->lineEdit->text();
		line += '6';
		ui->lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_7) //Dodaj na koniec lineEdita "7"
	{
		QString line = ui->lineEdit->text();
		line += '7';
		ui->lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_8) //Dodaj na koniec lineEdita "8"
	{
		QString line = ui->lineEdit->text();
		line += '8';
		ui->lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_9) //Dodaj na koniec lineEdita "9"
	{
		QString line = ui->lineEdit->text();
		line += '9';
		ui->lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_Backspace) //Usuń ostatni znak z lineEdita
	{
		QString line = ui->lineEdit->text();
		line.chop(1);
		if (line.isEmpty())
		{
			ui->lineEdit->setText("0");
		}
		else
		{
			ui->lineEdit->setText(line);
		}
	}
	else if (event->key() == Qt::Key_C) // Wyczyść lineEdita i wstaw zero
	{
		ui->lineEdit->setText("0");
	}
}
