#include <iostream>
#include <memory>
#include <vector>
#include "vld.h"

using namespace std;

/*********************** Zadanie 1 **************************/

weak_ptr<int> zad1()
{
	auto ptr1 = make_shared<int>();
    cout << "ptr1.use_count(): " << ptr1.use_count() << endl;
    cout << "ptr1.unique(): " << ptr1.unique() << endl << endl;

    auto ptr2 = ptr1, ptr3 = ptr1;

    cout << "ptr1.use_count(): " << ptr1.use_count() << endl;
    cout << "ptr1.unique(): " << ptr1.unique() << endl << endl;

	auto weak = weak_ptr<int>(ptr1);

    cout << "weak.use_count(): " << weak.use_count() << endl;
    cout << "weak.expired(): " << weak.expired() << endl;
    cout << "weak.lock(): " << weak.lock() << endl << endl;

    return weak;
}

/*********************** Zadanie 2 **************************/

struct Element
{
    friend class Stack;

private:
	int value; // value;
	shared_ptr<Element> next; // next;
	shared_ptr<Element> prev;

public:
    // odpowiedni konstruktor
	Element(int val, shared_ptr<Element> ptr) :value(val), next(ptr)
	{
		std::cout << "Jestem konstruktor struktury Element!\n";
	}
    // odpowiedni destruktor
    ~Element()
    {
		std::cout << "Jestem destruktor struktury Element!\n";
        // O_O 
    }
};

class Stack
{
private:
	shared_ptr<Element> head; // head;


public:
    void push(int val)
    {
			head = make_shared<Element>(val, head); // X_X
    }
    int pop()
    {
		int ret;
		if (head)
		{
			ret = head->value;
			head = move(head->next);
		}
		else {
			return -1;
		}
		return ret;
        // U_U
    }
    void print() const
    {
		shared_ptr<Element> temp = head;
		while (temp)
		{
			std::cout << temp->value << '\n';
			temp = temp->next;
		}
        // T_T
    }
};

/*********************** Zadanie 3 **************************/

class Mieszkanie;
class Lokator;

class Mieszkanie
{
	vector<shared_ptr<Lokator>> lokatorzy;

public:
	Mieszkanie()
	{
		std::cout << "Jestem konstruktor klasy Mieszkanie!\n";
	}
	~Mieszkanie()
	{
		std::cout << "Jestem destruktor klasy Mieszkanie!\n";
	}


	void dodaj(const shared_ptr<Lokator> & lok)
	{
		lokatorzy.push_back(lok);
	}
    // ...
};

class Lokator
{
	weak_ptr<Mieszkanie> mieszkanie;

public:
	Lokator()
	{
		std::cout << "Jestem konstruktor klasy Lokator!\n";
	}
	~Lokator()
	{
		std::cout << "Jestem destruktor klasy Lokator!\n";
	}
	void przypisz_mieszkanie(const weak_ptr<Mieszkanie> & ptr)
	{
		mieszkanie = ptr;
	}
    // ...
};

void zad3()
{
    auto mieszkanie = make_shared<Mieszkanie>();

    for (int i = 0; i < 10; ++i)
    {
		auto lok = make_shared<Lokator>();
		lok->przypisz_mieszkanie(mieszkanie);
		mieszkanie->dodaj(lok);
    }
}

/************************************************************/

int main()
{
    cout << boolalpha << "Zadanie 1" << endl << endl;

    auto weak = zad1();

    cout << "weak.use_count(): " << weak.use_count() << endl;
    cout << "weak.expired(): " << weak.expired() << endl;
    cout << "weak.lock(): " << weak.lock() << endl << endl;
	// obiekt zosta³ usuniêty poniewa¿ nie ma do niego zadnej referencji. referencje do niego by³y w funkcji, a weak pointer zacowuje s³abe referencje wiêc obiekt zosta³ usuniêty po zwróceniu



    cout << "Zadanie 2" << endl << endl;

    Stack test;
	test.push(21);
	test.push(40);
	test.push(51);
	test.push(671);
	test.push(631);
	test.push(1);
	test.print();

	test.pop();
	test.pop();
	test.pop();
	test.print();

    // ... 

    cout << "Zadanie 3" << endl << endl;

    zad3();
	getchar();
    return 0;
}
