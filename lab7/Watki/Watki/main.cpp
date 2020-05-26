#include <iostream>
#include <thread>
#include <ctime>
#include <chrono>
#include <vector>
#include <mutex>
using namespace std;



class Punkt
{
	//pola
	int x, y;

public:
	Punkt(int x1, int y1) :x(x1), y(y1) {}
	//konstruktor
	void operator() (int mnoznik)
	{
		std::this_thread::sleep_for(std::chrono::seconds(2));
		x = x * mnoznik;
		y = y * mnoznik;
		//...
	}
	void wyswietl_polozenie() {
		std::cout << "X: " << x << '\n';
		std::cout << "Y: " << y << '\n';
	}
    //...
};



class Skarbonka
{
	int suma = 0;
	std::mutex mut;
public:
	void operator() (int ilosc, bool dodaj)
	{
		mut.lock();
		for (int i = 0; i < ilosc; i++)
		{
			if (dodaj)
			{
				std::this_thread::sleep_for(chrono::microseconds(100));
				suma += 1;
				//...
			}
			else
			{
				std::this_thread::sleep_for(chrono::microseconds(100));
				suma -= 1;
				//...
			}
			
		}
		mut.unlock();
		
	}
	void wyswietl()
	{
		std::cout << "Wart w skarbonce: " << suma << '\n';
	}
	//...
};

void losowanie(std::vector<int> & v)
{
	int x;
	for (int i = 0; i < 100; ++i)
	{
		x = (rand() % 100) + 1;
		v.push_back(x);
	}
}

void parzyste(std::vector<int> v)
{
	int ile = 0;
	for (const auto el : v)
	{
		if (!(el % 2))
		{
			++ile;
		}
	}
	std::cout << "Parzyste: " << ile << '\n';
}

void nieparzyste(std::vector<int> v)
{
	int ile = 0;
	for (const auto el : v)
	{
		if (el % 2)
		{
			++ile;
		}
	}
	std::cout << "Nieparzyste: " << ile << '\n';
}

void srednia(double n)
{
	double l1 = n - 1;
	double l2 = n;
	double l3 = n + 1;



	std::thread thr([l1, l2, l3](){ double srednia = ((l1*l1) + (l2*l2) + (l3*l3)) / 3;
								   std::cout << "Srednia: " << srednia << '\n'; });
	thr.join();

}

int main()
{
	srand(time(NULL));
	//Zad 1
	std::cout << "Zadanie 1 " << endl;
	vector<int> losowe;
	std::thread thread1(losowanie, ref(losowe)); //wątek 1
	thread1.join();
	std::thread thread2(parzyste, ref(losowe)); //wątek 2
	thread2.join();
	std::thread thread3(nieparzyste, ref(losowe)); //wątek 3
	thread3.join();
	
	
	

	//Zad 2
	std::cout << "Zadanie 2 " << endl;
	Punkt NowyPunkt(1, 1);
	{
		std::thread thread4(ref(NowyPunkt), 10); // nowy wątek
		thread4.join();
		NowyPunkt.wyswietl_polozenie();
	}
	{
		std::thread thread4(ref(NowyPunkt), 10); // nowy wątek
		thread4.detach();
		NowyPunkt.wyswietl_polozenie();
	} //wątek nie zdązyl zapisać przed wypisaniem


	//Zad 3
	std::cout << "Zadanie 3 " << endl;
	std::thread thread5(srednia, 3);
	thread5.join();
	//nowy watek

	//Zad 4
	std::cout << "Zadanie 4 " << endl;
	Skarbonka NowaSkarbonka;
	std::thread t1(ref(NowaSkarbonka), 500, true);
	std::thread t2(ref(NowaSkarbonka), 500, false);
	std::thread t3(ref(NowaSkarbonka), 500, true);
	std::thread t4(ref(NowaSkarbonka), 500, false);
	std::thread t5(ref(NowaSkarbonka), 500, true);
	std::thread t6(ref(NowaSkarbonka), 500, false);
	std::thread t7(ref(NowaSkarbonka), 500, true);
	std::thread t8(ref(NowaSkarbonka), 500, false);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	NowaSkarbonka.wyswietl(); // wynik czesto rozni sie od siebie przed dodaniem mutexa
	// Nowy watek dodający 500
	// Nowy wątek odejmujący 500
	//...

	// nowywątek.join();
	//...
	getchar();
}

