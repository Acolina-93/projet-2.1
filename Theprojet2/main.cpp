// Theprojet2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme
// commence et se termine à cet endroit.
//

#include "Game.h"

int main()
{

    Game *game = Game::getInstance();

    game->run();

    // delete game;
    // on oublie pas de delete dans le destructeur
    return 0;
}
