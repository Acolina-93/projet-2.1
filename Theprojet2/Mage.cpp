#include "Mage.h"
#include "Entity.h"
#include "Game.h"
#include <conio.h>

void Mage::onCollision(Entity *)
{
    applyDamage(1);
}

void Mage::onUpdate()
{
    char key = _getch();
    PlayerInput input = inputToDirection(key);
    if (input == ACTION)
    {
        castSpell();
    }
    else
    {

        moveFromInput(input);
    }
}

void Mage::castSpell(Entity *target)
{
    if (target != nullptr && target->isAlive())
    {
        target->applyDamage(1);
    }
}