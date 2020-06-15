#ifndef LEVEL_H
#define LEVEL_H
#include "SFML/Graphics.hpp"
#include <array>
#include "Object.h"
#include "Block.h"

/**Klasa odpowiadajaca za plansze w grze*/
class Level
{
	/**tlo mapy po ktorej poruszaja sie jednostki*/
	sf::RectangleShape square; 
	const static size_t size_x = 26; 
	const static size_t size_y = 26;
	/**tablica dwuwymiarowa przechowujaca bloczki jakie znajduja sie na mapie*/
	std::array<std::array<Block, size_x>, size_y+1> data; 

public:

	/** Konstruktor klasy Level. Tworzy tlo planszy oraz pozycjonuje ja na ekranie
	@param window wskaznik na obiekt okna
	*/
	Level(sf::RenderWindow *& window);

	/** Metoda wczytujaca plansze z pliku .csv
	@param filename nazwa pliku
	*/
	void Load_level_from_file(const std::string & filename);

	/** Metoda rysujaca wszystkie bloczki planszy na ekranie
	@param window wskaznik na obiekt okna
	*/
	void Draw(sf::RenderWindow *& window);

	/** Metoda rysujaca tlo planszy na ekran.
	@param window wskaznik na obiekt okna
	*/
	void Draw_background(sf::RenderWindow *& window);

	/** Metoda zwracajaca pozycje x srodka planszy
	@return pozycja x srodka planszy
	*/
	float Get_center_x();

	/** Metoda zwracajaca pozycje y srodka planszy
	@return pozycja y srodka planszy
	*/
	float Get_center_y();

	/** Metoda zwracajaca szerokosc (x) planszy
	@return szerokosc planszy w bloczkach
	*/
	const float Get_size_x() const;

	/** Metoda zwracajaca wysokosc (y) planszy
	@return wysokosc planszy w bloczkach
	*/
	const float Get_size_y() const;

	/** Metoda zwracajaca bloczek na danym fragmencie planszy
	@param x numer wiersza kratki na planszy
	@param y numer kolumny kratki na planszy
	@return Obiekt bloczka
	*/
	Block Get_block(int x, int y);

	/** Metoda ustawia odpowiedni sprite i rodzaj bloczka w danej kolumnie i wierszy planszy
	@param x pozycja bloczka w rzedzie 
	@param y pozycja bloczka w kolumnie
	@param type typ na jaki zostanie ustawiony bloczek
	*/
	void Set_block(int x, int y, Block_type type);

};

#endif
