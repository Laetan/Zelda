#ifndef OBJETS_H
#define OBJETS_H

#include <QApplication>
#include <QLabel>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QSound>
#include <QTimer>  
#include <QEventLoop>
#include <QString>

#include"Model/Character/zelda.h"

using namespace std;

class Objets : public QGraphicsPixmapItem
{
public:
    Objets(QGraphicsScene* ,QString , int, int);
    void ramasse(Zelda*);
    void drop();
    void disappear();

private:
    QString type;
};

#endif // OBJETS_H
