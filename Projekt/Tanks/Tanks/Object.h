#ifndef OBJECT_H
#define OBJECT_H

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

enum Direction { UP_, DOWN_, LEFT_, RIGHT_};

class Object
{
protected:
	
	

	sf::Sprite sprite;
	Direction dir;
	float x, y;
	float velocity;
	int tile_x, tile_y;
	int tile_x_2, tile_y_2;
	

public:
	Object();
	virtual ~Object();
	Object(float x, float y, float speed, Direction d);
	virtual void set_Tile() = 0;
	virtual void shape_Sprite(sf::IntRect & x) = 0;
	virtual void Draw(sf::RenderWindow *& window) = 0;
	virtual void Update(sf::Event & ev, float dt) = 0; //TO DO: Player, Enemy
	Direction get_direction();
	sf::Vector2f getPosition()const;


	

};



#endif
