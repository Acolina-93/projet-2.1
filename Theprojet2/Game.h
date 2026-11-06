#pragma once
#include "Entity.h"
#include "Player.h"
#include "Vector2.h"

class Game
{

public:
	static Game* getInstance();
	void Run();

private:
	Game(); // privé

	static Game* instance; // l'unique exemplaire

	Player* player = nullptr;
	~Game()
	{
		delete player;
	}
};
