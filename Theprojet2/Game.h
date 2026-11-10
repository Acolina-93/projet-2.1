#pragma once
#include "Entity.h"
#include "Map.h"
#include "Player.h"
#include "Vector2.h"
#include <vector>

class Enemy;

class Game
{

public:
    static Game *getInstance();
    void run();
    const Map &GetMap() const
    {
        return map;
    }
    Game(const Game &) = delete; 
    Game &operator=(const Game &) = delete;

private:
    Map map;
    int currentLevel = 0;
    bool isRunning = false;
    std::vector<Enemy *> enemies;
    char GetSymbolAt(Vector2 pos) const;
    void goToNextLevel();
    void endGame(); 
    void display();
    Game(); // privé



    Player *player = nullptr;

    ~Game()
    {
        delete player;
    }
};
