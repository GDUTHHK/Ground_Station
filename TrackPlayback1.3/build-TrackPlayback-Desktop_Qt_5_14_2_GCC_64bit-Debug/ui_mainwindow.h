/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qwebengineview.h>
#include "video.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCurve;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_open_file;
    QPushButton *pushButton_realtime_display;
    QPushButton *pushButton;
    QPushButton *pushButton_start;
    QLabel *label;
    QComboBox *comboBox_times_vel;
    QLineEdit *url_input;
    QPushButton *play_video;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QWebEngineView *widget_map;
    video *openGLWidget;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *layout_for_dial;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *btn_change_control_mode;
    QPushButton *pushButton_connect_tcp;
    QPushButton *pushButton_send_data;
    QLineEdit *lineEdit;
    QPushButton *pushButton_control_s;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_12;
    QLabel *label_8;
    QLabel *label_lat_value;
    QLabel *label_13;
    QLabel *label_9;
    QLabel *label_time_value;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_yaw_value;
    QLabel *label_lng_value;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1174, 916);
        actionCurve = new QAction(MainWindow);
        actionCurve->setObjectName(QString::fromUtf8("actionCurve"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_5 = new QHBoxLayout(centralWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_open_file = new QPushButton(centralWidget);
        pushButton_open_file->setObjectName(QString::fromUtf8("pushButton_open_file"));

        horizontalLayout->addWidget(pushButton_open_file);

        pushButton_realtime_display = new QPushButton(centralWidget);
        pushButton_realtime_display->setObjectName(QString::fromUtf8("pushButton_realtime_display"));

        horizontalLayout->addWidget(pushButton_realtime_display);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));

        horizontalLayout->addWidget(pushButton_start);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        comboBox_times_vel = new QComboBox(centralWidget);
        comboBox_times_vel->addItem(QString());
        comboBox_times_vel->addItem(QString());
        comboBox_times_vel->addItem(QString());
        comboBox_times_vel->addItem(QString());
        comboBox_times_vel->addItem(QString());
        comboBox_times_vel->addItem(QString());
        comboBox_times_vel->addItem(QString());
        comboBox_times_vel->addItem(QString());
        comboBox_times_vel->setObjectName(QString::fromUtf8("comboBox_times_vel"));

        horizontalLayout->addWidget(comboBox_times_vel);

        url_input = new QLineEdit(centralWidget);
        url_input->setObjectName(QString::fromUtf8("url_input"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(url_input->sizePolicy().hasHeightForWidth());
        url_input->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(url_input);

        play_video = new QPushButton(centralWidget);
        play_video->setObjectName(QString::fromUtf8("play_video"));

        horizontalLayout->addWidget(play_video);

        horizontalSpacer_5 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 3);
        horizontalLayout->setStretch(3, 3);
        horizontalLayout->setStretch(4, 2);
        horizontalLayout->setStretch(5, 2);
        horizontalLayout->setStretch(8, 11);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        widget_map = new QWebEngineView(centralWidget);
        widget_map->setObjectName(QString::fromUtf8("widget_map"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_map->sizePolicy().hasHeightForWidth());
        widget_map->setSizePolicy(sizePolicy1);
        widget_map->setMinimumSize(QSize(650, 600));

        horizontalLayout_4->addWidget(widget_map);

        openGLWidget = new video(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(3);
        sizePolicy2.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy2);
        openGLWidget->setMinimumSize(QSize(100, 100));

        horizontalLayout_4->addWidget(openGLWidget);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        layout_for_dial = new QHBoxLayout();
        layout_for_dial->setSpacing(6);
        layout_for_dial->setObjectName(QString::fromUtf8("layout_for_dial"));

        horizontalLayout_3->addLayout(layout_for_dial);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        groupBox->setAlignment(Qt::AlignCenter);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn_change_control_mode = new QPushButton(groupBox);
        btn_change_control_mode->setObjectName(QString::fromUtf8("btn_change_control_mode"));

        gridLayout->addWidget(btn_change_control_mode, 4, 0, 1, 1);

        pushButton_connect_tcp = new QPushButton(groupBox);
        pushButton_connect_tcp->setObjectName(QString::fromUtf8("pushButton_connect_tcp"));

        gridLayout->addWidget(pushButton_connect_tcp, 1, 0, 1, 1);

        pushButton_send_data = new QPushButton(groupBox);
        pushButton_send_data->setObjectName(QString::fromUtf8("pushButton_send_data"));

        gridLayout->addWidget(pushButton_send_data, 3, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        pushButton_control_s = new QPushButton(groupBox);
        pushButton_control_s->setObjectName(QString::fromUtf8("pushButton_control_s"));

        gridLayout->addWidget(pushButton_control_s, 2, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox);

        horizontalSpacer = new QSpacerItem(13, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy3.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy3);
        groupBox_2->setAlignment(Qt::AlignCenter);
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_12, 3, 0, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        label_lat_value = new QLabel(groupBox_2);
        label_lat_value->setObjectName(QString::fromUtf8("label_lat_value"));

        gridLayout_2->addWidget(label_lat_value, 3, 1, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_13, 4, 0, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_9, 0, 1, 1, 1);

        label_time_value = new QLabel(groupBox_2);
        label_time_value->setObjectName(QString::fromUtf8("label_time_value"));

        gridLayout_2->addWidget(label_time_value, 1, 1, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_10, 1, 0, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_11, 2, 0, 1, 1);

        label_yaw_value = new QLabel(groupBox_2);
        label_yaw_value->setObjectName(QString::fromUtf8("label_yaw_value"));

        gridLayout_2->addWidget(label_yaw_value, 4, 1, 1, 1);

        label_lng_value = new QLabel(groupBox_2);
        label_lng_value->setObjectName(QString::fromUtf8("label_lng_value"));

        gridLayout_2->addWidget(label_lng_value, 2, 1, 1, 1);


        horizontalLayout_2->addWidget(groupBox_2);

        horizontalSpacer_3 = new QSpacerItem(13, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1174, 28));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Track Replay", nullptr));
        actionCurve->setText(QCoreApplication::translate("MainWindow", "Curve", nullptr));
        pushButton_open_file->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        pushButton_realtime_display->setText(QCoreApplication::translate("MainWindow", "\345\256\236\346\227\266\347\224\273\351\235\242", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\256\236\346\227\266\350\275\250\350\277\271", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\345\233\236\346\224\276", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\351\200\237\345\272\246\357\274\232", nullptr));
        comboBox_times_vel->setItemText(0, QCoreApplication::translate("MainWindow", "\303\2271", nullptr));
        comboBox_times_vel->setItemText(1, QCoreApplication::translate("MainWindow", "\303\2271.25", nullptr));
        comboBox_times_vel->setItemText(2, QCoreApplication::translate("MainWindow", "\303\2271.5", nullptr));
        comboBox_times_vel->setItemText(3, QCoreApplication::translate("MainWindow", "\303\2272", nullptr));
        comboBox_times_vel->setItemText(4, QCoreApplication::translate("MainWindow", "\303\2273", nullptr));
        comboBox_times_vel->setItemText(5, QCoreApplication::translate("MainWindow", "\303\2275", nullptr));
        comboBox_times_vel->setItemText(6, QCoreApplication::translate("MainWindow", "\303\22710", nullptr));
        comboBox_times_vel->setItemText(7, QCoreApplication::translate("MainWindow", "\303\22715", nullptr));

        url_input->setText(QCoreApplication::translate("MainWindow", "rtmp://120.79.189.12/live/livestream", nullptr));
        play_video->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\345\256\236\346\227\266\347\224\273\351\235\242", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\350\210\271\350\210\266\346\216\247\345\210\266", nullptr));
        btn_change_control_mode->setText(QCoreApplication::translate("MainWindow", "\345\205\250\345\261\200\350\267\257\345\276\204\350\247\204\345\210\222", nullptr));
        pushButton_connect_tcp->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        pushButton_send_data->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\235\220\346\240\207\347\202\271", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "S,0,3,0,#,", nullptr));
        pushButton_control_s->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\216\247\345\210\266\346\214\207\344\273\244", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\345\256\236\346\227\266\346\225\260\346\215\256", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\347\272\254\345\272\246\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\220\215\347\247\260", nullptr));
        label_lat_value->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "\350\211\217\345\220\221\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\345\256\236\346\227\266\346\225\260\345\200\274", nullptr));
        label_time_value->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\347\273\217\345\272\246\357\274\232", nullptr));
        label_yaw_value->setText(QString());
        label_lng_value->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
