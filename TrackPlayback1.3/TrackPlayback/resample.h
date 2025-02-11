#ifndef RESAMPLE_H
#define RESAMPLE_H
#include <mutex>
struct AVCodecParameters;
struct SwrContext;
struct AVFrame;
class Resample
{
public:
    //输出参数和输入参数一致除了采样格式,输出为s16
    virtual bool Open(AVCodecParameters *para,bool isClearPara = false);
    virtual void Close();

    //返回重采样后大小,不管成功与否都释放indata空间
    virtual int Res(AVFrame *indata, unsigned char *data);

    Resample();

    //AV_SAMPLE_FMT_S16
        int outFormat = 1;
protected:
    std::mutex mux;
    SwrContext *actx = 0;
};

#endif // RESAMPLE_H
