#include "decode.h"
#include <iostream>
extern "C"{
#include "libavcodec/avcodec.h"
//#include "libavfilter/avfilter.h"
//#include "libavformat/avformat.h"
#include "libavutil/avutil.h"
//#include "libavutil/ffversion.h"
#include "libswresample/swresample.h"
#include "libswscale/swscale.h"
//#include "libpostproc/postprocess.h"
}

using namespace std;

void FreeFrame(AVFrame **frame)
{
    if(!frame||!(*frame)) return;
    av_frame_free(frame);
}


void FreePacket (AVPacket **pkt)
{
    if(!pkt||!(*pkt)) return;
    av_packet_free(pkt);
}

//打开解码器
bool Decode::Open(AVCodecParameters *para)
{
    Close();
    if(!para) return false;

    //找到解码器
    AVCodec *vcodec = avcodec_find_decoder(para->codec_id);
    //若打开失败,则返回并清理空间
    if(!vcodec)
    {
        avcodec_parameters_free(&para);
        cout<<"can not find video codec id"<<endl;
        return false;
    }
    cout<<"find AVCodec "<<para->codec_id<<endl;
    //创建解码器上下文
    mux.lock(); //当访问到共享变量时,加锁
    codec = avcodec_alloc_context3(vcodec);
    //配置解码器上下文参数
    avcodec_parameters_to_context(codec,para);//相当于把之前AVStreams中codecpar的参数传递到解码器中
    avcodec_parameters_free(&para);
    //八线程解码
    codec->thread_count=8;
    //打开解码器上下文
    int ret = avcodec_open2(codec,0,0);
    if(ret!=0)
    {
        avcodec_free_context(&codec);
        mux.unlock();
        char buf[1024]={0};
        av_strerror(ret,buf,sizeof(buf)-1);
        cout<<"open avcodec failed"<<buf<<endl;
        return false;
    }
    mux.unlock();
    cout<<"open video codec success"<<endl;
    avcodec_parameters_free(&para);
    return true;
}

//清理和关闭
void Decode::Close()
{
    mux.lock();
    if(codec)
    {
        avcodec_close(codec);
        avcodec_free_context(&codec);
    }
    pts = 0;
    mux.unlock();
}
void Decode::Clear()
{
    mux.lock();
    //清理解码缓冲
    if(codec)
        avcodec_flush_buffers(codec);
    mux.unlock();
}

//发送到解码线程,不管是否成功都释放pkt空间(包括对象和媒体内容)
bool Decode::Send(AVPacket *pkt)
{
    if(!pkt ||pkt->size<=0 ||!pkt->data)return false;
    mux.lock();
    if(!codec)
    {
        mux.unlock();
        return false;
    }
    int ret =avcodec_send_packet(codec,pkt);
    mux.unlock();
    av_packet_free(&pkt);
    if(ret!=0)return false;
    return true;
}

//获取解码数据,一次send可能需要多次recv,获取视频最后几帧的缓冲数据send NULL再recv多次
//每次复制一份,由调用者释放 av_frame_free
AVFrame *Decode::Decode::Recv()
{
    mux.lock();
    if(!codec)
    {
        mux.unlock();
        return NULL;
    }
    AVFrame *frame = av_frame_alloc();
    int ret = avcodec_receive_frame(codec,frame);
    mux.unlock();
    if(ret!=0)
    {
        av_frame_free(&frame);
        return NULL;
    }
    pts = frame->pts;
    return frame;

}

Decode::Decode()
{

}

Decode::~Decode()
{

}
