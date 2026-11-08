#pragma once
#include "Entity.h"
#include "Vector2.h"
#include <iostream>

class Enemy : public Entity
{
public:

	Enemy(int hp, int maxHp, Vector2 pos, char cell) : Entity(hp, maxHp, pos, cell)
    {
    }
};


