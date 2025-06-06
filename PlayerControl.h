#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H

#include <QObject>
#include <QDir>
#include <QtMultimedia/QMediaPlayer>
#include <QAudioOutput>
#include <QAudioDevice>

class PlayerControl: public QObject {
    Q_OBJECT

public:
    explicit PlayerControl(QObject* parent = nullptr);
    void play();
    QString getName();

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
};

#endif // PLAYERCONTROL_H
