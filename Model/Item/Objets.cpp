#include "Objets.h"

using namespace std;

Objets::Objets(QGraphicsScene *map, QString  type, int posX, int posY):
    QGraphicsPixmapItem(QPixmap(type+".png"))
{
    setPos(posX,posY);
    map->addItem(this);
	
	QEventLoop loop;
	QTimer::singleShot(5000, &loop, SLOT(quit()));
	loop.exec();
	disappear(item);
}

void Objets::disappear(QGraphicsPixmapItem* item)
{
	int cpt = 5;
    while( cpt != 0){
        item->setVisible(false);
        QEventLoop loop;
        QTimer::singleShot(1000, &loop, SLOT(quit()));
        loop.exec();
        item->setVisible(true);
        QTimer::singleShot(1000, &loop, SLOT(quit()));
        loop.exec();
        cpt--;
    }
    delete item; // suppression de l'item
}

void Objets::ramasse(Zelda* zelda, string type ) {

    if( type.compare("rubisG") == 0){
        Zelda->setRubis(Zelda->getRubis()+1);
        QSound::play("OOT_Get_Rupee.wav");
    }
    if( type.compare("rubisB") == 0){
        Zelda->setRubis(Zelda->getRubis()+5);
        QSound::play("OOT_Get_Rupee.wav");
    }
    if( type.compare("rubisR") == 0){
        Zelda->setRubis(Zelda->getRubis()+20);
        QSound::play("OOT_Get_Rupee.wav");
    }
    if( type.compare("coeur") == 0){
        Zelda->setVie(Zelda->getVie()+1);
        QSound::play("LTTP_Item.wav");
    }
    if( type.compare("fee") == 0){
        Zelda->setVie(Zelda->getVie()+10);
        QSound sound("LTTP_Item.wav");
		sound.play();
		sound.setLoops(5);
    }
    if( type.compare("cle") == 0){
		//a definir
		QSound::play("MC_Fanfare_Item.wav");
    }
}
