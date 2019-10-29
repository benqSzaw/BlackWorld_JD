#include "hero.h"

Hero::Hero(string name, int strenge, int agility, int vitality)
{
    this->name = name;


    this->maxHp = 100 + (vitality * 10);
    this->hp = this->maxHp;

    this->maxStamina = 100 + (agility * 10);
    this->stamina = this->maxStamina; //test

    this->food = 100;
    this->gold = 0;

    this->strenght = strenge;
    this->vitality = vitality;
    this->agility = agility;
}
