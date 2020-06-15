#include "Game.h"
#include "Level.h"
#include "Block.h"
#include "Enemy.h"
#include <typeinfo>

Game::Game():game_state(MAIN_MENU), game_difficulty(EASY), entity_speed(0.2), enemies_on_map(0), score(0), block_size(16)
{
	
	Sprites instance;
	window = new sf::RenderWindow(sf::VideoMode(640, 480), "Game");
	menu = new Menu(window);
	stage = new Level(window);
	Init_default_keys();
	stage->Load_level_from_file("Stage1.txt");
	player = new Player(stage->Get_center_x()-64, stage->Get_center_y()+174, entity_speed, UP_); // wywalic stad inicjalizowac z
	entities.push_back(std::move(player));
	
	

}

Game::~Game()
{
	for (auto&el : entities)
	{
		delete el;
	}
	for (auto& el : bullets)
	{
		delete el;
	}
	delete stage;
	delete menu;
	delete window;
}

void Game::Run()
{
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);

	sf::Clock clock;
	sf::Time time;
	
	float delta_time= 0;
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
				score = 0;
				spawn_clock.restart();
				
			}
			else if (game_state == PLAYING)
			{
				if (player != nullptr)
				{
					player->Update(event, delta_time);
				}

			}

		}
		if (game_state == PLAYING)
		{
			for (auto it = entities.begin() + 1; it < entities.end(); ++it)
			{
				(*it)->Update(event, delta_time);
			}
			for (auto& el : bullets)
			{
				el->Update(event, delta_time);
			}
			

			if (spawn_clock.getElapsedTime().asSeconds() > 2)
			{
				Spawn_enemy();
			}
			for (auto it = entities.begin() + 1; it < entities.end(); it++)
			{
				dynamic_cast<Enemy*>(*it)->Choose_action();
			}

			Check_bullet_collisons(bullets);


		}
		Draw(window);
		time = clock.restart();
		delta_time = static_cast<float>(time.asMilliseconds());
	}
}

void Game::Draw(sf::RenderWindow * window)
{
	
	if (game_state == MAIN_MENU || game_state == OPTIONS)
	{
		window->clear(sf::Color::Black);
		menu->Draw(window);
		
		
	}
	else if (game_state == PLAYING)
	{
		window->clear(sf::Color(145, 145, 145));
		stage->Draw_background(window);
		for (auto& el : bullets)
		{
			el->Draw(window);
		}
		for (auto& el : entities)
		{
			el->Draw(window);
		}
		stage->Draw(window);

		menu->Draw(window);
		
	}
	else if (game_state == OVER)
	{
		window->clear(sf::Color::Black);
		menu->Draw(window);
	}
	window->display();
}

void Game::Init_default_keys()
{
	keys[UP] = sf::Keyboard::Up;
	keys[DOWN] = sf::Keyboard::Down;
	keys[LEFT] = sf::Keyboard::Left;
	keys[RIGHT] = sf::Keyboard::Right;
	keys[SHOOT] = sf::Keyboard::Space;
	keys[ESCAPE] = sf::Keyboard::Escape;
	keys[ENTER] = sf::Keyboard::Enter;
}

void Game::Create_Bullet(Object* ob)
{
	float entitity_bullet_speed;
	bool is_players;
	if (typeid(Player) == typeid(*ob))
	{
		is_players = 1;
		entitity_bullet_speed = bullet_speed * ratio;
	}
	else {
		is_players = 0;
		entitity_bullet_speed = bullet_speed;
	}

	int spawn_position_x = ob->Get_position().x;
	int spawn_position_y = ob->Get_position().y;
	if (ob->Get_direction() == UP_)
	{
		spawn_position_y -= (block_size + 1);
	}
	else if (ob->Get_direction() == DOWN_)
	{
		spawn_position_y += (block_size + 1);
	}
	else if (ob->Get_direction() == LEFT_)
	{
		spawn_position_x -= (block_size + 1);
	}
	else if (ob->Get_direction() == RIGHT_)
	{
		spawn_position_x += (block_size + 1);
	}
	

	Object* bullet = new Bullet(spawn_position_x + block_size, spawn_position_y + block_size, entitity_bullet_speed, ob->Get_direction(), is_players);
	bullets.push_back(bullet);
}

