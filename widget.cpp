#include "widget.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMediaPlayer>
#include <QStringList>
#include "qqmusic_api.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QQMusicAPI *api = new QQMusicAPI(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    QListWidget *list = new QListWidget();
    QPushButton *btn = new QPushButton("搜索歌曲");
    QLineEdit *edit = new QLineEdit();
    QMediaPlayer *mediaplay = new QMediaPlayer();

    layout->addWidget(edit);
    layout->addWidget(btn);
    layout->addWidget(list);

    QObject::connect(api, &QQMusicAPI::searchList, this, [=](QString text, QString url){
        new QListWidgetItem(text + "\n" + url, list);
    });

    QObject::connect(btn, &QPushButton::clicked, this, [=]{
        api->search(edit->text(), 1);
        list->clear();
    });

    QObject::connect(list, &QListWidget::currentRowChanged, this, [=](int current){

    });
}
