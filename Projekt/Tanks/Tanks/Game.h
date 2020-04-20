#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Menu.h"



class Game
{
private:
	
	State game_state;


	/////////
	Menu menu;
	sf::RenderWindow main_window;

	
	


public:

	Game();
	static Game & Get() { static Game Game; return Game; }

};

#endif // !GAME_H

