#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <QMouseEvent>
#include <QKeyEvent>
#include <QWidget>
#include <QtGui>
#include <QString>

#include "element.h"

class Personnage : public Element  // Classe abstraite
{
public:
    Personnage();
    Personnage(QString, QString);

    // Methods
    void death();

    bool Alive(int life);
    int ReceiveDmg(int dmg);
    void Attack(Personnage &target);
    void Speak();

    //Getter & Setter
    int getDmg() const;
    void setDmg(int value);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);


protected:

    int dmg;
    int x;
    int y;

};

#endif // PERSONNAGE_H
