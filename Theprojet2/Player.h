#pragma once
#include "Entity.h"
#include "Vector2.h"
class Player : public Entity
{
	
public:

	Player(int hp, int maxHp, Vector2 pos, char cell) : Entity(hp, maxHp, pos, cell) {}
	enum Direction { UP = 0, DOWN, LEFT, RIGHT, NONE };
	virtual void move(Vector2 dir);
	Direction InputToDirection(int key);
	void ApplyDirection(Direction direction, Vector2& pos);
};


