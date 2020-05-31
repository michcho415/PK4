#include "Object.h"
#include <fstream>
#include <iostream>
#include <cmath>

Object::Object(): tile_x(0), tile_y(0), dir(UP_)
{
}

Object::~Object()
{
}

Object::Object(float x, float y, float speed, Direction d): x(x), y(y), velocity(speed), tile_x(0), tile_y(0), dir(d)
{

}

//Oblicza na ktorej czesci mapy jest obiekt
void Object::set_Tile()
{

}

Direction Object::get_direction()
{
	return dir;
}

sf::Vector2f Object::getPosition() const
{
	return sf::Vector2f(x, y);
}

int Object::get_tile_x()
{
	return tile_x;
}

int Object::get_tile_y()
{
	return tile_y;
}

