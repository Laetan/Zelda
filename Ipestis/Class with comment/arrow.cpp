#include "arrow.h"
#include <QSound>
#include <QCoreApplication>
#include <QtDebug>

//Create an arrow depending on the direction and define their position
Arrow::Arrow(QPointF pos, QString dir):Projectile(dir,"arrow")
{
    if(dir=="z"){
        //Set the sprite
        this->setPixmap(QPixmap(QCoreApplication::applicationDirPath()+"/Ressources/sprites/arrow_U.png"));
        pos.setX(pos.x()+10);
    }
    else if(dir=="q"){
        this->setPixmap(QPixmap(QCoreApplication::applicationDirPath()+"/Ressources/sprites/arrow_L.png"));
        pos.setY(pos.y()+15);
    }
    else if(dir=="s"){
        this->setPixmap(QPixmap(QCoreApplication::applicationDirPath()+"/Ressources/sprites/arrow_D.png"));
        pos.setX(pos.x()+10);
        pos.setY(pos.y()+29);
    }
    else if(dir=="d"){
        this->setPixmap(QPixmap(QCoreApplication::applicationDirPath()+"/Ressources/sprites/arrow_R.png"));
        pos.setY(pos.y()+15);
        pos.setX(pos.x()+21);
    }

    //Define the speed of arrows
    this->speed = 4;

    pos.setX(pos.x()-pixmap().width()/2);
    pos.setY(pos.y()-pixmap().height()/2);
    this->setPos(pos);

    //Sound
    //QSound::play("OOT_Arrow_Shoot.wav");
}
