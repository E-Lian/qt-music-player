#include "PlayerControl.h"


PlayerControl::PlayerControl(QObject *parent) : QObject(parent) {
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // update duration when it's changed
    connect(player, &QMediaPlayer::durationChanged, this, [this](qint64 durationMs) {
        fileLength = durationMs;
        QString length = getLengthString();
        emit durationReady(length);
    });
    // update playback position
    connect(player, &QMediaPlayer::positionChanged, this, [this](qint64 ms) {
        currPos = ms;
        emit positionReady(ms);
    });
    // reminds system to play next file
    connect(player, &QMediaPlayer::mediaStatusChanged, this, [this](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia) {
            emit mediaEnd();
        }
    });
}

bool PlayerControl::play() {
    player->play();
    return player->isPlaying();
}

void PlayerControl::pause() {
    player->pause();
}

void PlayerControl::setMedia(PlaylistItem *media) {
    player->setSource(media->getUrl());
    curr = media;
}

void PlayerControl::setVolume(int volume) {
    float value = ((float) volume) / 100;
    audioOutput->setVolume(value);
}

// sets playback position
// pos: position of slider (max 100)
void PlayerControl::setPosition(int pos) {
    qint64 value = pos * getLength() / 100;
    player->setPosition(value);
}

PlaylistItem* PlayerControl::getCurr() {
    return curr;
}

QString PlayerControl::getName() {
    QUrl sourceUrl = player->source();
    QString fileName = sourceUrl.fileName();
    return fileName;
}

QString PlayerControl::getLengthString() {
    int l = player->duration();
    return formatTime(l);
}

qint64 PlayerControl::getLength() {
    return fileLength;
}

QString PlayerControl::formatTime(int t)  {
    int totalSeconds = t / 1000;
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    return QString("%1:%2")
        .arg(minutes, 2, 10, QLatin1Char('0'))
        .arg(seconds, 2, 10, QLatin1Char('0'));
}

bool PlayerControl::isPlaying() {
    return player->isPlaying();
}
