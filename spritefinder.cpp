#include "spritesheet.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QCoreApplication>
#include <QDir>
#include <QtDebug>

SpriteFinder::SpriteFinder(QString fileName)
{
    QFile file(fileName+".conf");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString()+":"+fileName+".conf");
    }
    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine();
        finder.append(line.split(";"));
    }
    file.close();
    in.reset();
    file.setFileName(fileName+".ref");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString()+":"+fileName+".ref");
    }
    while(!in.atEnd()) {
        QString line = in.readLine();
        refTable.append(line.split(";"));
    }
    file.close();

}
/**
 * @brief SpriteFinder::find Recupère les coordonnées du sprite req dans le sprite sheet
 * @param req
 * @return
 */
QList<int>SpriteFinder::find(const QString req ){
    QList<int> resp ;

    for(int i=0; i < finder.size(); i++){
        QList<QString> row = finder.at(i);
        if(row.size()>2 && req==row.at(2)){
            resp.append(row[0].toInt());
            resp.append(row[1].toInt());
        }
    }
    return resp;
}

QList<QString> SpriteFinder::allPic(){
    QList<QString> resp;
    for(int i=0; i < finder.size(); i++){
        QList<QString> row = finder.at(i);
        if(row.size()>2 && !row[2].isNull() && !row[2].isEmpty())
            resp.append(row[2]);
    }
    return resp;
}

QString SpriteFinder::findByRef(QString ref){
    for(int i =0; i < refTable.size();i++){
        if(refTable[i][0]==ref)
            return refTable[i][1];
    }
    return "";
}
QString SpriteFinder::findRef(const QString obj){
    for(int i =0; i < refTable.size();i++){
        if(refTable[i].size()>1 && refTable[i][1]==obj)
            return refTable[i][0];
    }
    return "";
}
