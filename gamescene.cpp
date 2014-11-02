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
    zelda = 0;
    timer = new QTimer(this);
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()),this, SLOT(update()));
    timer->start();
    loadStage(world.start());
}

void GameScene::remove(Monster *m)
{
    monsterList.removeOne(m);
    removeItem(m);
}

void GameScene::remove(Projectile *p)
{
    projectList.removeOne(p);
    removeItem(p);
}

void GameScene::remove(Objets *o)
{
    objetList.removeOne(o);
    removeItem(o);
    delete o;
}

void GameScene::remove(Element *e)
{
    if(e->getName()=="arrow" || e->getName()=="pewpew")
        this->remove((Projectile*)e);
    else if(e->getName()=="monster" || e->getName()=="bat")
        this->remove((Monster*)e);
    else
        this->remove((Objets*)e);
}
QList<QList<int> > GameScene::getEnvData() const
{
    return envData;
}

void GameScene::setEnvData(const QList<QList<int> > &value)
{
    envData = value;
}
QList<Projectile *> GameScene::getProjectList() const
{
    return projectList;
}

void GameScene::addProjectile(Projectile *p)
{
    projectList.append(p);
}
QList<Objets *> GameScene::getObjetList() const
{
    return objetList;
}

void GameScene::addObjet(Objets *o)
{
    objetList.append(o);
}
QList<Monster *> GameScene::getMonsterList() const
{
    return monsterList;
}

void GameScene::setMonsterList(const QList<Monster *> &value)
{
    monsterList = value;
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
    if(!fileEl.open(QIODevice::ReadOnly)){
        qDebug()<<file.errorString()+":"+fileName;
        return;
    }
    in.reset();
    in.setDevice(&fileEl);
    while(!in.atEnd()) {
        QString line = in.readLine();
        QList<QString> temp = line.split(";");
        QString path = QCoreApplication::applicationDirPath()+"/Ressources/sprites/";
        if(temp[2]=="rocker_red" || temp[2]=="rocker_blue"){
            Monster *m = new Monster(path+"monster_face.png",temp[0].toInt(),temp[1].toInt());
            m->setZValue(8);
            monsterList.append(m);
            this->addItem(m);
        }
        else if(temp[2]=="bat"){
            Monster *m = new Monster(path+"monster_face.png",temp[0].toInt(),temp[1].toInt());
            m->setZValue(8);
            monsterList.append(m);
            this->addItem(m);
        }


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
            if(zelda==0 && envData[x][y]<101){
                QString path = QCoreApplication::applicationDirPath()+"/Ressources/sprites/zelda.png";
                zelda = new Zelda(path);
                zelda->setZValue(10);
                zelda->setPos(x*32,y*32);
                this->addItem(zelda);

            }
        }
    }
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
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

void GameScene::keyReleaseEvent(QKeyEvent *event)
{
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

    if(event->button()==Qt::LeftButton){
        Arrow *a = new Arrow(zelda->pos(),zelda->getCurrentDir());
        this->addItem(a);
        projectList.append(a);
    }
}

void GameScene::update()
{
    zelda->update();

    foreach (Monster* m, monsterList) {
        m->update();
    }
    foreach (Projectile* a, projectList) {
        a->update();
    }
    foreach(Objets* o, objetList){
        o->update();
    }
}
