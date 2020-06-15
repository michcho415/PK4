#ifndef BLOCK_H
#define BLOCK_H
#include "Object.h"
#include "SFML/Graphics.hpp"

/**typ wyliczeniowy do okreslenia typu bloczka*/
enum Block_type {NONE, BRICK, METAL, BUSH};

/**Klasa reprezentujaca bloczek na planszy*/
class Block: public Object
{
private:
	/**rozmiar bloczka*/
	int size; 
	/**typ bloczka*/
	Block_type bl_type; 
	
public:
	Block();
	/**Konstruktor wieloargumentowy, ustawia pozycje bloczka oraz domyslnie ustawia predkosc bloczka na 0 i kierunek w gore.
	@param x pozycja x bloczka
	@param y pozycja y bloczka
	*/
	Block(double x, double y);
	/** Getter do sprawdzania rozmiaru bloczka.
	@return rozmiar bloczka
	*/
	int Get_size();

	/**Ustawia na jakim fragmencie planszy znajduje sie bloczek.
	*/
	void Set_tile();

	/**Metoda rysuje bloczek w oknie
	@param window wskaznik na obiekt okna
	*/
	void Draw(sf::RenderWindow *& window);

	/**Metoda na podstawie typu bloczka ustawia jego rodzaj i sprite'a
	@param type rodzaj bloczka
	*/
	void Set_sprite(Block_type type);

	/** Funkcja przesuwa bloczek.
	@param ev obiekt przechowujacy informacje o zdarzeniach
	@param dt czas miedzy klatkami (frametime)
	*/
	void Update(sf::Event & ev, double dt);

	/**Metoda zwraca rodzaj bloczka.
	@return zwraca rodzaj bloczka
	*/
	Block_type get_block_type() { return bl_type; }

};


#endif
