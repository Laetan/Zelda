#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <QMouseEvent>
#include <QKeyEvent>
#include <QWidget>
#include <QtGui>
#include <QString>

#include "Model/element.h"

/**
 * @brief Classe de base pour les personnages
 */
class Personnage : public Element  // Classe abstraite
{
public:
    Personnage();
    Personnage(QString,QString);

    // Methods

    //Getter & Setter
    int getLife() const;
    void setLife(int value);


protected:
    int life;
    int dmg;

};

#endif // PERSONNAGE_H
