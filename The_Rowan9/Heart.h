#ifndef HEART_H
#define HEART_H

#include "zelda.h"
#include <QList>
#include <QPixmap>

class Heart: public Zelda
{
public:
    Heart();

    void displayLifePoint(int);

    QList<QPixmap> getListLifePoint() const;

private:
    QList<QPixmap> listLifePoint;

};

#endif // HEART_H
