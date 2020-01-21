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
    //TODO: Create function for this
    cout <<
            " _   _   _   _+       |                                 " << endl <<
            "/_`-'_`-'_`-'_|  \\+/  |                       /-|      " << endl <<
            "\\_`M'_`D'_`C'_| _<=>_ |                     ___  \\    " << endl <<
            "  `-' `-' `-' 0/ \\ / o=o     ______________|  /|--]    " << endl <<
            "              \\/\\ ^ /`0                    | / |__|   " << endl <<
            "              | /_^_\\                       \\ /.\\ |  " << endl <<
            "              | || ||                        '|| ||     " << endl <<
            "            __|_d|_|b__                      <_'<_'     " << endl;

    cout << endl << endl<< "Press any key to start...";
    _getch();
    system("cls");
    game.start();



}

