#pragma once
#include <QWidget>
#include "ui_tomek.h"
#include "Virtual.h"
/**
 Klasa odpowiedzialna za logike dodatkowego modułu w kalkulatorze czyli konwersji jednostek
 */
class Tomek : public QWidget, public Virtual {
	Q_OBJECT

public:
	/**
	Konstruktor
	*/
	Tomek(QWidget * parent = Q_NULLPTR);
	~Tomek(); //Destruktor
	/**
	Wskaźnik na obiekt Tomek
	*/
	Ui::Tomek *ui;

public slots:
	/**
	Tutaj na bazie drzewa utowrzonego w prywatnych elementach klasy Tomek, korzystając ze "Switch case" dokonywana jest konwersja jednostek
	*/
	void dzialania() override;
	/**
	Usunięcie ostatniego chara z lineEdita
	*/
	void clickBackspace();
	/**
	Obsługa klawiatury
	*/
	void keyPressEvent(QKeyEvent * event);
private:
	
	
	/**
	Tutaj przechowywane są wartości dla każdej jednostki wykorzystywane w konwersji jednostki typu string do
	int, w celu możliwości korzystania ze "switch case"
	*/
	std::map <QString, int> jednostki;
};
