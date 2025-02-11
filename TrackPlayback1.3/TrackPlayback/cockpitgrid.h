#ifndef COCKPITGRID_H
#define COCKPITGRID_H


#include <qframe.h>
#include <qpalette.h>

class QwtDial;
class AttitudeIndicator;
class SpeedoMeter;

class CockpitGrid: public QFrame
{
    Q_OBJECT

public:
    CockpitGrid( QWidget *parent = NULL );


private Q_SLOTS:
    void changeSpeed();
    void changeGradient();
    void changeAngle();

private:
    QPalette colorTheme( const QColor & ) const;
    QwtDial *createDial(int pos );


    AttitudeIndicator *d_ai;
    SpeedoMeter *d_speedo;
};

#endif // COCKPITGRID_H
