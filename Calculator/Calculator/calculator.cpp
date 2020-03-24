#include <iostream>     
#include <iomanip>
#include "calculator.h"
#include"ui_calculator.h"
#include<cmath>
#include<vector>
#include<String>
#include <Qtcore>

Calculator::Calculator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.zero,		SIGNAL(released()), this, SLOT(clickDigit()));
	connect(ui.jeden,		SIGNAL(released()), this, SLOT(clickDigit()));
	connect(ui.dwa,			SIGNAL(released()), this, SLOT(clickDigit()));
	connect(ui.trzy,		SIGNAL(released()), this, SLOT(clickDigit()));
	connect(ui.cztery,		SIGNAL(released()), this, SLOT(clickDigit()));
	connect(ui.piec,		SIGNAL(released()), this, SLOT(clickDigit()));
	connect(ui.szesc,		SIGNAL(released()), this, SLOT(clickDigit()));
	connect(ui.siedem,		SIGNAL(released()), this, SLOT(clickDigit()));
	connect(ui.osiem,		SIGNAL(released()), this, SLOT(clickDigit()));
	connect(ui.dziewiec,	SIGNAL(released()), this, SLOT(clickDigit()));
	connect(ui.przecinek,	SIGNAL(released()), this, SLOT(clickPoint()));
	connect(ui.procent,		SIGNAL(released()), this, SLOT(click_procent()));
	connect(ui.plusminus,	SIGNAL(released()), this, SLOT(klik_plus_minus()));
	connect(ui.procent,		SIGNAL(released()), this, SLOT(klik_plus_minus()));
	connect(ui.clear,		SIGNAL(released()), this, SLOT(click_clear()));
	connect(ui.rowna,		SIGNAL(released()), this, SLOT(click_rowne()));
	connect(ui.plus,		SIGNAL(released()), this, SLOT(click_plus()));
	connect(ui.minus,		SIGNAL(released()), this, SLOT(click_minus()));
	connect(ui.razy,		SIGNAL(released()), this, SLOT(click_razy()));
	connect(ui.podzielic,	SIGNAL(released()), this, SLOT(click_podzielic()));
	connect(ui.backspace,	SIGNAL(released()), this, SLOT(backspaceClicked()));
	connect(ui.memory_minus,SIGNAL(released()), this, SLOT(pamiec()));
	connect(ui.memory_show, SIGNAL(released()), this, SLOT(pamiec()));
	connect(ui.memory_plus, SIGNAL(released()), this, SLOT(pamiec()));
	connect(ui.memory_last, SIGNAL(released()), this, SLOT(pamiec()));
	connect(ui.memory_first,SIGNAL(released()), this, SLOT(pamiec()));
	connect(ui.memory_all,	SIGNAL(released()), this, SLOT(pamiec()));
	connect(ui.sinus,		SIGNAL(released()), this, SLOT(trygonometryczne()));
	connect(ui.cosinus,		SIGNAL(released()), this, SLOT(trygonometryczne()));
	connect(ui.tangens,		SIGNAL(released()), this, SLOT(trygonometryczne()));
	connect(ui.logarytm,	SIGNAL(released()), this, SLOT(logarytmy()));
	connect(ui.lognat,		SIGNAL(released()), this, SLOT(logarytmy()));
	connect(ui.random,		SIGNAL(released()), this, SLOT(random()));
	connect(ui.kwadrat,		SIGNAL(released()), this, SLOT(dzialania()));
	connect(ui.szescian,	SIGNAL(released()), this, SLOT(dzialania()));
	connect(ui.odwrotnosc,	SIGNAL(released()), this, SLOT(dzialania()));
	connect(ui.pierwiastek, SIGNAL(released()), this, SLOT(dzialania()));
	connect(ui.silnia,		SIGNAL(released()), this, SLOT(dzialania()));
	connect(ui.naukowy,		SIGNAL(released()), this, SLOT(wersja_Kalkulatora()));
	connect(ui.klasyczny,	SIGNAL(released()), this, SLOT(wersja_Kalkulatorakl()));
	connect(ui.Gauss,		SIGNAL(released()), this, SLOT(nowe()));
	connect(ui.tomek,		SIGNAL(released()), this, SLOT(nowe()));

	ui.plus->setCheckable(true);
	ui.razy->setCheckable(true);
	ui.minus->setCheckable(true);
	ui.podzielic->setCheckable(true);
	ui.memory_minus->setCheckable(true);
	ui.memory_show->setCheckable(true);
	ui.memory_plus->setCheckable(true);
	ui.memory_first->setCheckable(true);
	ui.memory_last->setCheckable(true);
	ui.memory_all->setCheckable(true);
	ui.klasyczny->setCheckable(true);
	ui.naukowy->setCheckable(true);
	ui.klasyczny->setChecked(true);
	ui.logarytm->setCheckable(true);
	ui.lognat->setCheckable(true);
	ui.pierwiastek->setCheckable(true);
	ui.odwrotnosc->setCheckable(true);
	ui.kwadrat->setCheckable(true);
	ui.szescian->setCheckable(true);
	ui.silnia->setCheckable(true);
	ui.sinus->setCheckable(true);
	ui.cosinus->setCheckable(true);
	ui.tangens->setCheckable(true);
	ui.Gauss->setCheckable(true);
	ui.tomek->setCheckable(true);

	z = new Complex();
	t = new Tomek();

	ui.backspace->setStyleSheet("background-color: gray");
}

