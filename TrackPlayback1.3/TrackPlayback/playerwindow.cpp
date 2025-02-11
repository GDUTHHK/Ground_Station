#include "playerwindow.h"
#include "ui_playerwindow.h"

playerwindow::playerwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::playerwindow)
{
    ui->setupUi(this);

    MainPlayerWidget = new VlcWidgetVideo (ui->widget);//播放器界面类  指定显示在具体的父类
       MainPlayerWidget->resize(ui->widget->width(),ui->widget->height());//重新设定大小，如果不重新设定的话，可能无法看到视频
       seek = new VlcWidgetSeek (ui->widget_2);//播放器进度条类
       VolumeSlider = new VlcWidgetVolumeSlider (ui->widget_2);//播放器声音类

       instance = new VlcInstance(VlcCommon::args(), this);//单例模式
       player = new VlcMediaPlayer(instance);//播放控制类
       player->setVideoWidget(MainPlayerWidget);//装载播放器界面类
       MainPlayerWidget->setMediaPlayer(player);//将播放器界面类设置播放控制类
       seek->setMediaPlayer(player);//将进度条装载到播放控制类

       VolumeSlider->setMediaPlayer(player);//播放器声音装载到播放控制类
       VolumeSlider->setVolume(10);//设置初始的声音值


       media = new VlcMedia("rtmp://120.79.189.12/live/livestream", false, instance);//播放视频
       player->open(media);

       connect(ui->btn_start_play_video,&QPushButton::clicked,this,&playerwindow::slot_Start);//注册开始槽函数，点击按钮后播放视频
       connect(ui->btn_stop_video,&QPushButton::clicked,this,&playerwindow::slot_Stop);//注册停止槽函数，点击按钮后停止视频
       connect(ui->btn_pause_video,&QPushButton::clicked,this,&playerwindow::slot_Pause);//注册暂停函数，点击按钮暂停放视频

}

playerwindow::~playerwindow()
{

    delete media;
        delete player;
        delete instance;//析构时，一定要放在media，player的后面。不然会报异常停止的错误


        delete MainPlayerWidget;
        delete seek;



    delete ui;
}

void playerwindow::slot_Start()//视频播放槽函数具体实现
{
    player->play();
}

void playerwindow::slot_Pause()//视频暂停槽函数具体实现
{
    player->pause();
}

void playerwindow::slot_Stop()//视频停止槽函数具体实现
{
    player->stop();
}
