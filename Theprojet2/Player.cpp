#include "Player.h"
#include "Game.h"
#include <conio.h>

Player::Direction Player::inputToDirection(char key)
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

Vector2 Player::directionToVector(Direction direction)
{

    switch (direction)
    {

    case UP:
        return Vector2(0, -1);
    case DOWN:
        return Vector2(0, 1);
    case LEFT:
        return Vector2(-1, 0);
    case RIGHT:
        return Vector2(1, 0);
    case NONE:
        return Vector2(0, 0);
    }
}

void Player::onUpdate()
{
    char key = _getch();
    Direction direction = inputToDirection(key);
    Vector2 dir = directionToVector(direction);
    move(dir, Game::getInstance()->getMap());
}