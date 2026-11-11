#pragma once
#include "Enemy.h"

class HeadlessZombie : public Enemy
{
public:
    HeadlessZombie(Vector2 pos) : Enemy(hp, maxHp, pos, cell)
    {
    }

<<<<<<< HEAD
    protected:
    Vector2 chooseDirection() override;

    private:
    static constexpr int hp = 2;
    static constexpr int maxHp = 2;
    static constexpr char cell = 'Z';
=======
protected:
    Vector2 chooseDirection() override;
>>>>>>> 41774d1a53d0a60c3a99b422a6e1ae0041aebf61
};
