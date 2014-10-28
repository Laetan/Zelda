#include "element.h"

Element::Element(){QGraphicsPixmapItem();}

void Element::update()
{
    move();
    //checkCollision
}

void Element::move()
{
    if(dir == "z")
        this->moveBy(0,-1);
    else if(dir == "q")
        this->moveBy(-1,0);
    else if(dir == "s")
        this->moveBy(0,1);
    else if(dir == "d")
        this->moveBy(1,0);
    else
        qDebug() <<"Bad key";
}
