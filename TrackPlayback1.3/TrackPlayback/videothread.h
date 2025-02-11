#ifndef VIDEOTHREAD_H
#define VIDEOTHREAD_H
#include <iostream>
#include <QThread>
#include <mutex>
#include <list>
#include "videocall.h"
#include "decodethread.h"
using namespace std;
struct AVPacket;
struct AVCodecParameters;
class Decode;


class VideoThread : public DecodeThread
{
public:
    //解码pts，如果接收到的解码数据pts大于seekpts，显示该帧画面，并return true
    virtual bool RepaintPts(AVPacket *pkt,long long seekpts);
    VideoThread();
    virtual ~VideoThread();
    //打开，不管成功与否都清理
    virtual bool Open(AVCodecParameters *para,VideoCall *call,int width,int height);
    void run();
    void SetPause(bool isPause);
    bool isPause = false;

//同步时间
long long synpts = 0;

protected:
std::mutex vmux;
VideoCall *call = 0;
};

#endif // VIDEOTHREAD_H
