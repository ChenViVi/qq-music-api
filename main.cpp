#include <QDebug>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include "qqmusic_api.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget widget;
    widget.resize(600, 400);
    QQMusicAPI *api = new QQMusicAPI(&widget);

    //qDebug() << api->getSongUrl("002gh7iM42KPwh");

    QListWidget *list = new QListWidget();
    QPushButton *btn = new QPushButton("搜索歌曲");
    QLineEdit *edit = new QLineEdit();
    QObject::connect(btn, &QPushButton::clicked, &widget, [=]{
        api->search(edit->text(), 1);
        list->clear();
    });

    QVBoxLayout *layout = new QVBoxLayout(&widget);
    layout->addWidget(edit);
    layout->addWidget(btn);
    layout->addWidget(list);

    QObject::connect(api, &QQMusicAPI::searchList, &widget, [=](QString text){
        new QListWidgetItem(text, list);
    });

    widget.show();

    return app.exec();
}
