#pragma once
#include "Player.h"

class Mage : public Player
{

public:

	Mage(int hp, Vector2 pos) : Player(hp, pos) {}
	void Move(Vector2 dir) override;


};

