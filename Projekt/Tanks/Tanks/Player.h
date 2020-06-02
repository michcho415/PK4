#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"


class Player: public Object
{
public:
	const int size = 32;

public:
	Player(float x, float y, float speed, Direction dir);
	int get_size();
	void set_Tile();
	void Draw(sf::RenderWindow *& window);
	void Update(sf::Event & ev, float dt);
	void shape_Sprite(sf::IntRect & x);
	void Move_Up(const float & dt);
	void Move_Down(const float & dt);
	void Move_Left(const float & dt);
	void Move_Right(const float & dt);
	const int get_player_size();
	
	
	

};

#endif