#include "element.h"
#include <QPixmap>
#include <QtDebug>

Element::Element()
{
    QGraphicsPixmapItem();
}

Element::Element(QString picturePath, QString n): QGraphicsPixmapItem(QPixmap(picturePath)), name(n)
{
    pas=0;
}


void Element::update2()
{
    if(name=="monstre")
    {
        moveMonster();
    }
    if(name=="zelda")
    {
        move();
    }
}

void Element::move()
{
 //   qDebug()<<"move" + dir;
    if(dir == "z")
        this->moveBy(0,-1);
    else if(dir == "q")
        this->moveBy(-1,0);
    else if(dir == "s")
        this->moveBy(0,1);
    else if(dir == "d")
        this->moveBy(1,0);
}

void Element::moveMonster()
{
    qsrand(QTime::currentTime().msec());

    if(pas<=0)
    {
        QList<QString> DiffDir;
        DiffDir <<"z" <<"s"<< "q"<< "d";
        //pas = qrand()%10;
        pas = qrand()%50;
        int i = qrand()%4;
        this->setDir(DiffDir[i]);
    }
    //qDebug()<<pas;
    //qDebug()<<dir;
    if(dir == "z")
        this->moveBy(0,-1);
    else if(dir == "q")
        this->moveBy(-1,0);
    else if(dir == "s")
        this->moveBy(0,1);
    else if(dir == "d")
        this->moveBy(1,0);
    pas--;

}

void Element::death()
{

}



QString Element::getDir() const
{
    return dir;
}

void Element::setDir(const QString &value)
{
    dir = value;
}
QString Element::getName() const
{
    return name;
}
int Element::getLife() const
{
    return life;
}

void Element::setLife(int value)
{
    life = value;
}



