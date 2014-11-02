#include "Heart.h"
#include <QString>
#include <QtDebug>
#include <QPixmap>
#include <QCoreApplication>


Heart::Heart()
{
    Zelda();
    QString path = QCoreApplication::applicationDirPath()+"/Ressource/sprites/coeur01.png";
    QString path02 = QCoreApplication::applicationDirPath()+"/Ressource/sprites/coeur02.png";
    QString path03 = QCoreApplication::applicationDirPath()+"/Ressource/sprites/zelda_death_right.png";
    listLifePoint.append(QPixmap(path));
    listLifePoint.append(QPixmap(path02));
    listLifePoint.append(QPixmap(path03));
    listLifePoint.append(QPixmap(path));
    listLifePoint.append(QPixmap(path));
    listLifePoint.append(QPixmap(path));
    listLifePoint.append(QPixmap(path));
    listLifePoint.append(QPixmap(path));
    listLifePoint.append(QPixmap(path));
    listLifePoint.append(QPixmap(path));
    listLifePoint.append(QPixmap(path));
    listLifePoint.append(QPixmap(path));
    listLifePoint.append(QPixmap(path));
    listLifePoint.append(QPixmap(path));
    listLifePoint.append(QPixmap(path));
    listLifePoint.append(QPixmap(path));
}

void Heart::displayLifePoint(int life)
{
    //Boucle pour afficher tous les coeurs
    for(int i=0; i<=life; i++)
    {
        qDebug()<<i;
        this->setPixmap(this->getListLifePoint()[i]);
        this->setPos((i*20),0);
        this->isVisible();
    }

//    this->setPixmap(this->getListLifePoint()[0]);
//    this->setPos(20,0);
//    this->setPixmap(this->getListLifePoint()[1]);
//    this->setPos(40,0);
//    this->setPixmap(this->getListLifePoint()[2]);
//    this->setPos(60,0);

}
QList<QPixmap> Heart::getListLifePoint() const
{
    return listLifePoint;
}
