#include "PlaylistItem.h"

PlaylistItem::PlaylistItem(QListWidget *parent, const QUrl &fileUrl)
    : QListWidgetItem(parent), url(fileUrl) {
    fileName = url.fileName();
    setText(fileName);
}


QUrl PlaylistItem::getUrl() {
    return url;
}

QString PlaylistItem::getName() {
    return fileName;
}
