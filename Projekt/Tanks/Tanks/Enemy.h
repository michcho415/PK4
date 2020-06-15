#pragma once
#include "Object.h"

///Klasa Przeciwnik
class Enemy : public Object
{
	const int size = 32; ///rozmiar obiektu
	float driving_time; ///czas jak d³ugo bêdzie siê poruszaæ przeciwnik
	sf::Clock driving_timer; ///Zegar przechowuj¹cy jak d³ugo aktualnie wykonuje ruch
	sf::Clock shooting_timer; ///Zegar sprawdzaj¹cy d³ugoœæ odstêpu miêdzy kulami

public:
	Enemy() = default;

	/**Konstruktor wieloargumentowy inicjuj¹cy pozycjê, prêdkoœæ oraz kierunek przeciwnika
	@param x pozycja x przeciwnika
	@param y pozycja y przeciwnika
	@param speed prêdkoœæ przeciwnika
	@param dir zwrot przeciwnika
	*/
	Enemy(double x, double y, double speed, Direction dir);

	/**Metoda zwraca rozmiar przeciwnika.
	@return zwraca rozmiar przeciwnika
	*/
	int Get_size();

	/**Metoda ustawia na jakich bloczkach przeciwnik siê znajdujê na podstawie kierunku w którym siê porusza
	*/
	void Set_tile();

	/**Funkcja rysuje sprite'a przeciwnika w oknie programu
	@param window wskaŸnik na obiekt okna
	*/
	void Draw(sf::RenderWindow *& window);

	/**Metoda przesuwa przeciwnika zgodnie z jego ustawionym kierunkiem i spradza czy nie znalaz³ siê poza map¹.
	*/
	void Update(sf::Event & ev, double dt);

	/** Metoda przemieszcza przeciwnika w górê, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizjê z bloczkami u góry.
	@param dt czas miêdzy klatkami (frametime)
	*/
	void Move_Up(const double & dt);

	/** Metoda przemieszcza przeciwnika w dó³, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizjê z bloczkami na dole.
	@param dt czas miêdzy klatkami (frametime)
	*/
	void Move_Down(const double & dt);

	/** Metoda przemieszcza przeciwnika w lewo, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizjê z bloczkami po lewej stronie.
	@param dt czas miêdzy klatkami (frametime)
	*/
	void Move_Left(const double & dt);
	
	/** Metoda przemieszcza przeciwnika w prawo, ustawia mu odpowiedni zwrot i skorelowany z nim sprite oraz sprawdza kolizjê z bloczkami po prawej stronie.
	@param dt czas miêdzy klatkami (frametime) 
	*/
	void Move_Right(const double & dt);
	
	/**Metoda wybiera w któr¹ stronê ma poruszaæ siê przeciwnik
	*/
	void Choose_direction(); //wybierz w która stronê jechaæ;

	/**Metoda losuje czas z danego przedzia³u.
	@param x lewa granica przedzia³u
	@param y prawa granica przedzia³u
	@return zwraca wylosowany czas
	*/
	float Choose_time(float x, float y);

	/**Metoda co pewien czas ustawia kierunek w którym siê porusza przeciwnik oraz co pewnien czas aktywuje przeciwnikowi strza³
	*/
	void Choose_action();

	/** Metoda sprawdza czy przeciwnik nie koliduje z odpowiednimi typami bloczków
	@param Tile_x pozycja bloczka w rzêdzie
	@param Tile_y pozycja bloczka w kolumnie
	@return w przypadku kiedy kolizja wyst¹pi³a zwraca true, w przeciwnym wypadku false
	*/
	bool Check_collision_with_tiles(int Tile_x, int Tile_y) const;
	
	
};