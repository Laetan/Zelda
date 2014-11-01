#ifndef OBJETS_H
#define OBJETS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QSound>
#include <QTimer>  
#include <QEventLoop>
#include <QString>

class Objets : public QGraphicsPixmapItem
{
public:
    Objets(QGraphicsScene* ,QString , int, int);
    void ramasse(Zelda*, QString );
	void disappear(QGraphicsPixmapItem*);
};

#endif // OBJETS_H