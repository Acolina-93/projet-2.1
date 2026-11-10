#pragma once
#include "Enemy.h"
#include "Vector2.h"

class ZombieSwimmer : public Enemy
{
public:
    ZombieSwimmer(Vector2 pos) : Enemy(hp, maxHp, pos, cell)
    {
    }

    bool canSwim() const override
    {
        return true;
    }

protected:
    Vector2 chooseDirection() override;

private:
    static constexpr int hp = 2;
    static constexpr int maxHp = 2;
    static constexpr char cell = 'S';
};
