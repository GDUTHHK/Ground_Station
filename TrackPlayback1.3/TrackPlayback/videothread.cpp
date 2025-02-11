#include "videothread.h"
#include "decode.h"



bool VideoThread::Open(AVCodecParameters *para,VideoCall *call,int width,int height)
{
    if(!para)   return false;
    Clear();
    vmux.lock();
    synpts = 0;
    //初始化显示窗口
    this->call = call;  //回调函数
    if(call)
    {
        call->Init(width,height);
    }
     vmux.unlock();
    bool ret = true;
    if(!decode->Open(para))
    {
        ret = false;
        cout<<"audio decode open failed"<<endl;
    }


    cout<<"audio thread open "<<ret<<endl;
    return ret;
}

void VideoThread::SetPause(bool isPause)
{
    vmux.lock();
    this->isPause = isPause;

    vmux.unlock();
}

//解码pts，如果接收到的解码数据pts大于seekpts，显示该帧画面，并return true
bool VideoThread::RepaintPts(AVPacket *pkt,long long seekPts)
{
    vmux.lock();
    bool ret = decode->Send(pkt);
    if(!ret)
    {
        vmux.unlock();
        return true; //表示结束解码
    }
    AVFrame *frame = decode->Recv();
    if(!frame)
    {
        vmux.unlock();
        return false;
    }
    //到达指定位置
    if(decode->pts >=seekPts)
    {
        if(call)
        call->Repaint(frame);
        vmux.unlock();
        return true;
    }
    FreeFrame(&frame);
    vmux.unlock();
    return false;
}

void VideoThread::run()
{
    while(!isExit)
    {
        vmux.lock();
        if(this->isPause)
        {
            vmux.unlock();
            msleep(5);
            continue;
        }
        //音视频同步
//        if(synpts>0 && synpts < decode->pts)
//        {
//            vmux.unlock();
//            msleep(1);
//            continue;
//        }
        AVPacket *pkt = Pop();


        bool ret = decode->Send(pkt);
        if(!ret)
        {
            vmux.unlock();
            msleep(1);
            continue;
        }
        //一次send多次Recv
        while(!isExit)
        {
            AVFrame *frame = decode->Recv();
            if(!frame) break;
            //显示视频
            if (call)
            {
                call->Repaint(frame);


            }
        }
        vmux.unlock();
    }

}



VideoThread::VideoThread()
{

}

VideoThread::~VideoThread()
{

}
