#include <QApplication>
#include <QKeyEvent>
#include <QString>

#include "personnage.h"

// Constructor
Personnage::Personnage()
{
    Element();
}

Personnage::Personnage(QString picturePath):Element(picturePath){}

// Methods
bool Personnage::Alive(int life)
{
    if(life > 0)
        return true;
    else
        return false;
}

int Personnage::ReceiveDmg(int dmg)
{
    life -= dmg;

    if(life < 0)
        life =0;

    return life;
}

void Personnage::Attack(Personnage &target)
{
    int currentLife = target.ReceiveDmg(dmg);
    target.Alive(currentLife);
}

void Personnage::Speak()
{
    QString text = "blabla"; //Afficher sur l'écran
}


// Getter & Setter
int Personnage::getLife() const
{
    return life;
}

void Personnage::setLife(int value)
{
    life = value;
}
int Personnage::getDmg() const
{
    return dmg;
}

void Personnage::setDmg(int value)
{
    dmg = value;
}
int Personnage::getX() const
{
    return x;
}

void Personnage::setX(int value)
{
    x = value;
}
int Personnage::getY() const
{
    return y;
}

void Personnage::setY(int value)
{
    y = value;
}




