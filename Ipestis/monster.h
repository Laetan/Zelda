#ifndef MONSTER_H
#define MONSTER_H

#include "personnage.h"

class Monster : public Personnage
{
public:
    Monster();
    Monster(int life, int dmg);
};

#endif // MONSTER_H
