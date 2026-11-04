#pragma once
#include "Enemy.h"

class HeadlessZombie : public Enemy
{
public:

	HeadlessZombie(int hp, Vector2 pos) : Enemy(hp, pos) {}
	void Move(Vector2 dir) override;
};

