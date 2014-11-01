
#include "IntroScene.h"
#include <QGraphicsView>
#include <QDebug>
#include <QCoreApplication>
#include "basicscene.h"


IntroScene::IntroScene(int x, int y, int xx, int yy, QObject *parent):
    QGraphicsScene(x, y, xx, yy, parent)
{
    this->clear();
    this->display(QCoreApplication::applicationDirPath()+"/Image11.png");
    qDebug()<<this->parent();
}

void IntroScene::keyPressEvent(QKeyEvent *event)
{
    QGraphicsView *view= (QGraphicsView*)this->parent();
    BasicScene *scene = new BasicScene(0,0,600,600,view);
    switch(event->key())
    {
    case Qt::Key_Space:
        this->clear();
        this->display(QCoreApplication::applicationDirPath()+"/Image12.png");
        break;
    case Qt::Key_A:
        this->clear();
        this->display(QCoreApplication::applicationDirPath()+"/Image13.png");
        break;
    case Qt::Key_B:
        this->clear();
        this->display(QCoreApplication::applicationDirPath()+"/Image14.png");
        break;
    case Qt::Key_C:
        this->clear();
        view->setScene(scene);
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

