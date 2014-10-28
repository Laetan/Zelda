#include "basicscene.h"
#include <QtDebug>

BasicScene::BasicScene(QObject *parent) :
    QGraphicsScene(parent)
{

}

BasicScene::BasicScene(int x, int y, int xx , int yy, QObject *parent):
    QGraphicsScene(x,y,xx,yy,parent)
{
    timer = new QTimer(this);
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()),this, SLOT(update()));
    timer->start();
}


void BasicScene::update()
{
    foreach(QGraphicsItem* item,this->items()){
        item->update();
    }
    qDebug()<<"updated";
}
