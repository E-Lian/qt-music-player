#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    playerControl = new PlayerControl(this);
    connect(playerControl, &PlayerControl::durationReady, this, [this](const QString &durationStr) {
        ui->fileLength->setText(durationStr);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playBtn_clicked()
{
    if (playerControl->isPlaying()) {
        playerControl->pause();
    } else {
        playerControl->play();

        // show file name and length
        ui->fileName->setText(playerControl->getName());
    }
}

