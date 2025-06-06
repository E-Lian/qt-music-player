#include "PlayerControl.h"


PlayerControl::PlayerControl(QObject* parent)
    : QObject(parent) {
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // update duration when it's changed
    connect(player, &QMediaPlayer::durationChanged, this, [this](qint64 durationMs) {
        QString formatted = getLength();
        emit durationReady(formatted);
    });
}

void PlayerControl::play() {
    if (!player->source().isValid()) {
        QDir dir;
        QString relativePath = "../../media files/Sufjan Stevens - Carrie & Lowell (10th Anniversary Edition) - 01 Death with Dignity.wav";  //
        QString absolutePath = dir.absoluteFilePath(relativePath);
        player->setSource(QUrl::fromLocalFile(absolutePath));
        player->play();
    } else {
        player->play();
    }

}

void PlayerControl::pause() {
    player->pause();
}

QString PlayerControl::getName() {
    QUrl sourceUrl = player->source();
    QString fileName = sourceUrl.fileName();
    return fileName;
}

QString PlayerControl::getLength() {
    int l = (int) player->duration();
    int totalSeconds = l / 1000;
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    return QString("%1:%2")
        .arg(minutes, 2, 10, QLatin1Char('0'))
        .arg(seconds, 2, 10, QLatin1Char('0'));
}

bool PlayerControl::isPlaying() {
    return player->isPlaying();
}
