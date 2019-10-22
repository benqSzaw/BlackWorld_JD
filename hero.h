#ifndef HERO_H
#define HERO_H

#include <iostream>
using namespace std;


class Hero
{
private:
    string name;

    int hp;
    int maxHp;

    int gold;

    int stamina;
    int maxStamina;

    int food;

    int strenght;
    int vitality;
    int agility;

public:
    Hero(string name, int strenge, int agility, int vitality );

};

#endif // HERO_H
