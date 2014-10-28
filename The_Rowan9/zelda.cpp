#include "zelda.h"


Zelda::Zelda()
{
    life = 10;
    dmg = 0;
    nbreArrows = 0;
    name = "Zelda";
}

void Zelda::GetArrows()
{
    return nbreArrows;
}

Zelda::TakeItem(Ressource &item)
{
    // A implementer suivant les items créer
}


// Getter & Setter
int Zelda::getNbreArrows() const
{
    return nbreArrows;
}

void Zelda::setNbreArrows(int value)
{
    nbreArrows = value;
}
string Zelda::getName() const
{
    return name;
}

void Zelda::setName(const string &value)
{
    name = value;
}

void Zelda::mousePressEvent(QMouseEvent *event)
{
    // Appeler une fonction shoot
}

void Zelda::keyPressEvent(QKeyEvent *event)
{
    // Appeler une fonction move
    // Move : QTimer puis signal puis effectue le move
    // connect(QTimer object, SIGNAL(timeout()), this, SLOT(moveby(parameter)));
}

void Zelda::move(char dir)
{
    if(dir == "z")
    {
        this->moveby(0,-1);
    }

   // A faire pour les autres
}

void Zelda::startMove(char dir)
{
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(move(dir)));
}

