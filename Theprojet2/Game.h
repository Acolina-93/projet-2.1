#pragma once
#include "Entity.h"
#include "Player.h"
#include "Vector2.h"
#include "Map.h"
#include <vector>

class Enemy;

class Game
{

public:
	static Game* getInstance();
	void run();
    const Map &GetMap() const
    {
        return map;
    }
   
   
private:
    Map map;
    std::vector<Enemy *> enemies;
    char GetSymbolAt(Vector2 pos) const;
    void display();
	Game(); // privé

	static Game* instance; // l'unique exemplaire

	Player* player = nullptr;

	~Game()
	{
		delete player;
	}
};
