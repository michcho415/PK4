#ifndef  BULLET_H
#define BULLET_H
#include "Object.h"


///Klasa reprezentuj¹ca obiekt kuli w grze
class Bullet: public Object {
private:

	bool is_players; ///zmienna okreœlaj¹ca czyja jest kula 0 - jest przeciwnika, 1 -jest gracza
	const int size = 16; ///rozmiar kuli

public:

	~Bullet() = default;

	/**Konstruktor wieloargumentowy inicjuj¹cy pozycjê, prêdkoœæ, kierunek kuli oraz okreœla czy jest przeciwnika czy gracza.
	@param x pozycja x kuli
	@param y pozycja y kuli
	@param speed prêdkoœæ kuli
	@param dir zwrot kuli
	*/
	Bullet(double x, double y, double speed, Direction dir, bool whose);

	/**Metoda zwraca rozmiar kuli.
	@return zwraca rozmiar kuli
	*/
	int Get_size();

	/**Metoda ustawia na jakim bloczku planszy znajdujê siê kula.
	*/
	void Set_tile();

	/**Metoda przemieszcza kulê w odpowiednim kierunku oraz ustawia na którym z bloczków planszy aktualnie siê znajduje.
	@param ev obiekt przechowuj¹cy informacje o zdarzeniach
	@param dt czas miêdzy klatkami (frametime)
	*/
	void Update(sf::Event & ev, double dt);

	/**Metoda ustawia odpowiedni sprite dla kuli w zale¿noœci od zwrotu w którym siê porusza.
	@param d zwrot kuli
	*/
	void Set_sprite(Direction d);

	/**Metoda rysuje obiekt kuli w oknie programu.
	@param window wskaŸnik na obiekt okna
	*/
	void Draw(sf::RenderWindow *& window);

	/**Metoda przesuwa kulê w górê.
	@param dt czas miêdzy klatkami (frametime)
	*/
	void Move_Up(double dt);

	/**Metoda przesuwa kulê w dó³.
	@param dt czas miêdzy klatkami (frametime)
	*/
	void Move_Down(double dt);

	/**Metoda przesuwa kulê w lewo.
	@param dt czas miêdzy klatkami (frametime)
	*/
	void Move_Left(double dt);

	/**Metoda przesuwa kulê w prawo.
	@param dt czas miêdzy klatkami (frametime)
	*/
	void Move_Right(double dt);

	/**Metoda zwraca przynale¿noœæ kuli.
	@return Zwraca 0 kiedy kula jest przeciwnika, w przeciwnym przypadku zwraca 1.
	*/
	bool get_belongingness();
	
};
#endif // ! BULLET_H
