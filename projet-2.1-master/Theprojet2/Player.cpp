#include "Player.h"

Player::Player(int hp, int x, int y) : hp(hp), x(x), y(y) {}

int Player::GetHP() const
{
	return hp;
}

int Player::Maxhp() const
{
	return 100; // Assuming maximum HP is 100
}

void Player::deplacement()
{
	// Implementation for player movement
}