#ifndef OBJECT_H
#define OBJECT_H

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

/**Typ wyliczeniowy do okreslenia zwrotu obiektu*/
enum Direction { UP_, DOWN_, LEFT_, RIGHT_};

/**Klasa reprezentuje obiekt gry*/
class Object
{
protected:
	/**sprite obiektu gry*/
	sf::Sprite sprite; 
	/**zwrot obiektu gry*/
	Direction dir; 
	/** pozycja gracza*/
	double x, y; 
	/**predkosc obiektu gry*/
	double velocity; 
	/**Fragment planszy na ktorym aktualnie znajduje sie obiekt gry*/
	int tile_x, tile_y; 
	int tile_x_2, tile_y_2;
	
public:
	Object();
	virtual ~Object() = default;

	/**Konstruktor wieloargumentowy inicjujacy pozycje, predkosc oraz kierunek obiektu
	@param x pozycja x obiektu
	@param y pozycja y obiektu
	@param speed predkosc obiektu
	@param d zwrot obiektu
	*/
	Object(double x, double y, double speed, Direction d);

	/**Interfejs do sprawdzania rozmiaru obiektu
	*/
	virtual int Get_size() = 0;

	/**Interfejs do ustawiania na jakim bloczku (bloczkach) znajduje sie obiekt gry
	*/
	virtual void Set_tile() = 0;

	/**Metoda rysuje obiekt w oknie
	@param window wskaznik na obiekt okna
	*/
	virtual void Draw(sf::RenderWindow *& window) = 0;

	/**Metoda aktualizuje pozycje obiektu gry
	@param ev obiekt przechowujacy informacje o zdarzeniach
	@param dt czas miedzy klatkami (frametime)
	*/
	virtual void Update(sf::Event & ev, double dt) = 0;

	/**Getter umozliwiajacy sprawdzenie zwrotu obiektu gry
	@return zwraca kierunek obiektu gry
	*/
	Direction Get_direction();

	/**Metoda zwraca wektor z pozycja obiektu
	@return zwraca dwuelementowy wektor z pozycja
	*/
	sf::Vector2f Get_position()const;

	/**Metoda ustawia pozycje gracza
	@param X pozycja x
	@param Y pozycja Y
	*/
	void Set_position(double X, double Y);

	/**Getter do sprawdzania na ktorym bloczku aktualnie znajduje sie obiekt
	@return zwraca w ktorym rzedzie znajduje sie obiekt
	*/
	int Get_tile_x();

	/**Getter do sprawdzania na ktorym bloczku aktualnie znajduje sie obiekt
	@return zwraca w ktorej kolumnie znajduje sie obiekt
	*/
	int Get_tile_y();

};



#endif
