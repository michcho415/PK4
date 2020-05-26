#ifndef  BULLET_H
#define BULLET_H
#include "Object.h"



class Bullet: public Object {
private:

	const int size = 16;

public:
	Bullet();
	~Bullet();
	Bullet(float x, float y, float speed, Direction dir);
	void set_Tile();
	void Update(sf::Event & ev, float dt);
	void Set_sprite(Direction d);
	void Draw(sf::RenderWindow *& window);
	void shape_Sprite(sf::IntRect & x);
	void Move_Up(float dt);
	void Move_Down(float dt);
	void Move_Left(float dt);
	void Move_Right(float dt);
	
};
#endif // ! BULLET_H
