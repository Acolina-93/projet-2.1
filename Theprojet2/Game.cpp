#include "Game.h"
#include "HeadlessZombie.h"
#include "Mage.h"
#include "Player.h"
#include "Warrior.h"
#include "WarriorMage.h"
#include "ZombieSwimmer.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

char Game::GetSymbolAt(Vector2 pos) const
{
    if (player != nullptr && player->isAlive() && player->getPosition() == pos)
    {
        return player->GetCell();
    }
    for (const Enemy *enemy : enemies)
    {
        if (enemy->isAlive() && enemy->getPosition() == pos)
        {
            return enemy->GetCell();
        }
    }
    return map.GetTileChar(pos);
}
Game::Game()
{
    srand(static_cast<unsigned int>(time(nullptr)));
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

void Game::goToNextLevel()
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

void Game::endGame()
{
    display();
    system("cls");
    std::cout << "\nGAME OVER !\n";
    isRunning = false;
}

void Game::run()
{
    int currentLevel = 0;
    map.Load(currentLevel);

    player = new Warrior(map.GetPlayerStart());
    isRunning = true;

    while (isRunning)
    {
        display();
        player->onUpdate();

        if (player != nullptr && !player->isAlive())
        {
            endGame();
        }

        else if (map.IsExit(player->getPosition()))
        {
            goToNextLevel();
        }
    }
}
