#ifndef PEWPEW_H
#define PEWPEW_H

#include "Model/Item/projectile.h"
#include <QPointF>

class Pewpew : public Projectile
{
public:
    Pewpew(QPointF,QString);
};
#endif // PEWPEW_H
