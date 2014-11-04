#ifndef SSENV_H
#define SSENV_H

#include <QPixmap>

class SpriteFinder
{
public:
    SpriteFinder(QString,QString);
    QList<int> find(const QString);
    QList<QList<int> > findAll(const QString);
    QString findByRef(QString);
    QString findRef(const QString);
    const QList<int> picSize(const QString);
    QList<QString> allPic();
private:
    QList<QList<QString> > refTable;
    QList<QList<QString> > finder;
    QString type;
};

class SpriteSheetManager : public QPixmap
{
public:
    SpriteSheetManager(QString, QString);

    const QPixmap get(const QString);
    const QList<QPixmap> getAll(const QString);
    const QString type;
    SpriteFinder* finder;
};




#endif // SSENV_H
