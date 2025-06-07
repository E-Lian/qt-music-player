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

public:
    explicit PlayerControl(QObject* parent = nullptr);
    bool play();
    void pause();
    void setMedia(QUrl url);
    void setVolume(int volume);
    QString getName();
    QString getLength();
    bool isPlaying();

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
};

#endif // PLAYERCONTROL_H
