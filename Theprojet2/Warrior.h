#pragma once
#include "Player.h"

class Warrior : virtual public Player
{

public:
    Warrior(Vector2 pos) : Player(HP, MAX_HP, pos, cell)
    {
    }

    void onCollision(Entity *other) override;

protected:
    static constexpr int HP = 3;
    static constexpr int MAX_HP = 3;
    static constexpr char cell = 'W';
};
