#ifndef BLOCK_H
#define BLOCK_H
#include "Object.h"
#include "SFML/Graphics.hpp"


enum Block_type {NONE, BRICK, METAL, BUSH};

class Block: public Object
{
	Block_type type;
	
public:
	Block();
	Block(float x, float y); 
	void Draw(sf::RenderWindow *& window);
	void setSprite(Block_type type);
	void Update();

};


#endif
