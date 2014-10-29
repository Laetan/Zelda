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


using namespace std;

class Objets : public QGraphicsPixmapItem
{
public:
    Objets(QGraphicsScene* ,QString , int, int);
    void ramasse(Zelda*, QString );
    void drop();
	void dissapear();
};

#endif // OBJETS_H