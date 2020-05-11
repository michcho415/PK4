#include "Game.h"
#include "Level.h"

Game::Game():game_state(MAIN_MENU), game_difficulty(EASY)
{
	

	window = new sf::RenderWindow(sf::VideoMode(640, 480), "Game");
	menu = new Menu(window);
	stage = new Level(window);


	InitDefaultKeys();
	stage->LoadLevelfromFile("Stage1.txt");

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
				menu->CheckEvents(event, window, keys);
			}
			
		}

		
		if (game_state == MAIN_MENU)
		{
			window->clear(sf::Color::Black);
			menu->Draw(window);
		}
		else if (game_state == PLAYING)
		{
			window->clear(sf::Color(145,145,145));
			stage->Draw(window);
		}
		
		window->display();
	}
}

void Game::InitDefaultKeys()
{
	keys[UP] = sf::Keyboard::Up;
	keys[DOWN] = sf::Keyboard::Down;
	keys[LEFT] = sf::Keyboard::Left;
	keys[RIGHT] = sf::Keyboard::Right;
	keys[SHOOT] = sf::Keyboard::Space;
	keys[ESCAPE] = sf::Keyboard::Escape;
	keys[ENTER] = sf::Keyboard::Enter;
}


