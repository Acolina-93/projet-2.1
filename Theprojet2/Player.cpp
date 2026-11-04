#include "Player.h"
#include "Vector2.h"
#include <conio.h>
#include <iostream>

Player::Direction Player::InputToDirection(int key)
{

    // Map the input key to a direction

    switch (key)
    {
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

void Player::ApplyDirection(Direction direction, Vector2 &pos)
{

    // Update the position based on the direction

    switch (direction)
    {

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

void Player::onUpdate()
{

    char key = _getch(); // Utilisation de _getch() pour capturer la touche pressée
    Direction direction = InputToDirection(key);

    ApplyDirection(direction, position); // call after verify collision
}