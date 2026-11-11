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

void Game::clearEnemies()
{
    for (Enemy* enemy : enemies)
    {
        delete enemy;
    }
    enemies.clear();
}

void Game::spawnEnemies()
{
    clearEnemies();
    const std::vector<Vector2> &spawns = map.GetEnemySpawns();
    for (size_t i = 0; i < spawns.size(); ++i)
    {
        if (i % 2 == 0)
            enemies.push_back(new HeadlessZombie(spawns[i]));
        else
            enemies.push_back(new ZombieSwimmer(spawns[i]));
    }
}

void Game::updateEnemies()
{
    for (Enemy* enemy : enemies)
    {
        if (enemy->isAlive())
        {
            enemy->onUpdate();
        }
    }
}

void Game::resolveCollisions()
{
    if (player != nullptr && player->isAlive())
    {
        for (Enemy* enemy : enemies)
        {
            if (enemy->isAlive() && player->isAlive() &&
                enemy->getPosition() == player->getPosition())
            {
                player->onCollision(enemy);
                enemy->onCollision(player);
            }
        }
    }

    for (auto it = enemies.begin(); it != enemies.end();)
    {
        if (!(*it)->isAlive())
        {
            delete *it;
            it = enemies.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Game::run()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int currentLevel = 0;
    map.Load(currentLevel);
    spawnEnemies();

    player = new Warrior(map.GetPlayerStart());
    bool isRunning = true;

    display();

    while (isRunning)
    {
        if (player != nullptr && player->isAlive())
        {
            player->onUpdate();
            updateEnemies();
            resolveCollisions();
            display();


       
            if (player->isAlive() && map.IsExit(player->getPosition()))
            {
                ++currentLevel;
                if (currentLevel < Map::LEVEL_COUNT)
                {
                    map.Load(currentLevel);
                    spawnEnemies();
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
