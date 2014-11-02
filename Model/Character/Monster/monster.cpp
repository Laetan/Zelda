#include "monster.h"
#include "Model/Item/pewpew.h"
#include "gamescene.h"
#include <QString>
#include <QPixmap>


Monster::Monster(QString picturePath, int x, int y,QString type):Element(picturePath,x,y, type)
{
    if(type =="bat")
        setPixmap(QPixmap(QCoreApplication::applicationDirPath()+"/Ressources/sprites/bat1.png"));
    life = 5;
    dmg = 2;
    this->setAnimation();
    pas = 0;
    speed=1;
}

void Monster::checkCollideWithElement()
{
    QList<QGraphicsItem*> collidList = collidingItems();

    foreach(QGraphicsItem *item, collidList){
        QGraphicsPixmapItem *pic = (QGraphicsPixmapItem*)item;
        if(pic->pixmap().size().width()<30){
            Element* element = (Element*)item;            
            if(element->getName()=="arrow"){
                GameScene *_scene = (GameScene*) this->scene();
                _scene->remove(element);
                takeDmg();
            }
            else if(element->getName()=="bat" ||element->getName()=="monster" || element->getName()=="zelda")    move(true);
        }
    }
}

void Monster::shoot()
{
    if(qrand()%100>95){
        Pewpew* p = new Pewpew(pos(),dir);
        ((GameScene*)scene())->addItem(p);
        ((GameScene*)scene())->addProjectile(p);
    }
}

void Monster::update()
{
    move();
    if(name!="bat")
        shoot();
    if(checkCollideWithEnv())
        move(true);
    checkCollideWithElement();

}

void Monster::setAnimation()
{
    // Récupérer dans une QList les différentes sprites
    QString path = QCoreApplication::applicationDirPath()+"/Ressources/sprites/";
    QString path_face = path + "monster_face.png";
    QString path_back = path + "monster_back.png";
    QString path_right = path + "monster_rigth.png";
    QString path_left = path + "monster_left.png";
    QString bat1 = path + "bat1.png";
    QString bat2 = path + "bat2.png";


    listAnimation.append(QPixmap(path_face));
    listAnimation.append(QPixmap(path_back));
    listAnimation.append(QPixmap(path_right));
    listAnimation.append(QPixmap(path_left));
    listAnimation.append(QPixmap(bat1));
    listAnimation.append(QPixmap(bat2));
}

QList<QPixmap> Monster::getListAnimation() const
{
    return listAnimation;
}

void Monster::takeDmg(Element *element)
{
    (void*)element;
    death();
}

void Monster::move(bool collide)
{
    if(collide) speed*=-1;

    if(pas<=0)
    {
        QList<QString> DiffDir;
        DiffDir <<"s" <<"z"<< "d"<< "q";
        pas = qrand()%50;
        int i = qrand()%4;
        dir=DiffDir[i];
        if(name!="bat")
            setPixmap(listAnimation[i]);
    }
    if(name=="bat")
        setPixmap(listAnimation[4+pas%2]);
    if(dir == "z")
        this->moveBy(0,-1*speed);
    else if(dir == "q")
        this->moveBy(-1*speed,0);
    else if(dir == "s")
        this->moveBy(0,1*speed);
    else if(dir == "d")
        this->moveBy(1*speed,0);


    if(collide){
        speed*=-1;
        pas=0;
    }

    else        pas--;
}

void Monster::drop()
{
    int itemDrop = qrand() % 100 + 1;

    Objets *o;
    if( itemDrop <= 40) return;
    else if(itemDrop <= 60){
        o = new Objets("rubisV", pos().x(), pos().y());
    }
    else if(itemDrop <= 80){
        o = new Objets("coeur",pos().x(), pos().y());
    }
    else if(itemDrop <= 90){
        o = new Objets("rubisB",pos().x(), pos().y());
    }
    else if(itemDrop <= 95){
        o = new Objets("rubisR",pos().x(), pos().y());
    }
    else if(itemDrop <= 100){
        o = new Objets("fee",pos().x(), pos().y());
    }
    ((GameScene*)scene())->addItem(o);
    ((GameScene*)scene())->addObjet(o);
}

void Monster::death(){
    drop();
    ((GameScene*)scene())->getMonsterList().removeOne(this);
    ((GameScene*)scene())->remove(this);
    delete this;
}
