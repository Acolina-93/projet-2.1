#pragma once
#include "Entity.h"

class Player : public Entity
{
private:

public:

	int hp = 0;
	int x = 0;
	int y = 0;

	Player(int hp, int x, int y);
	int GetHP() const override;
	int Maxhp() const override;
	void deplacement() override;


};

