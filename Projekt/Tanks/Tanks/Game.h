#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Menu.h"
#include "Level.h"
#include "Sprites.h"
#include "Player.h"
#include "Bullet.h"

/**Klasa przechowujaca wszystkie obiekty w grze i zarzadzajaca nimi (singleton)*/
class Game
{
private:
	/**mapa klawiszy*/
	std::map<Keys, sf::Keyboard::Key> keys; 
	/**stan gry*/
	Game_State game_state; 
	/**poziom trudnosci*/
	Difficulty game_difficulty; 
	/**rozmiar bloczka w grze*/
	const unsigned int block_size; 
	/**predkosc kuli*/
	float bullet_speed; 
	/**predkosc jednostki*/
	double entity_speed; 
	/** mnoznik ustawiany w zaleznosci od poziomu trudnosci*/
	float ratio; 
	/**ilosc przecwinikow na mapie*/
	int enemies_on_map; 
	/**zegar ograniczajacy czestosc wystrzalu kuli dla gracza*/
	sf::Clock bullet_clock; 
	/**zegar okreslajacy czy moze przeciwnik pojawic sie na planszy*/
	sf::Clock spawn_clock; 
	/**aktualny wynik*/
	int score; 
	/**wynik w postaci tekstu*/
	sf::Text score_in_text; 
	/**wskaznik na Menu*/
	Menu* menu; 
	/**wskaznik na obiekt okna*/
	sf::RenderWindow* window; 
	/**wskaznik na plansze*/
	Level* stage; 
	/**wskaznik na gracza*/
	Object* player; 
	/**wektor przechowujacy wszystkie aktualne kule w grze*/
	std::vector<Object*> bullets; 
	/**wektor przechowujacy wszystkie jednostki w grze*/
	std::vector<Object*> entities; 

public:

	/** Konstruktor domyslny klasy. Inicjuje domyslnymi wartosciami podstawowe wartosci: predkosc jednostek,
	predkosc kul, rozmiar bloczka, stan gry, poziom trudnosci oraz wynik i ile jest przeciwnikow na mapie.
	Tworzy nowa plansze i inicjuje gracza oraz klawisze, ktorymi sie porusza.
	*/
	Game();

	/** Destruktor klasy Game. Usuwa wszystkie obiekty zaalokowane dynamiczne tj. kule, jednostki, plansze itp.
	*/
	~Game();
	Game(const Game & o) = delete;

	/** Metoda zwraca instancje obiektu gry.
	@return obiekt gry.
	*/
	static Game & Get() { static Game Game; return Game; }

	/** Metoda do ustawiania stanu gry.
	@param state na jaki stan ma zostac zmieniona aktualnie gra
	*/
	void Set_game_state(Game_State state) { game_state = state; }

	/** Metoda zwraca aktualny stan gry np. czy jestesmy w Menu czy toczy sie rozgrywka.
	@return zwraca stan gry
	*/
	Game_State Get_game_state() { return game_state; }

	/** Metoda ustawia poziom trudnosci w zaleznosci od parametru.
	@param diff poziom trudnosci jaki ma zostac ustawiony
	*/
	void Set_difficulty(Difficulty diff) { game_difficulty = diff; }

	/** Metoda zwraca aktualnie ustawiony poziom trudnosci w grze.
	@return poziom trudnosci
	*/
	Difficulty Get_difficulty() { return game_difficulty;}

	/** Metoda zwraca mape z klawiszami, ktorych uzytkownik uzywa do poruszania sie.
	@return mapa z kodami klawiszy
	*/
	std::map<Keys, sf::Keyboard::Key>& Get_keys() { return keys; }

	/** Metoda zwraca aktualny wybrany poziom w grze.
	@return zwraca wskaznik na poziom gry.
	*/
	Level* Get_level() { return stage; }

	/** Metoda zwraca aktualny wynik gracza.
	@return aktualny wynik uzyskany przez gracza.
	*/
	int Get_score() { return score; }
	
