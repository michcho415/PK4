#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Menu.h"
#include "Level.h"
#include "Sprites.h"
#include "Player.h"
#include "Bullet.h"





class Game
{
private:

	std::map<Keys, sf::Keyboard::Key> keys;
	Game_State game_state;
	Difficulty game_difficulty;
	const unsigned int block_size = 16;
	float bullet_speed;
	float entity_speed;
	float ratio;
	sf::Clock bullet_clock;


	//
	Menu* menu;
	sf::RenderWindow* window;
	Level* stage;
	Object* player;
	std::vector<Object*> bullets;
	std::vector<Object*> entities;

	//


public:

	Game();
	//~Game();
	Game(const Game & o) = delete;
	static Game & Get() { static Game Game; return Game; }

	void set_game_state(Game_State state) { game_state = state; }
	Game_State get_game_state() { return game_state; }
	void set_difficulty(Difficulty diff) { game_difficulty = diff; }
	Difficulty get_difficulty() { return game_difficulty;}
	const unsigned int get_block_size() { return block_size; }
	std::map<Keys, sf::Keyboard::Key>& get_keys() { return keys; }
	sf::RenderWindow* get_window() { return window; }
	Level* get_level() { return stage; }
	

	void Create_Bullet(Object* ob);
	void Run();
	void InitDefaultKeys();
	void Check_bullet_collisons(std::vector<Object*> & bullets);
	bool Check_if_bullet_is_not_on_map(const Object * bullet)const;
	bool Check_if_bullet_collides_with_block(Object * bullet);
	bool Check_if_bullet_destroys_entity(Object* bullet);
	float get_bullet_time();
	void restart_bullet_clock();
	void Init_if_game_diff_selected();
	
};

#endif // !GAME_H

