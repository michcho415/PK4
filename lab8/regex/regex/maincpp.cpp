#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include <list>


class Strona
{
private:

	std::string Adres;
	std::string Etykieta;
	std::string Opis;

public:
	std::string getAdres() { return Adres; }
	std::string getOpis() { return Opis; }
	std::string getEtykieta() { return Etykieta; }
	Strona() : Adres(""), Etykieta(""), Opis("") {}
	Strona(std::string pAdres, std::string pEtykieta, std::string pOpis): Adres(pAdres), Etykieta(pEtykieta), Opis(pOpis){}
	~Strona() = default;
	void wypisz()
	{
		std::cout << Etykieta << '\n' << Adres << ' \n' << Opis << "\n\n";
	}
};




void wypisz_znalezione_iteracyjnie(std::string str, std::regex reg)
{
	std::sregex_iterator Current(str.begin(), str.end(), reg);
	std::sregex_iterator End;

	std::ofstream plik;
	plik.open("Wynik.txt", std::ios::trunc);
	plik << "\n\n";

	while (Current != End)
	{
		std::smatch match = *Current;
		plik << match.str() << "\n";
		Current++;
	}

	plik << '\n';
	plik.close();
}

//do zadania nr 3

std::string wytnij_opis(const std::string & str)
{
	std::regex reg1("(.*?)\\d{4}");
	std::smatch match;
	regex_search(str, match, reg1);
	if (!match.empty())
		return match.str(1);
	else {
		return " ";
	}
	

}

std::string wytnij_etykiete(const std::string & str)
{
	std::regex reg1("<(.*?)>");
	std::smatch match;
	regex_search(str, match, reg1);
	if (!match.empty())
		return match.str(1);
	else {
		return " ";
	}
	
}

std::string wytnij_adres(const std::string & str)
{
	std::smatch match;
	std::regex regx("//(.*)");
	regex_search(str, match, regx);
	if (!match.empty())
		return match.str(1);
	else {
		return " ";
	}
	

}


void wczytaj_tekst(std::vector<std::string> & tekst)
{
	std::fstream plik("Tekst.txt");
	std::string linia;
	while (getline(plik, linia))
		tekst.push_back(linia);
	plik.close();
}

void usun_z_tekstu_niepotrzebne_elementy(std::vector<std::string> & pvector)
{
	std::regex regex1("spacja");
	std::string zamien_na = " ";

	for (unsigned int i = 0; i < pvector.size(); i++)
		pvector[i] = regex_replace(pvector[i], regex1, zamien_na);



	std::regex regex2("^(.*?)@");
	for (unsigned int i = 0; i < pvector.size(); i++)
	{
		std::smatch pasujacy;
		std::regex_search(pvector[i], pasujacy, regex2);
		if (!pasujacy.empty())
			pvector[i] = pasujacy.str(1);
	}
}

void wypisz_vector(const std::vector<std::string> & vector)
{
	for (auto el : vector)
		std::cout << el << '\n';
}

void usun_wadliwe(std::list<Strona*> & plista)
{
	std::regex reg1("(https://)?www\.[a-zA-Z]([\\w-]{1,18})?[a-zA-Z]\.(com|pl)");
	for (std::list<Strona*>::iterator i = plista.begin(); i != plista.end(); ++i)
	{
		std::smatch match;
		std::string xd = (*i)->getAdres();
		std::regex_search(xd, match, reg1);
		if (match.empty() || (*i)->getEtykieta() == "")
		{
			delete *i;
			i = plista.erase(i);
		}
	}
}


int main()
{
	//Zadanie 1a

	std::string s1 = "abaacadaeaaaafag";
	std::regex regex1("(a[^a])");
	std::smatch pasuje;

	int ile = 0;
	while (regex_search(s1, pasuje, regex1))
	{
		s1 = pasuje.suffix().str();
		ile++;
	}

	std::cout << "Ile pasuje:"<< ile <<'\n';

	//Zadanie 1b
	std::string numery = "123 123 123 234-234-234";
	std::regex regg("\\d{3}[ -]\\d{3}[ -]\\d{3}");
	wypisz_znalezione_iteracyjnie(numery, regg);

	//Zadanie 2
	std::vector<std::string> tekst;
	wczytaj_tekst(tekst);
	usun_z_tekstu_niepotrzebne_elementy(tekst);
	wypisz_vector(tekst);

	//Zadanie 3
	std::list<Strona*> lista;

	for (auto el : tekst)
		lista.push_front(new Strona(wytnij_adres(el), wytnij_etykiete(el), wytnij_opis(el)));

	std::cout << "Przed: \n";
	for (auto el : lista)
	{
		el->wypisz();
	}

	usun_wadliwe(lista);
	std::cout << "\n";

	
	std::cout << "Po: \n";
	for (auto el : lista)
	{
		el->wypisz();
	}

	//usuniecie listy
	while (!lista.empty())
	{
		delete lista.front();
		lista.pop_front();
	}


	getchar();
	return 0;
}