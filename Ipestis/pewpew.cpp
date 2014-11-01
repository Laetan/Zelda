#include "pewpew.h"
#include <QSound> //Ajouter aussi: multimedia au fichier .pro

Arrow::Arrow(QPointF pos, QString dir):Element()
{
    this->dir=dir;
    pos.setX(pos.x()+10);
    pos.setY(pos.y()+10);
    this->setPos(pos);

    if(dir=="z")this->setPixmap(QPixmap("C:\\Users\\Arthur\\Pictures\\Zelda\\pewpew_U"));
    else if(dir=="q")this->setPixmap(QPixmap("C:\\Users\\Arthur\\Pictures\\Zelda\\pewpew_L"));
    else if(dir=="s")this->setPixmap(QPixmap("C:\\Users\\Arthur\\Pictures\\Zelda\\pewpew_D"));
    else if(dir=="d")this->setPixmap(QPixmap("C:\\Users\\Arthur\\Pictures\\Zelda\\pewpew_R"));

    this->speed = 2;

    QSound::play("XX.wav");
}
