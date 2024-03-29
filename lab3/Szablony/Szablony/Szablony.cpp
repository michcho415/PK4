// Szablony.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

template<class T>
class Vector2D
{
	T x;
	T y;

public:

	Vector2D() = default;
	~Vector2D() = default;

	Vector2D(T x1, T y1) : x(x1), y(y1) {}

	Vector2D(const Vector2D &o)
	{
		x = o.x;
		y = o.y;
	}
	void normalise()
	{
		double dlugosc = std::sqrt(x*x + y*y);
		x = x / dlugosc;
		y = y / dlugosc;
	}

	Vector2D& operator+=(const Vector2D &o)
	{
		x += o.x;
		y += o.y;
		return *this;
	}
	Vector2D operator*(T wartosc)
	{
		Vector2D<T> v;
		v.x = x * wartosc;
		v.y = y * wartosc;
		return v;
	}
	void wypisz()
	{
		std::cout << x << " " << y << std::endl;
	}

};


template<class T>
class Object
{
	Vector2D<T> polozenie;
	Vector2D<T> kierunek;
	T predkosc;

public:

	~Object() = default;

	Object(T polozenieX, T polozenieY, T kierunekX, T kierunekY, T predk): polozenie(polozenieX, polozenieY), kierunek(kierunekX, kierunekY), predkosc(predk)
	{
		kierunek.normalise();
	}

	void move()
	{
		polozenie += kierunek * predkosc;
	}

	void wypisz()
	{
		std::cout << "Polozenie: ";
		polozenie.wypisz();
		std::cout << "\n";
		std::cout << "Kierunek: ";
		kierunek.wypisz();
		std::cout << "\n";
		std::cout << "Predkosc: " << predkosc << std::endl;
	}

};



int main()
{
	Vector2D<double> W1(2.1, 3.7);
	W1.normalise();
	W1.wypisz();

	//kopiowanie
	Vector2D<double> W2(W1);
	W2.wypisz();
	
	//dodawanie
	W1 += W2;
	W1.wypisz();

	//mnozenie
	Vector2D<double> W3(W1*10);
	W3.wypisz();

	//Obiekt
	auto O1 = new Object<double>(2., 3., 5., 5., 3.);
	O1->move();
	O1->wypisz();
	delete O1;



	return 0;

	
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


