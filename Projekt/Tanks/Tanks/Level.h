#ifndef LEVEL_H
#define LEVEL_H
#include "SFML/Graphics.hpp"
#include <array>
#include "Object.h"
#include "Block.h"

///Klasa odpowiadaj�ca za plansz� w grze
class Level
{
	sf::RectangleShape square; ///t�o mapy po kt�rej poruszaj� si� jednostki
	const static size_t size_x = 26; 
	const static size_t size_y = 26;
	std::array<std::array<Block, size_x>, size_y+1> data; /// tablica dwuwymiarowa przechowuj�ca bloczki jakie znajduj� si� na mapie

public:

	/** Konstruktor klasy Level. Tworzy t�o planszy oraz pozycjonuje j� na ekranie
	@param window wska�nik na obiekt okna
	*/
	Level(sf::RenderWindow *& window);

	/** Metoda wczytuj�ca plansz� z pliku .csv
	@param filename nazwa pliku
	*/
	void Load_level_from_file(const std::string & filename);

	/** Metoda rysuj�ca wszystkie bloczki planszy na ekranie
	@param window wska�nik na obiekt okna
	*/
	void Draw(sf::RenderWindow *& window);

	/** Metoda rysuj�ca t�o planszy na ekran.
	@param window wska�nik na obiekt okna
	*/
	void Draw_background(sf::RenderWindow *& window);

	/** Metoda zwracaj�ca pozycj� x �rodka planszy
	@return pozycja x �rodka planszy
	*/
	float Get_center_x();

	/** Metoda zwracaj�ca pozycj� y �rodka planszy
	@return pozycja y �rodka planszy
	*/
	float Get_center_y();

	/** Metoda zwracaj�ca szerokosc (x) planszy
	@return szerokosc planszy w bloczkach
	*/
	const float Get_size_x() const;

	/** Metoda zwracaj�ca wysokosc (y) planszy
	@return wysokosc planszy w bloczkach
	*/
	const float Get_size_y() const;

	/** Metoda zwracaj�ca bloczek na danym fragmencie planszy
	@param x numer wiersza kratki na planszy
	@param y numer kolumny kratki na planszy
	@return Obiekt bloczka
	*/
	Block Get_block(int x, int y);

	/** Metoda ustawia odpowiedni sprite i rodzaj bloczka w danej kolumnie i wierszy planszy
	@param x pozycja bloczka w rz�dzie 
	@param y pozycja bloczka w kolumnie
	@param type typ na jaki zostanie ustawiony bloczek
	*/
	void Set_block(int x, int y, Block_type type);

};

#endif
