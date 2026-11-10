#include "Entity.h"
#include "Map.h"
#include "Vector2.h"
#include <iostream>

int Entity::getHp() const
{
    return hp;
}

int Entity::getmaxHp() const
{
    return maxHp;
}

void Entity::move(const Vector2 &dir, const Map &map)
{

    Vector2 newPos = position + dir;

    if (map.CanEnter(newPos, canSwim()))
    {
        position = newPos;
    }
    
  
    
}
Vector2 Entity::getPosition() const
{
    return position;
}

void Entity::applyDamage(int damage)
{
    hp -= damage;
    if (hp < 0)
    {
        hp = 0;
    }
}

bool Entity::isAlive() const
{
    return hp > 0;
}
