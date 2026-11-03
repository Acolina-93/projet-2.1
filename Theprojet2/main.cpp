// Theprojet2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Warrior.h"
#include "Mage.h"
#include "Game.h"

int main()
{

    Game* game = Game::getInstance();
  
    game->Run();

	// delete game;
    // on oublie pas de delete dans le destructeur
    return 0;
}

