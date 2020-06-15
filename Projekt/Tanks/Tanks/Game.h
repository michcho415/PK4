#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Menu.h"
#include "Level.h"
#include "Sprites.h"
#include "Player.h"
#include "Bullet.h"

///Klasa przechowuj�ca wszystkie obiekty w grze i zarz�dzaj�ca nimi (singleton)
class Game
{
private:

	std::map<Keys, sf::Keyboard::Key> keys; ///mapa klawiszy
	Game_State game_state; ///stan gry
	Difficulty game_difficulty; ///poziom trudno�ci
	const unsigned int block_size; ///rozmiar bloczka w grze
	float bullet_speed; ///pr�dko�� kuli
	double entity_speed; ///pr�dko�� jednostki
	float ratio; /// mno�nik ustawiany w zale�no�ci od poziomu trudno�ci
	int enemies_on_map; ///ilo�� przecwinik�w na mapie
	sf::Clock bullet_clock; ///zegar ograniczaj�cy cz�sto�� wystrza�u kuli dla gracza
	sf::Clock spawn_clock; ///zegar okre�laj�cy czy mo�e przeciwnik pojawi� si� na planszy 
	int score; ///aktualny wynik
	sf::Text score_in_text; ///wynik w postaci tekstu
	Menu* menu; ///wska�nik na Menu
	sf::RenderWindow* window; ///wska�nik na obiekt okna
	Level* stage; ///wska�nik na plansz�
	Object* player; ///wska�nik na gracza
	std::vector<Object*> bullets; ///wektor przechowuj�cy wszystkie aktualne kule w grze
	std::vector<Object*> entities; ///wektor przechowuj�cy wszystkie jednostki w grze

public:

	/** Konstruktor domy�lny klasy. Inicjuje domy�lnymi warto�ciami podstawowe warto�ci: pr�dko�� jednostek,
	pr�dko�� kul, rozmiar bloczka, stan gry, poziom trudno�ci oraz wynik i ile jest przeciwnik�w na mapie.
	Tworzy now� plansz� i inicjuje gracza oraz klawisze, kt�rymi si� porusza.
	*/
	Game();

	/** Destruktor klasy Game. Usuwa wszystkie obiekty zaalokowane dynamiczne tj. kule, jednostki, plansz� itp.
	*/
	~Game();
	Game(const Game & o) = delete;

	/** Metoda zwraca instancj� obiektu gry.
	@return obiekt gry.
	*/
	static Game & Get() { static Game Game; return Game; }

	/** Metoda do ustawiania stanu gry.
	@param state na jaki stan ma zosta� zmieniona aktualnie gra
	*/
	void Set_game_state(Game_State state) { game_state = state; }

	/** Metoda zwraca aktualny stan gry np. czy jeste�my w Menu czy toczy si� rozgrywka.
	@return zwraca stan gry
	*/
	Game_State Get_game_state() { return game_state; }

	/** Metoda ustawia poziom trudno�ci w zale�no�ci od parametru.
	@param diff poziom trudno�ci jaki ma zosta� ustawiony
	*/
	void Set_difficulty(Difficulty diff) { game_difficulty = diff; }

	/** Metoda zwraca aktualnie ustawiony poziom trudno�ci w grze.
	@return poziom trudno�ci
	*/
	Difficulty Get_difficulty() { return game_difficulty;}

	/** Metoda zwraca map� z klawiszami, kt�rych u�ytkownik u�ywa do poruszania si�.
	@return mapa z kodami klawiszy
	*/
	std::map<Keys, sf::Keyboard::Key>& Get_keys() { return keys; }

	/** Metoda zwraca aktualny wybrany poziom w grze.
	@return zwraca wska�nik na poziom gry.
	*/
	Level* Get_level() { return stage; }

	/** Metoda zwraca aktualny wynik gracza.
	@return aktualny wynik uzyskany przez gracza.
	*/
	int Get_score() { return score; }
	
