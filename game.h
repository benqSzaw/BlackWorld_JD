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
    int currentEventId;
    Hero* mainHero;


public:
    Game();
    void start();
    void exit();
    void save();
    void load();
    void run();
    Hero* heroSetup();
    QList<Event> readEvents();
    void showEvent(Event event);

};

#endif // GAME_H
