#ifndef ELEMENT_H
#define ELEMENT_H

#include <QWidget>
#include <QtGui>
#include <QGraphicsPixmapItem>
#include <QString>

class Element : public QGraphicsPixmapItem
{
public:
    Element();
    Element(QString, QString);

    void update2();
    void move();
    void moveMonster();

    void death();

    // Getter & Setter
    QString getDir() const;
    void setDir(const QString &value);

    QString getName() const;

    int getLife() const;
    void setLife(int value);

protected:
    int life;
    QString dir;
    int pas;
    const QString name;

};

#endif // ELEMENT_H
