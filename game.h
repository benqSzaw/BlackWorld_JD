#ifndef GAME_H
#define GAME_H

#include "hero.h"
#include "event.h"

#include <QTextStream>
#include <QFile>
#include <QList>
#include <QString>
#include <QFile>

#include <fstream>
#include <iostream>
#include <fstream>

#include <cstdio>

#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

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
    int exitProgramm();
    void save();
    void load();
    void run();
    void bottomText();
    void options();
    Hero* heroSetup();
    QList<Event> readEvents();
    void showEvent(Event event);

};

#endif // GAME_H
