#pragma once
#include "Player.h"

class Mage : public Player
{

public:

	Mage(int hp, Vector2 pos) : Player(hp, pos) {}
	int GetHP() const override;
	int Maxhp() const override;
	void Move(Vector2 dir) override;


};

