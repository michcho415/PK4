#include "Game.h"
#include "Level.h"
#include <iostream>


Game::Game():game_state(MAIN_MENU), game_difficulty(EASY), bullet_speed(0.4f)
{
	

	window = new sf::RenderWindow(sf::VideoMode(640, 480), "Game");
	menu = new Menu(window);
	stage = new Level(window);
	InitDefaultKeys();
	stage->LoadLevelfromFile("Stage1.txt");
	player = new Player(stage->get_Center_x()-64, stage->get_Center_y()+176, 0.2f, UP_);


}

void Game::Run()
{


	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);
	sf::Clock clock;
	sf::Time time;
	float delta_time;
	while (window->isOpen())
	{

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
			if (game_state == MAIN_MENU || game_state == OPTIONS)
			{
				menu->CheckEvents(event, window, keys);
			}
			else if (game_state == PLAYING)
			{
				player->Update(event, delta_time);

			}

		}
		for (auto& el : bullets)
		{
			el->Update(event, delta_time);
		}
		
		if (game_state == MAIN_MENU || game_state == OPTIONS)
		{
			window->clear(sf::Color::Black);
			menu->Draw(window);
		}
		else if (game_state == PLAYING)
		{
			window->clear(sf::Color(145,145,145));
			stage->Draw_background(window);
			player->Draw(window);
			stage->Draw(window);
			for (auto& el : bullets)
			{
				el->Draw(window);
			}
			Check_bullet_collisons(bullets);

		}
		
		window->display();
		time = clock.restart();
		delta_time = static_cast<float>(time.asMilliseconds());

		
	}
}

/** Metoda inicjuje domyœlne klawisze do obs³ugi wejœcia w grze.
*/
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

/** Metoda tworzy now¹ kulê w grze na pozycji danej jednosti i zgodnie z jej kierunkiem
@param wskaŸnik na obiekt, który tworzy kulê
*/
void Game::Create_Bullet(Object* ob)
{
	Object* bullet = new Bullet(ob->getPosition().x + block_size, ob->getPosition().y + block_size, bullet_speed, ob->get_direction());
	bullets.push_back(bullet);
}

void Game::Check_bullet_collisons(std::vector<Object*> & bullets)
{

	for (auto it = bullets.begin(); it < bullets.end();)
	{
		
		if (Check_if_bullet_is_not_on_map(*it))
		{
			delete *it;
			it = bullets.erase(it);
		}
		else if (false) // niszczenie bloczka
		{

		}
		else {
			
			++it;
		}
		
		

	}

}

bool Game::Check_if_bullet_is_not_on_map(const Object * bullet) const
{
	if (bullet->getPosition().x < stage->get_Center_x() - 204 ||
		bullet->getPosition().x > stage->get_Center_x() + 204 ||
		bullet->getPosition().y < stage->get_Center_y() - 204 ||
		bullet->getPosition().y > stage->get_Center_y() + 204	)
	{
		return true;
	}
	return false;
}


