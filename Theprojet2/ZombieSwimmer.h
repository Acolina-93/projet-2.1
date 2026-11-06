#pragma once
#include "Enemy.h"

class ZombieSwimmer : public Enemy
{
public:
    ZombieSwimmer(int hp, int maxHp, Vector2 pos, char cell) : Enemy(hp, maxHp, pos, cell)
    {
    }

    // void onUpdate() override;
};
