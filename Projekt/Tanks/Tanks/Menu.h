#ifndef MENU_H
#define MENU_H

#include "OriginandPositionTemplate.h"
#include "SFML/Graphics.hpp"

///Typ wyliczeniowy do zapami�tywania poziomu trudno�ci wybranej przez gracza
enum Difficulty { EASY, MEDIUM, HARD };

///Kluzze odpowiadaj�ce wci�ni�ciu odpowiednich przycisk�w i zwi�zanej z nimi reakcji 
enum Keys { UP, DOWN, LEFT, RIGHT, SHOOT, ENTER, ESCAPE };

///Typ wyliczeniowy do rozpoznawania i sprawdzania stanu Gry
enum Game_State { PLAYING, MAIN_MENU, OPTIONS, EXIT, OVER };

///Klasa Menu odpowiadaj�ca za wy�wietlanie informacji i tworzenie interfejsu wizualnego z u�ytkownikiem
class Menu
{
private:
	
	int selectedItem; ///aktualnie wybrana pozycja w Menu wybrana przez u�ytkownika
	sf::Font font; ///czcionka
	sf::Text menu[10];
	sf::Text KeysText[10];
	sf::Text PointsText; ///napis "Punkty"
	sf::Text press_key;
	sf::Text Score; ///wynik w postaci tesktu
	sf::Text GameOver;
	sf::Texture tex;
	sf::Texture title;
	sf::Sprite select_sprite; ///sprite wskazuj�cy pozycj� wybran� przez gracza w Menu
	sf::Sprite Title;
public:

	/** Konstruktor klasy Menu. Inicjuje wszystkie text boxy, sprite'y i ich pozycje w Menu
	@param window wska�nik na obiekt okna
	*/
	Menu(sf::RenderWindow *& window);

	/** Metoda inicjuje ramk� z tekstem
	@param ramka tekstu
	*/
	void Init_text_box(sf::Text & text_box);

	/** Funkcja przesuwa pozycj� wyboru w menu g�r�
	*/
	void MoveUp();

	/** Funkcja przesuwa pozycj� wyboru w d�
	*/
	void MoveDown();

	/** Funkcja sprawdza czy gracz wcisn�� klawisz i wywo�uje odpowiedni� akcj� w Menu gry
	@param ev obiekt przechowuj�cy informacje o zdarzeniach
	@param window wska�nik na okno aplikacji
	@param keys mapa przycisk�w
	*/
	void CheckEvents(sf::Event ev, sf::RenderWindow *& window, std::map<Keys, sf::Keyboard::Key> & keys);

	/** Funkcja rysuje elementy Menu w zale�no�ci od stanu w oknie
	@param window wska�nik na obiekt okna
	*/
	void Draw(sf::RenderWindow *&window);

	/** Funkcja odczytuje odpowiednie zasoby z plik�w i inicjuje sprite'y widoczne w Menu
	*/
	void Init();

	/** Funkcja przypisuje kod wci�nietego klawisza do mapy klawiszy. Czeka ona na wci�ni�cie klawisza przez gracza
	@param keys mapa przycisk�w
	@param window wska�nik na okno aplikacji
	@param id klucz okre�laj�cy jaki klawisz ustawiamy
	@return Zwraca kod wci�ni�tego klawisza
	*/
	int set_Key(std::map<Keys, sf::Keyboard::Key>& keys, sf::RenderWindow *& window, enum Keys id);

	/** Funkcja zamienia kod klaiwsza na odpowiedni� liter�
	@param KeyCode kod klaiwsza
	@return Zwraca obiekt std::string z nazw� klawisza z klawiatury
	*/
	std::string exchange_key_code_to_string(int KeyCode);

	/** Funkcja ustawia poziom trudno�ci oraz pozwala na ustawianie klawiszy w opcjach gry
	@param keys mapa przycisk�w
	@param window wska�nik na okno aplikacji
	*/
	void BindKeysandChangeDifficulty(std::map<Keys, sf::Keyboard::Key>& keys, sf::RenderWindow *& window);

	/** Funkcja zameinia poziom trudno�ci jako klucz na napis
	@param diff poziom trudno�ci
	@return Zwraca obiekt std::string z napisem poziomu trudno�ci
	*/
	std::string Difficulty_to_string(Difficulty diff);

	/** Zamienia punkty na tekst, aby mo�na by�o je wy�wietli� na ekran.
	*/
	void Exchange_points_to_text();
};


#endif