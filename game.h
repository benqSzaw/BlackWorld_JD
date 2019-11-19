#ifndef GAME_H
#define GAME_H

#include "hero.h"
#include "event.h"

#include <QTextStream>
#include <QFile>
#include <QList>
#include <stdlib.h>
#include <iostream>

#include <string>
using namespace std;


class Game
{
private:
    bool isStarted;
    int currentEventId;

    void showEvent(Event event);

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
