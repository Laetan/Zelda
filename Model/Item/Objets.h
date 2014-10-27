#ifndef OBJETS_H
#define OBJETS_H


#include "Model/element.h"

#include <QSound>
#include <QTimer>

using namespace std;

class Objets : public Element
{
public:
    Objets(QGraphicsScene* ,string , int, int);
    void ramasse(Zelda*, string);
    void drop();
	void dissapear();
};

#endif // OBJETS_H
