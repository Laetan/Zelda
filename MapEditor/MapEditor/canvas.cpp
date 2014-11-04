#include "canvas.h"
#include "spritesheet.h"
#include "savewindow.h"
#include <QtDebug>
#include <QFileDialog>
#include <QCoreApplication>
#include <QTextStream>
#include <QMessageBox>

Canvas::Canvas(QObject *parent) :
    QGraphicsScene(0,0,960,736,parent),
    ssm("/Ressources/sprites/sprite_zone","env"),
    elemSS("sprite_monster1","elem"),grid(new Grid())
{
    this->addItem(grid);

    for(int x=0; x<30; x++){
        QList<QString> col;
        for(int y = 0; y < 23; y++)
            col.append("0");
        data.append(col);
    }
}

Canvas::Canvas(int posx,int posy,int width,int height,QObject *parent) :
    QGraphicsScene(posx,posy,width,height,parent),
    ssm("sprite_zone","env"),
    elemSS("sprite_monster1","elem"),grid(new Grid())
{
    this->addItem(grid);

    for(int x=0; x<30; x++){
        QList<QString> col;
        for(int y = 0; y < 23; y++)
            col.append("0");
        data.append(col);
    }
}

void Canvas::setPalette(Palette*p){
    palette=p;
}

void Canvas::drawCanvas(){
    this->clear();
    elemList.clear();
    grid = new Grid();
    this->addItem(grid);
    for(int x = 0; x < ZONE_WIDTH_MAX; x++){
        for(int y = 0; y < ZONE_HEIGTH_MAX; y++){
            QString label = ssm.finder->findByRef(data[x][y]);
            if(label=="empty")
                continue;
            QPixmap pix = ssm.get(label);
            QGraphicsPixmapItem *pixItem= new QGraphicsPixmapItem(pix);
            pixItem->setPos(x*SPRITE_WIDTH,y*SPRITE_HEIGTH);
            this->addItem(pixItem);
        }
    }

    foreach(QList<QString> elem,elemData){
        QGraphicsPixmapItem *pixElem = new QGraphicsPixmapItem();
        pixElem->setPixmap(elemSS.get(elem[2]));
        pixElem->setPos(elem[0].toInt(),elem[1].toInt());
        elemList.append(pixElem);
        this->addItem(pixElem);

    }

}

void Canvas::mousePressEvent(QGraphicsSceneMouseEvent *mouse){
    mouseAction(mouse->scenePos(),mouse->button());
}

void Canvas::mouseMoveEvent(QGraphicsSceneMouseEvent *mouse){
    mouseAction(mouse->scenePos(),mouse->button());
}

void Canvas::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse){
    if(mouse->button()==Qt::LeftButton|| mouse->button()==Qt::RightButton)
        painting = false;
}

void Canvas::mouseAction(QPointF pos, Qt::MouseButton button){
    QString sel = palette->getSelectedPixRef();
    if(sel=="") return;

    if(palette->getCurrentPalette()==Palette::ENVIRONNEMENT){
        if(!addEnv(pos,button, sel)) return;
    }
    else if(palette->getCurrentPalette()==Palette::ELEMENT && button==Qt::LeftButton){
        if(!addElement(pos,sel)) return;
    }
    else if(palette->getCurrentPalette()==Palette::ELEMENT && button==Qt::RightButton)
       if(!delElement(pos))  return;
    drawCanvas();
}

bool Canvas::addEnv(QPointF pos, Qt::MouseButton button, QString sel){
    int posX = pos.x()/32;
    int posY = pos.y()/32;
    if(button==Qt::LeftButton){
        painting = true;
        if(data[posX][posY]==sel) return false;
        data[posX][posY]=sel;
        painting = true;
    }else if(button==Qt::RightButton){
        if(data[posX][posY]=="0") return false;
        data[posX][posY]="0";
    }
    else if(button==Qt::NoButton){
        if(painting && data[posX][posY]!=sel)
            data[posX][posY]=sel;
        else if(!painting && data[posX][posY]!="0")
            data[posX][posY]="0";
        else return false;
    }
    return true;
}

bool Canvas::addElement(QPointF pos, QString sel){
    int posX = pos.x();
    int posY = pos.y();

    QList<int> hitbox = elemSS.finder->picSize(sel);
    posX-=hitbox[0]/2;
    posY-=hitbox[1]/2;

    QGraphicsPixmapItem *pix = new QGraphicsPixmapItem();
    pix->setPixmap(elemSS.get(sel));
    pix->setPos(posX,posY);
    this->addItem(pix);
    foreach (QGraphicsPixmapItem *item, elemList) {
        if(item->collidesWithItem(pix)){
            this->removeItem(pix);
            return false;
        }
    }

    elemList.append(pix);
    QList<QString> temp;
    temp <<QString::number(posX)<<QString::number(posY)<<sel;
    elemData<<temp;
    return true;
}

bool Canvas::delElement(QPointF pos){
    foreach(QList<QString> elem,elemData){
        QList<int> elemSize = elemSS.finder->picSize(elem[2]);
        int x = elem[0].toInt();
        int y = elem[1].toInt();
        if(pos.x()>=x && pos.x()<=x+elemSize[0]
                && pos.y()>=y && pos.y()<=y+elemSize[1]){
            elemData.removeOne(elem);
            return true;
        }
    }
    return false;
}

void Canvas::save(){
    qDebug()<<"Saving...";
    SaveWindow w(data,elemData);
    w.exec();
}

void Canvas::load(){
    qDebug()<<"Loading...";
    QFileDialog w;
    QString zonesDir = QCoreApplication::applicationDirPath()+"/Ressources/zones";
    w.setDirectory(QDir(zonesDir));
    w.exec();
    QString fileName(w.selectedFiles()[0]);
    if(!fileName.endsWith(".zn")){
        QMessageBox::information(0, "error", "Mauvaise extension. Doit être un .zn");
        return;
    }
    QFile loadFile(fileName);
    if(!loadFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", loadFile.errorString()+":"+fileName);
    }
    data.clear();
    elemData.clear();
    QTextStream in(&loadFile);
    while(!in.atEnd()) {
        QString line = in.readLine();
        data.append(line.split(";"));
    }
    fileName.chop(2);
    fileName+="el";
    QFile elemFile(fileName);
    if(elemFile.exists()){
        if(!elemFile.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", elemFile.errorString()+":"+fileName);
        }
        in.reset();
        in.setDevice(&elemFile);
        while(!in.atEnd()) {
            QString line = in.readLine();
            elemData.append(line.split(";"));
        }
    }

    drawCanvas();
}

void Canvas::clearAll(){
    for(int x = 0; x < data.size(); x++)
        for(int y = 0; y < data[x].size(); y++)
            data[x][y]="0";
    elemData.clear();
    drawCanvas();
}
