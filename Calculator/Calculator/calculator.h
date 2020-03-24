#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QtWidgets/QMainWindow>
#include "ui_calculator.h"
#include <vector>
#include "tomek.hpp"
#include "complex.hpp"
#include <QKeyEvent>


/** 
Glowna klasa odpowiadaj¹ca za QMainWindow oraz podstawowe operacje kalkulatora naukowego oraz klasycznego.
Tutaj tworzony jest obiek klasy Complex(liczby zespolone), oraz klasy Tomek(konwersja jednostek), w metodzie
"nowe()" po naciœnieciu odpowiedniego przycisku
 */
class Calculator : public QMainWindow
{
	Q_OBJECT

public:
	/**
	Konstruktor klasy Calculator
	*/
	Calculator(QWidget *parent = 0);
	/**
	Destruktor klasy Calculator
	*/
	~Calculator();
	/**
	Wektor, w którym przechowywane s¹ elementy dodane do pamiêci. 
	*/
	std::vector<QString> tab;
	/**
	Tutaj wpisywana jest pierwsza liczba do obliczeñ.
	*/
	double firstNum;
	/**
	Warunek do sprawdzania czy urzytkownik wpisuje ju¿ drug¹ cyfrê.
	*/
	bool useristypingseconnumber = false;
	Ui::CalculatorClass ui;
	int licznik = 0;
	
	
	

protected:
	Complex *z;
	Tomek *t;
	
protected slots:
	/**
	Po nacisniecu jednej z cyfr zostaje ona dodana do lineEdita.
	*/
	void clickDigit(); 
	/**
	Tutaj dodawany jest przecinek.
	*/
	void clickPoint(); 
	/**
	Zmienia znak liczby, oraz przedstawia wynik w procentach.
	*/
	void klik_plus_minus();
	/**
	Cyszczenie lineEdita.
	*/
	void click_clear();
	/**
	Po naciœnieciu przycisku równa siê sprawdzane jest który przycisk znaku dzia³ania jest naciœniêty, 
	oraz pobraniu nowej liczby do obliczeñ(secondNumber).
	Po sprawdzeniu tego wykonywane jest odpowiednie dzia³anie i wysy³ane do lineEdita.
	*/
	void click_rowne();
	/** 
	Zaznaczenie przycisku dzielenie, oraz pobranie pierwszej liczby do obliczeñ (firtsNum).
	*/
	void click_podzielic();
	/** 
	Zaznaczenie przycisku dzielenie, oraz pobranie pierwszej liczby do obliczeñ (firtsNum).
	*/
	void click_plus();
	/** 
	Zaznaczenie przycisku dzielenie, oraz pobranie pierwszej liczby do obliczeñ (firtsNum).
	*/
	void click_minus();
	/**
	Zaznaczenie przycisku dzielenie, oraz pobranie pierwszej liczby do obliczeñ (firtsNum).
	*/
	void click_razy();
	/**
	Usuniêcie ostatniego chara z lineEdita.
	*/
	void backspaceClicked();
	/** 
	Tutaj poprzez wykorzystanie std::vector<QString> tab;  u¿ytkownik dodaje sobie liczby do pamiêci.
	*/
	void pamiec();
	/** 
	Wykorzystywana do obliczeñ trygonometrycznych(sinus, cosinus, tangens).
	*/
	void trygonometryczne();
	/**
	Obliczenie logarytmu o podstawie 10, oraz logarytmu naturalnego.
	*/
	void logarytmy();
	/**
	Wylosowanie liczby pseudolosowej i pokazanie jej w lineEdicie.
	*/
	void random();
	/**
	Tutaj wykonywane s¹ dzia³ania w GUI przedstawione z niewiadom¹ "x"
	tj. odwrotnoœæ, pierwiastek, silnia, kwadrat, oraz szeœcian liczby pobranej z lineEdita.
	*/
	void dzialania();
	/**
	Ustawienie wersji kalkulatora na wersje naukow¹.
	*/
	void wersja_Kalkulatora();
	/** 
	Ustawienie wersji kalkulatora na wersje klasyczn¹.
	*/
	void wersja_Kalkulatorakl();
	/**
	Dodanie dwóch dodatkowych modu³ów tj. do obliczania liczb zespolonych (Klasa Complex),
	oraz modu³u do przeliczania jednostek d³ugoœci w pierwszej potêdze (Klasa Tomek).
	*/
	void nowe();
	/**
	Obs³uga klawiatury.
	*/
	void keyPressEvent(QKeyEvent * event);
};

#endif // CALCULATOR_H
