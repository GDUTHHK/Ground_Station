#ifndef CPUPIEMARKER_H
#define CPUPIEMARKER_H


#include <qwt_plot_item.h>

class CpuPieMarker: public QwtPlotItem
{
public:
    CpuPieMarker();

    virtual int rtti() const;

    virtual void draw( QPainter *,
        const QwtScaleMap &, const QwtScaleMap &, const QRectF & ) const;
};


#endif // CPUPIEMARKER_H
