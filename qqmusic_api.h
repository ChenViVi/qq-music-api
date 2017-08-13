#ifndef QQMUSICAPI_H
#define QQMUSICAPI_H

#include <QObject>
#include <QJsonObject>
#include <QMap>

class QNetworkAccessManager;
class QNetworkRequest;
class QNetworkReply;
class QUrl;

class QQMusicAPI : public QObject
{
    Q_OBJECT
    
public:
    QQMusicAPI(QObject *parent = 0);

    void search(const QString &keyword, const int page);
    QString getKey();

private slots:
    void searchFinished();
    void getKeyFinished();
    
private:
    QNetworkAccessManager *http;
    QString key;
};

#endif
