#ifndef SSENV_H
#define SSENV_H

#include <QPixmap>

/**
 * @brief Classes de gestion des sprites sheet
 */
class SpriteFinder
{
public:
    SpriteFinder(QString);
    QList<int> find(const QString);
    QString findByRef(QString);
    QString findRef(const QString);
    QList<QString> allPic();
private:
    QList<QList<QString> > refTable;
    QList<QList<QString> > finder;
};

class SpriteSheetManager : public QPixmap
{
public:
    SpriteSheetManager(QString);

    const QPixmap get(const QString);
    const QPixmap get(const int);
    SpriteFinder* finder;
};




#endif // SSENV_H
