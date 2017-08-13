#include "qqmusic_api.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

QQMusicAPI::QQMusicAPI(QObject *parent)
        : QObject(parent)
{
    http = new QNetworkAccessManager(this);
}

void QQMusicAPI::search(const QString &keyword, const int page)
{
    QNetworkRequest request;
    request.setUrl(QUrl("http://c.y.qq.com/soso/fcgi-bin/client_search_cp?t=0&aggr=1&lossless=1&cr=1&catZhida=1&format=json&p=1&n=2&w=wss"));
    http->get(request);

    connect(http, SIGNAL(finished(QNetworkReply *)), this, SLOT(searchFinished(QNetworkReply *)));
}

void QQMusicAPI::searchFinished(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
}
