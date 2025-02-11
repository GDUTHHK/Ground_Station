#include "decodethread.h"
#include "decode.h"
#include <QDebug>
DecodeThread::DecodeThread()
{
    //打开解码器
 if(!decode)   decode = new Decode();
}

DecodeThread::~DecodeThread()
{
    isExit = true;
    wait ();
}



void DecodeThread::Clear()
{
    mux.lock();
    decode->Clear();
    while(!packs.empty())
    {
        AVPacket *pkt = packs.front();
        FreePacket(&pkt);
        packs.pop_front();
    }
    mux.unlock();
}



void DecodeThread::Close()
{
    Clear();
    isExit = true;
    wait();
    decode->Close();
    mux.lock();
    delete decode;
    decode = NULL;
    mux.unlock();
}


void DecodeThread::Push(AVPacket *pkt)
{
    if(!pkt)   return;

    //若接收到的packet满了，则进行阻塞
    while (!isExit)
    {
         mux.lock();
         if(packs.size()<maxList)
         {
             packs.push_back(pkt);
             //qDebug()<<" push ";
             mux.unlock();
             break;
         }
         mux.unlock();
         msleep(16);

    }
}

AVPacket *DecodeThread::Pop()
{
    mux.lock();
    if(packs.empty())
    {
        mux.unlock();
        return NULL;
    }
AVPacket *pkt = packs.front();
packs.pop_front();
mux.unlock();
return pkt;
}
