#pragma once
#include "Vector2.h"

class Entity
{

protected:
	int hp = 0;
	int maxHp = 0;
	char cell = 'E';
	Vector2 position;

public:
	int GetHP() const;
	int Maxhp() const;
	virtual void Move(Vector2 dir);
	Vector2 GetPosition() const;
	void applyDamage(int damage);
	bool isAlive() const;
	virtual void onUpdate() = 0;
	virtual void onCollision(Entity* other) = 0;

	Entity(int hp, int maxHp, Vector2 pos, char cell)
		: hp(hp), maxHp(maxHp), position(pos), cell(cell)
	{
	}
	virtual ~Entity() = default;
};
