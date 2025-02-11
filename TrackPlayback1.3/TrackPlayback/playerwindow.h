#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>

#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>
#include <VLCQtCore/Common.h>

#include <VLCQtWidgets/WidgetVideo.h>
#include <VLCQtWidgets/WidgetSeek.h>
#include <VLCQtWidgets/WidgetVolumeSlider.h>

namespace Ui {
class playerwindow;
}

class playerwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit playerwindow(QWidget *parent = nullptr);
    ~playerwindow();

private slots:
    void slot_Start();
    void slot_Pause();
    void slot_Stop();

private:
    Ui::playerwindow *ui;
    VlcWidgetVideo *MainPlayerWidget;
        VlcInstance *instance;
        VlcMedia *media;
        VlcMediaPlayer *player;
        VlcWidgetSeek *seek;
        VlcWidgetVolumeSlider *VolumeSlider;
};

#endif // PLAYERWINDOW_H
