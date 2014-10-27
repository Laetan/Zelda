#include "spritesheet.h"
#include <QtDebug>
#include <QFile>
#include <QMessageBox>
#include <QCoreApplication>

SpriteSheetManager::SpriteSheetManager(QString s) : QPixmap()
{

    QString exePath = QCoreApplication::applicationDirPath();
    s = exePath  + "/Ressources/sprites/"+s;
    QFile file(s+".png");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString()+" : "+s);
    }
    file.close();
    this->load(s+".png","image/png");
    finder = new SpriteFinder(s);
}

const QPixmap SpriteSheetManager::get(const QString req){

    QPixmap resp ;
    QList<int>pics = finder->find(req);
    resp = this->copy(pics[0],pics[1],32,32);

    return resp;

}
const QPixmap SpriteSheetManager::get(const int ref){

    QString req =finder->findByRef(QString::number(ref));
    return get(req);

}
