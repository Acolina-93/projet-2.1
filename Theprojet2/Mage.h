#pragma once
#include "Player.h"

class Mage : virtual public Player
{

public:
    Mage(Vector2 pos) : Player(HP, MAX_HP, pos, SYMBOL)
    {
    }
    void onUpdate() override;
    void onCollision(Entity *other) override;

private:
    void castSpell();
    static constexpr int HP = 1;
    static constexpr int MAX_HP = 1;
    static constexpr char SYMBOL = 'M';
};