	/** Metoda tworzy nowa kule w grze na pozycji danej jednostki i zgodnie z jej kierunkiem oraz przydziela jej przynaleznosc w zaleznosci
	czy wystrzelil ja przeciwnik czy gracz.
	@param ob wskaznik na obiekt, ktory tworzy kule
	*/
	void Create_Bullet(Object* ob);

	/** Metoda "uruchamia" gre. Odpowiada ona za rysowania wszystkich obiektow na ekran w zaleznosci od stanu gry, obliczanie czasu miedzy klatkami
	oraz sprawdzaniu wydarzen i aktualizowaniu pozycji wszystkich obiektow na planszy.
	*/
	void Run();

	/** Metoda odpowiada za rysowanie obiektow w grze na ekran w zaleznosci od stanu gry. Odswieza ona ekran oraz rysuje i wyswietla
	elementy gry na ekranie.
	@param window wskaznik na obiekt okna
	*/
	void Draw(sf::RenderWindow * window);

	/** Metoda inicjuje domyslne klawisze do obslugi wejscia w grze.
	*/
	void Init_default_keys();

	/** Metoda dla kazdej kuli w grze sprawdza czy nastapila kolizja z krancem mapy, z innym graczem lub z bloczkiem na planszy.
	W przypadku, gdy nastapi kolizja kuli z jednostka na mapie to w zaleznosci od przynaleznosci kuli niszczy kule i przeciwnika lub
	niszczy kule i gracza. Sprawdza rowniez kolizje z bloczkami.
	@param bullets wektor kul znajdujacych sie w grze.
	*/
	void Check_bullet_collisons(std::vector<Object*> & bullets);

	/** Metoda sprawdza czy kula nie znajduje sie na mapie.
	@return zwraca true jesli kula jest poza mapa, w przeciwnym wypadku false
	*/
	bool Check_if_bullet_is_not_on_map(const Object * bullet)const;

	/** Sprawdza kolizje kuli z bloczkiem na ktorym znajduje sie aktualnie kula oraz w zaleznosci od typu bloczka ustawia mu teksture.
	@return w przypadku kiedy kula nie niszczy bloczka i moze przez niego przeleciec zwraca false,
	*/
	bool Check_if_bullet_collides_with_block(Object * bullet);

	/** Metoda sprawdza czy kula niszczy jednostke na mapie np. gracza lub przeciwnika. Jezeli kula nachodzi na gracza to sprawdza czyja jest kula
	i na jaka jednostke nachodzi (gracza czy przeciwnika).Jesli kula nalezy do przeciwnika i nachodzi na przeciwnika to nie niszczy go. Jesli kula
	jest gracza i nachodzi na przeciwnika to niszczy go. Jesli natomiast kula jest przeciwnika i nachodzi na gracza to nastepuje koniec gry i gracz jest niszczony.
	@return zwraca true jesli nastapila kolizja kuli z jakakolwiek jednostkom, a false jesli nie nastapila kolizja kuli z jednostka
	*/
	bool Check_if_bullet_destroys_entity(Object* bullet);

	/** Metoda zwraca jak dlugo porusza sie ostatnia wystrzelona kula przez gracza.
	@return czas od ostatniej stworzonej kuli przez gracza.
	*/
	float Get_bullet_time();

	/** Metoda resetuje zegar ostatnio wystrzelonej kuli.
	*/
	void Restart_bullet_clock();

	/** Metoda inicjuje szybkosc poruszania sie kul oraz mnoznik w zaleznosci od wybranego poziomu trudnosci.
	*/
	void Init_if_game_diff_selected();

	/** Tworzy gracza na planszy, jesli ich jest mniej niz 3 i w okreslonych odstepach czasu.
	*/
	void Spawn_enemy();

	/** Spradza czy jednostka nie jest na mapie.
	@return zwraca true jesli jednostka jest poza mapa, w przeciwnym wypadku zwraca false.
	*/
	bool Check_if_entity_is_not_on_map(Object* entity);
	
	
};

#endif // !GAME_H

