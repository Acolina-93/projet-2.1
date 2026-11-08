#pragma once
#include "Vector2.h"

class Player;
class Enemy;
class Map;

class Entity
{

protected:
    int hp = 0;
    int maxHp = 0;
    char cell = 'E';
    Vector2 position;

public:
    Entity(int hp, int maxHp, Vector2 pos, char cell)
        : hp(hp), maxHp(maxHp), position(pos), cell(cell)
    {
    }
    int GetHP() const;
    int Maxhp() const;
    void Move(const Vector2 &dir, const Map &map);
    Vector2 GetPosition() const;
    void applyDamage(int damage);
    bool isAlive() const;
    virtual void onUpdate() = 0;
    virtual void onCollision(Entity *other) = 0;

    virtual ~Entity() = default;
};
