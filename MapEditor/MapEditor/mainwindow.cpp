#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    canvas = new Canvas(0,0,960,736,this->ui->canvasView);
    palette = new Palette(0,0,200,800,this->ui->paletteView);
    canvas->setPalette(palette);
    this->ui->canvasView->setScene(canvas);
    this->ui->paletteView->setScene(palette);
    connect(ui->actionSauvegarder_zone,SIGNAL(triggered()), canvas,SLOT(save()));
    connect(ui->actionCharger_zone,SIGNAL(triggered()), canvas,SLOT(load()));
    connect(ui->actionEffacer_Tout,SIGNAL(triggered()), canvas,SLOT(clearAll()));
    connect(ui->actionElements,SIGNAL(triggered()), palette,SLOT(changePaletteToElement()));
    connect(ui->actionEnvironnement,SIGNAL(triggered()), palette,SLOT(changePaletteToEnvironement()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
