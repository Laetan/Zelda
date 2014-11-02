#ifndef OBJETS_H
#define OBJETS_H

#include <iostream>
#include <string>
#include <QApplication>
#include <QLabel>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QSound>
#include <cstdlib>
#include <ctime>

using namespace std;

class Objets : public QGraphicsPixmapItem
{
public:
    Objets(QGraphicsScene* ,string , int, int);
    void ramasse(Zelda*, string);
    void drop();
};

#endif // OBJETS_H
