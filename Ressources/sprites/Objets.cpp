#include "Objets.h"

using namespace std;

Objets::Objets(QGraphicsScene *map, string type, int posX, int posY):
    QGraphicsPixmapItem(QPixmap(type+".png"))
{
    setPos(posX,posY);
    map->addItem(this);
}

void Objets::ramasse(Zelda* zelda, string type ) {

    if( type.compare("rubisG") == 0){
        Zelda->setRubis(Zelda->getRubis()+1);
        QSound::play("mysounds/bells.wav");
    }
    if( type.compare("rubisB") == 0){
        Zelda->setRubis(Zelda->getRubis()+5);
        QSound::play("mysounds/bells.wav");
    }
    if( type.compare("rubisR") == 0){
        Zelda->setRubis(Zelda->getRubis()+20);
        QSound::play("mysounds/bells.wav");
    }
    if( type.compare("coeur") == 0){
        Zelda->setVie(Zelda->getVie()+1);
        QSound::play("mysounds/bells.wav");
    }
    if( type.compare("fee") == 0){
        Zelda->setVie(Zelda->getVie()+10);
        QSound::play("mysounds/bells.wav");
    }
    if( type.compare("cle") == 0){

    }
}