void Game::Check_bullet_collisons(std::vector<Object*> & bullets)
{

	for (auto it = bullets.begin(); it < bullets.end();)
	{
		
		if (Check_if_bullet_is_not_on_map(*it) ||
			Check_if_bullet_destroys_entity(*it) ||
			Check_if_bullet_collides_with_block(*it))
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
	if (bullet->Get_position().x < stage->Get_center_x() - 204 ||
		bullet->Get_position().x > stage->Get_center_x() + 204 ||
		bullet->Get_position().y < stage->Get_center_y() - 204 ||
		bullet->Get_position().y > stage->Get_center_y() + 204	)
	{
		return true;
	}
	return false;
}

bool Game::Check_if_bullet_collides_with_block(Object * bullet)
{
	Block_type temp = stage->Get_block(bullet->Get_tile_x(), bullet->Get_tile_y()).get_block_type();

	if (temp == NONE || temp == BUSH) // nie niszczy i moze przeleciec
	{
		return false;
	}
	else if (temp == METAL)// nie niszczy ale moze przeleciec
	{
		return true;
	}
	else if (temp == BRICK) //niszczy
	{
		stage->Set_block(bullet->Get_tile_x(), bullet->Get_tile_y(), NONE);
		return true;
	}
	return false;
}

bool Game::Check_if_bullet_destroys_entity(Object * bullet)
{
	for (auto it2 = entities.begin(); it2 < entities.end(); )
	{
		
		if (bullet->Get_position().x > (*it2)->Get_position().x && 
			bullet->Get_position().x < (*it2)->Get_position().x + 32 && 
			bullet->Get_position().y > (*it2)->Get_position().y &&
			bullet->Get_position().y < (*it2)->Get_position().y + 32) //sprawdz czy kula nachodzi za gracza
		{
			Object * ob = *it2;
			if (typeid(*ob) != typeid(Player) ) //RTTI do sprawdzenia czy gracz umarl jesli nie jest gracza
			{
				if (dynamic_cast<Bullet*>(bullet)->get_belongingness() == false) // jesli jest od przeciwnika
				{
					return true;
				}
				else {
					score += 10 * ratio;
				}
				--enemies_on_map;
			}
			else {
				Set_game_state(OVER);
				
				
			}
			
			delete *it2;
			it2 = entities.erase(it2);
			return true;
		}
		else {
			++it2;
		}
		
	}
	
	return false;
}

float Game::Get_bullet_time()
{
	float elapsed_time = bullet_clock.getElapsedTime().asSeconds();
	return elapsed_time;

}

void Game::Restart_bullet_clock()
{
	bullet_clock.restart();
}

void Game::Init_if_game_diff_selected()
{
	bullet_speed = 0.3f;
	switch (game_difficulty)
	{
	case EASY:
		
		ratio = 0.6f;
		break;
	case MEDIUM:

		ratio = 0.7f;
		break;
	case HARD:

		ratio = 0.9f;
		break;
	}
}

void Game::Spawn_enemy()
{
	if (enemies_on_map < 3)
	{
		Object * enemy = new Enemy(stage->Get_center_x() - stage->Get_size_x()/2 + 1, stage->Get_center_y() - stage->Get_size_y()/2 + 1, entity_speed*ratio, DOWN_);
		entities.push_back(enemy);
		++enemies_on_map;
		spawn_clock.restart();

	}

}

bool Game::Check_if_entity_is_not_on_map(Object * entity)
{
	if (entity->Get_position().y <= stage->Get_center_y() - 13 * block_size - 2  ||
		entity->Get_position().y >= stage->Get_center_y() + 11 * block_size + 2 ||
		entity->Get_position().x <= stage->Get_center_x() - 13 * block_size - 2 ||
		entity->Get_position().x >= stage->Get_center_x() + 11 * block_size + 2)
		
	{
		return true;
	}
	return false;
}

