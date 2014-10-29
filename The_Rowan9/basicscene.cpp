#include "basicscene.h"
#include <QtDebug>
#include <QGraphicsItem>
#include <QKeyEvent>
#include "element.h"

BasicScene::BasicScene(QObject *parent) :
    QGraphicsScene(parent)
{
    QString path = "C:\\Users\\faudi_000\\Desktop\\Qt\\build-TP_Zelda-Desktop_Qt_5_3_MinGW_32bit-Debug\\debug\\Ressource\\Sprites\\zelda.png";
    zelda = new Zelda(path);
    qDebug()<<zelda;
    this->addItem(zelda);
}

BasicScene::BasicScene(int x, int y, int xx , int yy, QObject *parent):
    QGraphicsScene(x,y,xx,yy,parent)
{
    QString path = "C:\\Users\\faudi_000\\Desktop\\Qt\\build-TP_Zelda-Desktop_Qt_5_3_MinGW_32bit-Debug\\debug\\Ressource\\Sprites\\zelda.png";
    zelda = new Zelda(path);
    qDebug()<<zelda;
    this->addItem(zelda);
    timer = new QTimer(this);
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()),this, SLOT(update()));
    timer->start();
}

void BasicScene::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<event->key();
    this->items();
    switch(event->key())
    {
    case Qt::Key_Z:
        zelda->setDir("z");
        break;
    case Qt::Key_Q:
        zelda->setDir("q");
        break;
    case Qt::Key_S:
        zelda->setDir("s");
        break;
    case Qt::Key_D:
        zelda->setDir("d");
        break;
    default:
        break;
    }
}


void BasicScene::update()
{
    QList<Element*> list;
    foreach(QGraphicsItem* item,this->items()){
        list.append((Element*) item);
    }
    foreach(Element* item,list){
        item->update2();

    }
}
