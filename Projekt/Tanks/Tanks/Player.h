#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"


class Player: public Object
{
public:
	const int size = 32;

public:
	Player(double x, double y, double speed, Direction dir);
	int get_size();
	void set_Tile();
	void Draw(sf::RenderWindow *& window);
	void Update(sf::Event & ev, double dt);
	void Move_Up(const double & dt);
	void Move_Down(const double & dt);
	void Move_Left(const double & dt);
	void Move_Right(const double & dt);
	const int get_player_size();
	bool Check_collision_on_tiles(int Tile_x, int Tile_y);
	
	
	

};

#endif