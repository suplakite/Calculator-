#pragma once
#pragma once
#include <cmath>
#include<sstream>


/**
Klasa odpowiedzalna za dzia³ania na liczbach zespolonych, wykorzystywane jest tutaj przeci¹¿enie operatorów, oraz strumieñ pamiêciowy
*/
class Zespolona
{
protected:
	/**
	Czêœæ urojona liczby zespolonej
	*/
	double im;
	/**
	Czêœæ rzeczywista liczby zespolonej
	*/
	double re;
public:
	/**
	Konstruktor liczby zespolonej
	*/
	Zespolona(double a, double b) : im(a), re(b) {};
	/**
	Konstruktor liczby zespolonej
	*/
	Zespolona() {};
	/**
	Konstruktor kopi¹cy
	*/
	Zespolona(Zespolona &a)
	{
		im = a.im;
		re = a.re;
	}
	/**
	Operator dodawania dwóch liczb zespolonych
	*/
	Zespolona operator+(Zespolona b)
	{
		return Zespolona(im + b.im, re + b.re);
	}
	/**
	Operator odejmowania dwóch liczb zespolonych
	*/
	Zespolona operator-(Zespolona b)
	{
		return Zespolona(im - b.im, re - b.re);
	}
	/**
	Operator mno¿enia dwóch liczb zespolonych
	*/
	Zespolona operator*(Zespolona b)
	{
		return Zespolona(im*b.re + re*b.im, re*b.re - im*b.im);
	}
	/**
	Operator dzielenia dwóch liczb zespolonych
	*/
	Zespolona operator/(Zespolona b)
	{
			return Zespolona(((im*b.re - re*b.im) / (b.re*b.re + b.im*b.im)), ((re*b.re + im*b.im) / (b.re*b.re + b.im*b.im)));
	}
	/**
	Operator porównania dwóch liczb zespolonych
	*/
	bool operator==(const Zespolona& b)
	{
		if (re == b.re && im == b.im) {
			return true;
		}
		else
			return false;
	}
	/**
	Metoda zwracaj¹ca liczbê zespolon¹ w postaci stringa 
	*/
	std::string toString()
	{
		std::ostringstream oss;
		oss << re << "+" << im;
		return oss.str();
	}
};