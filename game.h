#ifndef GAME_H
#define GAME_H

#include "hero.h"
#include "event.h"

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

public:
    Game();
    void start();
    void exit();
    void save(Hero *saveHero);
    void load();
    void run();
    Hero* heroSetup();
    QList<Event> readEvents();

};

#endif // GAME_H
