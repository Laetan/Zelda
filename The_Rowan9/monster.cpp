#include "monster.h"
#include "element.h"

#include <QString>
#include <QPixmap>

Monster::Monster():Element("", "monstre")
{
    life = 5;
    dmg = 2;
}

Monster::Monster(QString picturePath):Element(picturePath, "monstre")
{
    life = 5;
    dmg = 2;
    this->setAnimation();
}

void Monster::setAnimation()
{
    // Récupérer dans une QList les différentes sprites
    QString path = "C:\\Users\\faudi_000\\Desktop\\Qt\\build-TP_Zelda-Desktop_Qt_5_3_MinGW_32bit-Debug\\debug\\Ressource\\Sprites";
    QString path_face = path + "\\monster_face.png";
//    QString path_back = path + "\\zelda_back.png";
//    QString path_right = path + "\\zelda_right.png";
//    QString path_left = path + "\\zelda_left.png";

    listAnimation.append(QPixmap(path_face));
//    listAnimation.append(QPixmap(path_back));
//    listAnimation.append(QPixmap(path_right));
//    listAnimation.append(QPixmap(path_left));
}

QList<QPixmap> Monster::getListAnimation() const
{
     return listAnimation;
}

