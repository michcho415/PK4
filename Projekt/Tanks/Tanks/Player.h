#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"

///Klasa reprezentuj�ca gracza
class Player: public Object
{
private:

	const int size = 32; ///rozmiar jednostki gracza

public:

	/**Konstruktor wieloargumentowy inicjuj�cy pozycj�, pr�dko�� oraz kierunek gracza.
	@param x pozycja x gracza
	@param y pozycja y gracza
	@param speed pr�dko�� gracza
	@param dir zwrot gracza
	*/
	Player(double x, double y, double speed, Direction dir);

	/**Metoda zwraca rozmiar gracza.
	@return zwraca rozmiar gracza
	*/
	int Get_size();

	/**Metoda ustawia na jakich bloczkach planszy znajduj� si� gracz na podstawie kierunku w kt�rym si� porusza.
	*/
	void Set_tile();

	/**Funkcja rysuje sprite'a gracza w oknie programu.
	@param window wska�nik na obiekt okna
	*/
	void Draw(sf::RenderWindow *& window);

	/**Metoda sprawdza wci�ni�te klawisze z klawiatury i wywo�uje odpowiednie akcj� dla gracza np. przemieszcza go lub tworzy kul�.
	Ustawia r�wnie� na jakim fragmencie planszy znajduje si� gracz.
	@param ev obiekt przechowuj�cy informacje o zdarzeniach
	@param dt czas mi�dzy klatkami (frametime)
	*/
	void Update(sf::Event & ev, double dt);

	/** Metoda przemieszcza gracza w g�r�, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizj� z bloczkami u g�ry.
	@param dt czas mi�dzy klatkami (frametime)
	*/
	void Move_Up(const double & dt);

	/** Metoda przemieszcza gracza w d�, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizj� z bloczkami na dole.
	@param dt czas mi�dzy klatkami (frametime)
	*/
	void Move_Down(const double & dt);

	/** Metoda przemieszcza gracza w lewo, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizj� z bloczkami po lewej stronie.
	@param dt czas mi�dzy klatkami (frametime)
	*/
	void Move_Left(const double & dt);

	/** Metoda przemieszcza gracza w prawo, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizj� z bloczkami po prawej stronie.
	@param dt czas mi�dzy klatkami (frametime)
	*/
	void Move_Right(const double & dt);

	/**Metoda zwraca rozmiar gracza
	@return rozmiar gracza
	*/
	const int get_player_size() const;

	/** Metoda sprawdza czy gracz nie koliduje z odpowiednimi typami bloczk�w
	@param Tile_x pozycja bloczka w rz�dzie
	@param Tile_y pozycja bloczka w kolumnie
	@return w przypadku kiedy kolizja wyst�pi�a zwraca true, w przeciwnym wypadku false
	*/
	bool Check_collision_on_tiles(int Tile_x, int Tile_y);
	
};

#endif