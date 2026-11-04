#pragma once
#include "Player.h"

class Mage : public Player
{

public:
	Mage(int hp, int maxHp, Vector2 pos, char cell) : Player(hp, maxHp, pos, cell)
	{
	}


	void onCollision(Entity* other) override;



};
