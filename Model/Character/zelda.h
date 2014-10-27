#ifndef ZELDA_H
#define ZELDA_H

#include "personnage.h"

class Zelda : public Personnage
{
public:
    Zelda();

    int GetArrows();
    void TakeItem(Ressource &item); // Prend une vie, arme,...

private:
    int nbreArrows;
    string name;
};

#endif // ZELDA_H
