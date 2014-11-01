#ifndef CLASSVIEW_H
#define CLASSVIEW_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsView>
#include <Qtimer>
#include <QEventLoop>

class ClassView : QGraphicsView
{
public:
    ClassView();


private:
    QPixmap *personnage;
    QPixmap *map;
    QGraphicsPixmapItem *g_personnage;
    QGraphicsPixmapItem *g_map;
    QGraphicsScene *scene;
    QPoint xy;

    void keyPressEvent(QKeyEvent*);
};

#endif // CLASSVIEW_H
