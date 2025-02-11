#include "audiothread.h"
#include "decode.h"
#include "resample.h"
#include "audioplay.h"
#include <iostream>
extern "C"{
#include "libavcodec/avcodec.h"
//#include "libavfilter/avfilter.h"
//#include "libavformat/avformat.h"
//#include "libavutil/avutil.h"
//#include "libavutil/ffversion.h"
//#include "libswresample/swresample.h"
//#include "libswscale/swscale.h"
//#include "libpostproc/postprocess.h"
}
using namespace std;

 //停止线程，清理资源
void AudioThread::Close()
{
    DecodeThread::Close();
    if(res)
    {
        res->Close();
        amux.lock();
        delete res;
        res = NULL;
        amux.unlock();
    }
    if(ap)
    {
        ap->Close();
        amux.lock();
        ap = NULL;
        amux.unlock();
    }
}

void AudioThread::Clear()
{
    DecodeThread::Clear();
    mux.lock();
    if(ap) ap->Clear();
    mux.unlock();
}

bool AudioThread::Open(AVCodecParameters *para,int sampleRate,int channels)
{
    if(!para)   return false;
    Clear();
    amux.lock();
    pts = 0;

    bool ret = true;
    if(!res->Open(para,false))
    {
            ret = false;
        cout<<"resample open failed"<<endl;
    }
    ap->sampleRate = sampleRate;
    ap->channels = channels;
    if(!ap->Open())
    {
        ret = false;
        cout<<"AudioPlay open failed"<<endl;
        //mux.unlock();
        //return false;
    }
    if(!decode->Open(para))
    {
        ret = false;
        cout<<"audio decode open failed"<<endl;
    }

    amux.unlock();
    cout<<"audio thread open "<<ret<<endl;
    return ret;
}

void AudioThread::SetPause(bool isPause)
{
    //amux.lock();  //加锁会导致暂停后音频仍旧播放一段时间
    this->isPause = isPause;
    if(ap)
        ap->SetPause(isPause);
    //amux.unlock();
}


void AudioThread::run()
{
    unsigned char *pcm = new unsigned char[1024*1024*10];
    while(!isExit)
    {
        amux.lock();
        if(this->isPause)
        {
            amux.unlock();
            msleep(5);
            continue;
        }
        AVPacket *pkt = Pop();
        bool ret = decode->Send(pkt);
        if(!ret)
        {
            amux.unlock();
            msleep(1);
            continue;
        }
        //一次send多次Recv
        while(!isExit)
        {
            AVFrame *frame = decode->Recv();
            if(!frame) break;
            //以音频为时钟的音视频同步
            pts = decode->pts - ap->GetNoPlayMs(); //因为解码得到的帧还会放进缓冲队列中，不会立即播放，所以要减去缓存中未播放的时间
            //重采样
           int size = res->Res(frame,pcm);
           //播放音频
           while(!isExit)
           {
               if(size<=0)break;
               //缓冲未播完，空间不够
               if(ap->GetFree()<size || isPause)
               {
                   //msleep(1);  //加了msleep后出现断音
                   continue;
               }
               ap->Write(pcm,size);
               break;
           }
        }
        amux.unlock();
    }
        delete pcm;

}

AudioThread::AudioThread()
{
    if(!res)   res = new Resample();
    if(!ap)   ap = AudioPlay::Get();

}

AudioThread::~AudioThread()
{

}
