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

}
