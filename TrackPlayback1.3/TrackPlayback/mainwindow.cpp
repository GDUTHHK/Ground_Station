#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonObject>
#include <QJsonParseError>
#include<QInputDialog>
#include<QThread>
#include<qprocess.h>
#include<string>
#include<QString>
#include<QInputDialog>
#include<iostream>
#include <QDateTime>
#include <QFileDialog>
#include <demuxthread.h>
#include <iostream>
#include <QMessageBox>
#include <qpalette.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

static DemuxThread dt ;

//用于存储无人艇发送过来的经纬度航向角等数据
std::vector<std::vector<double>> lonlatheading(3,std::vector<double>(3, 0));

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui -> setupUi(this);

    //地面站总体色彩的设置
    QPalette palette;
    QColor base(Qt::darkGray);
    palette.setColor( QPalette::Window, base.dark( 130 ) );
    palette.setColor( QPalette::WindowText, base.light( 200 ) );
    setPalette(palette);

    //socket通信
    socket = new QTcpSocket();
    QObject::connect(socket, &QTcpSocket::readyRead, this, &MainWindow::socket_Read_Data);
    QObject::connect(socket, &QTcpSocket::disconnected, this, &MainWindow::socket_Disconnected);


    //实例化一个cpu监控表，并通过布局器将其放在mainwindow上
    cpu_plot = new CpuPlot();
    ui->layout_for_dial->addWidget(cpu_plot);
    //实例化一个仪表控件对象，并通过布局器将其放在mainwindow上
    dial =  new CockpitGrid();
    ui->layout_for_dial->addWidget(dial);

    //地图初始化
    mapWidgetInit();

    //计时器
    timer0 = new QTimer(this);
    connect(this->timer0,&QTimer::timeout,this,&MainWindow::updateTrack);

    //timer1用于反复读取无人艇发送来的经纬度航向角等数据
    timer1 = new QTimer(this);
    connect(this->timer1,&QTimer::timeout,this,&MainWindow::updaterealtimetrack);
    dt.Start();
    startTimer(40);

    //设置一开始按钮全部不可按
    this -> ui -> pushButton_start -> setEnabled(false);
    this -> ui -> comboBox_times_vel -> setEnabled(false);
    this -> ui -> pushButton_control_s -> setEnabled(false);
    this -> ui -> pushButton_send_data -> setEnabled(false);
    this->ui->btn_change_control_mode -> setEnabled(true);
    this -> ui -> pushButton -> setEnabled(false);

}

MainWindow::~MainWindow()
{

    channel -> deregisterObject(mapChannel);
    dt.Close();
    delete ui;
}

//存储从在线地图上得到的经纬度坐标数据
std::vector<std::vector<float>>gpssave;

//存储经纬度坐标
void savegps(float lng,float lat)
{
    gpssave.push_back({lng,lat});
}

//初始化百度地图
void MainWindow::mapWidgetInit()
{
    channel = new QWebChannel(this);
    mapChannel = new MapChannel(this);
    channel -> registerObject("passId",mapChannel);
    this -> ui -> widget_map -> page() -> setWebChannel(channel);

    QDir temDirs("/home/hhk/ffmpeg/TrackPlayback1.3/onlineMap/map.html");                       //relative path
    QString filePath = temDirs.absolutePath();                  //transform into absolutepath
    this -> ui -> widget_map -> load(QUrl("file:///"+filePath));    //qurl only accept absolutepath

    connect(mapChannel,&MapChannel::reloadMapClicked,this,&MainWindow::reloadMap);

    connect(mapChannel,&MapChannel::pointsCome,[](int index, float lng, float lat)               //此处接收从地图上传来的目标点经纬度
    {
        /*川改内容*/
//        gpssave.clear();

        qDebug()<<index<<QString::number(lng,'f',7)<<QString::number(lat,'f',7);

        savegps(lng,lat);   //将坐标推入数组中，以供接下来发送给船使用

    });
}

