#include "monster.h"

Monster::Monster()
{
    Element();
}

Monster::Monster(int life, int dmg)
{
    Element();
    this->life = life;
    this->dmg = dmg;
}

