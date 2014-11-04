#include "spritesheet.h"
#include <QtDebug>
#include <QFile>
#include <QMessageBox>
#include <QCoreApplication>

SpriteSheetManager::SpriteSheetManager(QString s,QString type) : QPixmap(),type(type)
{

    QString exePath = QCoreApplication::applicationDirPath();
    s = exePath  + "/Ressources/sprites/"+s;
    QFile file(s+".png");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString()+" : "+s+".png");
    }
    file.close();
    this->load(s+".png","image/png");
    finder = new SpriteFinder(s,type);
}

const QPixmap SpriteSheetManager::get(const QString req){

    QPixmap resp ;
    QList<int>pics = finder->find(req);
    QList<int> picSize;
    if(type=="env") picSize = {32,32};
    else if(type=="elem") picSize = finder->picSize(req);

    resp = this->copy(pics[0],pics[1],picSize[0],picSize[1]);

    return resp;

}

const QList<QPixmap> SpriteSheetManager::getAll(const QString req){
    QList<QPixmap> resp;
    QList<int>pics = finder->find(req);
    QList<int> size = finder->picSize(req);
    resp.append(this->copy(pics[0],pics[1],size[0],size[1]));

    return resp;

}
