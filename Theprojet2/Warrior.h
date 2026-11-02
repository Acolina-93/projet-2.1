#pragma once
#include "Player.h"

class Warrior : public Player
{
public:

	Warrior(int hp, Vector2 pos) : Player(hp, pos) {}
	void Move(Vector2 dir) override;

	
};

