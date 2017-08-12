#ifndef QQMUSICAPI_H
#define QQMUSICAPI_H

#include <QObject>
#include <QJsonObject>
#include <QMap>

class QNetworkAccessManager;
class QNetoworkRequest;
class QNetworkReply;
class QUrl;

class QQMusicAPI : public QObject
{
    Q_OBJECT
    

public:
    QQMusicAPI(QObject *parent = 0);

private:
    QNetworkAccessManager *http;
    QMap<QString, QString> map;
};

#endif
