#ifndef LEVEL_H
#define LEVEL_H
#include "SFML/Graphics.hpp"
#include <array>
#include "Object.h"
#include "Block.h"

///Klasa odpowiadaj¹ca za planszê w grze
class Level
{
	sf::RectangleShape square; ///t³o mapy po której poruszaj¹ siê jednostki
	const static size_t size_x = 26; 
	const static size_t size_y = 26;
	std::array<std::array<Block, size_x>, size_y+1> data; /// tablica dwuwymiarowa przechowuj¹ca bloczki jakie znajduj¹ siê na mapie

public:

	/** Konstruktor klasy Level. Tworzy t³o planszy oraz pozycjonuje j¹ na ekranie
	@param window wskaŸnik na obiekt okna
	*/
	Level(sf::RenderWindow *& window);

	/** Metoda wczytuj¹ca planszê z pliku .csv
	@param filename nazwa pliku
	*/
	void Load_level_from_file(const std::string & filename);

	/** Metoda rysuj¹ca wszystkie bloczki planszy na ekranie
	@param window wskaŸnik na obiekt okna
	*/
	void Draw(sf::RenderWindow *& window);

	/** Metoda rysuj¹ca t³o planszy na ekran.
	@param window wskaŸnik na obiekt okna
	*/
	void Draw_background(sf::RenderWindow *& window);

	/** Metoda zwracaj¹ca pozycjê x œrodka planszy
	@return pozycja x œrodka planszy
	*/
	float Get_center_x();

	/** Metoda zwracaj¹ca pozycjê y œrodka planszy
	@return pozycja y œrodka planszy
	*/
	float Get_center_y();

	/** Metoda zwracaj¹ca szerokosc (x) planszy
	@return szerokosc planszy w bloczkach
	*/
	const float Get_size_x() const;

	/** Metoda zwracaj¹ca wysokosc (y) planszy
	@return wysokosc planszy w bloczkach
	*/
	const float Get_size_y() const;

	/** Metoda zwracaj¹ca bloczek na danym fragmencie planszy
	@param x numer wiersza kratki na planszy
	@param y numer kolumny kratki na planszy
	@return Obiekt bloczka
	*/
	Block Get_block(int x, int y);

	/** Metoda ustawia odpowiedni sprite i rodzaj bloczka w danej kolumnie i wierszy planszy
	@param x pozycja bloczka w rzêdzie 
	@param y pozycja bloczka w kolumnie
	@param type typ na jaki zostanie ustawiony bloczek
	*/
	void Set_block(int x, int y, Block_type type);

};

#endif
