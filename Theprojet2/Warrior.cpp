#include "Warrior.h"
#include "Player.h"
#include "Vector2.h"
#include <iostream>

void Warrior::onCollision(Entity *other)
{
    applyDamage(1);
    applyDamage(other->getHp()); 

}