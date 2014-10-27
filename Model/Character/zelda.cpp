#include "zelda.h"


Zelda::Zelda()
{
    life = 10;
    dmg = 0;
    nbreArrows = 0;
    name = "Zelda";
}

Zelda::GetArrows()
{
    return nbreArrows;
}

Zelda::TakeItem(Ressource &item)
{
    // A implementer suivant les items créer
}

