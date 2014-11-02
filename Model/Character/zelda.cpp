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
    life = 3;
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
    int env=checkCollideWithEnv();
    if(env==1)
        move(true);
    else if(env > 0)
        eventEnv(env);
    if(blinkOn != 0)
        blink();
    else
        checkCollideWithElement();
}

void Zelda::checkCollideWithElement()
{
    QList<QGraphicsItem*> collidList = collidingItems();

    foreach(QGraphicsItem *item, collidList){
        QGraphicsPixmapItem *pic = (QGraphicsPixmapItem*)item;
        if(pic->pixmap().size().width()<30){
            Element* element = (Element*)item;
            if(element->getName()=="monstre" )    move(true);
            else if(element->getName()=="bat")
                takeDmg();
            else if(element->getName()=="pewpew" ){
                ((GameScene*) this->scene())->remove(element);
                takeDmg();
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

void Zelda::takeDmg()
{
    life--;
    qDebug()<<life;
    if(life>0) blinkOn = 40;
    else death();
}

void Zelda::blink()
{
    if(blinkCounter==0){
        setVisible(!isVisible());
        blinkCounter=1;
    }
    else    blinkCounter--;
    blinkOn--;
    if(blinkOn==0) setVisible(true);
}

void Zelda::death(){
    QString path = QCoreApplication::applicationDirPath()+"/Ressources/sprites";
    QString path_face = path + "/zelda_death_face.png";
    QString path_back = path + "/zelda_death_back.png";
    QString path_right = path + "/zelda_death_right.png";
    QString path_left = path + "/zelda_death_left.png";
    if(currentDir == "z")
        setPixmap(QPixmap(path_back));
    else if(currentDir == "q")
        setPixmap(QPixmap(path_right));
    else if(currentDir == "s")
        setPixmap(QPixmap(path_face));
    else if(currentDir == "d")
        setPixmap(QPixmap(path_left));
    qDebug()<<pixmap();
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

