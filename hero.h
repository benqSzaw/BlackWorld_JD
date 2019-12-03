#ifndef HERO_H
#define HERO_H

#include <iostream>
using namespace std;


class Hero
{
public:
    string name;

    int hp;
    int maxHp;

    int stamina;
    int maxStamina;

    int food;
    int gold;

    int strenght;
    int vitality;
    int agility;

    Hero();
    Hero(string name, int strenge, int agility, int vitality );

};

#endif // HERO_H
