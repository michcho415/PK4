#ifndef  BULLET_H
#define BULLET_H
#include "Object.h"



class Bullet: public Object {
private:
	bool is_players;
	const int size = 16;

public:
	Bullet();
	~Bullet();
	Bullet(double x, double y, double speed, Direction dir, bool whose);
	int get_size();
	void set_Tile();
	void Update(sf::Event & ev, double dt);
	void Set_sprite(Direction d);
	void Draw(sf::RenderWindow *& window);
	void Move_Up(double dt);
	void Move_Down(double dt);
	void Move_Left(double dt);
	void Move_Right(double dt);
	bool get_belongingness();
	
};
#endif // ! BULLET_H
