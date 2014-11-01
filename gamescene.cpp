#include "gamescene.h"
#include "Model/Item/arrow.h"
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QGraphicsPixmapItem>
#include <QtDebug>

GameScene::GameScene(QObject *parent) :
    QGraphicsScene(parent),envSS("sprite_zone"),world()
{
    qDebug()<<QCoreApplication::applicationDirPath();

    loadStage(world.start());
}

GameScene::GameScene(int x, int y, int xx , int yy, QObject *parent):
    QGraphicsScene(x,y,xx,yy,parent),envSS("sprite_zone"),world()
{
    QString path = QCoreApplication::applicationDirPath()+"/Ressources/sprites/zelda.png";

    zelda = new Zelda(path);
    this->addItem(zelda);
    qDebug()<<zelda->pixmap();
    timer = new QTimer(this);
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()),this, SLOT(update()));
    timer->start();
    loadStage(world.start());
}


void GameScene::loadStage(QString stageName){
    QString fileName = stageName+".zn";
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug()<<file.errorString()+":"+fileName;
        return;
    }
    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QList<QString> temp1 = line.split(";");
        QList<int> temp2;
        for(int i = 0; i<temp1.size(); i++){
            temp2<< temp1[i].toInt();
        }
        envData<<temp2;

    }    
    drawStage();

    fileName = stageName+".el";
    QFile fileEl(fileName);
    if(!fileEl.open(QIODevice::ReadOnly))return;
    in.reset();
    in.setDevice(&fileEl);
    while(!in.atEnd()) {
        QString line = in.readLine();
        QList<QString> temp = line.split(";");
        QString path = QCoreApplication::applicationDirPath()+"/Ressources/sprites/";
        if(temp[2]=="rocker_red" || temp[2]=="rocker_blue"){
//            Monster m = new Monster(path+"monster_face.png",temp[0],temp[1]);
//            monsterList.append(m);
//            this->addItem(m);
        }
        //else if(temp1[2]=="bat")
          //Monster m = new Monster(path+"monster_face.png",temp[0],temp[1]);


    }

}

void GameScene::drawStage(){
    this->setBackgroundBrush(Qt::black);
    for(int x = 0; x < envData.size();x++){
        for(int y = 0; y<envData[x].size();y++){
            if(envData[x][y]==0) continue;
            QGraphicsPixmapItem *pic = new QGraphicsPixmapItem();
            pic->setPixmap(envSS.get(envData[x][y]));
            pic->setPos(x*32,y*32);
            addItem(pic);
        }
    }
}

void GameScene::keyPressEvent(QKeyEvent *event)
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

void GameScene::keyReleaseEvent(QKeyEvent *event)
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

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QList<Element*> list;
    foreach(QGraphicsItem* item,this->items()){
        list.append((Element*) item);
    }
    foreach(Element* item,list){
        if(item->getName()=="zelda"){
            Arrow *a = new Arrow(item->pos(),item->getDir());
            this->addItem(a);
        }
    }
}

void GameScene::update()
{
    zelda->update2();

    foreach (Monster* m, monsterList) {
        m->update2();
    }
}
