#include "projectile.h"

Projectile::Projectile(QString dir): Element("projectile")
{
    this->dir=dir;
    this->setZValue(11);

}
