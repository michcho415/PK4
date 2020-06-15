#include "Object.h"
#include <fstream>
#include <cmath>

Object::Object(): tile_x(0), tile_y(0), dir(UP_)
{
}

Object::Object(double x, double y, double speed, Direction d): x(x), y(y), velocity(speed), tile_x(0), tile_y(0), dir(d)
{

}

Direction Object::Get_direction()
{
	return dir;
}

sf::Vector2f Object::Get_position() const
{
	return sf::Vector2f(x, y);
}

void Object::Set_position(double X, double Y)
{
	x = X;
	y = Y;
}

int Object::Get_tile_x()
{
	return tile_x;
}

int Object::Get_tile_y()
{
	return tile_y;
}

