﻿#ifndef AUDIOPLAY_H
#define AUDIOPLAY_H


class AudioPlay
{
public:
    int sampleRate = 44100;
    int sampleSize = 16;
    int channels = 2;
    //打开音频播放
    virtual bool Open()=0; //纯虚函数,使该类变为抽象类
    virtual void Close() = 0;
    virtual void Clear() = 0;
    //返回缓冲中还没播放的时间(ms)
    virtual long long GetNoPlayMs() = 0;
    //播放音频
    virtual bool Write(const unsigned char *data,int datasize)=0;
    virtual int GetFree() = 0;
    virtual void SetPause(bool isPause) = 0;
    static AudioPlay *Get();
    AudioPlay();
    virtual ~AudioPlay();
};

#endif // AUDIOPLAY_H
