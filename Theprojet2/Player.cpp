#include "Player.h"
#include <conio.h> 
#include <iostream>
#include "Vector2.h"



Player::Direction Player::InputToDirection(int key) {
	switch (key) {
	case 'z':
	case 'Z':
		return UP;
	case 's':
	case 'S':
		return DOWN;
	case 'q':
	case 'Q':
		return LEFT;
	case 'd':
	case 'D':
		return RIGHT;
	}
	return NONE;
}

void Player::ApplyDirection(Direction direction, Vector2& pos) {
	switch (direction) {
	case UP:
		pos.y--;
		break;
	case DOWN:
		pos.y++;
		break;
	case LEFT:
		pos.x--;
		break;
	case RIGHT:
		pos.x++;
		break;
	case NONE:
		break;
	}
}