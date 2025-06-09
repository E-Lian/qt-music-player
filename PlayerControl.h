#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H

#include "PlaylistItem.h"

#include <QObject>
#include <QDir>
#include <QtMultimedia/QMediaPlayer>
#include <QAudioOutput>
#include <QAudioDevice>

class PlayerControl: public QObject {
    Q_OBJECT

signals:
    void durationReady(const QString &d);
    void positionReady(const qint64 &d);
    void mediaEnd();

public:
    explicit PlayerControl(QObject* parent = nullptr);
    bool play();
    void pause();
    void setMedia(PlaylistItem *media);
    void setVolume(int volume);
    void setPosition(int pos);
    PlaylistItem* getCurr();
    QString getName();
    QString getLengthString();
    qint64 getLength();
    bool isPlaying();
    QString formatTime(int t);

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    PlaylistItem *curr;
    int fileLength;
    int currPos;
};

#endif // PLAYERCONTROL_H
