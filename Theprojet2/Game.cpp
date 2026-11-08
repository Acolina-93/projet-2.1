#include "Game.h"
#include "Mage.h"
#include "Player.h"
#include "Warrior.h"
#include <iostream>
#include <windows.h>


Game *Game::instance = nullptr;

char Game::GetSymbolAt(Vector2 pos) const
{
    if (player != nullptr && player->isAlive() && player->GetPosition() == pos)
    {
        return player->GetCell();
    }
    return map.GetTileChar(pos);
}
Game ::Game()
{
   

}
Game *Game::getInstance()
{

    if (instance == nullptr)
    {
        instance = new Game();
    }
    return instance;
}

void Game::Display()
{
    system("cls");
    for (int y = 0; y < Map::HEIGHT; ++y)
    {
        for (int x = 0; x < Map::WIDTH; ++x)
        {
            std::cout << GetSymbolAt(Vector2(x, y));
        }
        std::cout << '\n';
    }
}

void Game::Run()
{

    int currentLevel = 0;
    map.Load(currentLevel);

    // Joueur créé une seule fois avec le point de départ de la carte
    player = new Warrior(100, 100, map.GetPlayerStart(), 'W');
    bool isRunning = true;

    // Boucle principale du jeu
    while (isRunning)
    {
        Display();

        if (player != nullptr && player->isAlive())
        {
            player->onUpdate();
        }
        // TODO (Binôme) : Mettre à jour la liste des ennemis ici

        if (player != nullptr && !player->isAlive())
        {
            Display();
            std::cout << "\nGAME OVER !\n";
            isRunning = false;
        }
        else if (player != nullptr && map.IsExit(player->GetPosition()))
        {
            currentLevel++;
            if (currentLevel < Map::LEVEL_COUNT)
            {
                map.Load(currentLevel);
                player->SetPosition(map.GetPlayerStart());
            }
            else
            {
                Display();
                std::cout << "\nVICTOIRE !\n";
                isRunning = false;
            }
        }
    }

    // Main game loop

    // Display map , handle input, update entities, check collisions, etc.

    // entities.onupdate();

    // gameover();
}
