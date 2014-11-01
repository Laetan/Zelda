#ifndef MONSTER_H
#define MONSTER_H

#include "../../element.h"
#include <QPixmap>

class Monster : public Element
{
    public:
        Monster();
        Monster(QString,int,int);

        void setDeath();
        void update();
        void setAnimation();
        QList<QPixmap> getListAnimation() const;


    protected:
        int life;
        int dmg;
        int pas;
        QList<QPixmap> listAnimation;

        void move(bool = false);

};

#endif // MONSTER_H
