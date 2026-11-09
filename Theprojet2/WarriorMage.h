#pragma once
#include "Mage.h"
#include "Warrior.h"

class WarriorMage : public Warrior, public Mage
{
public:

    WarriorMage( Vector2 pos)
        : Player(hp, maxHp, pos, cell), Warrior(pos),
          Mage(pos)
    {
    }

    void onCollision(Entity *other) override
    {
        Warrior::onCollision(
            other); // Résout l'ambiguïté de méthode entre Warrior et Mage
    }

protected:
    int hp = 3;
    int maxHp = 3;
    char cell = 'B';
};