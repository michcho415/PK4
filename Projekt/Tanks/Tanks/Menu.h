#ifndef MENU_H
#define MENU_H

#include "OriginandPositionTemplate.h"
#include "SFML/Graphics.hpp"

///Typ wyliczeniowy do zapamiêtywania poziomu trudnoœci wybranej przez gracza
enum Difficulty { EASY, MEDIUM, HARD };

///Kluzze odpowiadaj¹ce wciœniêciu odpowiednich przycisków i zwi¹zanej z nimi reakcji 
enum Keys { UP, DOWN, LEFT, RIGHT, SHOOT, ENTER, ESCAPE };

///Typ wyliczeniowy do rozpoznawania i sprawdzania stanu Gry
enum Game_State { PLAYING, MAIN_MENU, OPTIONS, EXIT, OVER };

///Klasa Menu odpowiadaj¹ca za wyœwietlanie informacji i tworzenie interfejsu wizualnego z u¿ytkownikiem
class Menu
{
private:
	
	int selectedItem; ///aktualnie wybrana pozycja w Menu wybrana przez u¿ytkownika
	sf::Font font; ///czcionka
	sf::Text menu[10];
	sf::Text KeysText[10];
	sf::Text PointsText; ///napis "Punkty"
	sf::Text press_key;
	sf::Text Score; ///wynik w postaci tesktu
	sf::Text GameOver;
	sf::Texture tex;
	sf::Texture title;
	sf::Sprite select_sprite; ///sprite wskazuj¹cy pozycjê wybran¹ przez gracza w Menu
	sf::Sprite Title;
public:

	/** Konstruktor klasy Menu. Inicjuje wszystkie text boxy, sprite'y i ich pozycje w Menu
	@param window wskaŸnik na obiekt okna
	*/
	Menu(sf::RenderWindow *& window);

	/** Metoda inicjuje ramkê z tekstem
	@param ramka tekstu
	*/
	void Init_text_box(sf::Text & text_box);

	/** Funkcja przesuwa pozycjê wyboru w menu górê
	*/
	void MoveUp();

	/** Funkcja przesuwa pozycjê wyboru w dó³
	*/
	void MoveDown();

	/** Funkcja sprawdza czy gracz wcisn¹³ klawisz i wywo³uje odpowiedni¹ akcjê w Menu gry
	@param ev obiekt przechowuj¹cy informacje o zdarzeniach
	@param window wskaŸnik na okno aplikacji
	@param keys mapa przycisków
	*/
	void CheckEvents(sf::Event ev, sf::RenderWindow *& window, std::map<Keys, sf::Keyboard::Key> & keys);

	/** Funkcja rysuje elementy Menu w zale¿noœci od stanu w oknie
	@param window wskaŸnik na obiekt okna
	*/
	void Draw(sf::RenderWindow *&window);

	/** Funkcja odczytuje odpowiednie zasoby z plików i inicjuje sprite'y widoczne w Menu
	*/
	void Init();

	/** Funkcja przypisuje kod wciœnietego klawisza do mapy klawiszy. Czeka ona na wciœniêcie klawisza przez gracza
	@param keys mapa przycisków
	@param window wskaŸnik na okno aplikacji
	@param id klucz okreœlaj¹cy jaki klawisz ustawiamy
	@return Zwraca kod wciœniêtego klawisza
	*/
	int set_Key(std::map<Keys, sf::Keyboard::Key>& keys, sf::RenderWindow *& window, enum Keys id);

	/** Funkcja zamienia kod klaiwsza na odpowiedni¹ literê
	@param KeyCode kod klaiwsza
	@return Zwraca obiekt std::string z nazw¹ klawisza z klawiatury
	*/
	std::string exchange_key_code_to_string(int KeyCode);

	/** Funkcja ustawia poziom trudnoœci oraz pozwala na ustawianie klawiszy w opcjach gry
	@param keys mapa przycisków
	@param window wskaŸnik na okno aplikacji
	*/
	void BindKeysandChangeDifficulty(std::map<Keys, sf::Keyboard::Key>& keys, sf::RenderWindow *& window);

	/** Funkcja zameinia poziom trudnoœci jako klucz na napis
	@param diff poziom trudnoœci
	@return Zwraca obiekt std::string z napisem poziomu trudnoœci
	*/
	std::string Difficulty_to_string(Difficulty diff);

	/** Zamienia punkty na tekst, aby mo¿na by³o je wyœwietliæ na ekran.
	*/
	void Exchange_points_to_text();
};


#endif