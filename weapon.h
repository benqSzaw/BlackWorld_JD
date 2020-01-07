#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

class Weapon : Item
{
public:
    Weapon();

    int damage;
    int durability;
    int critic_chance;
    int critic_damage;
};

#endif // WEAPON_H
