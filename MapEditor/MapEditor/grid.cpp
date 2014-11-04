#include "grid.h"

Grid::Grid(QGraphicsItem *parent) : QGraphicsRectItem(0,0,960,736,parent)
{
    int w = this->rect().width();
    int h = this->rect().height();
    for(int i=0; i <= w; i+=32){
        QGraphicsLineItem *l = new QGraphicsLineItem(this);
        l->setLine(i,0,i,h);
    }
    for(int i=0; i <= h; i+=32){
        QGraphicsLineItem *l = new QGraphicsLineItem(this);
        l->setLine(0,i,w,i);
    }
}
