#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    playerControl = new PlayerControl(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playBtn_clicked()
{
    playerControl->play();

    // show file name and length (maybe not length, we'll see)
    ui->fileName->setText(playerControl->getName());
}

