#include <QDebug>
#include <QApplication>
#include <QWidget>
#include "qqmusic_api.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget widget;
    QQMusicAPI *api = new QQMusicAPI(&widget);
    api->search("李白", 1);

    widget.show();

    return app.exec();
}
