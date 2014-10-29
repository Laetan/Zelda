#include "element.h"
#include <QPixmap>
#include <QtDebug>

Element::Element()
{
    QGraphicsPixmapItem();
}

Element::Element(QString picturePath): QGraphicsPixmapItem(QPixmap(picturePath))
{

}


void Element::update2()
{
    move();
    //checkCollision
}

void Element::move()
{
    qDebug()<<dir;
    if(dir == "z")
        this->moveBy(0,-1);
    else if(dir == "q")
        this->moveBy(-1,0);
    else if(dir == "s")
        this->moveBy(0,1);
    else if(dir == "d")
        this->moveBy(1,0);
}
