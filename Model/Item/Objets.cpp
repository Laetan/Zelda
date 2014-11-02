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


void Objets::ramasse(Zelda *zelda) {

    /*if( type.compare("rubisG") == 0){
        zelda->setRubis(Zelda->getRubis()+1);
        QSound::play("OOT_Get_Rupee.wav");
    }
    if( type.compare("rubisB") == 0){
        zelda->setRubis(Zelda->getRubis()+5);
        QSound::play("OOT_Get_Rupee.wav");
    }
    if( type.compare("rubisR") == 0){
        zelda->setRubis(Zelda->getRubis()+20);
        QSound::play("OOT_Get_Rupee.wav");
    }
    if( type.compare("coeur") == 0){
        zelda->setVie(Zelda->getVie()+1);
        QSound::play("LTTP_Item.wav");
    }
    if( type.compare("fee") == 0){
        zelda->setVie(Zelda->getVie()+10);
        QSound sound("LTTP_Item.wav");
		sound.play();
		sound.setLoops(5);
    }*/
    if( type.compare("cle") == 0){
		//a definir
		QSound::play("MC_Fanfare_Item.wav");
    }
}

void Objets::update()
{
    if(--clearCounter<=0)
        disappear();
}
