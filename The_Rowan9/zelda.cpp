#include "zelda.h"
#include <QString>
#include <QtDebug>
#include <QPixmap>

// Constructors
Zelda::Zelda()
{
    Personnage();
    life = 10;
    dmg = 0;
    this->setAnimation();
}

Zelda::Zelda(QString picturePath):Personnage(picturePath, "zelda")
{
    life = 10;
    dmg = 0;
    this->setAnimation();
    this->setDeath();
}

void Zelda::death()
{
    //Voir basicScene PressEvent
}

// Methods
void Zelda::setAnimation()
{
    // Récupérer dans une QList les différentes sprites
    QString path = "C:\\Users\\faudi_000\\Desktop\\Qt\\build-TP_Zelda-Desktop_Qt_5_3_MinGW_32bit-Debug\\debug\\Ressource\\Sprites";
    QString path_face = path + "\\zelda_face.png";
    QString path_back = path + "\\zelda_back.png";
    QString path_right = path + "\\zelda_right.png";
    QString path_left = path + "\\zelda_left.png";

    listAnimation.append(QPixmap(path_face));
    listAnimation.append(QPixmap(path_back));
    listAnimation.append(QPixmap(path_right));
    listAnimation.append(QPixmap(path_left));
}

void Zelda::setDeath()
{
    // Récupérer dans une QList les différentes sprites
    QString path = "C:\\Users\\faudi_000\\Desktop\\Qt\\build-TP_Zelda-Desktop_Qt_5_3_MinGW_32bit-Debug\\debug\\Ressource\\Sprites";
    QString path_face = path + "\\zelda_death_face.png";
    QString path_back = path + "\\zelda_death_back.png";
    QString path_right = path + "\\zelda_death_right.png";
    QString path_left = path + "\\zelda_death_left.png";

    listDeath.append(QPixmap(path_face));
    listDeath.append(QPixmap(path_back));
    listDeath.append(QPixmap(path_right));
    listDeath.append(QPixmap(path_left));
}


// Getter & Setter
QList<QPixmap> Zelda::getListAnimation() const
{
    return listAnimation;
}
QList<QPixmap> Zelda::getListDeath() const
{
    return listDeath;
}


