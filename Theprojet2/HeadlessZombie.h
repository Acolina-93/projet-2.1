#pragma once
#include "Enemy.h"

class HeadlessZombie : public Enemy
{
public:
    HeadlessZombie(Vector2 pos) : Enemy(hp, maxHp, pos, cell)
    {
    }

    protected:
    Vector2 chooseDirection() override;

    private:
    static constexpr int hp = 2;
    static constexpr int maxHp = 2;
    static constexpr char cell = 'Z';
};
