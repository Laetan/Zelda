#include "Objets.h"
#include "gamescene.h"
#include <QCoreApplication>

//Recovers the list of sprites based on the "type" and puts them  with X and Y coordinates.
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

//Function of disappearance and flashes of objects.
void Objets::disappear()
{
    if(clearCounter<-50){
        //Remove item form the scene
        ((GameScene*)scene())->remove(this);
    }
    //Define visible or invisible item on the scene by counter and update
    else if(blinkCounter==0){
            setVisible(!isVisible());
            blinkCounter=1;
    }
    else    blinkCounter--;


}

//Update function (timer)
void Objets::update()
{
    if(--clearCounter<=0)
        disappear();
}
