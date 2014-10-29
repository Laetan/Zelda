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
    Element(QString,QString);

    void update2();
    void move();

    QString getName() const;

    QString getDir() const;

    QString getCurrentDir() const;
    void setCurrentDir(const QString &value);

protected:
    const QString name;
    int speed;
    QString dir;
    QString currentDir;

};

#endif // ELEMENT_H
