#include "Game.h"
#include "Mage.h"
#include "Player.h"
#include "Warrior.h"
#include <iostream>
#include <windows.h>


Game *Game::instance = nullptr;

char Game::GetSymbolAt(Vector2 pos) const
{
    if (player != nullptr && player->isAlive() && player->getPosition() == pos)
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
    static Game instance;
    return &instance;
}

void Game::display()
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

void Game::run()
{

    int currentLevel = 0;
    map.Load(currentLevel);

    // Joueur créé une seule fois avec le point de départ de la carte
    player = new Warrior(100, 100, map.GetPlayerStart(), 'W');
    bool isRunning = true;

    display();
    // Boucle principale du jeu
    while (isRunning)
    {
       

        if (player != nullptr && player->isAlive())
        {
            player->onUpdate(); // Attend la touche et déplace le joueur
            display();
        }
        // TODO (Binôme) : Mettre à jour la liste des ennemis ici

        else if (player != nullptr && !player->isAlive())
        {
            display();
            std::cout << "\nGAME OVER !\n";
            isRunning = false;
        }
        else if (player != nullptr && map.IsExit(player->getPosition()))
        {
            ++currentLevel;
            if (currentLevel < Map::LEVEL_COUNT)
            {
                map.Load(currentLevel);
                player->SetPosition(map.GetPlayerStart());
            }
            else
            {
                display();
                std::cout << "\nVICTOIRE !\n";
                isRunning = false;
            }
        }
    }

}
