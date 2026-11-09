#pragma once
#include "Player.h"

class Warrior : virtual public Player
{

public:
    Warrior( Vector2 pos) : Player(hp, maxHp, pos, cell)
    {
    }

    void onCollision(Entity *other) override;

protected:

    int hp = 3;
    int maxHp = 3;
    char cell = 'W';
};
