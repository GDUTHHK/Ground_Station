#ifndef DEMUXTHREAD_H
#define DEMUXTHREAD_H
#include <QThread>
#include <mutex>
#include  "videocall.h"
class Demux;
class VideoThread;
class AudioThread;

class DemuxThread : public QThread
{
public:
    virtual bool Open(const char *url,VideoCall *call);
    //启动所有线程
    virtual void Start();
    //关闭线程清理资源
    virtual void Close();
    //使得Seek操作时清空缓存，加快跳转速度
    virtual void Clear();
    virtual void Seek(double pos);
    void run();
    DemuxThread();
    virtual ~DemuxThread();
    bool isExit = false;
    long long pts = 0;
    long long totalMs = 0;
    void SetPause(bool isPause);
    bool isPause = false;

protected:
    std::mutex mux;
    Demux *demux = 0;
    VideoThread *vt = 0;
    AudioThread *at = 0;
};

#endif // DEMUXTHREAD_H

