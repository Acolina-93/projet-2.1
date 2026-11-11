#include "Warrior.h"



void Warrior::onCollision(Entity *other)
{
    applyDamage(1);
    other->applyDamage(1);
}