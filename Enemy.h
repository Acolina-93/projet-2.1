#pragma once
#include "Entity.h"
#include "Vector2.h"

class Enemy : public Entity
{
protected :
	
	int hp = 0;
	Vector2 position;

public :
	
	Enemy(int hp, Vector2 pos) : hp(hp), position(pos) {}
	int Maxhp() const override;
	int GetHP() const override;
	void Move(Vector2 dir) override;
};