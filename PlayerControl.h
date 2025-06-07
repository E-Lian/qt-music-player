#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H

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

public:
    explicit PlayerControl(QObject* parent = nullptr);
    bool play();
    void pause();
    void setMedia(QUrl url);
    void setVolume(int volume);
    QString getName();
    QString getLengthString();
    int getLength();
    bool isPlaying();
    QString formatTime(int t);

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    int fileLength;
    int currPos;
};

#endif // PLAYERCONTROL_H
