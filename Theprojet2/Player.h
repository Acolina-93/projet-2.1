#pragma once
#include "Entity.h"
#include "Map.h"
#include "Vector2.h"

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

    Direction inputToDirection(char key);
    Vector2 directionToVector(Direction direction);

    void onUpdate() override;
};
