#include "Entity.h"
#include "Map.h"
#include "Vector2.h"
#include <iostream>

int Entity::GetHP() const
{
    return hp;
}

int Entity::Maxhp() const
{
    return maxHp;
}

void Entity::Move(Vector2 &dir, const Map &map)
{

    Vector2 newPos = position + dir;
    map.IsInside(newPos);
    map.CanEnter(newPos, false);
    
    
}
Vector2 Entity::GetPosition() const
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
