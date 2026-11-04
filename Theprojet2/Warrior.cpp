#include "Warrior.h"
#include "Player.h"
#include "Vector2.h"
#include <conio.h> // Indispensable pour _kbhit() et _getch()
#include <iostream>

void Warrior::onCollision(Entity *other)
{
    // Implement Warrior-specific collision logic here
    // If the Warrior collides with an enemy, he lost 1 hp and the enemy lost 1 hp too
}