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

char Game::getSymbolAt(Vector2 pos) const
{
    if (player != nullptr && player->isAlive() && player->getPosition() == pos)
    {
        return player->getCell();
    }
    for (const Enemy *enemy : enemies)
    {
        if (enemy->isAlive() && enemy->getPosition() == pos)
        {
            return enemy->getCell();
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
            std::cout << getSymbolAt(Vector2(x, y));
        }
        std::cout << '\n';
    }
}

void Game::spawnEnemies()
{
    for (const Vector2 &spawnPos : map.GetEnemySpawns())
    {
        int enemyType = std::rand() % 3;
        Enemy *enemy = nullptr;
        switch (enemyType)
        {
        case 0:
            enemy = new HeadlessZombie(2, 2, spawnPos, 'H');
            break;
        case 1:
            enemy = new ZombieSwimmer(spawnPos);
            break;
        case 2:
            enemy = new HeadlessZombie(3, 3, spawnPos, 'Z');
            break;
        }
        if (enemy != nullptr)
        {
            enemies.push_back(enemy);
        }
    }
}

void Game::clearEnemies()
{
    for (Enemy *enemy : enemies)
    {
        delete enemy;
    }
    enemies.clear();
}

void Game::updateEnemies()
{
    for (Enemy *enemy : enemies)
    {
        if (enemy->isAlive())
        {
            enemy->onUpdate();
        }
    }
}

void Game::checkCollisions()
{
    for (Enemy *enemy : enemies)
    {
        if (enemy->isAlive() && player->isAlive() &&
            enemy->getPosition() == player->getPosition())
        {
            player->onCollision(enemy);
            enemy->onCollision(player);
        }
    }
}

void Game::enemiesTurn()
{
    updateEnemies();
    checkCollisions();
}

void Game::goToNextLevel()
{
    ++currentLevel;
    if (currentLevel < Map::LEVEL_COUNT)
    {
        map.Load(currentLevel);
        clearEnemies();
        spawnEnemies();
        player->setPosition(map.GetPlayerStart());
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
   
    std::cout << "\nGAME OVER !\n";
    isRunning = false;
}

void Game::run()
{
    currentLevel = 0;
    map.Load(currentLevel);
    spawnEnemies();
    player = new Warrior(map.GetPlayerStart());
    isRunning = true;

    while (isRunning)
    {
        display();
        player->onUpdate();
        checkCollisions();
        enemiesTurn();

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
