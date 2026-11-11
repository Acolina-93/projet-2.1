#include "Player.h"
#include "Game.h"
#include <conio.h>

Player::PlayerInput Player::inputToDirection(char key)
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
    case ' ':
        return ACTION;
    }
    return NONE;
}

Vector2 Player::directionToVector(PlayerInput input)
{

    switch (input)
    {

    case UP:
        return Vector2(0, -1);
    case DOWN:
        return Vector2(0, 1);
    case LEFT:
        return Vector2(-1, 0);
    case RIGHT:
        return Vector2(1, 0);
    case ACTION:
        return Vector2(0, 0);
    case NONE:
        return Vector2(0, 0);
    }
}

Player::PlayerInput Player::readInput()
{
    char key = _getch();
    return inputToDirection(key);
}

Vector2 Player::moveFromInput(PlayerInput input)
{
    Vector2 dir = directionToVector(input);
    move(dir, Game::getInstance()->getMap());
    return dir;
}
void Player::onUpdate()
{
    char key = _getch();
    readInput();
    moveFromInput(inputToDirection(key));
  
}