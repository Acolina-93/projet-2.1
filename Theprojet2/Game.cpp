#include "Game.h"
#include "Mage.h"
#include "Player.h"
#include "Warrior.h"
#include <iostream>
#include "HeadlessZombie.h"
#include "ZombieSwimmer.h"
#include <cstdlib>
#include <ctime>

Game *Game::instance = nullptr;

char Game::GetSymbolAt(Vector2 pos) const
{
    if (player != nullptr && player->isAlive() && player->getPosition() == pos)
    {
        return player->GetCell();
    }
    for (const Enemy* enemy : enemies)
    {
        if (enemy->isAlive() && enemy->getPosition() == pos)
        {
            return enemy->GetCell();
        }
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

    player = new Warrior(map.GetPlayerStart());
    bool isRunning = true;

    display();

    while (isRunning)
    {
        if (player != nullptr && player->isAlive())
        {
            player->onUpdate();
            display();

       
            if (map.IsExit(player->getPosition()))
            {
                ++currentLevel;
                if (currentLevel < Map::LEVEL_COUNT)
                {
                    map.Load(currentLevel);
                    player->SetPosition(map.GetPlayerStart());
                    display();
                }
                else
                {
                    display();
                    std::cout << "\nVICTOIRE !\n";
                    isRunning = false;
                }
            }
        }
        else if (player != nullptr && !player->isAlive())
        {
            display();
            std::cout << "\nGAME OVER !\n";
            isRunning = false;
        }
    }
}
