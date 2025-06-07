#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    playerControl = new PlayerControl(this);

    // set file length when ready
    connect(playerControl, &PlayerControl::durationReady, this, [this](const QString &duration) {
        ui->fileLength->setText(duration);
    });
    // set playback position
    connect(playerControl, &PlayerControl::positionReady, this, [this](const qint64 &position) {
        ui->currPos->setText(playerControl->formatTime(position));
        ui->posCtr->setValue((int) 100 * position / playerControl->getLength());
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
        ui->playBtn->setText("Play");
    } else {
        bool tmp = playerControl->play();
        if (tmp) {
            ui->playBtn->setText("Pause");
        }
    }
}


void MainWindow::on_actionOpen_File_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select audio file"), "");   ///
    playerControl->setMedia(QUrl(fileName));

    // show file name
    ui->fileName->setText(playerControl->getName());
}

void MainWindow::on_volumeCtr_valueChanged(int value)
{
    playerControl->setVolume(value);
}