bool MainWindow::readfromfile()
{

    QString path = QFileDialog::getOpenFileName(this,"Open","./","TXT(*.txt *.csv)");
    if(path.isEmpty() == false)
    {
        QFile file(path);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return false;
        }

        lines.clear();
        LineIndex = 0;
        this -> mapChannel -> clearTrack();

        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();  //读取一行
            lines.append(line);  //在列表尾部添加
        }
        file.close();
        LineLength = lines.length();

        QString line = lines.at(0);
        QStringList subs = line.split(",");
        this -> ui -> label_time_value -> setText(subs.at(timeCol));
        this -> ui -> label_lng_value -> setText(subs.at(lngCol));
        this -> ui -> label_lat_value -> setText(subs.at(latCol));
        this -> ui -> label_yaw_value -> setText(subs.at(yawCol));

        mapChannel -> panTo(subs.at(lngCol).toDouble(),subs.at(latCol).toDouble());

        return true;
    }
    else {
        return false;
    }
}

void MainWindow::updateTrack()
{
    if(LineIndex < LineLength)
    {
        QString line = lines.at(LineIndex);
        line  = line.trimmed();     //返回值为去除了开头和结尾空白的字符串
        QStringList subs = line.split(",");
        double lng = subs.at(lngCol).toDouble();
        double lat = subs.at(latCol).toDouble();
        double yaw = subs.at(yawCol).toDouble();
        mapChannel->updateBoatPos(lng,lat,yaw);
        QDateTime current_time = QDateTime::currentDateTime();     //实现在地图上实时显示船的位置和轨迹的函数，传入的是经纬度和航向角
        QString StrCurrentTime = current_time.toString("yyyy/MM/dd hh:mm:ss.zzz ddd");
        QString qlng = QString(" %1").arg(lng);
        QString qlat = QString(" %1").arg(lat);
        QString qyaw = QString(" %1").arg(yaw);
        this -> ui -> label_time_value -> setText(StrCurrentTime);
        this -> ui -> label_lng_value -> setText(qlng);
        this -> ui -> label_lat_value -> setText(qlat);
        this -> ui -> label_yaw_value -> setText(qyaw);

        LineIndex++;
    }
    else
    {
        this -> timer0 -> stop();
        this -> ui -> pushButton_start -> setText("开始回放");
        this -> ui -> pushButton_start -> setEnabled(false);
        this -> ui -> comboBox_times_vel -> setEnabled(false);
    }
}

void MainWindow::on_pushButton_open_file_clicked()
{

    timeCol = 3;
    lngCol = 0;
    latCol = 1;
    yawCol = 2;
    if(readfromfile())
    {
        QMessageBox::information(this,"成功","文件打开成功,请检查实时数据是否正确!");
        this -> ui -> pushButton_start -> setEnabled(true);
        this -> ui -> comboBox_times_vel -> setEnabled(true);
    }
    else {
        //this->close();
        QMessageBox::critical(this,"错误","文件打开失败，请重试!");
    }
}

void MainWindow::on_pushButton_start_clicked()  //开始
{
    if(this -> ui -> pushButton_start -> text() == "开始回放")
    {
        switch(this -> ui -> comboBox_times_vel  -> currentIndex())
        {
        case 0:
            this -> TimersVel = 1;
            break;
        case 1:
            this -> TimersVel = 1.25;
            break;
        case 2:
            this -> TimersVel = 1.5;
            break;
        case 3:
            this -> TimersVel = 2;
            break;
        case 4:
            this -> TimersVel = 3;
            break;
        case 5:
            this -> TimersVel = 5;
            break;
        case 6:
            this -> TimersVel = 10;
            break;
        case 7:
            this -> TimersVel = 15;
            break;
        default:
            break;
        }
        this -> timer0 -> start(int(1000/TimersVel));

        this -> ui -> pushButton_start -> setText("停止回放");
    }
    else {
        this -> timer0 -> stop();
        this -> ui -> pushButton_start -> setText("开始回放");
    }

}

void MainWindow::on_comboBox_times_vel_currentIndexChanged(int index)
{
    switch(index)
    {
    case 0:
        this -> TimersVel = 1;
        break;
    case 1:
        this -> TimersVel = 1.25;
        break;
    case 2:
        this -> TimersVel = 1.5;
        break;
    case 3:
        this -> TimersVel = 2;
        break;
    case 4:
        this -> TimersVel = 3;
        break;
    case 5:
        this -> TimersVel = 5;
        break;
    case 6:
        this -> TimersVel = 10;
        break;
    case 7:
        this -> TimersVel = 15;
        break;
    default:
        break;
    }
    if(this -> ui -> pushButton_start -> text() == "停止回放")
        this -> timer0 ->start(int(1000/TimersVel));
}

void MainWindow::clear_target_point()
{
}

