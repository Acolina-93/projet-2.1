#pragma once
#include "Entity.h"
#include "Player.h"
#include "Vector2.h"
#include "Map.h"
#include "ZombieSwimmer.h"
class Game
{

public:
	static Game* getInstance();
	void Run();
   
private:
    Map map;
	Game(); // privé

	static Game* instance; // l'unique exemplaire

	Player* player = nullptr;

	~Game()
	{
		delete player;
	}
};
