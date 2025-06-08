#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    playerControl = new PlayerControl(this);
    posSliderPressed = false;

    // set file length when ready
    connect(playerControl, &PlayerControl::durationReady, this, [this](const QString &duration) {
        ui->fileLength->setText(duration);
    });
    // set playback positions
    connect(playerControl, &PlayerControl::positionReady, this, [this](const qint64 &position) {
        if (!posSliderPressed) {
            // update slider
            ui->posCtr->setValue((int) 100 * position / playerControl->getLength());
            // update label
            ui->currPos->setText(playerControl->formatTime(position));
        }
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
    QString file = QFileDialog::getOpenFileName(this, tr("Select audio file"), "");   ///
    QUrl fileUrl = QUrl(file);

    playerControl->setMedia(fileUrl);

    // add file to list
    new PlaylistItem(ui->playList, fileUrl);
}

void MainWindow::on_volumeCtr_valueChanged(int value)
{
    playerControl->setVolume(value);
}

void MainWindow::on_posCtr_sliderPressed()
{
    posSliderPressed = true;
}


void MainWindow::on_posCtr_sliderReleased()
{
    posSliderPressed = false;
    playerControl->setPosition(ui->posCtr->sliderPosition());
}

