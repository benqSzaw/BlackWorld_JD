#ifndef GAME_H
#define GAME_H

#include "hero.h"
#include "event.h"

#include <windows.h>
#include <stdlib.h>

#include <QTextStream>
#include <QFile>
#include <QList>
#include <QString>
#include <QFile>

#include <fstream>
#include <iostream>
#include <fstream>

#include <cstdio>

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
    void options();
    Hero* heroSetup();
    QList<Event> readEvents();
    void showEvent(Event event);

};

#endif // GAME_H
