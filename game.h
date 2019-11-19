#ifndef GAME_H
#define GAME_H

#include "hero.h"
#include "event.h"


#include <fstream>
#include <QTextStream>
#include <QFile>
#include <QList>
#include <stdlib.h>
#include <QString>

#include <iostream>
#include <fstream>

#include <string>
using namespace std;


class Game
{
private:
    bool isStarted;
<<<<<<< HEAD
    int currentEventId;

    void showEvent(Event event);
=======
    Hero* mainHero;
>>>>>>> 8ebca597328d86a32f94d6bb9051988b6d559365

public:
    Game();
    void start();
    void exit();
    void save();
    void load();
    void run();
    Hero* heroSetup();
    QList<Event> readEvents();


};

#endif // GAME_H
