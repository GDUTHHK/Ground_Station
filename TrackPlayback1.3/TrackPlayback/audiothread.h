#ifndef AUDIOTHREAD_H
#define AUDIOTHREAD_H
#include <QThread>
#include <mutex>
#include <list>
#include "decodethread.h"
struct AVCodecParameters;
struct AVPacket;
class Decode;
class AudioPlay;
class Resample;

class AudioThread :public DecodeThread
{
public:
    //当前音频播放的pts
    long long pts = 0;
    //打开，不管成功与否都清理
    virtual bool Open(AVCodecParameters *para,int sampleRate,int channels);
    //停止线程，清理资源
    virtual void Close();
    virtual void Clear();
    void run();
    void SetPause(bool isPause);
    bool isPause = false;

    AudioThread();
    virtual ~AudioThread();

protected:

    std::mutex amux;
    AudioPlay *ap = 0;
    Resample *res = 0;
};

#endif // AUDIOTHREAD_H
