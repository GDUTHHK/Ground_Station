#ifndef VIDEO_H
#define VIDEO_H
#include "videocall.h"
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <mutex>
#include <QPainter>
struct AVFrame;

class video: public QOpenGLWidget,protected QOpenGLFunctions,public VideoCall
{
public:
    virtual void Init(int width,int height);

    //不管是否成功，都释放frame空间
    virtual void Repaint(AVFrame *frame);

    video(QWidget *parent);

protected:
    //刷新显示
    void paintGL();

    //初始化gl
    void initializeGL();

    // 窗口尺寸变化
    void resizeGL(int width, int height);

private:

    std::mutex mux;
    //shader程序
    QOpenGLShaderProgram program;

    //shader中yuv变量地址
    GLuint unis[3] = {0};
    //openg的 texture地址
    GLuint texs[3] = { 0 };

    //材质内存空间
    unsigned char *datas[3] = { 0 };

    int width = 240;
    int height = 128;

};

#endif // VIDEO_H
