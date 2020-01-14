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

public:
    Game();
    void start();
    void save();
    void load();
    void run();
    void quit();
    void settings();
    void changeScreenResolution(int choosenResolution);
    void changeFontScale(int choosenFontScale);
    Hero* heroSetup();
    QList<Event> readEvents();


};

#endif // GAME_H