//接收到地图给的信号后   重新加载地图
void MainWindow:: reloadMap()
{

    this -> ui -> widget_map -> load(QUrl("file:////home/hhk/ffmpeg/TrackPlayback1.3/onlineMap/map.html"));
}

void MainWindow::on_pushButton_realtime_display_clicked()
{
    QProcess process(this);
    QString str = "C:/tmp/VLC/vlc.exe";
    process.startDetached(str);

}

////全局路径规划相关模块
//cv::Mat rasterize_map(const cv::Mat& map) {
//    // 定义栅格化后的地图大小，和初始化坐标点全为0
//        cv::Mat raster = cv::Mat::zeros(map.rows, map.cols, CV_8UC1);

//        // 遍历原始地图中所有像素点
//        for (int i = 0; i < map.rows; ++i) {
//            for (int j = 0; j < map.cols; ++j) {
//                // 取出该坐标点的 BGR 三个通道值
//                unsigned char b = map.at<cv::Vec3b>(i, j)[0];
//                unsigned char g = map.at<cv::Vec3b>(i, j)[1];
//                unsigned char r = map.at<cv::Vec3b>(i, j)[2];
//                // 计算灰度值
//                unsigned char gray = 0.299 * r + 0.587 * g + 0.114 * b;

//                // 若该坐标点灰度值在 threshold范围内，表示该点为空闲区域，赋值为255
//                if (gray< 210 && gray > 200) {
//                    raster.at<unsigned char>(i, j) = 255;
//                }
//                // 若该坐标点灰度值大于等于 threshold，表示该点为障碍物区域，赋值为0
//                else {
//                    raster.at<unsigned char>(i, j) = 0;
//                }
//            }
//        }
//        return raster;
//}

////全局路径规划相关模块(用于qimage转cv::mat)
//inline cv::Mat QImageToCvMat( const QImage &inImage, bool inCloneImageData = true )
//{
//    switch ( inImage.format() )
//    {
//    // 8-bit, 4 channel
//    case QImage::Format_ARGB32:
//    case QImage::Format_ARGB32_Premultiplied:
//    {
//        cv::Mat  mat( inImage.height(), inImage.width(),
//                      CV_8UC4,
//                      const_cast<uchar*>(inImage.bits()),
//                      static_cast<size_t>(inImage.bytesPerLine())
//                      );

//        return (inCloneImageData ? mat.clone() : mat);
//    }

//    // 8-bit, 3 channel
//    case QImage::Format_RGB32:
//    case QImage::Format_RGB888:
//    {
//        if ( !inCloneImageData )
//        {
//            qWarning() << "CVS::QImageToCvMat() - Conversion requires cloning because we use a temporary QImage";
//        }

//        QImage   swapped = inImage;

//        if ( inImage.format() == QImage::Format_RGB32 )
//        {
//            swapped = swapped.convertToFormat( QImage::Format_RGB888 );
//        }

//        swapped = swapped.rgbSwapped();

//        return cv::Mat( swapped.height(), swapped.width(),
//                        CV_8UC3,
//                        const_cast<uchar*>(swapped.bits()),
//                        static_cast<size_t>(swapped.bytesPerLine())
//                        ).clone();
//    }

//    // 8-bit, 1 channel
//    case QImage::Format_Indexed8:
//    {
//        cv::Mat  mat( inImage.height(), inImage.width(),
//                      CV_8UC1,
//                      const_cast<uchar*>(inImage.bits()),
//                      static_cast<size_t>(inImage.bytesPerLine())
//                      );

//        return (inCloneImageData ? mat.clone() : mat);
//    }

//    default:
//        qWarning() << "CVS::QImageToCvMat() - QImage format not handled in switch:" << inImage.format();
//        break;
//    }

//    return cv::Mat();
//}



//显示无人艇航迹（启动对应的时钟）
void MainWindow::on_pushButton_clicked()
{
    if(ui->pushButton->text() == tr("显示实时轨迹"))
    {
        this -> timer1 -> start(int(1000));
        ui->pushButton->setText("停止显示实时轨迹");
    }
    else
    {
        ui->pushButton->setText("显示实时轨迹");
        this->timer1->stop();
    }
}