	/** Metoda tworzy now� kul� w grze na pozycji danej jednostki i zgodnie z jej kierunkiem oraz przydziela jej przynale�no�� w zale�no�ci
	czy wystrzeli� j� przeciwnik czy gracz.
	@param wska�nik na obiekt, kt�ry tworzy kul�
	*/
	void Create_Bullet(Object* ob);

	/** Metoda "uruchamia" gr�. Odpowiada ona za rysowania wszystkich obiekt�w na ekran w zale�no�ci od stanu gry, obliczanie czasu mi�dzy klatkami
	oraz sprawdzaniu wydarze� i aktualizowaniu pozycji wszystkich obiekt�w na planszy.
	*/
	void Run();

	/** Metoda odpowiada za rysowanie obiekt�w w grze na ekran w zale�no�ci od stanu gry. Od�wie�a ona ekran oraz rysuje i wy�wietla
	elementy gry na ekranie.
	@param window wska�nik na obiekt okna
	*/
	void Draw(sf::RenderWindow * window);

	/** Metoda inicjuje domy�lne klawisze do obs�ugi wej�cia w grze.
	*/
	void Init_default_keys();

	/** Metoda dla ka�dej kuli w grze sprawdza czy nast�pi�a kolizja z kra�cem mapy, z innym graczem lub z bloczkiem na planszy.
	W przypadku, gdy nast�pi kolizja kuli z jednostk� na mapie to w zale�no�ci od przynale�no�ci kuli niszczy kul� i przeciwnika lub
	niszczy kul� i gracza. Sprawdza r�wnie� kolizj� z bloczkami.
	@param bullets wektor kul znajduj�cych si� w grze.
	*/
	void Check_bullet_collisons(std::vector<Object*> & bullets);

	/** Metoda sprawdza czy kula nie znajduje si� na mapie.
	@return zwraca true je�li kula jest poza map�, w przeciwnym wypadku false
	*/
	bool Check_if_bullet_is_not_on_map(const Object * bullet)const;

	/** Sprawdza kolizj� kuli z bloczkiem na kt�rym znajduje si� aktualnie kula oraz w zale�no�ci od typu bloczka ustawia mu tekstur�.
	@return w przypadku kiedy kula nie niszczy bloczka i mo�e przez niego przelecie� zwraca false,
	*/
	bool Check_if_bullet_collides_with_block(Object * bullet);

	/** Metoda sprawdza czy kula niszczy jednostk� na mapie np. gracza lub przeciwnika. Je�eli kula nachodzi na gracza to sprawdza czyja jest kula
	i na jak� jednostk� nachodzi (gracza czy przeciwnika).Je�li kula nale�y do przeciwnika i nachodzi na przeciwnika tonie niszczy go. Je�li kula
	jest gracza i nachodzi na przeciwnika to niszczy go. Je�li natomiast kula jest przeciwnika i nachodzi na gracza to nast�puje koniec gry i gracz jest niszczony.
	@return zwraca true je�li nastapi�a kolizja kuli z jak�kolwiek jednostkom, a false je�li nie nast�pi�a kolizja kuli z jednostk�
	*/
	bool Check_if_bullet_destroys_entity(Object* bullet);

	/** Metoda zwraca jak d�ugo porusza si� ostatnia wystrzelona kula przez gracza.
	@return czas od ostatniej stworzonej kuli przez gracza.
	*/
	float Get_bullet_time();

	/** Metoda resetuje zegar ostatnio wystrzelonej kuli.
	*/
	void Restart_bullet_clock();

	/** Metoda inicjuje szybko�� poruszania si� kul oraz mno�nik w zale�no�ci od wybranego poziomu trudno�ci.
	*/
	void Init_if_game_diff_selected();

	/** Tworzy gracza na planszy, je�li ich jest mniej ni� 3 i w okre�lonych odst�pach czasu.
	*/
	void Spawn_enemy();

	/** Spradza czy jednostka nie jest na mapie.
	@return zwraca true je�li jednostka jest poza map�, w przeciwnym wypadku zwraca false.
	*/
	bool Check_if_entity_is_not_on_map(Object* entity);
	
	
};

#endif // !GAME_H

