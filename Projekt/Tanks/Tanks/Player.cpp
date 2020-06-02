#include "Player.h"
#include "Game.h"
#include "Sprites.h"
#include <iostream>

Player::Player(float x, float y, float speed, Direction dir): Object(x, y, speed, dir)
{
	sprite = Sprites::Get().get_sprite("Tanks", sf::IntRect(0, 0, 32, 32));
	sprite.setPosition(x, y);
	this->set_Tile();
	//if (Game::Get().get_difficulty() == EASY) { velocity = 3; }
	//else if (Game::Get().get_difficulty() == MEDIUM) { velocity = 2; }
	//else if (Game::Get().get_difficulty() == HARD) { velocity = 1.5; }
}

int Player::get_size()
{
	return size;
}

void Player::set_Tile()
{

	tile_x = (int)floor((x - 52) / 16); //-52
	tile_y = (int)floor((y - 32) / 16); //-32 
	tile_x_2 = (int)floor((x - 24) / 16); //dobrac tak zeby przy danym x nie bylo kolizji //-26 -24
	tile_y_2 = (int)floor((y - 4) / 16); //-6 lub -2 -4


	//std::cout << "X: " << x - 52 << " " << "Y: " << y - 32 << '\n';
	//std::cout << "tile_X: " << tile_x << " " << "tile_Y: " << tile_y << "\t\t tile_X2: " << tile_x_2 << " " << "tile_Y2: " << tile_y_2 << '\n';

}

void Player::Draw(sf::RenderWindow *& window)
{
	window->draw(sprite);
}

void Player::Update(sf::Event & ev, float dt)
{
	std::map<Keys, sf::Keyboard::Key> keys = Game::Get().get_keys();

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
			if (Game::Get().get_bullet_time() > 0.4)
			{
				Game::Get().Create_Bullet(this);
				Game::Get().restart_bullet_clock();
			}
			
		}
		
	}
	sprite.setPosition(x, y);
	this->set_Tile();

}

void Player::shape_Sprite(sf::IntRect & x)
{
}

void Player::Move_Up(const float & dt)
{
	dir = UP_;
	float previous_y = y;
	y -= velocity * dt;
	sprite = Sprites::Get().get_sprite("Tanks", sf::IntRect(0, 0, size, size));
	if (y <= (Game::Get().get_level()->get_Center_y() - 208))
		y = Game::Get().get_level()->get_Center_y() - 208;
	if (tile_y != 0){
		//sprawdzenie kolizji z bloczkami od gory
		if (Game::Get().get_level()->get_block(tile_x, tile_y).get_block_type() != NONE &&
			Game::Get().get_level()->get_block(tile_x, tile_y).get_block_type() != BUSH) { //jesli jest rozny od None lub Bush
			y = previous_y;
		}
		if (Game::Get().get_level()->get_block(tile_x_2, tile_y_2 - 2).get_block_type() != NONE &&
			Game::Get().get_level()->get_block(tile_x_2, tile_y_2 - 2).get_block_type() != BUSH) {
			y = previous_y;			}
	}
}

void Player::Move_Down(const float & dt)
{
	dir = DOWN_;
	float previous_y = y;
	y += velocity * dt;
	sprite = Sprites::Get().get_sprite("Tanks", sf::IntRect(0, 64, size, size));
	if (y >= (Game::Get().get_level()->get_Center_y() + 208 - size))
		y = Game::Get().get_level()->get_Center_y() + 208 - size;
	if (tile_y != 25){


		//sprawdzenie kolizji z bloczkami od dolu
		if (Game::Get().get_level()->get_block(tile_x, tile_y + 2).get_block_type() != NONE &&
			Game::Get().get_level()->get_block(tile_x, tile_y + 2).get_block_type() != BUSH) //jesli jest rozny od None lub Bush
			y = previous_y;
		if (Game::Get().get_level()->get_block(tile_x_2, tile_y_2).get_block_type() != NONE &&
			Game::Get().get_level()->get_block(tile_x_2, tile_y_2).get_block_type() != BUSH)
			y = previous_y;
			
	}
}

void Player::Move_Left(const float & dt)
{
	dir = LEFT_;
	float previous_x = x;
	x -= velocity * dt;
	sprite = Sprites::Get().get_sprite("Tanks", sf::IntRect(0, 96, size, size));

	if (x <= (Game::Get().get_level()->get_Center_x() - 208))
		x = Game::Get().get_level()->get_Center_x() - 208;
	if(tile_x != 0) {
		//sprawdzenie kolizji z bloczkami od lewej
		if (Game::Get().get_level()->get_block(tile_x, tile_y).get_block_type() != NONE &&
			Game::Get().get_level()->get_block(tile_x, tile_y).get_block_type() != BUSH) //jesli jest rozny od None lub Bush
			x = previous_x;
		if (Game::Get().get_level()->get_block(tile_x, tile_y_2).get_block_type() != NONE &&
			Game::Get().get_level()->get_block(tile_x, tile_y_2).get_block_type() != BUSH)
			x = previous_x;
	}
}

void Player::Move_Right(const float & dt)
{
	dir = RIGHT_;
	float previous_x = x;
	x += velocity * dt;
	sprite = Sprites::Get().get_sprite("Tanks", sf::IntRect(0, 32, size, size));

	if (x >= (Game::Get().get_level()->get_Center_x() + 208 - size))
		x = Game::Get().get_level()->get_Center_x() + 208 - size;
	if (tile_x != 24) {
		//sprawdzenie kolizji z bloczkami od prawej
		if (Game::Get().get_level()->get_block(tile_x + 2, tile_y).get_block_type() != NONE &&
			Game::Get().get_level()->get_block(tile_x + 2, tile_y).get_block_type() != BUSH) //jesli jest rozny od None lub Bush
			x = previous_x;
		if (Game::Get().get_level()->get_block(tile_x_2, tile_y_2).get_block_type() != NONE &&
			Game::Get().get_level()->get_block(tile_x_2, tile_y_2).get_block_type() != BUSH)
			x = previous_x;
	}
}

const int Player::get_player_size()
{
	return size;
}


