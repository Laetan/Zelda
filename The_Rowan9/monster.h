#ifndef MONSTER_H
#define MONSTER_H

#include "element.h"

class Monster : public Element
{
public:
    Monster();
    Monster(int life, int dmg);

    void move();

    // Fonction move à rédéfinir
    // nbre de pas random + dir random (z, q, s, d)
};

#endif // MONSTER_H
