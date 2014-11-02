#include "zelda.h"
#include "gamescene.h"
#include <QString>
#include <QtDebug>
#include <QPixmap>

Zelda::Zelda()
{
    Personnage();
    life = 10;
    dmg = 0;
    nbreArrows = 0;
    speed=1;
    this->setAnimation();
}

Zelda::Zelda(QString picturePath):Personnage(picturePath, "zelda")
{
    life = 10;
    speed=2;
    dmg = 0;
    nbreArrows = 0;
    this->setAnimation();
}

void Zelda::update()
{
    if(dir!="")
        currentDir=dir;
    move();
    bool collide = checkCollideWithEnv();
    if(collide)
        move(true);
    checkCollideWithElement();
}

void Zelda::checkCollideWithElement()
{
    QList<QGraphicsItem*> collidList = collidingItems();

    foreach(QGraphicsItem *item, collidList){
        QGraphicsPixmapItem *pic = (QGraphicsPixmapItem*)item;
        if(pic->pixmap().size().width()<30){
            Element* element = (Element*)item;
            if(element->getName()=="monstre" || element->getName()=="bat")    move(true);
            else if(element->getName()=="pewpew"){
                ((GameScene*) this->scene())->remove(element);
                qDebug()<<"OUCH!";
                //takeDmg();
            }
            else if(element->getName()!="arrow"){
                loot(element->getName());
                qDebug()<<element->getName();
                ((GameScene*) this->scene())->remove(element);
            }
        }
    }
}

void Zelda::loot(QString type)
{
    if( type=="rubisV"){
        //zelda->setRubis(Zelda->getRubis()+1);
        QSound::play(QCoreApplication::applicationDirPath()+"/Ressources/Sounds/OOT_Get_Rupee.wav");
    }
    if( type=="rubisB"){
       // zelda->setRubis(Zelda->getRubis()+5);
        QSound::play(QCoreApplication::applicationDirPath()+"/Ressources/Sounds/OOT_Get_Rupee.wav");
    }
    if( type=="rubisR"){
        //zelda->setRubis(Zelda->getRubis()+20);
        QSound::play(QCoreApplication::applicationDirPath()+"/Ressources/Sounds/OOT_Get_Rupee.wav");
    }
    if( type=="coeur"){
        //zelda->setVie(Zelda->getVie()+1);
        QSound::play(QCoreApplication::applicationDirPath()+"/Ressources/Sounds/LTTP_Item.wav");
    }
    if( type=="fee"){
        //zelda->setVie(Zelda->getVie()+10);
        QSound sound(QCoreApplication::applicationDirPath()+"/Ressources/Sounds/LTTP_Item.wav");
        sound.play();
        sound.setLoops(5);
    }
    if( type=="cle"){
        //a definir
        QSound::play(QCoreApplication::applicationDirPath()+"/Ressources/Sounds/MC_Fanfare_Item.wav");
    }
}

int Zelda::getArrows()
{
    return nbreArrows;
}

void Zelda::setAnimation()
{
    // Récupérer dans une QList les différentes sprites
    QString path = QCoreApplication::applicationDirPath()+"/Ressources/sprites/";;
    QString path_face = path + "zelda_face.png";
    QString path_back = path + "zelda_back.png";
    QString path_right = path + "zelda_right.png";
    QString path_left = path + "zelda_left.png";

    listAnimation.append(QPixmap(path_face));
    listAnimation.append(QPixmap(path_back));
    listAnimation.append(QPixmap(path_right));
    listAnimation.append(QPixmap(path_left));
}

//void Zelda::takeItem(Ressource &item)
//{
//    // A implementer suivant les items créer
//}


// Getter & Setter
int Zelda::getNbreArrows() const
{
    return nbreArrows;
}

void Zelda::setNbreArrows(int value)
{
    nbreArrows = value;
}

QString Zelda::getDir() const
{
    return dir;
}

void Zelda::setDir(const QString &value)
{
    dir = value;
}
QList<QPixmap> Zelda::getListAnimation() const
{
    return listAnimation;
}

