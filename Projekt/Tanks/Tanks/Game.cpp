#include "Game.h"

Game::Game():game_state(MAIN_MENU)
{
	window = new sf::RenderWindow(sf::VideoMode(400, 300), "Game");
	menu = new Menu(window->getSize().x, window->getSize().y);


}

void Game::Run()
{
	while (window->isOpen())
	{

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
			if (game_state == MAIN_MENU)
			{
				menu->CheckEvents(event, window, game_state, Keys);
			}
			
		}

		window->clear(sf::Color::Black);
		if (game_state == MAIN_MENU)
		{
			menu->Draw(*window, window->getSize().x, window->getSize().y);
		}
		
		window->display();
	}
}

int set_Keys(std::map<std::string, sf::Keyboard::Key> & keys, sf::Event & event, const char* name)
{	

	if (event.type == sf::Event::MouseButtonPressed)
	{
		//keys[name] = event.key.code;
		return event.key.code;
		
	}

}

