#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


#include <QMainWindow>
#include <QFile>
#include <QList>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QUrl>
#include <QWebEnginePage>
#include <QWebChannel>
#include <QTimer>
#include <QFileDialog>
#include <QTime>
#include<QString>
#include<vector>
#include<QInputDialog>
#include<QTcpSocket>
#include "mapchannel.h"
#include "cockpitgrid.h"
#include "cpuplot.h"
class CockpitGrid;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    CockpitGrid *dial;
    CpuPlot *cpu_plot;
    ~MainWindow();
    bool readfromfile();



signals:
    void update(int);



private slots:
    void updateTrack();
    void reloadMap();
    void clear_target_point();

    //new_change
    void updaterealtimetrack();

private slots:

    void on_pushButton_open_file_clicked();

    void on_pushButton_start_clicked();

    void on_comboBox_times_vel_currentIndexChanged(int index);

    void socket_Read_Data();

    void socket_Disconnected();



    void on_pushButton_realtime_display_clicked();

//    void on_btn_change_control_mode_clicked();



    void on_pushButton_clicked();

    void on_pushButton_connect_tcp_clicked();

    void on_pushButton_send_data_clicked();

    void on_pushButton_control_s_clicked();

    void on_play_video_clicked();

//    void on_btn_change_control_mode_clicked();

private:
    Ui::MainWindow *ui;


    void mapWidgetInit();
    QWebChannel *channel;
    MapChannel *mapChannel;

    QList<QString> lines;
    QTimer* timer0;

    //new_change
    QTimer* timer1;

    int LineIndex;
    int LineLength;
    int timeCol;
    int lngCol;
    int latCol;
    int yawCol;

    //new_change
    double TimersVel;

    //new_change 创建套接字以实现tcp通信
    QTcpSocket *socket;


};

#endif // MAINWINDOW_H
