#include "Object.h"
#include <fstream>

Object::Object()
{
}

Object::Object(float x, float y, float speed): x(x), y(y), velocity(speed)
{

}

void Object::setPosition(float a, float b)
{
	x = a;
	y = b;
}

void Object::shapeSprite(sf::IntRect & x)
{
	sprite.setTextureRect(x);
}

