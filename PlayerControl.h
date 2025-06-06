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
    void play();
    void pause();
    QString getName();
    QString getLength();
    bool isPlaying();

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
};

#endif // PLAYERCONTROL_H
