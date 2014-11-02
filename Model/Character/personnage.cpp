#include <QApplication>
#include <QKeyEvent>
#include <QString>

#include "personnage.h"

// Constructor
Personnage::Personnage()
{
    Element();
}

Personnage::Personnage(QString picturePath, QString n):Element(picturePath,n){}



// Getter & Setter
int Personnage::getLife() const
{
    return life;
}

void Personnage::setLife(int value)
{
    life = value;
}
