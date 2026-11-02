#pragma once
#include "Vector2.h"

class Entity
{

protected:

	int hp = 0;
	Vector2 position;

public:

	
	virtual int GetHP() const = 0;
	virtual int Maxhp() const = 0;
	virtual void Move(Vector2 dir) = 0;
	virtual Vector2 GetPosition() const = 0;

	virtual void onUpdate() = 0;
	virtual void onCollision(Entity* other) = 0;
	virtual void applyDamage(int damage) = 0;
	virtual bool isAlive() const = 0;

	virtual ~Entity() = default;

};

