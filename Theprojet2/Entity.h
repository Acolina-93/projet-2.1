#pragma once
#include "Vector2.h"
#include "Map.h"

class Entity
{

protected:
	int hp = 0;
	int maxHp = 0;
	char cell = 'E';
	Vector2 position;

public:
    Entity(int hp, int maxHp, Vector2 pos, char cell)
        : hp(hp), maxHp(maxHp), position(pos), cell(cell)
    {
    }
	int GetHP() const;
	int Maxhp() const;
    virtual void Move(Player &player, Vector2 &dir, Map &map, Enemy &enemy) = 0;
	Vector2 GetPosition() const;
	void applyDamage(int damage);
	bool isAlive() const;
	virtual void onUpdate() = 0;
	virtual void onCollision(Entity* other) = 0;

	
	virtual ~Entity() = default;
};
