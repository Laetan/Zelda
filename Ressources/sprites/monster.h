#ifndef MONSTER_H
#define MONSTER_H

#include "personnage.h"
#include "objets.h"

#include <iostream>
#include <string>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QSound>
#include <cstdlib>
#include <ctime>

class Monster : public Personnage, QGraphicsPixmapItem
{
public:
    Monster(string);
    Monster(int life, int dmg);
	void drop();
	getPosX();
	getPosY();
};

#endif // MONSTER_H
