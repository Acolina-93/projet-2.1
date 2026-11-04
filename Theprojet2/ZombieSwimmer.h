#pragma once
#include "Enemy.h"

class ZombieSwimmer : public Enemy
{
public:

	ZombieSwimmer(int hp, Vector2 pos) : Enemy(hp, pos) {}
	void Move(Vector2 dir) override;
};

