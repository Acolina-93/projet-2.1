#pragma once
#include "Player.h"

class Mage : public Player
{


public:

	Mage(int hp, int maxHp, Vector2 pos, char cell) : Player(hp, maxHp, pos, cell) {}

	void onUpdate() override;
	void onCollision(Entity* other) override {
		// Implement Mage-specific collision logic here
	}
};

