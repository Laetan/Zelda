#ifndef MONSTER_H
#define MONSTER_H

#include "element.h"
#include <QPixmap>

class Monster : public Element
{
    public:
        Monster();
        Monster(QString);

        void setDeath();

        //Getter & Setter
        void setAnimation();
        QList<QPixmap> getListAnimation() const;

    // Fonction move à rédéfinir
    // nbre de pas random + dir random (z, q, s, d)

    protected:
        int life;
        int dmg;
        QList<QPixmap> listAnimation;

};

#endif // MONSTER_H
