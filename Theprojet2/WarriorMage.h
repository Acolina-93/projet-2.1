#pragma once
#include "Player.h"

class WarriorMage : public Player
{

public:
    WarriorMage(int hp, int maxHp, Vector2 pos, char cell) : Player(hp, maxHp, pos, cell)
    {
    }

    void onCollision(Entity* other);
};
