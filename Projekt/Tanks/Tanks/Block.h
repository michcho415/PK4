#ifndef BLOCK_H
#define BLOCK_H
#include "Object.h"
#include "SFML/Graphics.hpp"

///typ wyliczeniowy do 
enum Block_type {NONE, BRICK, METAL, BUSH};

///Klasa reprezentuj�ca bloczek na planszy
class Block: public Object
{
private:

	int size; ///rozmiar bloczka
	Block_type bl_type; ///typ bloczka
	
public:
	Block();
	/**Konstruktor wieloargumentowy, ustawia pozycj� bloczka oraz domy�lnie ustawia pr�dko�c bloczka na 0 i kierunek w g�r�.
	@param x pozycja x bloczka
	@param y pozycja y bloczka
	*/
	Block(double x, double y);
	/** Getter do sprawdzania rozmiaru bloczka.
	@return rozmiar bloczka
	*/
	int Get_size();

	/**Ustawia na jakim fragmencie planszy znajduje si� bloczek.
	*/
	void Set_tile();

	/**Metoda rysuje bloczek w oknie
	@param wska�nik na obiekt okna
	*/
	void Draw(sf::RenderWindow *& window);

	/**Metoda na podstawie typu bloczka ustawia jego rodzaj i sprite'a
	@param type rodzaj bloczka
	*/
	void Set_sprite(Block_type type);

	/** Funkcja przesuwa bloczek.
	@param ev obiekt przechowuj�cy informacje o zdarzeniach
	@param dt czas mi�dzy klatkami (frametime)
	@TODO Wrazie potrzeby zaimplementowa�
	*/
	void Update(sf::Event & ev, double dt);

	/**Metoda zwraca rodzaj bloczka.
	@return zwraca rodzaj bloczka
	*/
	Block_type get_block_type() { return bl_type; }

};


#endif
