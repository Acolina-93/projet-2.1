#include "Player.h"
#include "Game.h"
#include <conio.h> // Indispensable pour _kbhit() et _getch()
#include <iostream>

Player::Direction Player::InputToDirection(char key)
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

Vector2 Player::DirectionToVector(Direction direction)
{

    // Update the position based on the direction

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
    return Vector2(0, 0);
}

void Player::onUpdate()
{
    char key = _getch();
    Direction direction = InputToDirection(key);
    Vector2 dir = DirectionToVector(direction);
    move(dir, Game::getInstance()->GetMap());
}