#pragma once
#include "Player.h"

class Warrior : virtual public Player
{

public:
    Warrior(int hp, int maxHp, Vector2 pos, char cell) : Player(hp, maxHp, pos, cell)
    {
    }

    void onCollision(Entity *other);
};
