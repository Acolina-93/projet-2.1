#include "Player.h"
#include <conio.h> 
#include <iostream>
#include "Vector2.h"

void Player::move(Vector2 dir) {

	// Update the player's position based on the direction
	// Implementation for moving the player

		
	position = position + dir; // ou Move(dir) hérité d'Entity
	
};

Player::Direction Player::InputToDirection(int key) {

	// Map the input key to a direction

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

	// Update the position based on the direction

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

