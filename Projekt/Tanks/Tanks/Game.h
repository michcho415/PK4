#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Menu.h"
#include "Level.h"
#include "Sprites.h"
#include "Player.h"
#include "Bullet.h"

///Klasa przechowuj¹ca wszystkie obiekty w grze i zarz¹dzaj¹ca nimi (singleton)
class Game
{
private:

	std::map<Keys, sf::Keyboard::Key> keys; ///mapa klawiszy
	Game_State game_state; ///stan gry
	Difficulty game_difficulty; ///poziom trudnoœci
	const unsigned int block_size; ///rozmiar bloczka w grze
	float bullet_speed; ///prêdkoœæ kuli
	double entity_speed; ///prêdkoœæ jednostki
	float ratio; /// mno¿nik ustawiany w zale¿noœci od poziomu trudnoœci
	int enemies_on_map; ///iloœæ przecwiników na mapie
	sf::Clock bullet_clock; ///zegar ograniczaj¹cy czêstoœæ wystrza³u kuli dla gracza
	sf::Clock spawn_clock; ///zegar okreœlaj¹cy czy mo¿e przeciwnik pojawiæ siê na planszy 
	int score; ///aktualny wynik
	sf::Text score_in_text; ///wynik w postaci tekstu
	Menu* menu; ///wskaŸnik na Menu
	sf::RenderWindow* window; ///wskaŸnik na obiekt okna
	Level* stage; ///wskaŸnik na planszê
	Object* player; ///wskaŸnik na gracza
	std::vector<Object*> bullets; ///wektor przechowuj¹cy wszystkie aktualne kule w grze
	std::vector<Object*> entities; ///wektor przechowuj¹cy wszystkie jednostki w grze

public:

	/** Konstruktor domyœlny klasy. Inicjuje domyœlnymi wartoœciami podstawowe wartoœci: prêdkoœæ jednostek,
	prêdkoœæ kul, rozmiar bloczka, stan gry, poziom trudnoœci oraz wynik i ile jest przeciwników na mapie.
	Tworzy now¹ planszê i inicjuje gracza oraz klawisze, którymi siê porusza.
	*/
	Game();

	/** Destruktor klasy Game. Usuwa wszystkie obiekty zaalokowane dynamiczne tj. kule, jednostki, planszê itp.
	*/
	~Game();
	Game(const Game & o) = delete;

	/** Metoda zwraca instancjê obiektu gry.
	@return obiekt gry.
	*/
	static Game & Get() { static Game Game; return Game; }

	/** Metoda do ustawiania stanu gry.
	@param state na jaki stan ma zostaæ zmieniona aktualnie gra
	*/
	void Set_game_state(Game_State state) { game_state = state; }

	/** Metoda zwraca aktualny stan gry np. czy jesteœmy w Menu czy toczy siê rozgrywka.
	@return zwraca stan gry
	*/
	Game_State Get_game_state() { return game_state; }

	/** Metoda ustawia poziom trudnoœci w zale¿noœci od parametru.
	@param diff poziom trudnoœci jaki ma zostaæ ustawiony
	*/
	void Set_difficulty(Difficulty diff) { game_difficulty = diff; }

	/** Metoda zwraca aktualnie ustawiony poziom trudnoœci w grze.
	@return poziom trudnoœci
	*/
	Difficulty Get_difficulty() { return game_difficulty;}

	/** Metoda zwraca mapê z klawiszami, których u¿ytkownik u¿ywa do poruszania siê.
	@return mapa z kodami klawiszy
	*/
	std::map<Keys, sf::Keyboard::Key>& Get_keys() { return keys; }

	/** Metoda zwraca aktualny wybrany poziom w grze.
	@return zwraca wskaŸnik na poziom gry.
	*/
	Level* Get_level() { return stage; }

	/** Metoda zwraca aktualny wynik gracza.
	@return aktualny wynik uzyskany przez gracza.
	*/
	int Get_score() { return score; }
	
