#-------------------------------------------------
#
# Project created by QtCreator 2019-07-24T15:44:47
#
#-------------------------------------------------

QT       += core gui
QT       += webenginewidgets
QT       +=network
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
DEFINES += QT_DEPRECATED_WARNINGS QWT_DLL

TARGET = TrackPlayback
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    attitudeindicator.cpp \
    audioplay.cpp \
    audiothread.cpp \
    cockpitgrid.cpp \
    cpupiemarker.cpp \
    cpuplot.cpp \
    cpustat.cpp \
    decode.cpp \
    decodethread.cpp \
    demux.cpp \
    demuxthread.cpp \
        main.cpp \
        mainwindow.cpp \
    mapchannel.cpp \
    resample.cpp \
    speedometer.cpp \
    video.cpp \
    videothread.cpp

HEADERS += \
    attitudeindicator.h \
    audioplay.h \
    audiothread.h \
    cockpitgrid.h \
    cpupiemarker.h \
    cpuplot.h \
    cpustat.h \
    decode.h \
    decodethread.h \
    demux.h \
    demuxthread.h \
    mainwindow.h \
    mapchannel.h \
    resample.h \
    speedometer.h \
    video.h \
    videocall.h \
    videothread.h

FORMS += \
        mainwindow.ui


#opencv
#win32:CONFIG(release, debug|release): LIBS += -LD:/OpenCV/opencv/build/x64/vc15/lib/ -lopencv_world451
#else:win32:CONFIG(debug, debug|release): LIBS += -LD:/OpenCV/opencv/build/x64/vc15/lib/ -lopencv_world451d

win32:CONFIG(release, debug|release): LIBS += -L    /usr/include/opencv2/core -lopencv_world451
else:win32:CONFIG(debug, debug|release): LIBS += -LD:/OpenCV/opencv/build/x64/vc15/lib/ -lopencv_world451d

INCLUDEPATH += D:/OpenCV/opencv/build/include
DEPENDPATH += D:/OpenCV/opencv/build/include

#ffmpeg
INCLUDEPATH += "/usr/local/include"

LIBS +=     -L"/usr/local/lib"  \
-lavformat \
-lavcodec \
-lswscale \
-lavutil \
-lavfilter \
-lpostproc \
-lswresample \
-lavdevice \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#Qwt
#win32:CONFIG(release, debug|release): LIBS += -LD:/Qt/5.15.2/msvc2019_64/lib/ -lqwt
#else:win32:CONFIG(debug, debug|release): LIBS += -LD:/Qt/5.15.2/msvc2019_64/lib/ -lqwtd
#else:unix: LIBS += -LD:/Qt/5.15.2/msvc2019_64/lib/ -lqwt

INCLUDEPATH += /usr/local/qwt-6.2.0/include
LIBS += -L"/usr/local/qwt-6.2.0/lib/" -lqwt


