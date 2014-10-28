#include "zelda.h"
#include <QString>


Zelda::Zelda()
{
    life = 10;
    dmg = 0;
    nbreArrows = 0;
    name = "Zelda";
}

int Zelda::getArrows()
{
    return nbreArrows;
}

//void Zelda::takeItem(Ressource &item)
//{
//    // A implementer suivant les items créer
//}


// Getter & Setter
int Zelda::getNbreArrows() const
{
    return nbreArrows;
}

void Zelda::setNbreArrows(int value)
{
    nbreArrows = value;
}
QString Zelda::getName() const
{
    return name;
}

void Zelda::setName(const QString &value)
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

//void Zelda::move(QString dir)
//{
//    if(dir == "z")
//        this->moveBy(0,-1);
//    else if(dir == "q")
//        this->moveBy(-1,0);
//    else if(dir == "s")
//        this->moveBy(0,1);
//    else if(dir == "d")
//        this->moveBy(1,0);
//    else
//        qDebug() <<"Bad key";
//}
