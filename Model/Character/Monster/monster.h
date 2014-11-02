#ifndef MONSTER_H
#define MONSTER_H

#include "../../element.h"
#include <QPixmap>

/**
 * @brief Classe de gestion des monstres
 */
class Monster : public Element
{
    public:

        Monster(QString, int, int, QString);

        void checkCollideWithElement();
        void shoot();
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
