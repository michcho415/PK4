#pragma once
#include "Object.h"

///Klasa Przeciwnik
class Enemy : public Object
{
	const int size = 32; ///rozmiar obiektu
	float driving_time; ///czas jak d�ugo b�dzie si� porusza� przeciwnik
	sf::Clock driving_timer; ///Zegar przechowuj�cy jak d�ugo aktualnie wykonuje ruch
	sf::Clock shooting_timer; ///Zegar sprawdzaj�cy d�ugo�� odst�pu mi�dzy kulami

public:
	Enemy() = default;

	/**Konstruktor wieloargumentowy inicjuj�cy pozycj�, pr�dko�� oraz kierunek przeciwnika
	@param x pozycja x przeciwnika
	@param y pozycja y przeciwnika
	@param speed pr�dko�� przeciwnika
	@param dir zwrot przeciwnika
	*/
	Enemy(double x, double y, double speed, Direction dir);

	/**Metoda zwraca rozmiar przeciwnika.
	@return zwraca rozmiar przeciwnika
	*/
	int Get_size();

	/**Metoda ustawia na jakich bloczkach przeciwnik si� znajduj� na podstawie kierunku w kt�rym si� porusza
	*/
	void Set_tile();

	/**Funkcja rysuje sprite'a przeciwnika w oknie programu
	@param window wska�nik na obiekt okna
	*/
	void Draw(sf::RenderWindow *& window);

	/**Metoda przesuwa przeciwnika zgodnie z jego ustawionym kierunkiem i spradza czy nie znalaz� si� poza map�.
	*/
	void Update(sf::Event & ev, double dt);

	/** Metoda przemieszcza przeciwnika w g�r�, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizj� z bloczkami u g�ry.
	@param dt czas mi�dzy klatkami (frametime)
	*/
	void Move_Up(const double & dt);

	/** Metoda przemieszcza przeciwnika w d�, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizj� z bloczkami na dole.
	@param dt czas mi�dzy klatkami (frametime)
	*/
	void Move_Down(const double & dt);

	/** Metoda przemieszcza przeciwnika w lewo, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizj� z bloczkami po lewej stronie.
	@param dt czas mi�dzy klatkami (frametime)
	*/
	void Move_Left(const double & dt);
	
	/** Metoda przemieszcza przeciwnika w prawo, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizj� z bloczkami po prawej stronie.
	@param dt czas mi�dzy klatkami (frametime) 
	*/
	void Move_Right(const double & dt);
	
	/**Metoda wybiera w kt�r� stron� ma porusza� si� przeciwnik
	*/
	void Choose_direction(); //wybierz w kt�ra stron� jecha�;

	/**Metoda losuje czas z danego przedzia�u.
	@param x lewa granica przedzia�u
	@param y prawa granica przedzia�u
	@return zwraca wylosowany czas
	*/
	float Choose_time(float x, float y);

	/**Metoda co pewien czas ustawia kierunek w kt�rym si� porusza przeciwnik oraz co pewnien czas aktywuje przeciwnikowi strza�
	*/
	void Choose_action();

	/** Metoda sprawdza czy przeciwnik nie koliduje z odpowiednimi typami bloczk�w
	@param Tile_x pozycja bloczka w rz�dzie
	@param Tile_y pozycja bloczka w kolumnie
	@return w przypadku kiedy kolizja wyst�pi�a zwraca true, w przeciwnym wypadku false
	*/
	bool Check_collision_with_tiles(int Tile_x, int Tile_y) const;
	
	
};