#include <QDebug>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include "qqmusic_api.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget widget;
    widget.resize(600, 400);
    QQMusicAPI *api = new QQMusicAPI(&widget);

    QPushButton *btn = new QPushButton("搜索歌曲");
    QLineEdit *edit = new QLineEdit();
    QObject::connect(btn, &QPushButton::clicked, &widget, [=]{
        api->search(edit->text(), 1);
    });

    qDebug() << api->getSongUrl("002gh7iM42KPwh");

    QVBoxLayout *layout = new QVBoxLayout(&widget);
    layout->addWidget(edit);
    layout->addWidget(btn);

    widget.show();

    return app.exec();
}
