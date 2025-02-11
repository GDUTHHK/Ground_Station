#include "resample.h"
extern "C"{
#include "libavcodec/avcodec.h"
//#include "libavfilter/avfilter.h"
#include "libavformat/avformat.h"
#include "libavutil/avutil.h"
//#include "libavutil/ffversion.h"
#include "libswresample/swresample.h"
//#include "libswscale/swscale.h"
//#include "libpostproc/postprocess.h"
}
#include <iostream>
using namespace std;
//输出参数和输入参数一致除了采样格式,输出为s16
bool Resample::Open(AVCodecParameters *para,bool isClearPara)
{
    if (!para)return false;
        mux.lock();
        //音频重采样 上下文初始化
        //如果actx为NULL会分配空间
        actx = swr_alloc_set_opts(actx,
            av_get_default_channel_layout(2),	//输出格式
            (AVSampleFormat)outFormat,			//输出样本格式 1 AV_SAMPLE_FMT_S16
            para->sample_rate,					//输出采样率
            av_get_default_channel_layout(para->channels),//输入格式
            (AVSampleFormat)para->format,
            para->sample_rate,
            0, 0
        );
        if(isClearPara)  //默认是不清理
        avcodec_parameters_free(&para);
        int ret = swr_init(actx);
        mux.unlock();
        if (ret != 0)
        {
            char buf[1024] = { 0 };
            av_strerror(ret, buf, sizeof(buf) - 1);
            cout << "swr_init  failed! :" << buf << endl;
            return false;
        }
        //unsigned char *pcm = NULL;
        return true;
}

int Resample::Res(AVFrame *indata, unsigned char *d)
{
    if (!indata) return 0;
    if (!d)
    {
        av_frame_free(&indata);
        return 0;
    }
    uint8_t *data[2] = { 0 };
    data[0] = d;
    int re = swr_convert(actx,
        data, indata->nb_samples,		//输出
        (const uint8_t**)indata->data, indata->nb_samples	//输入
    );

    int outSize = re * indata->channels * av_get_bytes_per_sample((AVSampleFormat)outFormat);
    av_frame_free(&indata);
    if (re <= 0)return re;
    return outSize;
}

void Resample::Close()
{
    mux.lock();
    if (actx)
        swr_free(&actx);

    mux.unlock();
}

Resample::Resample()
{

}
