#pragma once
#include "Map.h"
#include "Player.h"
#include <vector>

class Enemy;

class Game
{

public:
    static Game *getInstance();
    void run();
    const Map &getMap() const
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
    char getSymbolAt(Vector2 pos) const;
    void spawnEnemies();
    void clearEnemies();
    void updateEnemies();
    void checkCollisions();
    void removeDeadEnemies();
    void goToNextLevel();
    void endGame();
    void display();
    Game(); 

    Player *player = nullptr;

    ~Game()
    {
        clearEnemies();
        delete player;
    }
};
