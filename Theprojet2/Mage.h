#pragma once
#include "Player.h"

class Mage : virtual public Player
{

public:
    Mage(Vector2 pos) : Player(HP, MAX_HP, pos, cell)
    {
    }

    void onCollision(Entity *other) override;

private:
    static constexpr int HP = 1;
    static constexpr int MAX_HP = 1;
    char cell = 'M';
};
