#pragma once
#include "Object.h"


class Enemy : public Object
{
	const int size = 32;
	float driving_time; //jak dlugo ma poruszac sie przeciwnik
	sf::Clock driving_timer; // jak dlugo aktualnie wykonuje ruch
	sf::Clock shooting_timer; //jak d�ugi jest odst�p mi�dzy kolejnymi kulami

public:
	Enemy();
	Enemy(double x, double y, double speed, Direction dir);
	int get_size();
	void set_Tile();
	void Draw(sf::RenderWindow *& window);
	void Update(sf::Event & ev, double dt);
	void Move_Up(const double & dt);
	void Move_Down(const double & dt);
	void Move_Left(const double & dt);
	void Move_Right(const double & dt);
	void Choose_direction(); //wybierz w kt�ra stron� jecha�;
	float Choose_time(float x, float y);
	void Choose_action(); //wybierz jak� akcje na jak dlugo
	bool Check_collision_with_tiles(int Tile_x, int Tile_y) const;
	
	
};