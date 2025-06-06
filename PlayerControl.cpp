#include "PlayerControl.h"


PlayerControl::PlayerControl(QObject* parent)
    : QObject(parent) {
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
}

void PlayerControl::play() {
    QDir dir;
    QString relativePath = "../../media files/Sufjan Stevens - Carrie & Lowell (10th Anniversary Edition) - 01 Death with Dignity.wav";  //
    QString absolutePath = dir.absoluteFilePath(relativePath);
    player->setSource(QUrl::fromLocalFile(absolutePath));
    player->play();
}

QString PlayerControl::getName() {
    QUrl sourceUrl = player->source();
    QString fileName = sourceUrl.fileName();
    qDebug() << "Playing file:" << fileName;
    return fileName;
}


