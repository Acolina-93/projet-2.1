#include "Mage.h"
#include "Player.h"
#include "Vector2.h"
#include <conio.h> // Indispensable pour _kbhit() et _getch()
#include <iostream>

void Mage::onCollision(Entity *other)
{
    applyDamage(1); 
   
}