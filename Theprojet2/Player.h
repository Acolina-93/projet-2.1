#pragma once
#include "Entity.h"
#include "Vector2.h"
#include "Map.h"


class Player : public Entity    
{

public:

    Player(int hp, int maxHp, Vector2 pos, char cell) : Entity(hp, maxHp, pos, cell)
    {
    }
    
    enum Direction
    {
        UP = 0,
        DOWN,
        LEFT,
        RIGHT,
        NONE
    };

    void Move(Player &player, Vector2 &dir, Map &map, Enemy &enemy);

    Direction InputToDirection(int key);
    void ApplyDirection(Direction direction, Vector2 &pos);

    virtual void onUpdate();
};
