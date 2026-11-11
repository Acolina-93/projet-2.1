#include "Mage.h"
#include "Enemy.h"
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

            bool aGauche = (ePos.x == position.x - 1 && ePos.y == position.y);
            bool aDroite = (ePos.x == position.x + 1 && ePos.y == position.y);
            bool enHaut = (ePos.x == position.x && ePos.y == position.y - 1);
            bool enBas = (ePos.x == position.x && ePos.y == position.y + 1);

            if (aGauche || aDroite || enHaut || enBas)
            {
                enemy->applyDamage(1);
            }
        }
    }
}
