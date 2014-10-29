#include "basicscene.h"
#include <QtDebug>
#include <QGraphicsItem>
#include <QKeyEvent>
#include "element.h"
#include "zelda.h"

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

    // Instancier un monster

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
        zelda->setPixmap(zelda->getListAnimation()[1]);
        break;
    case Qt::Key_Q:
        zelda->setDir("q");
        zelda->setPixmap(zelda->getListAnimation()[3]);
        break;
    case Qt::Key_S:
        zelda->setDir("s");
        zelda->setPixmap(zelda->getListAnimation()[0]);
        break;
    case Qt::Key_D:
        zelda->setDir("d");
        zelda->setPixmap(zelda->getListAnimation()[2]);
        break;
    default:
        break;
    }
}

void BasicScene::keyReleaseEvent(QKeyEvent *event)
{
    qDebug()<<event->key();
    if(event->key() == Qt::Key_Z && zelda->getDir()=="z")
        zelda->setDir("");
    if(event->key() == Qt::Key_Q && zelda->getDir()=="q")
        zelda->setDir("");
    if(event->key() == Qt::Key_S && zelda->getDir()=="s")
        zelda->setDir("");
    if(event->key() == Qt::Key_D && zelda->getDir()=="d")
        zelda->setDir("");
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
