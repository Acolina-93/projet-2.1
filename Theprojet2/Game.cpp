#include "Game.h"
#include "Mage.h"
#include "Player.h"
#include "Warrior.h"
#include <iostream>

Game *Game::instance = nullptr;

Game::Game()
{
    // Initialize game state here
    player = new Warrior(3, 3, Vector2(0, 0), 'W');
}

Game *Game::getInstance()
{

    if (instance == nullptr)
    {
        instance = new Game();
    }
    return instance;
}

void Game::Run()
{

    // Récupérer où placer le joueur
    Vector2 start = map.GetPlayerStart();

    bool isRunning = true;

    // Boucle principale du jeu
    while (isRunning)
    {
        // system("cls");
    }

    // Main game loop

    // Display map , handle input, update entities, check collisions, etc.

    // entities.onupdate();

    // gameover();
}
