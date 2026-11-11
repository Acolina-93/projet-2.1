#include "Warrior.h"
#include "Player.h"
#include "Vector2.h"


void Warrior::onCollision(Entity *other)
{
    applyDamage(1);
    other->applyDamage(1);
}