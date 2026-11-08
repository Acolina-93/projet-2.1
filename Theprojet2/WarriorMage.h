#pragma once
#include "Mage.h"
#include "Warrior.h"

class WarriorMage : public Warrior, public Mage
{
public:
    WarriorMage(int hp, int maxHp, Vector2 pos, char cell)
        : Player(hp, maxHp, pos, cell), Warrior(hp, maxHp, pos, cell),
          Mage(hp, maxHp, pos, cell)
    {
    }

    void onCollision(Entity *other) override
    {
        Warrior::onCollision(
            other); // Résout l'ambiguïté de méthode entre Warrior et Mage
    }
};