#pragma once
#include "Enemy.h"

class HeadlessZombie : public Enemy
{
public:
    HeadlessZombie(int hp, int maxHp, Vector2 pos, char cell)
        : Enemy(hp, maxHp, pos, cell)
    {
    }

};
