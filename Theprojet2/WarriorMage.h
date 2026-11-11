#pragma once
#pragma warning(disable : 4250)
#include "Mage.h"
#include "Warrior.h"

class WarriorMage : public Warrior, public Mage
{
public:
    WarriorMage(Vector2 pos)
        : Player(Warrior::HP, Warrior::MAX_HP, pos, SYMBOL), Warrior(pos), Mage(pos)
    {
    }

    void onCollision(Entity *other) override
    {
        Warrior::onCollision(other);
    }

private:
    static constexpr char SYMBOL = 'N';
};