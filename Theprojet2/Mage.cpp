#include "Mage.h"
#include "Player.h"
#include "Vector2.h"
#include <conio.h> // Indispensable pour _kbhit() et _getch()
#include <iostream>

void Mage::onCollision(Entity *other)
{
    // Implement Mage-specific collision logic here
    // If the Mage collides with an enemy, he lost 1 hp
}