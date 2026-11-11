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

<<<<<<< HEAD
void Game::clearEnemies()
{
    for (Enemy* enemy : enemies)
=======
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
>>>>>>> 41774d1a53d0a60c3a99b422a6e1ae0041aebf61
    {
        delete enemy;
    }
    enemies.clear();
}

<<<<<<< HEAD
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
=======
void Game::updateEnemies()
{
    for (Enemy *enemy : enemies)
>>>>>>> 41774d1a53d0a60c3a99b422a6e1ae0041aebf61
    {
        if (enemy->isAlive())
        {
            enemy->onUpdate();
        }
    }
}

<<<<<<< HEAD
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
=======
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
>>>>>>> 41774d1a53d0a60c3a99b422a6e1ae0041aebf61

void Game::run()
{
<<<<<<< HEAD
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int currentLevel = 0;
=======
    currentLevel = 0;
>>>>>>> a1fbc39b88dd73b56f69c2b143fb5e926302bae3
    map.Load(currentLevel);
    spawnEnemies();
<<<<<<< HEAD

=======
>>>>>>> 41774d1a53d0a60c3a99b422a6e1ae0041aebf61
    player = new Warrior(map.GetPlayerStart());
    isRunning = true;

    while (isRunning)
    {
<<<<<<< HEAD
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
=======
        display();
        player->onUpdate();
        checkCollisions();
        enemiesTurn();

        if (player != nullptr && !player->isAlive())
>>>>>>> 41774d1a53d0a60c3a99b422a6e1ae0041aebf61
        {
            endGame();
        }

        else if (map.IsExit(player->getPosition()))
        {
            goToNextLevel();
        }
    }
}
