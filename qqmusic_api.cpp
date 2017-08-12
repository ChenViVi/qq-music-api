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
    map["Accept"] = "*/*";
    map["Accept-Language"] = "zh-CN,zh;q=0.8,gl;q=0.6,zh-TW;q=0.4";
    map["Connection"] = "keep-alive";
    map["Content-Type"] = "application/x-www-form-urlencoded";
    map["Host"] = "y.qq.com";
    map["Referer"] = "http://y.qq.com/portal/player.html";
    map["User-Agent"] = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/33.0.1750.152 Safari/537.36";
}
