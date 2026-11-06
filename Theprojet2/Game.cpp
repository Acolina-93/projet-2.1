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
    // Charger le niveau 0 (le premier)
    map.Load(0);

    // Récupérer où placer le joueur
    Vector2 start = map.GetPlayerStart();
    Player *player = new Warrior(100, start);

    // Créer un ennemi par point d'apparition
    for (const Vector2 &spawn : map.GetEnemySpawns())
    {
        entities.push_back(new Zombie(spawn));
    }

    // Tester un déplacement
    Vector2 newPos = playerPosi() + Vector2(1, 0);
    if (map.CanEnter(newPos))
    {
        // le déplacement est autorisé
    }

    // Un nageur peut entrer dans l'eau
    if (map.CanEnter(newPos, true))
    { /* ... */
    }

    // Sortie atteinte ?
    if (map.IsExit(player->GetPosition()))
    {
        map.Load(1); // niveau suivant
    }



    // Main game loop

    // Display map , handle input, update entities, check collisions, etc.

    // entities.onupdate();

    // gameover();
}
