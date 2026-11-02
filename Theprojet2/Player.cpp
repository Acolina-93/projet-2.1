#include "Player.h"
#include <iostream>
#include "Vector2.h"



int Player::GetHP() const
{
	return hp;
}

int Player::Maxhp() const
{
	return 100; // Assuming maximum HP is 100
}

void Player::Move(Vector2 dir)
{
	//Vector2 newPos = player.pos + dir;
	
}