#include "Player.h"
#include "Enemy.h"
#include "Game.h"
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

   if (_kbhit()) // Vérifie si une touche a été pressée sans bloquer le jeu
    {
        char key = _getch();
        Direction direction = InputToDirection(key);
        Vector2 dir = DirectionToVector(direction);
        Move(dir, Game::getInstance()->GetMap());
    }
    
}