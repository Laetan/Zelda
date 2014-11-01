
#include "IntroScene.h"
#include <QGraphicsView>
#include <QDebug>


IntroScene::IntroScene(int x, int y, int xx, int yy, QObject *parent):
    QGraphicsScene(x, y, xx, yy, parent)
{
    this->clear();
    this->display("C:\\Users\\faudi_000\\Desktop\\Qt\\build-tst_fenetre-Desktop_Qt_5_3_MinGW_32bit-Debug\\debug\\Image11.png");
    qDebug()<<parent;
}

void IntroScene::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Space:
        this->clear();
        this->display("C:\\Users\\faudi_000\\Desktop\\Qt\\build-tst_fenetre-Desktop_Qt_5_3_MinGW_32bit-Debug\\debug\\Image12.png");
        break;
    case Qt::Key_A:
        this->clear();
        this->display("C:\\Users\\faudi_000\\Desktop\\Qt\\build-tst_fenetre-Desktop_Qt_5_3_MinGW_32bit-Debug\\debug\\Image13.png");
        break;
    case Qt::Key_B:
        this->clear();
        this->display("C:\\Users\\faudi_000\\Desktop\\Qt\\build-tst_fenetre-Desktop_Qt_5_3_MinGW_32bit-Debug\\debug\\Image14.png");
        break;
    case Qt::Key_C:
        this->clear();
        //parent.setScene(scene);
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

