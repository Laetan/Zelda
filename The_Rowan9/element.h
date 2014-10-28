#ifndef ELEMENT_H
#define ELEMENT_H

#include <QWidget>
#include <QtGui>
#include <QGraphicsPixmapItem>
#include <QString>

class Element : public QGraphicsPixmapItem
{
public:
    Element();
    ~Element();
    void update();
    void move();

private:
    QString dir;

};

#endif // ELEMENT_H