	/** Metoda tworzy now¹ kulê w grze na pozycji danej jednostki i zgodnie z jej kierunkiem oraz przydziela jej przynale¿noœæ w zale¿noœci
	czy wystrzeli³ j¹ przeciwnik czy gracz.
	@param wskaŸnik na obiekt, który tworzy kulê
	*/
	void Create_Bullet(Object* ob);

	/** Metoda "uruchamia" grê. Odpowiada ona za rysowania wszystkich obiektów na ekran w zale¿noœci od stanu gry, obliczanie czasu miêdzy klatkami
	oraz sprawdzaniu wydarzeñ i aktualizowaniu pozycji wszystkich obiektów na planszy.
	*/
	void Run();

	/** Metoda odpowiada za rysowanie obiektów w grze na ekran w zale¿noœci od stanu gry. Odœwie¿a ona ekran oraz rysuje i wyœwietla
	elementy gry na ekranie.
	@param window wskaŸnik na obiekt okna
	*/
	void Draw(sf::RenderWindow * window);

	/** Metoda inicjuje domyœlne klawisze do obs³ugi wejœcia w grze.
	*/
	void Init_default_keys();

	/** Metoda dla ka¿dej kuli w grze sprawdza czy nast¹pi³a kolizja z krañcem mapy, z innym graczem lub z bloczkiem na planszy.
	W przypadku, gdy nast¹pi kolizja kuli z jednostk¹ na mapie to w zale¿noœci od przynale¿noœci kuli niszczy kulê i przeciwnika lub
	niszczy kulê i gracza. Sprawdza równie¿ kolizjê z bloczkami.
	@param bullets wektor kul znajduj¹cych siê w grze.
	*/
	void Check_bullet_collisons(std::vector<Object*> & bullets);

	/** Metoda sprawdza czy kula nie znajduje siê na mapie.
	@return zwraca true jeœli kula jest poza map¹, w przeciwnym wypadku false
	*/
	bool Check_if_bullet_is_not_on_map(const Object * bullet)const;

	/** Sprawdza kolizjê kuli z bloczkiem na którym znajduje siê aktualnie kula oraz w zale¿noœci od typu bloczka ustawia mu teksturê.
	@return w przypadku kiedy kula nie niszczy bloczka i mo¿e przez niego przelecieæ zwraca false,
	*/
	bool Check_if_bullet_collides_with_block(Object * bullet);

	/** Metoda sprawdza czy kula niszczy jednostkê na mapie np. gracza lub przeciwnika. Je¿eli kula nachodzi na gracza to sprawdza czyja jest kula
	i na jak¹ jednostkê nachodzi (gracza czy przeciwnika).Jeœli kula nale¿y do przeciwnika i nachodzi na przeciwnika tonie niszczy go. Jeœli kula
	jest gracza i nachodzi na przeciwnika to niszczy go. Jeœli natomiast kula jest przeciwnika i nachodzi na gracza to nastêpuje koniec gry i gracz jest niszczony.
	@return zwraca true jeœli nastapi³a kolizja kuli z jak¹kolwiek jednostkom, a false jeœli nie nast¹pi³a kolizja kuli z jednostk¹
	*/
	bool Check_if_bullet_destroys_entity(Object* bullet);

	/** Metoda zwraca jak d³ugo porusza siê ostatnia wystrzelona kula przez gracza.
	@return czas od ostatniej stworzonej kuli przez gracza.
	*/
	float Get_bullet_time();

	/** Metoda resetuje zegar ostatnio wystrzelonej kuli.
	*/
	void Restart_bullet_clock();

	/** Metoda inicjuje szybkoœæ poruszania siê kul oraz mno¿nik w zale¿noœci od wybranego poziomu trudnoœci.
	*/
	void Init_if_game_diff_selected();

	/** Tworzy gracza na planszy, jeœli ich jest mniej ni¿ 3 i w okreœlonych odstêpach czasu.
	*/
	void Spawn_enemy();

	/** Spradza czy jednostka nie jest na mapie.
	@return zwraca true jeœli jednostka jest poza map¹, w przeciwnym wypadku zwraca false.
	*/
	bool Check_if_entity_is_not_on_map(Object* entity);
	
	
};

#endif // !GAME_H

