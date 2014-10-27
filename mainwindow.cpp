#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamescene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GameScene *game = new GameScene(ui->graphicsView);
    ui->graphicsView->setScene(game);
}

MainWindow::~MainWindow()
{
    delete ui;
}
