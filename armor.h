#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"

class Armor : Item
{
public:
    Armor();

    int defence;
    int durability;
};

#endif // ARMOR_H
