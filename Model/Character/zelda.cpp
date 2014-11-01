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
    speed=1;
    this->setAnimation();
}

Zelda::Zelda(QString picturePath):Personnage(picturePath, "zelda")
{
    life = 10;
    speed=2;
    dmg = 0;
    nbreArrows = 0;
    this->setAnimation();
}

int Zelda::getArrows()
{
    return nbreArrows;
}

void Zelda::setAnimation()
{
    // Récupérer dans une QList les différentes sprites
    QString path = QCoreApplication::applicationDirPath()+"/Ressources/sprites/";;
    QString path_face = path + "zelda_face.png";
    QString path_back = path + "zelda_back.png";
    QString path_right = path + "zelda_right.png";
    QString path_left = path + "zelda_left.png";

    listAnimation.append(QPixmap(path_face));
    listAnimation.append(QPixmap(path_back));
    listAnimation.append(QPixmap(path_right));
    listAnimation.append(QPixmap(path_left));
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

QString Zelda::getDir() const
{
    return dir;
}

void Zelda::setDir(const QString &value)
{
    dir = value;
}
QList<QPixmap> Zelda::getListAnimation() const
{
    return listAnimation;
}

