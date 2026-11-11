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

    enum PlayerInput
    {
        UP = 0,
        DOWN,
        LEFT,
        RIGHT,
        ACTION,
        NONE
    };

    PlayerInput inputToDirection(char key);
    Vector2 directionToVector(PlayerInput input);

    void onUpdate() override;

protected:
    PlayerInput readInput();
    Vector2 moveFromInput(PlayerInput input);
};