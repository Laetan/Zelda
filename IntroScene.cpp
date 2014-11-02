
#include "IntroScene.h"
#include <QGraphicsView>
#include <QDebug>
#include <QCoreApplication>
#include "gamescene.h"


IntroScene::IntroScene(int x, int y, int xx, int yy, QObject *parent):
    QGraphicsScene(x, y, xx, yy, parent)
{
    this->clear();
    this->display(QCoreApplication::applicationDirPath()+"/Ressources/sprites/Image11.png");
    qDebug()<<this->parent();
}

void IntroScene::keyPressEvent(QKeyEvent *event)
{
    QGraphicsView *view= (QGraphicsView*)this->parent();
    GameScene *game =  new GameScene(0,0,900,734,view);
    switch(event->key())
    {
    case Qt::Key_Space:
        this->clear();
        this->display(QCoreApplication::applicationDirPath()+"/Ressources/sprites/Image12.png");
        break;
    case Qt::Key_A:
        this->clear();
        this->display(QCoreApplication::applicationDirPath()+"/Ressources/sprites/Image13.png");
        break;
    case Qt::Key_B:
        this->clear();
        this->display(QCoreApplication::applicationDirPath()+"/Ressources/sprites/Image14.png");
        break;
    case Qt::Key_C:
        this->clear();
        view->setScene(game);
        break;
    default:
        break;
    }
}

void IntroScene::display(QString path)
{
    QPixmap image(path);
    this->addPixmap(image);
}

void IntroScene::close(QGraphicsView view)
{
    view.close();
}

