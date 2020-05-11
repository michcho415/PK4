#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Menu.h"
#include "Level.h"
#include "Sprites.h"





class Game
{
private:

	std::map<Keys, sf::Keyboard::Key> keys;
	Game_State game_state;
	Difficulty game_difficulty;
	const unsigned int block_size = 16;


	//
	Menu* menu;
	sf::RenderWindow* window;
	Level* stage;
	//


public:

	Game();
	//~Game();
	void Run();
	void InitDefaultKeys();
	void set_game_state(Game_State state) { game_state = state; }
	Game_State get_game_state() { return game_state; }
	void set_difficulty(Difficulty diff) { game_difficulty = diff; }
	Difficulty get_difficulty() { return game_difficulty;}
	const unsigned int get_block_size() { return block_size; }
	sf::RenderWindow* get_window() { return window; }
	static Game & Get() { static Game Game; return Game; }


};

#endif // !GAME_H

