#include "demux.h"
#include <iostream>
extern "C"{
#include "libavcodec/avcodec.h"
//#include "libavfilter/avfilter.h"
#include "libavformat/avformat.h"
#include "libavutil/avutil.h"
//#include "libavutil/ffversion.h"
//#include "libswresample/swresample.h"
//#include "libswscale/swscale.h"
//#include "libpostproc/postprocess.h"
}

using namespace std;

static double r2d(AVRational r) //使用static关键字可以使得该函数名只能在该cpp文件中可见
{
    return r.den==0?0:(double)r.num/(double)r.den;
}

bool Demux::Open(const char *url)
{
    Close();  //先清理之前的空间防止内存泄漏
    //参数设置
    AVDictionary *opts=NULL;
    //设置rtsp流以tcp协议打开
    av_dict_set(&opts,"rtsp_transport","tcp",0);
    //网络延时时间 (当网络状况不佳时,若设置延时过小,会导致频繁断线)
    av_dict_set(&opts,"max_delay","500",0);

    //通过以下两步设置降低打开视频流的阻塞时间
    av_dict_set(&opts,"probesize","2048",0);
    av_dict_set(&opts,"max_analyze_duration","1000",0);

    mux.lock();
    int ret=avformat_open_input(&ic,url,0,&opts);//成功返回0
    if(ret!=0)
    {
        mux.unlock();
        char buf[1024]={0};
        av_strerror(ret,buf,sizeof(buf)-1);
        cout<<"open failed"<<buf<<endl;
        return false;
    }
    cout<<"open "<<url<<" success"<<endl;

    //获取流信息
    ret=avformat_find_stream_info(ic,0);
    //打印总时长(微秒)
    this->total_time=ic->duration/AV_TIME_BASE*1000;//单位是AV_TIME_BASE(微秒)
    cout<<"total times = "<<this->total_time<<endl;
    //打印视频流详细信息
   // av_dump_format(ic,0,0,0);//最后一个参数表示是否是输出(也就是是封装过程还是解封装过程)


    //获取视频流
    video_stream=av_find_best_stream(ic,AVMEDIA_TYPE_VIDEO,-1,-1,NULL,0);
    AVStream*as=ic->streams[video_stream];
    height=as->codecpar->height;
    width=as->codecpar->width;
    cout<<"视频信息"<<endl;
    cout<<"视频fps:"<<r2d(as->avg_frame_rate)<<endl;
    cout<<"视频宽高:"<<as->codecpar->width<<" x "<<as->codecpar->height<<endl;

    //获取音频流
//    audio_stream=av_find_best_stream(ic,AVMEDIA_TYPE_AUDIO,-1,-1,NULL,0);
//    as=ic->streams[audio_stream];
//    cout<<"音频信息"<<endl;
//    cout<<"样本率:"<<as->codecpar->sample_rate<<endl;
//    cout<<"样本采样格式:"<<as->codecpar->format<<endl;
//    cout<<"通道数量:"<<as->codecpar->channels<<endl;
//    cout<<"编码格式:"<<as->codecpar->codec_id<<endl;

//    sampleRate = as->codecpar->sample_rate;
//    channels = as->codecpar->channels;

    mux.unlock();

    return true;
}

//清空读取缓存
void Demux::Clear()
{
    mux.lock();
    if(!ic)
    {
        mux.unlock();
        return ;
    }
    //清理读取缓冲
    avformat_flush(ic);
    mux.unlock();
}
void Demux::Close()
{
    mux.lock();
    if(!ic)
    {
        mux.unlock();
        return ;
    }
    avformat_close_input(&ic);
    //媒体总时常(ms)
    total_time = 0;
    mux.unlock();
}


//seek 位置 pos 0.0~1.0 类似与百分比
bool Demux::Seek(double pos)
{
    mux.lock();
    if(!ic)
    {
        mux.unlock();
        return false;
    }
    //清理读取缓冲
    avformat_flush(ic);

    long long seekPos = 0;
    seekPos = ic->streams[video_stream]->duration*pos;//总时常乘百分比得到需要seek到的实际位置
    int ret = av_seek_frame(ic,video_stream,seekPos,AVSEEK_FLAG_BACKWARD|AVSEEK_FLAG_FRAME);
    mux.unlock();
    if(ret<0) return false;
    return true;
}

//针对Seek操作时，只需要读视频不需要读音频的情况
AVPacket *Demux::ReadVideo()
{
    mux.lock();
    if(!ic)
    {
        mux.unlock();
        return 0;
    }
    mux.unlock();
    AVPacket *pkt = NULL;
    //防止阻塞
    for(int i=0;i<20;i++)
    {
        pkt = Read();
        if(!pkt) break;
        if(pkt->stream_index == video_stream)
            break;
        av_packet_free(&pkt);
    }
    return pkt;
}

//获取视频参数  返回的空间需要清理  avcodec_parameters_free()
AVCodecParameters *Demux::CopyVPara()
{
    mux.lock();
    if(!ic)
    {
        mux.unlock();
        return NULL;
    }
    AVCodecParameters *pa = avcodec_parameters_alloc();
    avcodec_parameters_copy(pa,ic->streams[video_stream]->codecpar);
    mux.unlock();
    return pa;
}

//获取音频参数  返回的空间需要清理  avcodec_parameters_free()
AVCodecParameters *Demux::CopyAPara()
{
    mux.lock();
    if(!ic)
    {
        mux.unlock();
        return NULL;
    }
    AVCodecParameters *pa = avcodec_parameters_alloc();
    avcodec_parameters_copy(pa,ic->streams[audio_stream]->codecpar);
    mux.unlock();
    return pa;
}

//判断是否是音频
bool Demux::IsAudio(AVPacket *pkt)
{
    if(!pkt)return false;
    if(pkt->stream_index==video_stream)
        return false;
    return true;
}

//空间需要调用者释放,包括AVPacket对象空间和数据空间(av_packet_free)
AVPacket *Demux::Read()
{
    mux.lock();//上锁是防止读的时候AVFormatContext被关闭导致读失败
    if(!ic)
    {
        mux.unlock();
        return 0;
    }
    //这一步只是分配了对象空间,没有分配具体的数据空间
    AVPacket *pkt = av_packet_alloc();
    //读取一帧,并分配空间
    int ret = av_read_frame(ic,pkt);
    if(ret!=0)  //检验是否读取成功
    {
        mux.unlock();
        av_packet_free(&pkt);//释放空间,防止内存泄漏
        return 0;
    }
    //pts转换为毫秒
    pkt->pts = pkt->pts*(1000*(r2d(ic->streams[pkt->stream_index]->time_base)));
    pkt->dts = pkt->dts*(1000*(r2d(ic->streams[pkt->stream_index]->time_base)));
    mux.unlock();
    //cout<<" pkt->pts:"<<pkt->pts<<flush;
    return pkt;
}

Demux::Demux()
{
    static bool isFirst = true;
    static std::mutex dmux;  //上锁,保证多线程创建对象时的安全
    dmux.lock();
    if(isFirst)
    {
    //初始化封装库
    av_register_all();
    //初始化网络库
    avformat_network_init();
    isFirst = false;
    }
    dmux.unlock();
}

Demux::~Demux()
{

}
