#include "Objets.h"

using namespace std;

Objets::Objets(QGraphicsScene *map, string type, int posX, int posY):
    QGraphicsPixmapItem(QPixmap(type+".png"))
{
    setPos(posX,posY);
    map->addItem(this);
	
	QTimer *timer1 = new QTimer;
	timer1->setInterval(5000);
	timer1->start();
	connect(timer1,SIGNAL (timeout()),this, SLOT (disappear())
}

void Objets::disappear()
{
	QTimer *timer1 = new QTimer;
	timer1->setInterval(6000);
	timer1->start();
	while(timer1 < 6000)
	{
		if( timer1 == 0 || timer1 == 2000 || timer1 == 4000) this.setVisible(false) ;
		if( timer1 == 1000 || timer1 == 3000 || timer1 == 5000) this.setVisible(true) ;
	}
	if( timer1 == 6000)
	{
		map->remove(this);
	}
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
		//a definir
    }
}
