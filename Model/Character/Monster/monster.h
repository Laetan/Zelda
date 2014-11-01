#ifndef MONSTER_H
#define MONSTER_H

#include "Model/Character/personnage.h"
#include "Model/Item/Objets.h"

#include <QSound>

class Monster : public Personnage
{
public:
    Monster(QString);
    Monster(int life, int dmg);
    void drop();
};

#endif // MONSTER_H
