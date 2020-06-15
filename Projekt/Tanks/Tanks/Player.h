#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"

///Klasa reprezentuj¹ca gracza
class Player: public Object
{
private:

	const int size = 32; ///rozmiar jednostki gracza

public:

	/**Konstruktor wieloargumentowy inicjuj¹cy pozycjê, prêdkoœæ oraz kierunek gracza.
	@param x pozycja x gracza
	@param y pozycja y gracza
	@param speed prêdkoœæ gracza
	@param dir zwrot gracza
	*/
	Player(double x, double y, double speed, Direction dir);

	/**Metoda zwraca rozmiar gracza.
	@return zwraca rozmiar gracza
	*/
	int Get_size();

	/**Metoda ustawia na jakich bloczkach planszy znajdujê siê gracz na podstawie kierunku w którym siê porusza.
	*/
	void Set_tile();

	/**Funkcja rysuje sprite'a gracza w oknie programu.
	@param window wskaŸnik na obiekt okna
	*/
	void Draw(sf::RenderWindow *& window);

	/**Metoda sprawdza wciœniête klawisze z klawiatury i wywo³uje odpowiednie akcjê dla gracza np. przemieszcza go lub tworzy kulê.
	Ustawia równie¿ na jakim fragmencie planszy znajduje siê gracz.
	@param ev obiekt przechowuj¹cy informacje o zdarzeniach
	@param dt czas miêdzy klatkami (frametime)
	*/
	void Update(sf::Event & ev, double dt);

	/** Metoda przemieszcza gracza w górê, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizjê z bloczkami u góry.
	@param dt czas miêdzy klatkami (frametime)
	*/
	void Move_Up(const double & dt);

	/** Metoda przemieszcza gracza w dó³, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizjê z bloczkami na dole.
	@param dt czas miêdzy klatkami (frametime)
	*/
	void Move_Down(const double & dt);

	/** Metoda przemieszcza gracza w lewo, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizjê z bloczkami po lewej stronie.
	@param dt czas miêdzy klatkami (frametime)
	*/
	void Move_Left(const double & dt);

	/** Metoda przemieszcza gracza w prawo, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizjê z bloczkami po prawej stronie.
	@param dt czas miêdzy klatkami (frametime)
	*/
	void Move_Right(const double & dt);

	/**Metoda zwraca rozmiar gracza
	@return rozmiar gracza
	*/
	const int get_player_size() const;

	/** Metoda sprawdza czy gracz nie koliduje z odpowiednimi typami bloczków
	@param Tile_x pozycja bloczka w rzêdzie
	@param Tile_y pozycja bloczka w kolumnie
	@return w przypadku kiedy kolizja wyst¹pi³a zwraca true, w przeciwnym wypadku false
	*/
	bool Check_collision_on_tiles(int Tile_x, int Tile_y);
	
};

#endif