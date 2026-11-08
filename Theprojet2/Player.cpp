#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include "Entity.h"
#include "Vector2.h"
#include <conio.h>
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

void Player::ApplyDirection(Direction direction)
{

    // Update the position based on the direction

    switch (direction)
    {

    case UP:
        position.y--;
        break;
    case DOWN:
        position.y++;
        break;
    case LEFT:
        position.x--;
        break;
    case RIGHT:
        position.x++;
        break;
    case NONE:
        break;
    }
}
/*
void Player::Move(Player &player, Vector2 &dir, Map &map, Enemy &enemy)
{
   // Vector2 dir = Direction InputToDirection(int key);
    Vector2 newPos = player.position;
    newPos.x += dir.x; // override + operator for less code
    newPos.y += dir.y;

    // Borders check
    if (newPos.x < 0 || newPos.x >= map.WIDTH || newPos.y < 0 || newPos.y >= map.HEIGHT)
       

    /* int mapIndex = get1DCell(newPos, map.WIDTH);
    int cellType = map.cells[mapIndex];

    if (!g_cellInfos[cellType].isWalkable)
        return false;

    if (characterMoveCollision(character, newPos, characters))
        return false;

    player.position = newPos;

}*/

void Player::onUpdate()
{

    char key = _getch(); // Utilisation de _getch() pour capturer la touche pressée
    Direction direction = InputToDirection(key);

    ApplyDirection(direction); // call after verify collision
}