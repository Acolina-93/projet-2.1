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

    Direction InputToDirection(char key);
    Vector2 DirectionToVector(Direction direction);

   void onUpdate() override;

    Player() = default;
};
