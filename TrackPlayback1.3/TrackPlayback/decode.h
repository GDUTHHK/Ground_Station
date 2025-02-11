#ifndef DECODE_H
#define DECODE_H
#include <mutex>
struct AVCodecParameters;
struct AVCodecContext;
struct AVPacket;
struct AVFrame;

extern void FreePacket (AVPacket **pkt);
extern void FreeFrame (AVFrame **frame);

    class Decode
{
public:

    bool isAudio = false;
    long long pts = 0; //当前解码到的pts，用于音视频同步
    //打开解码器,不管是否成功都释放para空间
    virtual bool Open(AVCodecParameters *para);

    //发送到解码线程,不管是否成功都释放pkt空间(包括对象和媒体内容)
    virtual bool Send(AVPacket *pkt);
    //获取解码数据,一次send可能需要多次recv,获取视频最后几帧的缓冲数据send NULL再recv多次
    //每次复制一份,由调用者释放 av_frame_free
    virtual AVFrame *Recv();




    //清理和关闭
    virtual void Close();
    virtual void Clear();


    Decode();
    virtual ~Decode();
protected:
    AVCodecContext *codec=0;
    std::mutex mux;
};

#endif // DECODE_H
