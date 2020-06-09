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
	double x, y;
	double velocity;
	int tile_x, tile_y;
	int tile_x_2, tile_y_2;
	

public:
	Object();
	virtual ~Object() = default;
	Object(double x, double y, double speed, Direction d);
	virtual int get_size() = 0;
	virtual void set_Tile() = 0;
	virtual void Draw(sf::RenderWindow *& window) = 0;
	virtual void Update(sf::Event & ev, double dt) = 0;
	Direction get_direction();
	sf::Vector2f getPosition()const;
	int get_tile_x();
	int get_tile_y();


	

};



#endif
