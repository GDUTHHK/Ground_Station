#include "attitudeindicator.h"
#include <qwt_point_polar.h>
#include <qwt_round_scale_draw.h>
#include <qevent.h>
#include <qpainter.h>
#include <qpolygon.h>
#include <QPainterPath>

AttitudeIndicatorNeedle::AttitudeIndicatorNeedle( const QColor &color )
{
    QPalette palette;   //用来设置颜色的类
    palette.setColor( QPalette::Text, color );  //设置颜色
    setPalette( palette );
}

void AttitudeIndicatorNeedle::drawNeedle( QPainter *painter,
    double length, QPalette::ColorGroup colorGroup ) const
{
    double triangleSize = length * 0.1;  //根据表盘的长度确定三角形指针的大小
    double pos = length - 2.0;   //根据表盘的长度确定三角形指针的位置

    QPainterPath path;  //用于填充，概述和裁剪
    //以下三步画了个三角形
    path.moveTo( pos, 0 );
    path.lineTo( pos - 2 * triangleSize, triangleSize );
    path.lineTo( pos - 2 * triangleSize, -triangleSize );
    path.closeSubpath();  //通过在子路径的开头绘制一条线来关闭当前子路径，从而自动开始新路径。新路径的当前点是(0,0)。

    painter->setBrush( palette().brush( colorGroup, QPalette::Text ) );  //设置三角形指针背景的颜色
    painter->drawPath( path );   //画出该三角形指针

    //以下三步画出表盘中水平的那条线段
    double l = length - 2;
    painter->setPen( QPen( palette().color( colorGroup, QPalette::Text ), 3 ) );
    painter->drawLine( QPointF( 0.0, -l ), QPointF( 0.0, l ) );
}

AttitudeIndicator::AttitudeIndicator(
    QWidget *parent ):
    QwtDial( parent ),
    d_gradient( 0.0 )
{
    QwtRoundScaleDraw *scaleDraw = new QwtRoundScaleDraw();
    scaleDraw->enableComponent( QwtAbstractScaleDraw::Backbone, false );
    scaleDraw->enableComponent( QwtAbstractScaleDraw::Labels, false );
    setScaleDraw( scaleDraw );  //应用之前设置的属性

    setMode( RotateScale );   //设置旋转的是指针还是表盘
    setWrapping( true );

    setOrigin( 270.0 );

    setScaleMaxMinor( 0 );
    setScaleStepSize( 30.0 );
    setScale( 0.0, 360.0 );

    const QColor color = palette().color( QPalette::Text );
    setNeedle( new AttitudeIndicatorNeedle( color ) );
}

void AttitudeIndicator::setGradient( double gradient )
{
    if ( gradient < -1.0 )
        gradient = -1.0;
    else if ( gradient > 1.0 )
        gradient = 1.0;

    if ( d_gradient != gradient )
    {
        d_gradient = gradient;
        update();
    }
}

void AttitudeIndicator::drawScale( QPainter *painter,
    const QPointF &center, double radius ) const
{
    const double offset = 4.0;

    const QPointF p0 = qwtPolar2Pos( center, offset, 1.5 * M_PI );

    const double w = innerRect().width();

    QPainterPath path;
    path.moveTo( qwtPolar2Pos( p0, w, 0.0 ) );
    path.lineTo( qwtPolar2Pos( path.currentPosition(), 2 * w, M_PI ) );
    path.lineTo( qwtPolar2Pos( path.currentPosition(), w, 0.5 * M_PI ) );
    path.lineTo( qwtPolar2Pos( path.currentPosition(), w, 0.0 ) );

    painter->save();
    painter->setClipPath( path ); // swallow 180 - 360 degrees

    QwtDial::drawScale( painter, center, radius );

    painter->restore();
}

void AttitudeIndicator::drawScaleContents( QPainter *painter,
        const QPointF &, double ) const
{
    int dir = 360 - qRound( origin() - value() ); // counter clockwise
    int arc = 90 + qRound( gradient() * 90 );

    const QColor skyColor( 38, 151, 221 );

    painter->save();
    painter->setBrush( skyColor );
    painter->drawChord( scaleInnerRect(),
        ( dir - arc ) * 16, 2 * arc * 16 );
   painter->restore();
}

void AttitudeIndicator::keyPressEvent( QKeyEvent *event )
{
    switch( event->key() )
    {
        case Qt::Key_Plus:
        {
            setGradient( gradient() + 0.05 );
            break;
        }
        case Qt::Key_Minus:
        {
            setGradient( gradient() - 0.05 );
            break;
        }
        default:
            QwtDial::keyPressEvent( event );
    }
}
