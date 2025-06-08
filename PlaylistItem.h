#ifndef PLAYLISTITEM_H
#define PLAYLISTITEM_H

#include <QListWidgetItem>
#include <QUrl>

class PlaylistItem: public QListWidgetItem {
public:
    explicit PlaylistItem(QListWidget *parent, const QUrl &fileUrl);
    QUrl getUrl();
    QString getName();

private:
    QUrl url;
    QString fileName;
};

#endif // PLAYLISTITEM_H
