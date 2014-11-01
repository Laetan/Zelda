#include "classview.h"

ClassView::ClassView()
{
    // création des pixmap
    personnage = new QPixmap;
    map = new QPixmap;

    // création des items
    g_personnage = new QGraphicsPixmapItem;
    g_map = new QGraphicsPixmapItem;

    // création de la scene
    scene = new QGraphicsScene;

    personnage->load("zelda.png");
    map->load("fond.png");

    g_personnage->setPixmap(*personnage);
    g_map->setPixmap(*map);

    scene->addItem(g_map);
    scene->addItem(g_personnage);

    xy.setX(100);
    xy.setY(0);
    g_personnage->setX(xy.x());
    g_personnage->setY(xy.y());
    g_map->setX(xy.x());
    g_map->setY(xy.y());

    this->setFixedSize(800,600);
    this->setScene(scene);

    //Test
    /*QGraphicsView view;

    view.setFixedSize(500,400);
    view.setScene(scene);

    view.show();

    QEventLoop loop;
    QTimer::singleShot(10000, &loop, SLOT(quit()));
    loop.exec();*/

}

void ClassView::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        printf("UP");
        xy.ry()-=2;
        g_personnage->setY(xy.y());
        g_personnage->setX(xy.x());
    }
    else if(event->key() == Qt::Key_Down)
    {
        printf("DOWN");
        xy.ry()+=2;
        g_personnage->setY(xy.y());
        g_personnage->setX(xy.x());
    }
    else if (event->key() == Qt::Key_Left)
    {
        printf("LEFT");
        xy.rx()-=2;
        g_personnage->setX(xy.x());
        g_personnage->setY(xy.y());
    }
    else if(event->key() == Qt::Key_Right)
    {
        printf("RIGHT");
        xy.rx()+=2;
        g_personnage->setX(xy.x());
        g_personnage->setY(xy.y());
    }
}
