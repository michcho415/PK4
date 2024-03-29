// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <typeinfo>
//
//  main.cpp
//  Labki_PK4
//
//  Created by Dawid Rudy on 03/03/2020.
//  Copyright © 2020 Dawid Rudy. All rights reserved.
//




//ZAD 1

class TBladMatematyczny : public std::exception
{
public:
	void what()
	{ 
		std::cout << "TBladMatematyczny\n";
	}
};

//**

//ZAD 2
class TDzielPrzezZero :public TBladMatematyczny
{
public:
	void what()
	{
		std::cout << "TDzielPrzezZero\n";
	}
};


//**

//ZAD 3
class TSsak
{
	int waga;
public:
	TSsak(int w = 0) : waga(w) {}
	virtual ~TSsak() {}
	int get_waga() { return waga; }
};


//**

//ZAD 4
class TZwierze : virtual public TSsak
{
	int dlugosc;
public:
	TZwierze(int w = 1, int dl = 2) : TSsak(w), dlugosc(dl) {}
	virtual ~TZwierze() {}
};


//******************************************************************************

//ZAD 5

double dziel(int liczba1, int liczba2)
{
	
	double iloraz = 0;
	if (liczba2 == 0)
	{
		throw TDzielPrzezZero();
	}
	else {
		iloraz = liczba1 / liczba2;
	}

}


//******************************************************************************

int main()
{
	//ZAD 6

	std::cout << "Zad 6: \n";
	try {
		std::cout << dziel(0, 0) << std::endl; //działa
	}
	catch(TDzielPrzezZero& o){
		std::cout << "Nie dzielimy przez zero";
	}
	catch (...)
	{

	}
	

	std::cout << "\n\n";

	//ZAD 7

	TSsak* s1 = new TSsak(1);
	TSsak* s2 = new TSsak(2);
	TSsak* s3 = new TSsak(3);
	TZwierze* z1 = new TZwierze(4, 7);
	TZwierze* z2 = new TZwierze(5, 8);
	TZwierze* z3 = new TZwierze(6, 9);
	TZwierze* z4 = new TZwierze(7, 10);

	TSsak * tab_pSsak[8];
	tab_pSsak[0] = s1;
	tab_pSsak[1] = s2;
	tab_pSsak[2] = s3;
	tab_pSsak[3] = z1;
	tab_pSsak[4] = z2;
	tab_pSsak[5] = z3;
	tab_pSsak[6] = z4;
	tab_pSsak[7] = nullptr;

	//ZAD 8

	std::cout << "Zad 8: \n";

	        for( auto ssak : tab_pSsak )
	        {
				try {
					std::cout << typeid(*ssak).name() << std::endl;
				}
				catch(const std::bad_typeid& e)
				{
					std::cout << "Zlapano wyjatek bad_typid\n";
				}
				catch (...)
				{
					std::cout << "złapano inny wyjatek\n";
				}
	            
	        }

	std::cout << "\n\n";

	//ZAD 9

	std::cout << "Zad 9: \n";

	        for( auto ssak : tab_pSsak )
	        {
				
				try {
					TZwierze & ss = dynamic_cast<TZwierze&>(*ssak);
					std::cout << "Waga: " << ss.get_waga() << std::endl; //błąd wyrzuca dla nullptr bo nie można dla nullptr wywoałać metody trzeba by go sprawdzic za pomoca if()
				}
				catch (const std::bad_cast& e)
				{
					std::cout << "złapano wyjatek bad_cast\n";
				}
				catch (...)
				{
					std::cout << "złapano inny wyjatek\n";
				}
	            
	        }

	std::cout << "\n\n";

}