Calculator::~Calculator()
{
	if (z->isVisible())
	{
		z->close();
	}
	if (t->isVisible())
	{
		t->close();
	}

	delete z;
	delete t;
}
void Calculator::backspaceClicked()
{
	/*Pobranie zawartoœci lineEdita*/
	QString text = ui.lineEdit->text(); 
	text.chop(1); //usuniêcie ostatniego chara ze zmiennej text
	if (text.isEmpty()) 
	{
		text = "0";			// jezeli lineEdit jest pusty wype³nij go zerem
	}
	ui.lineEdit->setText(text); //Ustawienie tekstu lineEdita
}
void Calculator::wersja_Kalkulatorakl()
{
	if (ui.klasyczny->isChecked()) //Sprawdzenie czy klasyczny zosta³ naciœniety
	{
		ui.naukowy->setChecked(false); //Ustawienie przyciksu odklikniêtego
		ui.centralWidget->setFixedSize(291, 373); //ustawienie rozmiaru ca³ego okna
		this->setFixedSize(291, 373); 
	}
}
void Calculator::wersja_Kalkulatora()
{
	if (ui.naukowy->isChecked())//Sprawdzenie czy naukowy zosta³ naciœniety
	{
		ui.klasyczny->setChecked(false);//Ustawienie przyciksu odklikniêtego
		ui.centralWidget->setFixedSize(536, 375);//ustawienie rozmiaru ca³ego okna
		this->setFixedSize(534, 372);
	}
}
void Calculator::clickDigit()
{
	if (ui.lineEdit->text() == '0')
	{
		ui.lineEdit->clear();
	}

	/*stworzenie wskaŸnika dowolnego buttona */
	QPushButton * button = (QPushButton*)sender(); 
	/*Tutaj wpisana jest cyfra, pobrana z textu buttona*/
	double liczbaButtonow; 
	QString newLine; 

	if ((ui.plus->isChecked() || ui.minus->isChecked() || ui.razy->isChecked() || ui.podzielic->isChecked()) && (!useristypingseconnumber))/*! */
	{
		liczbaButtonow = button->text().toDouble(); /*! */
		useristypingseconnumber = true;
		newLine = QString::number(liczbaButtonow, 'g', 15); //zamiana typu double na typ QString, o precyzji 15
	}
	else
	{
		if (ui.lineEdit->text().contains('.') && button->text() == "0")
		{
			newLine = ui.lineEdit->text() + button->text();
		}
		else
		{
			liczbaButtonow = (ui.lineEdit->text() + button->text()).toDouble();
			newLine = QString::number(liczbaButtonow, 'g', 15); // konwertuje z double na String liczbe o precyji 15
		}

	}
	ui.lineEdit->setText(newLine); // ustawienie tekstu lineEdita na "newLine"
}
void Calculator::clickPoint()
{
	if (ui.lineEdit->text().isEmpty())
	{
		ui.lineEdit->setText("0");			// jezeli lineEdit jest pusty ustaw zero
	}
	QString line = ui.lineEdit->text(); // pobranie textu z lineEdita
	if (!line.contains('.') && !ui.lineEdit->text().isEmpty())  
	{
		ui.lineEdit->setText(ui.lineEdit->text() + '.');  // Je¿eli "line" nie zawiera przecinka, oraz 
														  //lineEdit nie jest pusty do lineEdita dodana zostanie kropke
	}
}
void Calculator::klik_plus_minus()
{
	if (ui.lineEdit->text().isEmpty())
	{
		ui.lineEdit->setText("0");				// jezeli lineEdit jest pusty ustaw zero
	}
	/*stworzenie wskaŸnika dowolnego buttona */
	QPushButton * button = (QPushButton*)sender();
	/*Tutaj wpisana jest cyfra, pobrana z textu buttona*/
	double liczbaButtonow;
	/*Tutaj wpisany jest tekst po odpowiednich obliczeniach, a nastêpnie wpisywany jest do lineEdita*/
	QString newLine;

	if (button->text() == "+/-")
	{
		liczbaButtonow = ui.lineEdit->text().toDouble();
		liczbaButtonow = liczbaButtonow * (-1);					//Je¿eli tekst buttona to +/- pomnó¿ zawartoœæ lineEdita przez -1
		newLine = QString::number(liczbaButtonow, 'g', 15);		
	}

	else if (button->text() == "%")
	{
		liczbaButtonow = ui.lineEdit->text().toDouble();
		liczbaButtonow = liczbaButtonow * 0.01;					//Je¿eli tekst buttona to +/- pomnó¿ zawartoœæ lineEdita przez 0.01
		newLine = QString::number(liczbaButtonow, 'g', 15);
	}
	ui.lineEdit->setText(newLine);
}
void Calculator::click_clear()
{
	ui.plus->setChecked(false);
	ui.minus->setChecked(false);
	ui.razy->setChecked(false);				//Ustawienie przycisków funkcyjnych odklikniêtych
	ui.podzielic->setChecked(false);

	useristypingseconnumber = false;
	ui.lineEdit->setText("0");  //wyczyszczenie tekstu i wstawienie zera
}
void Calculator::click_rowne()
{
	if (ui.lineEdit->text().isEmpty())
	{
		ui.lineEdit->setText("0");		//Je¿eli lineEdit pusty ustaw zero
	}

	/* Tutaj zapisywane s¹ wyniki obliczeñ */
	double liczbaButtonow;
	/* Tutaj pobierana jest druga liczba do obliczeñ z lineEdita */
	double secondNum;
	/* Tutaj zapisywana zostaje liczba po wszystkich obliczeniach */
	QString newLine;
	/*Druga liczba do obliczeñ pobrana z lineEdita*/
	secondNum = ui.lineEdit->text().toDouble();

	if (ui.plus->isChecked())
	{
		liczbaButtonow = firstNum + secondNum;
		newLine = QString::number(liczbaButtonow, 'g', 15);
		ui.lineEdit->setText(newLine);
		ui.plus->setChecked(false);
	}
	else if (ui.minus->isChecked())
	{
		liczbaButtonow = firstNum - secondNum;
		newLine = QString::number(liczbaButtonow, 'g', 15);
		ui.lineEdit->setText(newLine);
		ui.minus->setChecked(false);
	}
	else if (ui.razy->isChecked())
	{
		liczbaButtonow = firstNum * secondNum;
		newLine = QString::number(liczbaButtonow, 'g', 15);
		ui.lineEdit->setText(newLine);
		ui.razy->setChecked(false);
	}
	else if (ui.podzielic->isChecked())
	{
		if (secondNum != 0)
		{
			liczbaButtonow = firstNum*(1 / secondNum);
			newLine = QString::number(liczbaButtonow, 'g', 14);
			ui.lineEdit->setText(newLine);
		}
		else
		{
			QMessageBox::warning(this, "Blad", "Nie dzielimy przez zero");
			ui.lineEdit->setText("https://bit.ly/2OJe9yY");			//Wys³ania ostrze¿enia, podczas dzielenia przez zero
		}
		ui.podzielic->setChecked(false);
	}
	useristypingseconnumber = false;
	licznik = 0;
}
void Calculator::click_podzielic()
{
	if (ui.lineEdit->text().isEmpty())
	{
		ui.lineEdit->setText("0");		//Je¿eli lineEdit pusty ustaw zero
	}

	if (ui.podzielic->isChecked())
	{
		ui.plus->setChecked(false);
		ui.razy->setChecked(false);		//Ustawienie reszty przycisków odklikniêtych
		ui.minus->setChecked(false);
	}
	if (!ui.lineEdit->text().isEmpty())
		firstNum = ui.lineEdit->text().toDouble();	//Pobranie pierwszej liczby
	
}
void Calculator::click_plus()
{
	if (ui.lineEdit->text().isEmpty())
	{
		ui.lineEdit->setText("0");		//Je¿eli lineEdit pusty ustaw zero
	}
	if (ui.plus->isChecked())
	{
		ui.minus->setChecked(false);
		ui.razy->setChecked(false);		//Ustawienie reszty przycisków odklikniêtych
		ui.podzielic->setChecked(false);
	}
	if (!ui.lineEdit->text().isEmpty())
	firstNum = ui.lineEdit->text().toDouble();	//Pobranie pierwszej liczby
}
void Calculator::click_minus()
{
	if (ui.lineEdit->text().isEmpty())
	{
		ui.lineEdit->setText("0");		//Je¿eli lineEdit pusty ustaw zero
	}
	if (ui.minus->isChecked())
	{
		ui.plus->setChecked(false);
		ui.razy->setChecked(false);		//Ustawienie reszty przycisków odklikniêtych
		ui.podzielic->setChecked(false);
	}
	if (!ui.lineEdit->text().isEmpty())
	firstNum = ui.lineEdit->text().toDouble();		//Pobranie pierwszej liczby
}
void Calculator::click_razy()
{
	if (ui.lineEdit->text().isEmpty())
	{
		ui.lineEdit->setText("0");		//Je¿eli lineEdit pusty ustaw zero
	}
	if (ui.razy->isChecked())
	{
		ui.plus->setChecked(false);
		ui.minus->setChecked(false);	//Ustawienie reszty przycisków odklikniêtych
		ui.podzielic->setChecked(false);
	}
	if (!ui.lineEdit->text().isEmpty())
	firstNum = ui.lineEdit->text().toDouble();	//Pobranie pierwszej liczby
}
void Calculator::trygonometryczne()
{
	if (ui.lineEdit->text().isEmpty())
	{
		ui.lineEdit->setText("0");			//Je¿eli lineEdit pusty ustaw zero
	}

	/*Wartoœæ pobrana z lineEdita*/
	double num = ui.lineEdit->text().toDouble();
	/*Tutaj zapisywana jest liczba w typie Qstring o precyzji 15*/
	QString newLine;
	/*Tutaj zapisywany jest wynik obliczeñ trygonometrycznych*/
	double obliczenie;
	if (ui.sinus->isChecked())
	{
		obliczenie = sin(num);
		newLine = QString::number(obliczenie, 'g', 15);
		ui.lineEdit->setText(newLine);
		ui.sinus->setChecked(false);
	}
	else if (ui.cosinus->isChecked())
	{
		obliczenie = cos(num);
		newLine = QString::number(obliczenie, 'g', 15);
		ui.lineEdit->setText(newLine);
		ui.cosinus->setChecked(false);
	}
	else if (ui.tangens->isChecked())
	{
		obliczenie = tan(num);
		newLine = QString::number(obliczenie, 'g', 15);
		ui.lineEdit->setText(newLine);
		ui.tangens->setChecked(false);
	}
}
void Calculator::logarytmy()
{
	if (ui.lineEdit->text().isEmpty())
	{
		ui.lineEdit->setText("0");			//Je¿eli lineEdit pusty ustaw zero
	}
	/*Tutaj zapisywana jest liczba z lineEdita*/
	double num = ui.lineEdit->text().toDouble();
	/*Tutaj zapisywana jest liczba w typie Qstring, po obliczeniach o precyzji 15*/
	QString newLine;
	/*Tutaj zapisywana jest liczba po obliczeniach*/
	double obliczenie;
	if (ui.logarytm->isChecked())
	{
		if (num > 0)	//sprawdzenie czy liczba logarytmowana jest wiêksza od zera
		{
			obliczenie = log10(num);
			newLine = QString::number(obliczenie, 'g', 15);
			ui.lineEdit->setText(newLine);
		}
		else
		{
			QMessageBox::warning(this, "Blad", "Obliczenie logarytmu z liczby mniejszej, lub rownej zeru jest nie mozliwe!");
		}
		ui.logarytm->setChecked(false);
	}
	else if (ui.lognat->isChecked())
	{
		if (num > 0)	//sprawdzenie czy liczba logarytmowana jest wiêksza od zera
		{
			obliczenie = log(num);
			newLine = QString::number(obliczenie, 'g', 15);
			ui.lineEdit->setText(newLine);
		}
		else
		{
			QMessageBox::warning(this, "Blad", "Obliczenie logarytmu z liczby mniejszej, lub rownej zeru jest nie mozliwe!");
		}
		ui.lognat->setChecked(false);
	}
}
void Calculator::random()
{
	/*Liczba wylosowana*/
	double r = rand();
	QString newLine;
	newLine = QString::number(r, 'g', 15);
	ui.lineEdit->setText(newLine);
}
void Calculator::dzialania()
{
	if (ui.lineEdit->text().isEmpty())
	{
		ui.lineEdit->setText("0");
	}
	/*Tutaj zapisywana jest liczba po wszystkich obliczeniach w typie QString o precyzji 15*/
	QString newLine;
	/*Tutaj pobrana jest liczba z lineEdita*/
	double num = ui.lineEdit->text().toDouble();
	/*Tutaj zapisywana jest liczba po obliczeniach*/
	double obliczenie;
	if (ui.kwadrat->isChecked())	//potêga druga
	{
		obliczenie = num*num;
		newLine = QString::number(obliczenie, 'g', 15);
		ui.lineEdit->setText(newLine);
		ui.kwadrat->setChecked(false);
	}
	else if (ui.szescian->isChecked()) //Potêga trzecia
	{
		obliczenie = num*num*num;
		newLine = QString::number(obliczenie, 'g', 15);
		ui.lineEdit->setText(newLine);
		ui.szescian->setChecked(false);
	}
	else if (ui.odwrotnosc->isChecked()) //1/x
	{
		if (ui.lineEdit->text() == "0")
		{
			QMessageBox::warning(this, "Blad", "Dzielisz przez 0");
			ui.odwrotnosc->setChecked(false);
		}
		else
		{
			obliczenie = 1 / num;
			newLine = QString::number(obliczenie, 'g', 15);
			ui.lineEdit->setText(newLine);
			ui.odwrotnosc->setChecked(false);
		}
	}
	else if (ui.pierwiastek->isChecked()) //Pierwiastek
	{
		if (num >= 0)
		{
			obliczenie = sqrt(num);
			newLine = QString::number(obliczenie, 'g', 15);
			ui.lineEdit->setText(newLine);
		}
		else
		{
			QMessageBox::warning(this, "Blad", "Pierwiastek liczymy tylko z liczb wiêkszych lub równych zeru!!");
		}
		ui.pierwiastek->setChecked(false);
	}
	else if (ui.silnia->isChecked()) //Silnia
	{
		/*Wartoœæ po obliczeniach silni pocz¹tkowo równa jeden*/
		int silnia = 1;
		if (num < 0 || num / ceil(num) != 1)  //Sprawdzenie czy liczba nale¿y do liczb Naturalnych
		{
			QMessageBox::warning(this, "Blad", "Liczba musi nalezec do zbioru liczb naturalnych");
		}
		else if (num < 28) //Max liczba z której liczona jest silnia
		{
			for (int i = 1; i <= num; ++i)
			{
				silnia *= i;
			}

			newLine = QString::number(silnia, 'g', 30);
			ui.lineEdit->setText(newLine);
		}
		else
		{
			ui.lineEdit->setText("inf"); //Je¿eli liczba jest zbyt du¿a
		}
		ui.silnia->setChecked(false);
	}
}
void Calculator::pamiec()
{
	if (ui.lineEdit->text().isEmpty())
	{
		ui.lineEdit->setText("0");			//Je¿eli lineEdit pusty ustaw zero
	}
	/*Zapisanie tego co bêdzie dodane do pamiêci*/
	QString mem;
	/*Urzywane w Mr do zsumowania elementów pamiêci*/
	double suma_pamieci = 0;
	/*Tutaj zapisywana jest suma_pamieci przekonwertowana na typ QString*/
	QString newLine;

	if (ui.memory_plus->isChecked())	//M+
	{
		mem = ui.lineEdit->text();
		tab.push_back(mem);
		ui.memory_plus->setChecked(false);
	}
	else if (ui.memory_minus->isChecked())	//M-
	{
		if (!tab.empty())							//Usuniêcie 
		{											//Ostatnio dodanego elementu z wektora
			tab.pop_back();							
		}
		ui.memory_minus->setChecked(false);
	}
	else if (ui.memory_show->isChecked()) //Mr
	{
		for (int i = 0; i < tab.size(); ++i)
		{
			suma_pamieci += tab[i].toDouble();				//Zsumowanie wszystkich elementów wektora

		}
		newLine = QString::number(suma_pamieci, 'g', 15);
		ui.lineEdit->setText(newLine);
		ui.memory_show->setChecked(false);
	}
	else if (ui.memory_first->isChecked()) //Mf
	{
		if (!tab.empty())
		{
			ui.lineEdit->setText(tab[0]);			//Pokazanie pierwszego dodanego elementu
		}
		ui.memory_first->setChecked(false);
	}
	else if (ui.memory_last->isChecked())	//Ml
	{
		if (!tab.empty())
		{
			int p = tab.size() - 1;						//Pokazanie ostatniego dodanego elementu
			ui.lineEdit->setText(tab[p]);
		}
		ui.memory_last->setChecked(false);
	}
	else if (ui.memory_all->isChecked()) //Ma
	{
		if (!tab.empty())
		{
			for (int i = 0; i < tab.size(); ++i)
			{
				mem += tab[i];
				if (i != tab.size() - 1)					//Pokazanie urzytkownikowi jakie liczny doda³ do pamiêci
				{
					mem += ", ";
				}
			}
			mem += "  :Takie liczby znajduja sie w Twojej pamieci.";
			QMessageBox::information(this, "W pamieci: ", mem);
		}
		else
		{
			QMessageBox::information(this, "W pamieci: ", "Twoja pamiec jest pusta.");
		}
		ui.memory_all->setChecked(false);
	}
}
void Calculator::nowe()
{
	if (ui.Gauss->isChecked())
	{
			z->show();										// Dodanie do G³ównego okna QWidgetu 
			z->ui->lineEdit->clear();
			z->ui->Im1->clear();
			z->ui->Im2->clear();
			z->ui->Re1->clear();
			z->ui->Re2->clear();
			z->setGeometry(450, 530, 319, 212);				// do wykonywania obliczen na liczbach zespolonych
			ui.Gauss->setChecked(false);
	}
	else if (ui.tomek->isChecked())
	{														// Dodanie do G³ównego okna QWidgetu 
			t->show();										// do zamiany jednostek
			t->ui->lineEdit->clear();
			t->ui->lineEdit_przeliczone->clear();
			t->setGeometry(400, 300, 270, 113);			
			ui.tomek->setChecked(false);
	}
}
void Calculator::keyPressEvent(QKeyEvent * event)
{
	
	if (ui.lineEdit->text() == '0')
	{
		ui.lineEdit->clear();
	}


	if (ui.razy->isChecked() | ui.podzielic->isChecked() | ui.plus->isChecked() | ui.minus->isChecked())
	{
		ui.lineEdit->text().clear();
	}


	if (event->key() == Qt::Key_Period && !ui.lineEdit->text().contains(".")) // Dodanie "." do lineEdita
	{
		QString line = ui.lineEdit->text();
		if (ui.lineEdit->text().isEmpty())
		{
			line += "0.";
		}
		else
		{
			line += ".";
		}
		ui.lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_0) // Dodanie "0" do lineEdita
	{
		QString line = ui.lineEdit->text();
		line += '0';
		ui.lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_1) // Dodanie "1" do lineEdita
	{
		QString line = ui.lineEdit->text();
		line += '1';
		ui.lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_2) // Dodanie "2" do lineEdita
	{
		QString line = ui.lineEdit->text();
		line += '2';
		ui.lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_3) // Dodanie "3" do lineEdita
	{
		QString line = ui.lineEdit->text();
		line += '3';
		ui.lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_4) // Dodanie "4" do lineEdita
	{
		QString line = ui.lineEdit->text();
		line += '4';
		ui.lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_5) // Dodanie "5" do lineEdita
	{
		QString line = ui.lineEdit->text();
		line += '5';
		ui.lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_6) // Dodanie "6" do lineEdita
	{
		QString line = ui.lineEdit->text();
		line += '6';
		ui.lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_7) // Dodanie "7" do lineEdita
	{
		QString line = ui.lineEdit->text();
		line += '7';
		ui.lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_8) // Dodanie "8" do lineEdita
	{
		QString line = ui.lineEdit->text();
		line += '8';
		ui.lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_9) // Dodanie "9" do lineEdita
	{
		QString line = ui.lineEdit->text();
		line += '9';
		ui.lineEdit->setText(line);
	}
	else if (event->key() == Qt::Key_Backspace) //Usuwanie ostatniego chara z lineEdita
	{
		QString line = ui.lineEdit->text();
		line.chop(1);
		if (line.isEmpty())
		{
			ui.lineEdit->setText("0");
		}
		else
		{
			ui.lineEdit->setText(line);
		}
	}
	else if (event->key() == Qt::Key_C)	//Wyczyszczenie lineEdita i wstawienie zera
	{
		ui.lineEdit->setText("0");
	}
	else if (event->key() == Qt::Key_S)
	{
		QString mem;
		if (!tab.empty())
		{
			for (int i = 0; i < tab.size(); ++i)
			{
				mem += tab[i];
				if (i != tab.size() - 1)					//Pokazanie u¿ytkownikowi jakie liczby doda³ do pamiêci
				{
					mem += ", ";
				}
			}
			mem += "  :Takie liczby znajduja sie w Twojej pamieci.";
			QMessageBox::information(this, "W pamieci: ", mem);
		}
		else
		{
			QMessageBox::information(this, "W pamieci: ", "Twoja pamiec jest pusta.");
		}
		if (ui.lineEdit->text().isEmpty())
			ui.lineEdit->setText("0");
	}
	else if (event->key() == Qt::Key_A)
	{
		if (ui.lineEdit->text().isEmpty())
		{
			ui.lineEdit->setText("0");
		}

		QString mem;
		mem = ui.lineEdit->text();
		tab.push_back(mem);
	}
	else if (event->key() == Qt::Key_D)
	{
		if (!tab.empty())							 
		{											
			tab.pop_back();
		}
	}
	else if (event->key() == Qt::Key_Equal)
	{

		ui.rowna->setChecked(true);
		click_rowne();
	}
	else if (event->key() == Qt::Key_Q)
	{
		ui.plus->setChecked(true);
		click_plus();
		//ui.lineEdit->clear();
	}
	else if (event->key() == Qt::Key_W)
	{
		ui.minus->setChecked(true);
		click_minus();
	//	ui.lineEdit->clear();
	}
	else if (event->key() == Qt::Key_E)
	{
		ui.razy->setChecked(true);
		click_razy();
		//ui.lineEdit->clear();
	}
	else if (event->key() == Qt::Key_R)
	{
		ui.podzielic->setChecked(true);
		click_podzielic();
		//ui.lineEdit->clear();
	}
}
