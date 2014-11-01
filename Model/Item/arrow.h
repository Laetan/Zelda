#ifndef ARROW_H
#define ARROW_H

#include "Model/Item/projectile.h"
#include <QPointF>

class Arrow : public Projectile
{
public:
    Arrow(QPointF,QString);
};

#endif // ARROW_H
