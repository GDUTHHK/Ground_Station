#include "mapchannel.h"

MapChannel::MapChannel(QObject *parent) : QObject(parent)
{

}

void MapChannel::getMousePoint(double lng, double lat)
{
    emit mousePointChanged(lng,lat);
    cout<<"mousePointChanged"<<endl;
}

void MapChannel::addPoint(double lng, double lat)
{
    emit addPointClicked(lng,lat);
    cout<<"addPointClicked"<<endl;
}

void MapChannel::movePoint(int id, double lng, double lat)
{
    emit movePointClicked(id,lng,lat);
    cout<<"movePointClicked"<<endl;
}

void MapChannel::transTask(int type, int len)
{
    emit taskCome(type,len);
    cout<<"taskCome"<<endl;
}

void MapChannel::transPoints(int id, double lng, double lat)
{
    emit pointsCome(id,lng,lat);
    cout<<"pointsCome"<<endl;
}

void MapChannel::updateBoatPos(double lng, double lat, double course)
{
    emit boatPosUpdated(lng,lat,course);
    cout<<"boatPosUpdated"<<endl;
}

void MapChannel::reloadMap()
{
    emit reloadMapClicked();
    cout<<"reloadMapClicked"<<endl;
}

void MapChannel::setOrigin(double lng, double lat)
{
    emit setOriginPoint(lng,lat);
    cout<<"setOriginPoint"<<endl;
}

void MapChannel::clearWaypoints()
{
    emit clearWaypointsClicked();
    cout<<"clearWaypointsClicked"<<endl;
}

void MapChannel::clearAll()
{
    emit clearAllClicked();
    cout<<"clearAllClicked"<<endl;
}

void MapChannel::addFencePoint(double lng, double lat)
{
    emit addFencePointClicked(lng,lat);
    cout<<"addFencePointClicked"<<endl;
}

void MapChannel::addFence()
{
    emit addFenceClicked();
    cout<<"addFenceClicked"<<endl;
}

void MapChannel::clearFence()
{
    emit clearFenceClicked();
    cout<<"clearFenceClicked"<<endl;
}

void MapChannel::panTo(double lng, double lat)
{
    emit panToClicked(lng,lat);
    cout<<"mousePointChanged"<<endl;
}

void MapChannel::clearTrack()
{
    emit clearTrackClicked();
    cout<<"mousePointChanged"<<endl;
}
