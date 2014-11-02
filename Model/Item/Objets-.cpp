#include "Objets.h"
#include "gamescene.h"
#include <QCoreApplication>

Objets::Objets(QString  type, int posX, int posY):
   Element(QCoreApplication::applicationDirPath()+"/Ressources/sprites/"+type+".png",type)
{
    setPos(posX,posY);
    clearCounter =2*50;
//    qDebug()<<QCoreApplication::applicationDirPath()+"/Ressources/sprites/"+type+".png";
    QFile file(QCoreApplication::applicationDirPath()+"/Ressources/sprites/"+type+".png");

    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<file.errorString();
    }
}

void Objets::disappear()
{
    if(clearCounter<-50){
        ((GameScene*)scene())->remove(this);
    }
    else if(blinkCounter==0){
            setVisible(!isVisible());
            blinkCounter=1;
    }
    else    blinkCounter--;


}

void Objets::update()
{
    if(--clearCounter<=0)
        disappear();
}
