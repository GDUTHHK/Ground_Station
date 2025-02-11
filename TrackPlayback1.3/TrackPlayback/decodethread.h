#ifndef DECODETHREAD_H
#define DECODETHREAD_H
#include <QThread>
#include <mutex>
#include <list>
struct AVPacket;
class Decode;

class DecodeThread : public QThread
{
public:
    DecodeThread();
    virtual ~DecodeThread();
     virtual void Push(AVPacket *pkt);
    //清理队列
    virtual void Clear();
    //清理资源，停止线程
    virtual void Close();

    //取出一帧数据，并出栈，没有则返回NULL
    virtual AVPacket *Pop();
    //最大队列
int maxList = 100;
bool isExit =false;



protected:
    std::list <AVPacket *> packs;   //用来存放指向AVPacket的指针
    std::mutex mux;
    Decode *decode = 0;
};

#endif // DECODETHREAD_H
