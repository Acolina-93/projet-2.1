#include "Enemy.h"
#include "Game.h"
#include "Vector2.h"
#include <cstdlib>
#include <iostream>

void Enemy::onUpdate()
{
    move(chooseDirection(), Game::getInstance()->getMap());
}

void Enemy::onCollision(Entity *)
{
}

Vector2 Enemy::randomDirection()
{
    switch (std::rand() % 5)
    {
    case 0:
        return Vector2(0, -1);
    case 1:
        return Vector2(0, 1);
    case 2:
        return Vector2(-1, 0);
    case 3:
        return Vector2(1, 0);
    default:
        return Vector2(0, 0);
    }
}