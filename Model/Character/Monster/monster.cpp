#include "monster.h"

#include <QString>
#include <QPixmap>

Monster::Monster():Element("", "monstre")
{
    life = 5;
    dmg = 2;
}

Monster::Monster(QString picturePath, int x, int y):Element(picturePath,x,y, "monstre")
{
    life = 5;
    dmg = 2;
    this->setAnimation();
    pas = 0;
    speed=1;
}

void Monster::update()
{
    move();
    if(checkCollideWithEnv())
        move(true);
}

void Monster::setAnimation()
{
    // Récupérer dans une QList les différentes sprites
    QString path = QCoreApplication::applicationDirPath()+"Ressources/sprites/";
    QString path_face = path + "monster_face.png";


    listAnimation.append(QPixmap(path_face));
//    listAnimation.append(QPixmap(path_back));
//    listAnimation.append(QPixmap(path_right));
//    listAnimation.append(QPixmap(path_left));
}

QList<QPixmap> Monster::getListAnimation() const
{
    return listAnimation;
}

void Monster::move(bool collide)
{
    if(collide) speed*=-1;

    if(pas<=0)
    {
        QList<QString> DiffDir;
        DiffDir <<"z" <<"s"<< "q"<< "d";
        pas = qrand()%50;
        int i = qrand()%4;
        dir=DiffDir[i];
    }
    if(dir == "z")
        this->moveBy(0,-1*speed);
    else if(dir == "q")
        this->moveBy(-1*speed,0);
    else if(dir == "s")
        this->moveBy(0,1*speed);
    else if(dir == "d")
        this->moveBy(1*speed,0);


    if(collide){
        speed*=-1;
        pas=0;
    }

    else        pas--;
}

