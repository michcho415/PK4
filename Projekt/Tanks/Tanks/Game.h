#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Menu.h"

enum Difficulty{EASY, MEDIUM, HARD};



class Game
{
private:

	std::map<std::string, sf::Keyboard::Key> Keys;
	Game_State game_state;
	Difficulty game_difficulty;


	/////////
	Menu* menu;
	sf::RenderWindow* window;

	
	


public:

	Game();
	void Run();
	void set_game_state(Game_State state) { game_state = state; }
	Game & Get() { return *this; }
	friend int set_Keys(std::map<std::string, sf::Keyboard::Key> & keys, sf::Event & event, const char* name);

};

#endif // !GAME_H

