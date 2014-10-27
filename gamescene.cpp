#include "gamescene.h"
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QGraphicsPixmapItem>
#include <QtDebug>

GameScene::GameScene(QObject *parent) :
    QGraphicsScene(parent),envSS("sprite_zone"),world()
{
    //qDebug()<<QCoreApplication::applicationDirPath();

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
