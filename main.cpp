#include <QDebug>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include "qqmusic_api.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget widget;
    widget.resize(600, 400);
    QQMusicAPI *api = new QQMusicAPI(&widget);

    QPushButton *btn = new QPushButton("搜索歌曲", &widget);
    QObject::connect(btn, &QPushButton::clicked, &widget, [=]{
        api->search("麻痹", 1);
    });
    api->getKey();

    widget.show();

    return app.exec();
}
