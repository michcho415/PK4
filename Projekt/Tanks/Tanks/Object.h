#ifndef OBJECT_H
#define OBJECT_H

#include "SFML/Graphics.hpp"

class Object
{
protected:

	sf::Sprite sprite;
	float x, y;
	float velocity;
	

public:
	Object();
	Object(float x, float y, float speed);
	void setPosition(float a, float b);
	void shapeSprite(sf::IntRect & x);
	virtual void Draw(sf::RenderWindow *& window) = 0;
	virtual void Update() = 0; //TO DO: Player, Enemy

	

};



#endif
