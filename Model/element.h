#ifndef ELEMENT_H
#define ELEMENT_H

#include <QGraphicsPixmapItem>

class Element : public QGraphicsPixmapItem
{
public:
    Element();
    virtual ~Element();
protected:
	QRectF hitbox;
    QList<QPixmap*> pixs;
};

#endif // ELEMENT_H
