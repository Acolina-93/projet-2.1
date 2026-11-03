#include "Entity.h"
#include <iostream>

#include "Vector2.h"

int Entity::GetHP() const
{
	return hp;
}

int Entity::Maxhp() const
{
	return maxHp;
}

void Entity::Move(Vector2 dir)
{
	position = position + dir;
}


Vector2 Entity::GetPosition() const
{
	return position;
}

void Entity::applyDamage(int damage)
{
	hp -= damage;
	if (hp < 0) {
		hp = 0;
	}
}

bool Entity::isAlive() const
{
	return hp > 0;
}

