#include <QDebug>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMediaPlayer>
#include <QStringList>
#include "qqmusic_api.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget widget;
    widget.resize(800, 600);
    QQMusicAPI *api = new QQMusicAPI(&widget);

    QListWidget *list = new QListWidget();
    QPushButton *btn = new QPushButton("搜索歌曲");
    QLineEdit *edit = new QLineEdit();

    QVBoxLayout *layout = new QVBoxLayout(&widget);
    layout->addWidget(edit);
    layout->addWidget(btn);
    layout->addWidget(list);

    QObject::connect(api, &QQMusicAPI::searchList, &widget, [&](QString text, QString url){
        new QListWidgetItem(text + "\n" + url, list);
    });

    QObject::connect(btn, &QPushButton::clicked, &widget, [=]{
        api->search(edit->text(), 1);
        list->clear();
    });

    QMediaPlayer *mediaplay = new QMediaPlayer(&widget);

    QObject::connect(list, &QListWidget::currentRowChanged, &widget, [&](int current){

    });

    widget.show();

    return app.exec();
}
