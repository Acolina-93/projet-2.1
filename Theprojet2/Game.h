#pragma once
#include "Entity.h"
#include "Player.h"
#include "Vector2.h"
#include "Map.h"
#include "Enemy.h"
#include <vector>

class Game
{

public:
	static Game* getInstance();
	void run();
    const Map &GetMap() const
    {
        return map;
    }
    const Player* GetPlayer() const
    {
        return player;
    }
   
   
private:
    Map map;
    char GetSymbolAt(Vector2 pos) const;
    void display();
	Game(); // privé

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
};
