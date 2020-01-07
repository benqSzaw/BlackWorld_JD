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
    void executeEvent(QString cons);
    void changeHeroStats(QString attr , QString value);

public:
    Game();

    void start();
    void save();
    void load();
    void run();
    void showStats();
    void options();
    void exitProgramm();
    void bottomText();

    Hero* heroSetup();
    QList<Event> readEvents();
    void showEvent(Event event);
};

#endif // GAME_H
