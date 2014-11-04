#include "savewindow.h"
#include "ui_savewindow.h"
#include <QtDebug>
#include <QCoreApplication>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

SaveWindow::SaveWindow(QList<QList<QString> > d,QList<QList<QString> > e,QWidget *parent) :
    QDialog(parent),
    data(d),
    elemData(e),
    ui(new Ui::SaveWindow)
{
    ui->setupUi(this);
}

SaveWindow::~SaveWindow()
{
    save();
    delete ui;
}

void SaveWindow::save(){
    QString fileName = this->ui->lineEdit->text();
    if(result()==0 || fileName==""){
        QMessageBox::information(0, "error", "Zone non sauvegardée");
        return;
    }
    QString exePath = QCoreApplication::applicationDirPath();
    fileName = exePath  + "/Ressources/zones/"+fileName;
    QFile fileEnv(fileName+".zn");
    QFile fileElem(fileName+".el");
    if(fileEnv.exists() || fileElem.exists()){
        QMessageBox confirm;
        confirm.information(0, "error", "Une zone de ce nom existe déja.");
         if(confirm.result()==0)
             return;

    }

    if(!fileEnv.open(QIODevice::WriteOnly)) {
        QMessageBox::information(0, "error", fileEnv.errorString()+":"+fileName+".zn");
        return;
    }
    if(!fileElem.open(QIODevice::WriteOnly)) {
        QMessageBox::information(0, "error", fileElem.errorString()+":"+fileName+".el");
        return;
    }
    QTextStream out(&fileEnv);
    for(int x = 0; x < data.size(); x++){
        for(int y = 0; y < data[x].size(); y++){
            out<<data[x][y];
            if(y+1<data[x].size()) out<<";";
        }
        if(x+1<data.size()) out<<"\n";
    }

    out.reset();
    out.setDevice(&fileElem);
    for(int x = 0; x < elemData.size(); x++){
        for(int y = 0; y < elemData[x].size(); y++){
            out<<elemData[x][y];
            if(y+1<elemData[x].size()) out<<";";
        }
        if(x+1<elemData.size()) out<<"\n";
    }
    QMessageBox::information(0, "error", fileName+" is saved");
    return;
}
