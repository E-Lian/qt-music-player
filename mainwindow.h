#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "PlayerControl.h"
#include "PlaylistItem.h"

#include <QMainWindow>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_playBtn_clicked();

    void on_actionOpen_File_triggered();

    void on_volumeCtr_valueChanged(int value);

    void on_posCtr_sliderPressed();

    void on_posCtr_sliderReleased();

private:
    Ui::MainWindow *ui;
    PlayerControl *playerControl;
    bool posSliderPressed;
};
#endif // MAINWINDOW_H
