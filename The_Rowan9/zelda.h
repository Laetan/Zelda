#ifndef ZELDA_H
#define ZELDA_H

#include "personnage.h"
#include <QTimer>
#include <QObject>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class Zelda : public Personnage
{
public:
    //Constructor & Destructor
    Zelda();
    Zelda(QString);

    //Methods
    void death();
    void setDeath();
    void setAnimation();

    // Getter & Setter
    QList<QPixmap> getListAnimation() const;

    QList<QPixmap> getListDeath() const;

protected:
    QPixmap picture;
    QTimer timer;
    QList<QPixmap> listAnimation;
    QList<QPixmap> listDeath;

};

#endif // ZELDA_H
