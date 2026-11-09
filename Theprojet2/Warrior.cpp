#include "Warrior.h"
#include "Player.h"
#include "Vector2.h"
#include <iostream>

void Warrior::onCollision(Entity *other)
{
    applyDamage(1);
    applyDamage(other->getHp()); // Apply damage to the other entity as well
    // Implement Warrior-specific collision logic here
    // If the Warrior collides with an enemy, he lost 1 hp and the enemy lost 1 hp too
}