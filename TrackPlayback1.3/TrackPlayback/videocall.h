#ifndef VIDEOCALL_H
#define VIDEOCALL_H
struct AVFrame;
//隔离接口，到时换显示方式时，videothread不需要更改，
class VideoCall
{
public:
    virtual void Init(int width,int height) = 0;
    virtual void Repaint(AVFrame *frame) = 0;
};

#endif // VIDEOCALL_H