//定时接受无人艇发送的数据并且显示
static bool ispanto = true;
void MainWindow::updaterealtimetrack()     //多次调用该函数实现轨迹的更新
{
    if(!lonlatheading.empty())
    {
        double lon=lonlatheading.back().at(0);
        double lat=lonlatheading.back().at(1);
        double heading=lonlatheading.back().at(2);
        mapChannel->updateBoatPos(lat,lon,heading);
        //第一次调用时将地图中心点panto到无人艇当前位置
        if(ispanto)
        {
            mapChannel->panTo(lat,lon);
            ispanto = false;
        }

        QDateTime current_time = QDateTime::currentDateTime();     //实现在地图上实时显示船的位置和轨迹的函数，传入的是经纬度和航向角
        QString StrCurrentTime = current_time.toString("yyyy/MM/dd hh:mm:ss.zzz ddd");
        QString qlng = QString(" %1").arg(lon);
        QString qlat = QString(" %1").arg(lat);
        QString qyaw = QString(" %1").arg(heading);
        this -> ui -> label_time_value -> setText(StrCurrentTime);
        this -> ui -> label_lng_value -> setText(qlng);
        this -> ui -> label_lat_value -> setText(qlat);
        this -> ui -> label_yaw_value -> setText(qyaw);

    }
    else
    {
        qDebug()<<"未收到坐标数据";
    }

//控制数组大小，防止内存溢出
    if(sizeof(lonlatheading)>480)
    {

        lonlatheading.erase(lonlatheading.begin(),lonlatheading.end()-3);

    }

}

//读取服务器传输过来的数据
void MainWindow::socket_Read_Data()
 {
     QString buffer;

     //读取缓冲区数据
     buffer = socket->readAll();
     if(!buffer.isEmpty())
     {
         //解析无人艇发送过来的报文数据
         QStringList R = buffer.split(",");
         double lon=R.at(1).toDouble();
         double lat=R.at(2).toDouble();
         double heading=R.at(3).toDouble();

         lonlatheading.push_back({lon,lat,heading});
     }
 }

 void MainWindow::socket_Disconnected()
 {
     //发送按键失能
     ui->pushButton_send_data->setEnabled(false);
     //修改按键文字
     ui->pushButton_connect_tcp->setText("连接服务器");
     qDebug() << "Disconnected!";
 }


void MainWindow::on_pushButton_connect_tcp_clicked()
{
    if (ui->pushButton_connect_tcp->text() == tr("连接服务器"))
         {
             QString IP;
             int port;

             //获取IP地址
             IP = "120.77.0.8";
             //获取端口号
             port = 5678;

             //取消已有的连接
             socket->abort();
             //连接服务器
             socket->connectToHost(IP, port);

             //等待连接成功
             if(!socket->waitForConnected())
             {
                 qDebug() << "Connection failed!";
                 return;
             }else
             {
             qDebug() << "Connect successfully!";

             //发送按键使能
             this -> ui -> pushButton_control_s -> setEnabled(true);
             this -> ui -> pushButton_send_data -> setEnabled(true);
             this->ui->btn_change_control_mode -> setEnabled(true);
             this -> ui -> pushButton -> setEnabled(true);

             //修改按键文字
             ui->pushButton_connect_tcp->setText("断开连接");
             }
         }
         else
         {
             //断开连接
             socket->disconnectFromHost();
             //修改按键文字
             ui->pushButton_connect_tcp->setText("连接服务器");
             this -> ui -> pushButton_control_s -> setEnabled(false);
             this -> ui -> pushButton_send_data -> setEnabled(false);
             this->ui->btn_change_control_mode -> setEnabled(false);
         }
}

void MainWindow::on_pushButton_send_data_clicked()
{
    qDebug() << "Send: ";
    std::string send_lonlat="P,";

    for(int i=0;i<(int)gpssave.size();i++)
    {
      for(int k=0;k<2;k++)
      {
    send_lonlat+=std::to_string(gpssave[i][k]);
    send_lonlat+=',';
      }

    }
char *c = new char[send_lonlat.length()];
strcpy(c,send_lonlat.data());


    socket->write(c);
    socket->flush();
    gpssave.clear();
}

void MainWindow::on_pushButton_control_s_clicked()
{
    std::string S;
    S=ui->lineEdit->text().toStdString();
    char *p = new char[S.length()];
    strcpy(p,S.data());
    socket->write(p);
    socket->flush();
}

void MainWindow::on_play_video_clicked()
{
    //选择文件
    //QString name = QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("选择视频文件"));
    QString name = ui->url_input->text();
    if(name.isEmpty())return;
    if (!dt.Open(name.toLocal8Bit(),ui->openGLWidget))
    {
        QMessageBox::information(0,"error","open file failed");
        return;
    }
}

