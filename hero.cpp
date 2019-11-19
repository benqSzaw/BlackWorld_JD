#include "hero.h"

Hero::Hero(string name, int strenge, int agility, int vitality)
{
    this->name = name;


    this->maxHp = 100 + (vitality * 10);
    this->hp = this->maxHp;

    this->maxStamina = 100 + (agility * 10);
<<<<<<< HEAD
    this->stamina = this->maxStamina;

=======
    this->stamina = this->maxStamina; //test
>>>>>>> 8ebca597328d86a32f94d6bb9051988b6d559365

    this->food = 100;
    this->gold = 0;

    this->strenght = strenge;
    this->vitality = vitality;
    this->agility = agility;
}
