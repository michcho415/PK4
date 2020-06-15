#ifndef MENU_H
#define MENU_H

#include "OriginandPositionTemplate.h"
#include "SFML/Graphics.hpp"

/**Typ wyliczeniowy do zapamietywania poziomu trudnosci wybranej przez gracza*/
enum Difficulty { EASY, MEDIUM, HARD };

/**Klucze odpowiadajace wcisnieciu odpowiednich przyciskow i zwiazanej z nimi reakcji*/
enum Keys { UP, DOWN, LEFT, RIGHT, SHOOT, ENTER, ESCAPE };

/**Typ wyliczeniowy do rozpoznawania i sprawdzania stanu gry*/
enum Game_State { PLAYING, MAIN_MENU, OPTIONS, EXIT, OVER };

/**Klasa Menu odpowiadajaca za wyswietlanie informacji i tworzenie interfejsu wizualnego z uzytkownikiem*/
class Menu
{
private:
	/**aktualnie wybrana pozycja w Menu wybrana przez uzytkownika*/
	int selectedItem; 
	/**czcionka*/
	sf::Font font; 
	sf::Text menu[10];
	sf::Text KeysText[10];
	/**napis "Punkty"*/
	sf::Text PointsText; 
	sf::Text press_key;
	/**wynik w postaci tesktu*/
	sf::Text Score; 
	sf::Text GameOver;
	sf::Texture tex;
	sf::Texture title;
	/**sprite wskazujzcy pozycje wybrana przez gracza w Menu*/
	sf::Sprite select_sprite; 
	sf::Sprite Title;
public:

	/** Konstruktor klasy Menu. Inicjuje wszystkie text boxy, sprite'y i ich pozycje w Menu
	@param window wskaznik na obiekt okna
	*/
	Menu(sf::RenderWindow *& window);

	/** Metoda inicjuje ramke z tekstem
	@param text_box ramka tekstu
	*/
	void Init_text_box(sf::Text & text_box);

	/** Funkcja przesuwa pozycje wyboru w menu gore
	*/
	void MoveUp();

	/** Funkcja przesuwa pozycje wyboru w dol
	*/
	void MoveDown();

	/** Funkcja sprawdza czy gracz wcisnal klawisz i wywoluje odpowiednia akcje w Menu gry
	@param ev obiekt przechowujacy informacje o zdarzeniach
	@param window wskaznik na okno aplikacji
	@param keys mapa przyciskow
	*/
	void CheckEvents(sf::Event ev, sf::RenderWindow *& window, std::map<Keys, sf::Keyboard::Key> & keys);

	/** Funkcja rysuje elementy Menu w zaleznosci od stanu w oknie
	@param window wskaznik na obiekt okna
	*/
	void Draw(sf::RenderWindow *&window);

	/** Funkcja odczytuje odpowiednie zasoby z plikow i inicjuje sprite'y widoczne w Menu
	*/
	void Init();

	/** Funkcja przypisuje kod wcisnietego klawisza do mapy klawiszy. Czeka ona na wcisniecie klawisza przez gracza
	@param keys mapa przyciskow
	@param window wskaznik na okno aplikacji
	@param id klucz okreslajacy jaki klawisz ustawiamy
	@return Zwraca kod wcisnietego klawisza
	*/
	int set_Key(std::map<Keys, sf::Keyboard::Key>& keys, sf::RenderWindow *& window, enum Keys id);

	/** Funkcja zamienia kod klaiwsza na odpowiednia litere
	@param KeyCode kod klawisza
	@return Zwraca obiekt std::string z nazwa klawisza z klawiatury
	*/
	std::string exchange_key_code_to_string(int KeyCode);

	/** Funkcja ustawia poziom trudnosci oraz pozwala na ustawianie klawiszy w opcjach gry
	@param keys mapa przyciskow
	@param window wskaznik na okno aplikacji
	*/
	void BindKeysandChangeDifficulty(std::map<Keys, sf::Keyboard::Key>& keys, sf::RenderWindow *& window);

	/** Funkcja zameinia poziom trudnosci jako klucz na napis
	@param diff poziom trudnosci
	@return Zwraca obiekt std::string z napisem poziomu trudnosci
	*/
	std::string Difficulty_to_string(Difficulty diff);

	/** Zamienia punkty na tekst, aby mozna bylo je wyswietlic na ekran.
	*/
	void Exchange_points_to_text();
};


#endif