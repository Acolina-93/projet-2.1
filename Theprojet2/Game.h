#pragma once
#include "Map.h"
<<<<<<< HEAD
#include "Enemy.h"
#include <vector>
=======
#include "Player.h"
#include <vector>

class Enemy;
>>>>>>> 41774d1a53d0a60c3a99b422a6e1ae0041aebf61

class Game
{

public:
    const std::vector<Enemy *> &getEnemies() const
    {
        return enemies;
    }
    static Game *getInstance();
    void run();
    const Map &getMap() const
    {
        return map;
    }
<<<<<<< HEAD
    const Player* GetPlayer() const
    {
        return player;
    }
   
   
=======
    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;

>>>>>>> 41774d1a53d0a60c3a99b422a6e1ae0041aebf61
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
    void enemiesTurn();
    void goToNextLevel();
    void endGame();
    void display();
    Game();

<<<<<<< HEAD
	void spawnEnemies();
    void clearEnemies();
    void updateEnemies();
    void resolveCollisions();

	static Game* instance; // l'unique exemplaire

	Player* player = nullptr;
    std::vector<Enemy *> enemies;

	~Game()
	{
        clearEnemies();
		delete player;
	}
=======
    Player *player = nullptr;

    ~Game()
    {
        clearEnemies();
        delete player;
    }
>>>>>>> 41774d1a53d0a60c3a99b422a6e1ae0041aebf61
};
