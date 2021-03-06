#include "zelda.h"
#include <QString>
#include <QtDebug>
#include <QPixmap>

Zelda::Zelda()
{
    Personnage();
    life = 10;
    dmg = 0;
    nbreArrows = 0;
    name = "Zelda";

    // Récupérer dans une QList les différentes sprites
//    QString path ="C:\Qt\Tools\QtCreator\bin\build-Animation-Desktop_Qt_5_3_MinGW_32bit-Debug";
//    listAnimation =
}

Zelda::Zelda(QString picturePath):Personnage(picturePath,"zelda")
{
    life = 10;
    dmg = 0;
    nbreArrows = 0;
    this->speed = 1;
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
QString Zelda::getDir() const
{
    return dir;
}

void Zelda::setDir(const QString &value)
{
    dir = value;
}

void Zelda::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<event->key();
    switch(event->key())
    {
    case Qt::Key_Z:
        dir = "z";
        break;
    case Qt::Key_Q:
        dir = "q";
        break;
    case Qt::Key_S:
        dir = "s";
        break;
    case Qt::Key_D:
        dir ="d";
        break;
    default:
        break;
    }

    // Appeler une fonction move
}
