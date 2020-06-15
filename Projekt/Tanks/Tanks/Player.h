#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"

/**Klasa reprezentujaca gracza*/
class Player: public Object
{
private:
	/**rozmiar jednostki gracza*/
	const int size = 32; 

public:

	/**Konstruktor wieloargumentowy inicjujacy pozycje, predkosc oraz kierunek gracza.
	@param x pozycja x gracza
	@param y pozycja y gracza
	@param speed predkosc gracza
	@param dir zwrot gracza
	*/
	Player(double x, double y, double speed, Direction dir);

	/**Metoda zwraca rozmiar gracza.
	@return zwraca rozmiar gracza
	*/
	int Get_size();

	/**Metoda ustawia na jakich bloczkach planszy znajduje sie gracz na podstawie kierunku w ktorym sie porusza.
	*/
	void Set_tile();

	/**Funkcja rysuje sprite'a gracza w oknie programu.
	@param window wskaznik na obiekt okna
	*/
	void Draw(sf::RenderWindow *& window);

	/**Metoda sprawdza wcisniete klawisze z klawiatury i wywoluje odpowiednie akcje dla gracza np. przemieszcza go lub tworzy kule.
	Ustawia rowniez na jakim fragmencie planszy znajduje sie gracz.
	@param ev obiekt przechowujacy informacje o zdarzeniach
	@param dt czas miedzy klatkami (frametime)
	*/
	void Update(sf::Event & ev, double dt);

	/** Metoda przemieszcza gracza w gore, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizje z bloczkami u gory.
	@param dt czas miedzy klatkami (frametime)
	*/
	void Move_Up(const double & dt);

	/** Metoda przemieszcza gracza w dol, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizje z bloczkami na dole.
	@param dt czas miedzy klatkami (frametime)
	*/
	void Move_Down(const double & dt);

	/** Metoda przemieszcza gracza w lewo, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizje z bloczkami po lewej stronie.
	@param dt czas miedzy klatkami (frametime)
	*/
	void Move_Left(const double & dt);

	/** Metoda przemieszcza gracza w prawo, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizje z bloczkami po prawej stronie.
	@param dt czas miedzy klatkami (frametime)
	*/
	void Move_Right(const double & dt);

	/**Metoda zwraca rozmiar gracza
	@return rozmiar gracza
	*/
	const int get_player_size() const;

	/** Metoda sprawdza czy gracz nie koliduje z odpowiednimi typami bloczkow
	@param Tile_x pozycja bloczka w rzedzie
	@param Tile_y pozycja bloczka w kolumnie
	@return w przypadku kiedy kolizja wystapila zwraca true, w przeciwnym wypadku false
	*/
	bool Check_collision_on_tiles(int Tile_x, int Tile_y);
	
};

#endif