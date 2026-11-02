#pragma once
#include "Entity.h"
#include "Vector2.h"
class Player : public Entity
{


public:

	int hp = 0;
	Vector2 position;

	Player(int hp, Vector2 pos) : hp(hp), position(pos) {}
	int GetHP() const override;
	int Maxhp() const override;
	void Move(Vector2 dir) override;


};

