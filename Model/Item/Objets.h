#ifndef OBJETS_H
#define OBJETS_H

#include <QApplication>
#include <QLabel>

#include <QGraphicsScene>
#include <QSound>
#include <QTimer>  
#include <QEventLoop>
#include <QString>

#include"Model/Character/zelda.h"
#include "Model/element.h"
using namespace std;

class Objets : public Element
{
public:
    Objets(QString , int, int);
    void ramasse(Zelda*);
    void update();
    void drop();
    void disappear();

private:
    int clearCounter;
    int blinkCounter;
    QString type;
};

#endif // OBJETS_H
