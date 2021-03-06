#include "pewpew.h"

Pewpew::Pewpew(QPointF pos, QString dir): Projectile(dir,"pewpew")
{
    if(dir=="z"){
        this->setPixmap(QPixmap(QCoreApplication::applicationDirPath()+"/Ressources/sprites/pewpew_U.png"));
        pos.setX(pos.x()+8);
    }
    else if(dir=="q"){
        this->setPixmap(QPixmap(QCoreApplication::applicationDirPath()+"/Ressources/sprites/pewpew_L.png"));
        pos.setY(pos.y()+8);
    }
    else if(dir=="s"){
        this->setPixmap(QPixmap(QCoreApplication::applicationDirPath()+"/Ressources/sprites/pewpew_D.png"));
        pos.setX(pos.x()+8);
        pos.setY(pos.y()+8);
    }
    else if(dir=="d"){
        this->setPixmap(QPixmap(QCoreApplication::applicationDirPath()+"/Ressources/sprites/pewpew_R.png"));
        pos.setY(pos.y()+8);
        pos.setX(pos.x()+8);
    }
    this->speed = 3;
    pos.setX(pos.x()-pixmap().width()/2);
    pos.setY(pos.y()-pixmap().height()/2);
    this->setPos(pos);

    //QSound::play("XX.wav");
}
