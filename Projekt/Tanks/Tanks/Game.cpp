#include "Game.h"
#include "Level.h"
#include "Block.h"

#include <iostream>


Game::Game():game_state(MAIN_MENU), game_difficulty(EASY), entity_speed(0.2f)
{
	

	window = new sf::RenderWindow(sf::VideoMode(640, 480), "Game");
	menu = new Menu(window);
	stage = new Level(window);
	InitDefaultKeys();
	stage->LoadLevelfromFile("Stage1.txt");
	player = new Player(stage->get_Center_x()-64, stage->get_Center_y()+176, entity_speed, UP_);
	entities.push_back(std::move(player));

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
				Init_if_game_diff_selected();
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
			for (auto& el : bullets)
			{
				el->Draw(window);
			}
			stage->Draw(window);

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
	int spawn_position_x = ob->getPosition().x;
	int spawn_position_y = ob->getPosition().y;
	if (ob->get_direction() == UP_)
	{
		spawn_position_y -= (block_size + 1);
	}
	else if (ob->get_direction() == DOWN_)
	{
		spawn_position_y += (block_size + 1);
	}
	else if (ob->get_direction() == LEFT_)
	{
		spawn_position_x -= (block_size + 1);
	}
	else if (ob->get_direction() == RIGHT_)
	{
		spawn_position_x += (block_size + 1);
	}
	Object* bullet = new Bullet(spawn_position_x + block_size, spawn_position_y + block_size, bullet_speed, ob->get_direction());
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
		else if(Check_if_bullet_destroys_entity(*it)) // niszczenie czo³gu
		{
			delete *it;
			it = bullets.erase(it);
		}
		else if (Check_if_bullet_collides_with_block(*it)) // niszczenie bloczka
		{
			delete *it;
			it = bullets.erase(it);		
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

bool Game::Check_if_bullet_collides_with_block(Object * bullet)
{

	if (stage->get_block(bullet->get_tile_x(), bullet->get_tile_y()).get_block_type() == BUSH ||
		stage->get_block(bullet->get_tile_x(), bullet->get_tile_y()).get_block_type() == NONE) // nie niszczy i moze przeleciec
	{
		return false;
	}
	else if (stage->get_block(bullet->get_tile_x(), bullet->get_tile_y()).get_block_type() == METAL)// nie niszczy ale moze przeleciec
	{
		return true;
	}
	else if (stage->get_block(bullet->get_tile_x(), bullet->get_tile_y()).get_block_type() == BRICK) //niszczy
	{
		stage->set_block(bullet->get_tile_x(), bullet->get_tile_y(), NONE);
		return true;
	}
	return false;
}

bool Game::Check_if_bullet_destroys_entity(Object * bullet)
{
	for (auto it2 = entities.begin(); it2 < entities.end(); ++it2)
	{
		if (bullet->getPosition().x > (*it2)->getPosition().x - 8 && //(*it)->get_size() / 2
			bullet->getPosition().x < (*it2)->getPosition().x + 8 &&
			bullet->getPosition().y >(*it2)->getPosition().y - 8 / 2 &&
			bullet->getPosition().y < (*it2)->getPosition().y + 8 / 2)
		{
			if(it2) //RTTI do sprawdzenia czy gracz umar³
			return true;
		}
		
	}
	
	return false;
}

float Game::get_bullet_time()
{
	float elapsed_time = bullet_clock.getElapsedTime().asSeconds();
	return elapsed_time;

}

void Game::restart_bullet_clock()
{
	bullet_clock.restart();
}

void Game::Init_if_game_diff_selected()
{
	switch (game_difficulty)
	{
	case EASY:
		bullet_speed = 0.3f;
		ratio = 1;
		break;
	case MEDIUM:
		bullet_speed = 0.4f;
		ratio = 1.05;
		break;
	case HARD:
		bullet_speed = 0.6f;
		ratio = 1.2f;
		break;
	}
}






