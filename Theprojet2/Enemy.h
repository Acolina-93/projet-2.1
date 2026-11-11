#pragma once
#include "Entity.h"


class Enemy : public Entity
{
public:
    Enemy(int hp, int maxHp, Vector2 pos, char cell) : Entity(hp, maxHp, pos, cell)
    {
    }

    void onUpdate() override;
    void onCollision(Entity *other) override;

protected:
    virtual Vector2 chooseDirection() = 0;

    static Vector2 randomDirection();
};
