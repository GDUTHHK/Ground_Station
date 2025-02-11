#ifndef DEMUX_H
#define DEMUX_H
#include <mutex>
struct AVFormatContext;  //声明要用的结构体   头文件在.cpp中包含,可以防止重复引用头文件的问题
struct AVPacket;
struct AVCodecParameters;
class Demux
{
public:
    //打开媒体文件,或者流媒体
    virtual bool Open(const char *url);

    //判断是否是音频
    virtual bool IsAudio(AVPacket *pkt);

    //空间需要调用者释放,包括AVPacket对象空间和数据空间(av_packet_free)
    virtual AVPacket *Read();

    //针对Seek操作时，只需要读视频不需要读音频的情况
    virtual AVPacket *ReadVideo();

    //获取视频参数     返回的空间需要清理  avcodec_parameters_free()
    virtual AVCodecParameters *CopyVPara();

    //获取音频参数     返回的空间需要清理  avcodec_parameters_free()
    virtual AVCodecParameters *CopyAPara();

    //seek 位置 pos 0.0~1.0 类似与百分比
    virtual bool Seek(double pos);

    //清空读取缓存
    virtual void Clear();
    virtual void Close();

    Demux();
    virtual ~Demux();

    //媒体总时常(ms)
    int total_time = 0;
    int width = 0;
    int height = 0;
    int sampleRate = 0;
    int channels = 0;


protected:
    std::mutex mux; //保证多次打开时不会出现问题
    //解封装上下文
    AVFormatContext *ic=NULL;
    //音视频流索引
    int video_stream=0;
    int audio_stream=1;

};

#endif // DEMUX_H
