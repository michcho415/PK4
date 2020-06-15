#ifndef  BULLET_H
#define BULLET_H
#include "Object.h"


///Klasa reprezentuj�ca obiekt kuli w grze
class Bullet: public Object {
private:

	bool is_players; ///zmienna okre�laj�ca czyja jest kula 0 - jest przeciwnika, 1 -jest gracza
	const int size = 16; ///rozmiar kuli

public:

	~Bullet() = default;

	/**Konstruktor wieloargumentowy inicjuj�cy pozycj�, pr�dko��, kierunek kuli oraz okre�la czy jest przeciwnika czy gracza.
	@param x pozycja x kuli
	@param y pozycja y kuli
	@param speed pr�dko�� kuli
	@param dir zwrot kuli
	*/
	Bullet(double x, double y, double speed, Direction dir, bool whose);

	/**Metoda zwraca rozmiar kuli.
	@return zwraca rozmiar kuli
	*/
	int Get_size();

	/**Metoda ustawia na jakim bloczku planszy znajduj� si� kula.
	*/
	void Set_tile();

	/**Metoda przemieszcza kul� w odpowiednim kierunku oraz ustawia na kt�rym z bloczk�w planszy aktualnie si� znajduje.
	@param ev obiekt przechowuj�cy informacje o zdarzeniach
	@param dt czas mi�dzy klatkami (frametime)
	*/
	void Update(sf::Event & ev, double dt);

	/**Metoda ustawia odpowiedni sprite dla kuli w zale�no�ci od zwrotu w kt�rym si� porusza.
	@param d zwrot kuli
	*/
	void Set_sprite(Direction d);

	/**Metoda rysuje obiekt kuli w oknie programu.
	@param window wska�nik na obiekt okna
	*/
	void Draw(sf::RenderWindow *& window);

	/**Metoda przesuwa kul� w g�r�.
	@param dt czas mi�dzy klatkami (frametime)
	*/
	void Move_Up(double dt);

	/**Metoda przesuwa kul� w d�.
	@param dt czas mi�dzy klatkami (frametime)
	*/
	void Move_Down(double dt);

	/**Metoda przesuwa kul� w lewo.
	@param dt czas mi�dzy klatkami (frametime)
	*/
	void Move_Left(double dt);

	/**Metoda przesuwa kul� w prawo.
	@param dt czas mi�dzy klatkami (frametime)
	*/
	void Move_Right(double dt);

	/**Metoda zwraca przynale�no�� kuli.
	@return Zwraca 0 kiedy kula jest przeciwnika, w przeciwnym przypadku zwraca 1.
	*/
	bool get_belongingness();
	
};
#endif // ! BULLET_H
