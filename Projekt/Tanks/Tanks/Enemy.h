#pragma once
#include "Object.h"

/**Klasa Przeciwnik*/
class Enemy : public Object
{
	/**rozmiar obiektu*/
	const int size = 32; 
	/**czas jak dlugo bedzie sie poruszac przeciwnik*/
	float driving_time; 
	/**Zegar przechowujacy jak dlugo aktualnie wykonuje ruch*/
	sf::Clock driving_timer; 
	/**Zegar sprawdzajacy dlugosc odstepu miedzy kulami*/
	sf::Clock shooting_timer; 

public:
	Enemy() = default;

	/**Konstruktor wieloargumentowy inicjujacy pozycje, predkosc oraz kierunek przeciwnika
	@param x pozycja x przeciwnika
	@param y pozycja y przeciwnika
	@param speed predkosc przeciwnika
	@param dir zwrot przeciwnika
	*/
	Enemy(double x, double y, double speed, Direction dir);

	/**Metoda zwraca rozmiar przeciwnika.
	@return zwraca rozmiar przeciwnika
	*/
	int Get_size();

	/**Metoda ustawia na jakich bloczkach przeciwnik sie znajduje na podstawie kierunku w ktorym sie porusza
	*/
	void Set_tile();

	/**Funkcja rysuje sprite'a przeciwnika w oknie programu
	@param window wskaznik na obiekt okna
	*/
	void Draw(sf::RenderWindow *& window);

	/**Metoda przesuwa przeciwnika zgodnie z jego ustawionym kierunkiem i spradza czy nie znalazl sie poza mapa.
	*/
	void Update(sf::Event & ev, double dt);

	/** Metoda przemieszcza przeciwnika w gore, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizje z bloczkami u gory.
	@param dt czas miedzy klatkami (frametime)
	*/
	void Move_Up(const double & dt);

	/** Metoda przemieszcza przeciwnika w dol, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizje z bloczkami na dole.
	@param dt czas miedzy klatkami (frametime)
	*/
	void Move_Down(const double & dt);

	/** Metoda przemieszcza przeciwnika w lewo, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizje z bloczkami po lewej stronie.
	@param dt czas miedzy klatkami (frametime)
	*/
	void Move_Left(const double & dt);
	
	/** Metoda przemieszcza przeciwnika w prawo, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizje z bloczkami po prawej stronie.
	@param dt czas miedzy klatkami (frametime) 
	*/
	void Move_Right(const double & dt);
	
	/**Metoda wybiera w ktora strone ma poruszac sie przeciwnik
	*/
	void Choose_direction(); //wybierz w ktora strone jechac;

	/**Metoda losuje czas z danego przedzialu.
	@param x lewa granica przedzialu
	@param y prawa granica przedzialu
	@return zwraca wylosowany czas
	*/
	float Choose_time(float x, float y);

	/**Metoda co pewien czas ustawia kierunek w ktorym sie porusza przeciwnik oraz co pewnien czas aktywuje przeciwnikowi strzal
	*/
	void Choose_action();

	/** Metoda sprawdza czy przeciwnik nie koliduje z odpowiednimi typami bloczkow
	@param Tile_x pozycja bloczka w rzedzie
	@param Tile_y pozycja bloczka w kolumnie
	@return w przypadku kiedy kolizja wystapila zwraca true, w przeciwnym wypadku false
	*/
	bool Check_collision_with_tiles(int Tile_x, int Tile_y) const;
	
	
};