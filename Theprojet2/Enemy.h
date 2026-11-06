#pragma once
#include <iostream>
#include "Entity.h"
#include "Vector2.h"

class Enemy : public Entity
{
public:

	Enemy(int hp, int maxHp, Vector2 pos, char cell) : Entity(hp, maxHp, pos, cell)
	{
	}
};

//test txt
