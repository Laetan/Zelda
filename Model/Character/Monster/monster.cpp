#include "monster.h"

#include <QString>

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

void Monster::move()
{
    int pas = 0, i=0;
    this->setDir() = "";
    QVector<QString> DiffDir = {"z", "q", "s", "d"};
    qsrand(0);

    pas = qrand()%100;
    i = qrand()%4;
    this->setDir(DiffDir(i));
}

