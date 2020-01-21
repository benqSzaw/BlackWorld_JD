/*
 ***********************************
 *                                 *
 * @Authors:                       *
 *  Beniamin Szawracki             *
 *  Maciej Szymkiewicz             *
 *  Natan Świątkowski              *
 *                                 *
 *                                 *
 *                                 *
 *                                 *
 *                                 *
 ***********************************
*/

#include <QCoreApplication>
#include "game.h"
#include "hero.h"

int main()
{
    Game game;
    game.startLogo();
    game.start();
}

