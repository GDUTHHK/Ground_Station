#include "audioplay.h"
#include <QAudioFormat>
#include <QAudioOutput>
#include <mutex>

class HAudioPlay :public AudioPlay
{
public:
    QAudioOutput *output = NULL;
    QIODevice *io = NULL;
    std::mutex mux;

    virtual void Close()
    {
        mux.lock();
        if (io)
        {
            io->close ();
            io = NULL;
        }
        if (output)
        {
            output->stop();
            delete output;
            output = 0;
        }
        mux.unlock();
    }

    virtual void Clear()
    {
        mux.lock();
        if(io)
        {
            io->reset();
        }
        mux.unlock();
    }

    virtual bool Open()
    {
        Close();
        QAudioFormat fmt;
        fmt.setSampleRate(sampleRate);
        fmt.setSampleSize(sampleSize);
        fmt.setChannelCount(channels);
        fmt.setCodec("audio/pcm");
        fmt.setByteOrder(QAudioFormat::LittleEndian);
        fmt.setSampleType(QAudioFormat::UnSignedInt);

        mux.lock();
        output = new QAudioOutput(fmt);
        io = output->start(); //开始播放
        mux.unlock();
        if(io)
            return true;
        return false;
    }

   virtual long long GetNoPlayMs()
    {
        mux.lock();
        if(!output)
        {
            mux.unlock();
            return 0;
        }
        long long pts = 0;
        //还未播放的字节数
        double size = output->bufferSize() - output->bytesFree();
        //一秒音频的字节大小
        double secSize = sampleRate * (sampleSize/8) * channels;
        if(secSize<=0)
        {
            pts = 0;
        }
        else
        {
            pts = (size / secSize) * 1000;
        }

        mux.unlock();
        return pts;
    }

    virtual void SetPause(bool isPause)
    {
        mux.lock();
        if(!output)
        {
            mux.unlock();
            return;
        }
        if(isPause)
            output->suspend();
        else
            output->resume();
        mux.unlock();
    }

    //播放音频
   virtual bool Write(const unsigned char *data,int datasize)
    {
        if (!data || datasize <= 0)return false;
                mux.lock();
                if (!output || !io)
                {
                    mux.unlock();
                    return false;
                }
                int size = io->write((char *)data, datasize);
                mux.unlock();
                if (datasize != size)
                    return false;
                return true;


    }
    virtual int GetFree()
    {
        mux.lock();
        if(!output)
        {
            mux.unlock();
            return false;
        }
        int free = output->bytesFree();//返回音频缓冲区的可用空间(以字节为单位)
        mux.unlock();
        return free;
    }

};



 AudioPlay *AudioPlay::Get() //为了隔离qt和ffmpeg
{
    static HAudioPlay play;
    return &play;
}

AudioPlay::AudioPlay()
{

}

AudioPlay::~AudioPlay()
{

}
