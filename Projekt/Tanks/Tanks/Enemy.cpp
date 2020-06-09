#include "Enemy.h"
#include "Sprites.h"
#include "Game.h"
#include <random>
#include <iostream>
#include <chrono>

Enemy::Enemy() :Object()
{
}

Enemy::Enemy(double x, double y, double speed, Direction dir): Object(x, y, speed, dir)
{
	sprite = Sprites::Get().get_sprite("Tanks", sf::IntRect(64, 64, size, size));
	tile_x = 0;
	tile_x_2 = 0;
	tile_y = 0;
	tile_y_2 = 0;
	sprite.setPosition(x, y);
}

int Enemy::get_size()
{
	return size;
}

void Enemy::set_Tile()
{
	if (dir == UP_)
	{
		tile_x = (int)(x - 50) / 16; 
		tile_y = (int)(y - 32) / 16; 
		tile_x_2 = (int)(x - 25) / 16; //dobrac tak zeby sprawdza³o odpowiednie bloczki
		tile_y_2 = (int)(y - 32) / 16;
	}
	else if (dir == DOWN)
	{
		tile_x = (int)(x - 50) / 16;
		tile_y = (int)(y / 16);
		tile_x_2 = (int)(x - 25) / 16;
		tile_y_2 = (int)(y / 16);
	}
	else if (dir == LEFT_)
	{
		tile_x = (int)(x - 50) / 16;
		tile_y = (int)(y - 32) / 16;
		tile_x_2 = (int)(x - 50) / 16;
		tile_y_2 = (int)(y - 2) / 16;
	}
	else if (dir == RIGHT_)
	{
		tile_x = (int)(x - 20) / 16;
		tile_y = (int)(y - 32) / 16;
		tile_x_2 = (int)(x - 20) / 16;
		tile_y_2 = (int)(y - 2) / 16;
	}
	//std::cout << "X: " << x << " " << "Y: " << y << '\n';
	//std::cout << "tile_X: " << tile_x << " " << "tile_Y: " << tile_y << "\t\t tile_X2: " << tile_x_2 << " " << "tile_Y2: " << tile_y_2 << '\n';
}

void Enemy::Draw(sf::RenderWindow *& window)
{
	window->draw(sprite);
}

void Enemy::Update(sf::Event & ev, double dt)
{
	float previous_x = x;
	float previous_y = y;
	switch (dir)
	{
	case UP_:
		Move_Up(dt);
		break;
	case DOWN_:
		Move_Down(dt);
		break;
	case LEFT_:
		Move_Left(dt);
		break;
	case RIGHT_:
		Move_Right(dt);
		break;
	}
	if (Game::Get().Check_if_entity_is_not_on_map(this))
	{
		x = previous_x;
		y = previous_y;
	}
	sprite.setPosition(x, y);

}

void Enemy::Move_Up(const double & dt)
{
	set_Tile();
	float previous_y = y;
	y -= velocity * dt;
	sprite = Sprites::Get().get_sprite("Tanks", sf::IntRect(64, 0, size, size));
	if (tile_y > 0) {
		//sprawdzenie kolizji z bloczkami od gory
		if (Check_collision_with_tiles(tile_x, tile_y) ||
			Check_collision_with_tiles(tile_x_2, tile_y_2))
		{
			y = previous_y;
		}
	}

}

void Enemy::Move_Down(const double & dt)
{
	set_Tile();
	float previous_y = y;
	y += velocity * dt;
	sprite = Sprites::Get().get_sprite("Tanks", sf::IntRect(64, 64, size, size));
	if (tile_y < 25) {


		//sprawdzenie kolizji z bloczkami od dolu
		if (Check_collision_with_tiles(tile_x, tile_y) ||
			Check_collision_with_tiles(tile_x_2, tile_y_2))
		{
			y = previous_y;
		}

	}
}

void Enemy::Move_Left(const double & dt)
{
	set_Tile();
	float previous_x = x;
	x -= velocity * dt;
	sprite = Sprites::Get().get_sprite("Tanks", sf::IntRect(64, 96, size, size));
	if (tile_x > 0) {
		//sprawdzenie kolizji z bloczkami od lewej
		if (Check_collision_with_tiles(tile_x, tile_y) ||
			Check_collision_with_tiles(tile_x_2, tile_y_2))
		{
			x = previous_x;
		}
	}
}

void Enemy::Move_Right(const double & dt)
{
	set_Tile();
	float previous_x = x;
	x += velocity * dt;
	sprite = Sprites::Get().get_sprite("Tanks", sf::IntRect(64, 32, size, size));
	if (tile_x < 24) {
		//sprawdzenie kolizji z bloczkami od prawej
		if (Check_collision_with_tiles(tile_x, tile_y) ||
			Check_collision_with_tiles(tile_x_2, tile_y_2))
		{
			x = previous_x;
		}

	}
}

void Enemy::Choose_direction()
{
	
	std::default_random_engine engine;
	std::uniform_int_distribution<int> distribution(0, 3);
	engine.seed(std::chrono::system_clock::now().time_since_epoch().count());

	int choose_dir = distribution(engine);
	switch (choose_dir)
	{
	case 0:
		dir = UP_;
		break;
	case 1:
		dir = DOWN_;
		break;
	case 2:
		dir = LEFT_;
		break;
	case 3:
		dir = RIGHT_;
		break;
	}

	

}

float Enemy::Choose_time(float x, float y)
{
	std::default_random_engine engine;
	std::uniform_real_distribution<float> distribution(x, y);
	engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
	
	return distribution(engine);

}



void Enemy::Choose_action()
{
	driving_time = Choose_time(0.6, 1.1);
	if (driving_timer.getElapsedTime().asSeconds() > driving_time) // jezeli czas zegara przekroczyl tyle ile przeciwnik mial jechac to resetuj zegar i wybierz nowy czas
	{
		driving_timer.restart();
		Choose_direction();
	}

	float shooting_time = Choose_time(0.4, 0.7); //odstêp czasu miêdzy nastêpnymi kulami
	if (shooting_timer.getElapsedTime().asSeconds() > shooting_time)
	{
		shooting_timer.restart();
		Game::Get().Create_Bullet(this);
	}


}


bool Enemy::Check_collision_with_tiles(int Tile_x, int Tile_y) const
{
	if (Game::Get().get_level()->get_block(Tile_x, Tile_y).get_block_type() != NONE && //jesli jest rozny od None lub Bush
		Game::Get().get_level()->get_block(Tile_x, Tile_y).get_block_type() != BUSH)
	{
		return true;
	}
	return false;
}
