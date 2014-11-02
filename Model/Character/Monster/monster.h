#ifndef MONSTER_H
#define MONSTER_H

#include "../../element.h"
#include <QPixmap>

class Monster : public Element
{
    public:
        Monster();
        Monster(QString,int,int);

        void checkCollideWithElement();
        void shoot();
        void setDeath();
        void drop();
        void update();
        void setAnimation();
        QList<QPixmap> getListAnimation() const;


    protected:
        int life;
        int dmg;
        int pas;
        QList<QPixmap> listAnimation;

        void takeDmg(Element* = 0);
        void move(bool = false);
        void death();

};

#endif // MONSTER_H
