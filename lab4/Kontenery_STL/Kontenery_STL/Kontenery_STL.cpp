// Kontenery_STL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <iostream>
#include <stack>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

//Zadanie 3.1


class Student {

	std::string imie;
	std::string nazwisko;
	int nr_zestawu;

public:
	//Zadanie 3.2
	Student() { nr_zestawu = rand() % 101; }
	~Student() = default;
	
	Student(std::string im, std::string nazw) :imie(im), nazwisko(nazw), nr_zestawu(rand() % 101) {}
		int pokaz_zestaw() { return nr_zestawu; }

};

//Zadanie 3.5
void Egzamin(std::queue<Student>& oczek, std::queue<Student>& zd, std::queue<Student>& niezd)
{
	while (!oczek.empty())
	{
		if (oczek.front().pokaz_zestaw() % 2)
		{
			niezd.push(oczek.front());
		}
		else {
			zd.push(oczek.front());
		}
		oczek.pop();
	}
}


//Zadanie 3.6
void wypisz_i_usun(std::queue<Student> & kolejka)
{
	while (!kolejka.empty())
	{
		cout << kolejka.front().pokaz_zestaw() << " ";
		kolejka.pop();
	}
}




int main() {

	srand(time(NULL));
	//Zadanie 1

	vector<int> ile;
	cout << "Podaj ile naleśniow zjadla:";
	int liczba=0;
	for (int i = 0; i < 10; i++)
	{
		cout << "\nOsoba nr " << i+1 << ": ";
		cin >> liczba;
		ile.push_back(liczba);
	}
	liczba = 0;
	for (int i = 0; i < 10; i++)
	{
		if (ile[liczba] < ile[i])
			liczba = i;
	}
	cout << "Najwiecej zjadla osoba nr " << liczba+1 << '\n';

	//Zadanie 2
	std::stack<std::string> stos;
	std::string wyraz;

	std::ifstream plik_we("zdania.txt");
	while (plik_we >> wyraz)
	{
		stos.push(wyraz);
	}

	plik_we.close();

	std::ofstream plik_wy("zdania2.txt");
	while (!stos.empty())
	{
		if (plik_wy)
		{
			plik_wy << stos.top() << " ";
		}
		stos.pop();
	}
	plik_wy.close();

	//Zadanie 3.3
	std::queue<Student> oczekujacy_na_egzamin;
	std::queue<Student> zdali;
	std::queue<Student> nie_zdali;

	//Zadanie 3.4

	oczekujacy_na_egzamin.push({ "Jan", "P." });
	oczekujacy_na_egzamin.push({ "Kazimierz", "S." });
	oczekujacy_na_egzamin.push({ "Pawel", "R." });
	oczekujacy_na_egzamin.push({ "Damian", "G." });
	oczekujacy_na_egzamin.push({ "Karol", "L." });

	Egzamin(oczekujacy_na_egzamin, zdali, nie_zdali);

	std::cout << "\n\nZdali: ";
	wypisz_i_usun(zdali);
	std::cout << "\n\nNie zdali: ";
	wypisz_i_usun(nie_zdali);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
