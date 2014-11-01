#include "element.h"
#include <QPixmap>
#include <QtDebug>

Element::Element()
{
    QGraphicsPixmapItem();
}

Element::Element(QString picturePath, QString n): QGraphicsPixmapItem(QPixmap(picturePath)),name(n)
{

}


void Element::update2()
{
    if(dir!="")
        currentDir=dir;
    move();
    //checkCollision
}

void Element::move()
{
    if(dir!=""){
        qDebug()<<dir;
    }
    if(dir == "z")
        this->moveBy(0,-1*speed);
    else if(dir == "q")
        this->moveBy(-1*speed,0);
    else if(dir == "s")
        this->moveBy(0,1*speed);
    else if(dir == "d")
        this->moveBy(1*speed,0);
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



