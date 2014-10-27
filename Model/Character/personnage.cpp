#include "personnage.h"


Personnage::Personnage()
{
}

bool Personnage::Alive(int life)
{
    if(life > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Personnage::ReceiveDmg(int dmg)
{
    life -= dmg;

    if(life < 0)
    {
        life =0;
    }
    return life;
}

void Personnage::Attack(Personnage &target)
{
    int currentLife = target.ReceiveDmg(dmg);
    target.Alive(currentLife);
}

void Personnage::Speak()
{
    string text = "blabla"; //Afficher sur l'écran
}
