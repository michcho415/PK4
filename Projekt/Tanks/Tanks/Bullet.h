#ifndef  BULLET_H
#define BULLET_H
#include "Object.h"


/**Klasa reprezentujaca obiekt kuli w grze*/
class Bullet: public Object {
private:
	/**zmienna okreslajaca czyja jest kula 0 - jest przeciwnika, 1 - jest gracza*/
	bool is_players; 
	/**rozmiar kuli*/
	const int size = 16; 

public:

	~Bullet() = default;

	/**Konstruktor wieloargumentowy inicjujacy pozycje, predkosc, kierunek kuli oraz okresla czy jest przeciwnika czy gracza.
	@param x pozycja x kuli
	@param y pozycja y kuli
	@param speed predkosc kuli
	@param dir zwrot kuli
	@param whose czyja jest kula
	*/
	Bullet(double x, double y, double speed, Direction dir, bool whose);

	/**Metoda zwraca rozmiar kuli.
	@return zwraca rozmiar kuli
	*/
	int Get_size();

	/**Metoda ustawia na jakim bloczku planszy znajduje sie kula.
	*/
	void Set_tile();

	/**Metoda przemieszcza kule w odpowiednim kierunku oraz ustawia na ktorym z bloczkow planszy aktualnie sie znajduje.
	@param ev obiekt przechowujacy informacje o zdarzeniach
	@param dt czas miedzy klatkami (frametime)
	*/
	void Update(sf::Event & ev, double dt);

	/**Metoda ustawia odpowiedni sprite dla kuli w zaleznosci od zwrotu w ktorym sie porusza.
	@param d zwrot kuli
	*/
	void Set_sprite(Direction d);

	/**Metoda rysuje obiekt kuli w oknie programu.
	@param window wskaznik na obiekt okna
	*/
	void Draw(sf::RenderWindow *& window);

	/**Metoda przesuwa kule w gore.
	@param dt czas miedzy klatkami (frametime)
	*/
	void Move_Up(double dt);

	/**Metoda przesuwa kule w dol.
	@param dt czas miedzy klatkami (frametime)
	*/
	void Move_Down(double dt);

	/**Metoda przesuwa kule w lewo.
	@param dt czas miedzy klatkami (frametime)
	*/
	void Move_Left(double dt);

	/**Metoda przesuwa kule w prawo.
	@param dt czas miedzy klatkami (frametime)
	*/
	void Move_Right(double dt);

	/**Metoda zwraca przynaleznosc kuli.
	@return Zwraca 0 kiedy kula jest przeciwnika, w przeciwnym przypadku zwraca 1.
	*/
	bool get_belongingness();
	
};
#endif // ! BULLET_H
