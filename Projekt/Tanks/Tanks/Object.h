#ifndef OBJECT_H
#define OBJECT_H

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

///Typ wyliczeniowy do okre�lenia zwrotu obiektu
enum Direction { UP_, DOWN_, LEFT_, RIGHT_};

///Klasa reprezentuje obiekt gry
class Object
{
protected:
	
	sf::Sprite sprite; ///sprite obiektu gry
	Direction dir; ///zwrot obiektu gry
	double x, y; /// pozycja gracza
	double velocity; ///pr�dko�� obiektu gry
	int tile_x, tile_y; ///Fragment planszy na kt�rym aktualnie znajduje si� obiekt gry
	int tile_x_2, tile_y_2;
	
public:
	Object();
	virtual ~Object() = default;

	/**Konstruktor wieloargumentowy inicjuj�cy pozycj�, pr�dko�� oraz kierunek obiektu
	@param x pozycja x obiektu
	@param y pozycja y obiektu
	@param speed predko�� obiektu
	@param d zwrot obiektu
	*/
	Object(double x, double y, double speed, Direction d);

	/**Interfejs do sprawdzania rozmiaru obiektu
	*/
	virtual int Get_size() = 0;

	/**Interfejs do ustawiania na jakim bloczku (bloczkach) znajduje si� obiekt gry
	*/
	virtual void Set_tile() = 0;

	/**Metoda rysuje obiekt w oknie
	@param window wska�nik na obiekt okna
	*/
	virtual void Draw(sf::RenderWindow *& window) = 0;

	/**Metoda aktualizuje pozycj� obiektu gry
	@param ev obiekt przechowuj�cy informacje o zdarzeniach
	@param dt czas mi�dzy klatkami (frametime)
	*/
	virtual void Update(sf::Event & ev, double dt) = 0;

	/**Getter umo�liwiaj�cy sprawdzenie zwrotu obiektu gry
	@return zwraca kierunek obiektu gry
	*/
	Direction Get_direction();

	/**Metoda zwraca wektor z pozycj� obiektu
	@return zwraca dwuelementowy wektor z pozycj�
	*/
	sf::Vector2f Get_position()const;

	/**Metoda ustawia pozycj� gracza
	@param X pozycja x
	@param Y pozycja Y
	*/
	void Set_position(double X, double Y);

	/**Getter do sprawdzania na kt�rym bloczku aktualnie znajduje si� obiekt
	@return zwraca w kt�rym rz�dzie znajduje si� obiekt
	*/
	int Get_tile_x();

	/**Getter do sprawdzania na kt�rym bloczku aktualnie znajduje si� obiekt
	@return zwraca w kt�rej kolumnie znajduje si� obiekt
	*/
	int Get_tile_y();

};



#endif
