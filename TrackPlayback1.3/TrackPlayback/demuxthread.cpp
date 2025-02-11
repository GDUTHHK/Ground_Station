#include "demuxthread.h"
#include "demux.h"
#include "videothread.h"
#include "audiothread.h"
#include <iostream>
#include "decode.h"
extern "C"
{
#include <libavformat/avformat.h>
}
using namespace std;

void DemuxThread::SetPause(bool isPause)
{
    mux.lock();
    this->isPause = isPause;
    if(at) at->SetPause(isPause);
    if(vt) vt->SetPause(isPause);
    mux.unlock();
}

void DemuxThread::Clear()
{
    mux.lock();
    if(demux) demux->Clear();
    if(vt) vt->Clear();
    if(at) at->Clear();
    mux.unlock();
}

void DemuxThread::Seek(double pos)
{
    //清理缓冲
    Clear();

    mux.lock();
    bool status = this->isPause;
    mux.unlock();
    //暂停 以确保seek到的是当前帧
    SetPause(true);
    mux.lock();
    if(demux)
        demux->Seek(pos);
    //实际要显示的位置的pts
    long long seekPts = pos*demux->total_time;
    while(!isExit)
    {
        AVPacket *pkt = demux->ReadVideo();
        if(!pkt)break;
        //如果解码到指定位置，break
        if(vt->RepaintPts(pkt,seekPts))
        {
            this->pts = seekPts;
            break;
        }

    }
    mux.unlock();
    //seek时不是暂停状态，则seek后继续播放
    if(!status)
    SetPause(false);
}

void DemuxThread::run()
{
    while(!isExit)
    {

        mux.lock();
        if(isPause)
        {
            mux.unlock();
            msleep(5);
                    continue;
        }
        if(!demux)
        {
            mux.unlock();
            msleep(5);
            continue;
        }

        //音视频同步
//        if(vt && at)
//        {
//            pts = at->pts;
//            vt->synpts = at->pts;
//        }

        AVPacket *pkt = demux->Read();
        if(!pkt)
        {
            mux.unlock();
            msleep(5);
            continue;
        }
//        //判断数据包是音频还是视频
//        if(demux->IsAudio(pkt))
//        {
//            if(at) at->Push(pkt);
//        }
//        else
//        {
             if(vt) vt->Push(pkt);

//        }
        mux.unlock();
        msleep(16);

    }

}

bool DemuxThread::Open(const char *url,VideoCall *call)
{
    mux.lock();


    //打开解封装
    bool ret = demux->Open(url);
    if(!ret)
    {
        cout<<"url open failed"<<endl;
        return false;
    }

    //打开视频解码器和处理线程
    ret = vt->Open(demux->CopyVPara(),call,demux->width,demux->height);
    if(!ret)
    {
        cout<<" vt->Open() failed "<<endl;
    }

    //打开音频解码器和处理线程
//    ret = at->Open(demux->CopyAPara(),demux->sampleRate,demux->channels);
//    if(!ret)
//    {
//        cout<<" at->Open() failed "<<endl;
//    }

//    totalMs = demux->total_time;
//    cout<<"open demuxthread "<<ret<<endl;
    mux.unlock();
    return ret;
}

void DemuxThread::Close()
{
    isExit = true;
    wait();
    if(vt) vt->Close();
    //if(at) at->Close();
    mux.lock();
    delete vt;
    //delete at;
    vt = NULL;
    //at = NULL;
    mux.unlock();
}

void DemuxThread::Start()
{
    mux.lock();
    //启动当前线程
    if(!demux) demux = new Demux();
    if(!vt) vt = new VideoThread();
    //if(!at) at = new AudioThread();
    QThread::start();
    //if(at) at->start();
    if(vt) vt->start();


    mux.unlock();
}




DemuxThread::DemuxThread()
{

}

DemuxThread::~DemuxThread()
{

    isExit = true;
    wait();
}
