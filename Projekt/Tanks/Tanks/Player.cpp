#include "Player.h"
#include "Game.h"
#include "Sprites.h"
#include <iostream>

Player::Player(double x, double y, double speed, Direction dir): Object(x, y, speed, dir)
{
	sprite = Sprites::Get().get_sprite("Tanks", sf::IntRect(0, 0, 32, 32));
	sprite.setPosition(x, y);
	this->set_Tile();
	
}

int Player::get_size()
{
	return size;
}

void Player::set_Tile()
{
	if (dir == UP_)
	{
		tile_x = (int)(x - 50) / 16; //-52
		tile_y = (int)(y - 32) / 16; //-32 
		tile_x_2 = (int)(x - 25) / 16; //dobrac tak zeby przy danym x nie bylo kolizji //-26 -24
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

void Player::Draw(sf::RenderWindow *& window)
{
	window->draw(sprite);
}

void Player::Update(sf::Event & ev, double dt) //switch
{
	std::map<Keys, sf::Keyboard::Key> keys = Game::Get().get_keys();
	float previous_y = y;
	float previous_x = x;

	if (ev.type == sf::Event::KeyPressed)
	{
		if (ev.key.code == keys[UP])
		{
			Move_Up(dt);
		}
		else if (ev.key.code == keys[DOWN])
		{
			Move_Down(dt);
		}
		else if (ev.key.code == keys[LEFT])
		{
			Move_Left(dt);
		}
		else if (ev.key.code == keys[RIGHT])
		{
			Move_Right(dt);
		}
		else if (ev.key.code == keys[SHOOT])
		{
			if (Game::Get().get_bullet_time() > 0.7)
			{
				Game::Get().Create_Bullet(this);
				Game::Get().restart_bullet_clock();
			}
		}
	}
	sprite.setPosition(x, y);
}



void Player::Move_Up(const double & dt)
{

	dir = UP_;
	this->set_Tile();
	float previous_y = y;
	y -= velocity * dt;
	sprite = Sprites::Get().get_sprite("Tanks", sf::IntRect(0, 0, size, size));
	if (Game::Get().Check_if_entity_is_not_on_map(this))
	{
		y = previous_y;
	}
	if (tile_y > 0){
		//sprawdzenie kolizji z bloczkami od gory
		if (Check_collision_on_tiles(tile_x, tile_y) ||
			Check_collision_on_tiles(tile_x_2, tile_y_2))
		{
			y = previous_y;
		}
	}
}

void Player::Move_Down(const double & dt)
{
	dir = DOWN_;
	this->set_Tile();
	float previous_y = y;
	y += velocity * dt;
	sprite = Sprites::Get().get_sprite("Tanks", sf::IntRect(0, 64, size, size));
	if (Game::Get().Check_if_entity_is_not_on_map(this))
	{
		y = previous_y;
	}
	if (tile_y < 25){
		//sprawdzenie kolizji z bloczkami od dolu
		if (Check_collision_on_tiles(tile_x, tile_y) ||
			Check_collision_on_tiles(tile_x_2, tile_y_2))
		{
			y = previous_y;
		}
			
	}
}

void Player::Move_Left(const double & dt)
{
	dir = LEFT_;
	this->set_Tile();
	float previous_x = x;
	x -= velocity * dt;
	sprite = Sprites::Get().get_sprite("Tanks", sf::IntRect(0, 96, size, size));

	if (Game::Get().Check_if_entity_is_not_on_map(this))
	{
		x = previous_x;
	}
	if(tile_x > 0) {
		//sprawdzenie kolizji z bloczkami od lewej
		if (Check_collision_on_tiles(tile_x, tile_y) ||
			Check_collision_on_tiles(tile_x_2, tile_y_2))
		{
			x = previous_x;
		}
	}
}

void Player::Move_Right(const double & dt)
{
	dir = RIGHT_;
	this->set_Tile();
	float previous_x = x;
	x += velocity * dt;
	sprite = Sprites::Get().get_sprite("Tanks", sf::IntRect(0, 32, size, size));

	if (Game::Get().Check_if_entity_is_not_on_map(this))
	{
		x = previous_x;
	}
	if (tile_x < 24) {
		//sprawdzenie kolizji z bloczkami od prawej
		if (Check_collision_on_tiles(tile_x, tile_y) ||
			Check_collision_on_tiles(tile_x_2, tile_y_2))
		{
			x = previous_x;
		}

	}
	
	
}




const int Player::get_player_size()
{
	return size;
}

bool Player::Check_collision_on_tiles(int Tile_x, int Tile_y)
{
	if (Game::Get().get_level()->get_block(Tile_x, Tile_y).get_block_type() != NONE && //jesli jest rozny od None lub Bush
		Game::Get().get_level()->get_block(Tile_x, Tile_y).get_block_type() != BUSH)
	{
		return true;
	}
	return false;
}


