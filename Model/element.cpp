#include "element.h"
#include <QPixmap>
#include <QtDebug>
#include <QList>
#include "gamescene.h"

Element::Element()
{
    QGraphicsPixmapItem();
}
Element::Element(QString n): QGraphicsPixmapItem(), name(n)
{

}

Element::Element(QString picturePath, QString n): QGraphicsPixmapItem(QPixmap(picturePath)),name(n)
{

}

Element::Element(QString picturePath,int x,int y,QString n): QGraphicsPixmapItem(QPixmap(picturePath)),name(n)
{
    this->setPos(x,y);
}

void Element::update()
{
    if(dir!="")
        currentDir=dir;
    move();
    bool collide = checkCollideWithEnv();
    if( collide && name=="projectile")
        ((GameScene*)scene())->remove(this);
    else if(collide)
        move(true);

}

void Element::move(bool collide)
{
    if(collide) speed*=-1;
    if(dir == "z")
        this->moveBy(0,-1*speed);
    else if(dir == "q")
        this->moveBy(-1*speed,0);
    else if(dir == "s")
        this->moveBy(0,1*speed);
    else if(dir == "d")
        this->moveBy(1*speed,0);
    if(collide) speed*=-1;
}

bool Element::checkCollideWithEnv(){

    int x(pos().x()),y(pos().y()),w(pixmap().size().width()),h(pixmap().size().height());
    return collideWithEnv(x,y) || collideWithEnv(x+w,y)
            || collideWithEnv(x,y+h) || collideWithEnv(x+w,y+h);

}

bool Element::collideWithEnv(int x, int y)
{
    QList<QList<int> > data = ((GameScene*)this->scene())->getEnvData();
    return (data[(int)x/32][(int)y/32]>100);

}





QString Element::getName() const
{
    return name;
}
QString Element::getDir() const
{
    return currentDir;
}
QString Element::getCurrentDir() const
{
    return currentDir;
}

void Element::setCurrentDir(const QString &value)
{
    currentDir = value;
}



