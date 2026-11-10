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

void Mage::castSpell()
{
    for (Enemy *enemy : Game::getInstance()->getEnemies())
    {
        if (enemy != nullptr && enemy->isAlive())
        {
            Vector2 ePos = enemy->getPosition();
            int dx = std::abs(ePos.x - position.x);
            int dy = std::abs(ePos.y - position.y);

            // Vérifie si l'ennemi est sur l'une des 4 cases adjacentes (haut, bas,
            // gauche, droite)
            if (dx + dy == 1)
            {
                enemy->applyDamage(
                    enemy->getHp()); // Inflige tous ses PV restants pour le tuer
            }
        }
    }
}

 
