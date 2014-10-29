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

    QString getDir() const;
    void setDir(const QString &value);

protected:
    QString dir;
    const QString name;

};

#endif // ELEMENT_H
