#pragma once
#include <QWidget>
#include "ui_complex.h"
#include "Virtual.h"
#include "Zespolone.h"
//#include "calculator.h"


/**
Klasa odpowiedzialna za logikę dodatkowego modułu w
kalkulatorze czyli wykonywania obliczen na liczbach zespolonych
*/
class Complex : public QWidget, public Zespolona, public Virtual {
	Q_OBJECT

public:
	/**
	Konstruktor klasy Complex
	*/
	Complex(QWidget * parent = Q_NULLPTR); 
	/**
	Destruktor klasy Complex
	*/
	~Complex(); 

	int licznikcom = 0;
	Ui::Complex *ui;

public slots: //Prywatne sloty funkcji Complex
	/**
	Funkcja nadpisywana klasy bazowej Virtual.
	Tutaj wykonywane są wszystkie obliczenia na liczbach zespolonych
	*/
	void dzialania() override;
	/**
	Niszczenie obiektu klasy Complex,
	po naciśnieciu przycisku zamknij.
	*/
	

private:
	
};
