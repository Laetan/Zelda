#include "element.h"
#include <QPixmap>
#include <QtDebug>
#include <QList>
#include "gamescene.h"

Element::Element()
{
    QGraphicsPixmapItem();
}
Element::Element(QString n): QGraphicsPixmapItem(), name(n)
{

}

Element::Element(QString picturePath, QString n): QGraphicsPixmapItem(QPixmap(picturePath)),name(n)
{

}

Element::Element(QString picturePath,int x,int y,QString n): QGraphicsPixmapItem(QPixmap(picturePath)),name(n)
{
    this->setPos(x,y);
}

void Element::update()
{
    move();
    int env = checkCollideWithEnv();
    if( env==1 && (name=="pewpew" || name=="arrow"))
        ((GameScene*)scene())->remove(this);
    else if(env==1)
        move(true);

}

void Element::move(bool collide)
{
    if(collide) speed*=-1;
    if(dir == "z")
        this->moveBy(0,-1*speed);
    else if(dir == "q")
        this->moveBy(-1*speed,0);
    else if(dir == "s")
        this->moveBy(0,1*speed);
    else if(dir == "d")
        this->moveBy(1*speed,0);
    if(collide) speed*=-1;
}

int Element::checkCollideWithEnv(){

    int x(pos().x()),y(pos().y()),w(pixmap().size().width()),h(pixmap().size().height());
    int a(collideWithEnv(x,y)),b(collideWithEnv(x,y+h)),c(collideWithEnv(x+w,y)),d(collideWithEnv(x+w,y+h));
    if(a==1 || b==1 || c==1 || d==1)
        return 1;
    else
        return qMax(qMax(a,b),qMax(c,d));


}

int Element::collideWithEnv(int x, int y)
{
    QList<QList<int> > data = ((GameScene*)this->scene())->getEnvData();
    if(data[(int)x/32][(int)y/32]>100 && data[(int)x/32][(int)y/32]<201 || data[(int)x/32][(int)y/32]==0){
        return 1;
    }
    else if(data[(int)x/32][(int)y/32]>200){
        return data[(int)x/32][(int)y/32];
    }
    else
        return 0;

}

void Element::eventEnv(int env)
{
    switch(env){
    case 201:
        ((GameScene*)scene())->changeStage("U");
        break;
    case 202:
        ((GameScene*)scene())->changeStage("D");
        break;
    case 203:
        ((GameScene*)scene())->changeStage("N");
        break;
    case 204:
        ((GameScene*)scene())->changeStage("S");
        break;
    case 205:
        ((GameScene*)scene())->changeStage("E");
        break;
    case 206:
        ((GameScene*)scene())->changeStage("W");
        break;
    default:
        break;
    }
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



