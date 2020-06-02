#include "Bullet.h"
#include "Sprites.h"
#include "OriginandPositionTemplate.h"
#include <iostream>

Bullet::Bullet() : Object()
{

}

Bullet::~Bullet()
{
}

Bullet::Bullet(float x, float y, float speed, Direction dir):Object(x, y, speed, dir)
{
	Set_sprite(dir);
}

int Bullet::get_size()
{
	return size;
}

void Bullet::set_Tile()
{
	tile_x = (int)floor((x - 52) / 16); //-52
	tile_y = (int)floor((y - 32) / 16); //-32 
	//tile_x_2 = (int)floor((x - 24) / 16); //dobrac tak zeby przy danym x nie bylo kolizji //-26 -24
	//tile_y_2 = (int)floor((y - 4) / 16);
	std::cout << "X:" << tile_x << "Y: " << tile_y << '\n';
}


void Bullet::Update(sf::Event & ev, float dt)
{
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
	default:
		break;
	}
	sprite.setPosition(x, y);
	this->set_Tile();
}

void Bullet::Set_sprite(Direction d)
{
	dir = d;
	switch (d)
	{
	case UP_:
		sprite = Sprites::Get().get_sprite("Bullets", sf::IntRect(0, 0, size, size));
		break;
	case DOWN_:
		sprite = Sprites::Get().get_sprite("Bullets", sf::IntRect(2 * size, 0, size, size));
		break;
	case LEFT_:
		sprite = Sprites::Get().get_sprite("Bullets", sf::IntRect(3 * size, 0, size, size));
		break;
	case RIGHT_:
		sprite = Sprites::Get().get_sprite("Bullets", sf::IntRect(size, 0, size, size));
		break;
	}
	CenterOrigin(sprite);
}

void Bullet::Draw(sf::RenderWindow *& window)
{
	window->draw(sprite);
}

void Bullet::shape_Sprite(sf::IntRect & x)
{
}

void Bullet::Move_Up(float dt)
{
	y -= velocity * dt;
}

void Bullet::Move_Down(float dt)
{
	y += velocity * dt;
}

void Bullet::Move_Left(float dt)
{
	x -= velocity * dt;
}

void Bullet::Move_Right(float dt)
{
	x += velocity * dt;
}
