#pragma once
#include "Player.h"

class Warrior : public Player
{



public:


	Warrior(int hp, int maxHp, Vector2 pos, char cell) : Player(hp, maxHp, pos, cell) {}
	void onUpdate() override {
		// Implement Warrior-specific update logic here
	}
	void onCollision(Entity* other) override {
		// Implement Warrior-specific collision logic here
	}
};

