#include "projectile.h"

Projectile::Projectile(QString dir, QString type): Element(type)
{
    this->dir=dir;
    this->setZValue(11);

}
