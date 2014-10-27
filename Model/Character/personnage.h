#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Model/element.h"

class Personnage : public Element  // Classe abstraite
{
public:
    Personnage()=0; // Fonction virtuelle pure
    ~Personnage();

    virtual void move();
    bool alive();
    int receiveDmg(int dmg);
    virtual void die();
    void attack();

protected:
    int life;
    int dmg;
};

#endif // PERSONNAGE_H
