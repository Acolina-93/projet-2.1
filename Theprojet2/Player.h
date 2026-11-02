#pragma once
#include "Entity.h"
#include "Vector2.h"
class Player : public Entity
{

public:

	Player(int hp, Vector2 pos);
	int GetHP() const override;
	int Maxhp() const override;
	void Move(Vector2 dir) override;
	Vector2 GetPosition() const override;

};


