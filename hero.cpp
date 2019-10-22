#include "hero.h"

Hero::Hero(string name, int strenge, int agility, int vitality)
{
    this->name = name;
    this->strenght = strenge;
    this->agility = agility;
    this->vitality = vitality;

    this->maxHp = 100 + (vitality * 10);
    this->hp = this->maxHp;
    this->gold = 0;
    this->food = 100;
    this->maxStamina = 100 + (agility * 10);
    this->stamina = this->maxStamina;

}
