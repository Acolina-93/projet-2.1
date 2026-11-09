#pragma once
#include "Player.h"

class Mage : virtual public Player
{

public:
	Mage(Vector2 pos) : Player(hp, maxHp, pos, cell)
	{
	}


	void onCollision(Entity* other) override;

protected:
    int hp = 1;
    int maxHp = 1;
    char cell = 'M';


};
