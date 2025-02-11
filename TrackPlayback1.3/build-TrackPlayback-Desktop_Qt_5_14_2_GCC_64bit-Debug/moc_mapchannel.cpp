/****************************************************************************
** Meta object code from reading C++ file 'mapchannel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../TrackPlayback/mapchannel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapchannel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MapChannel_t {
    QByteArrayData data[27];
    char stringdata0[329];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MapChannel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MapChannel_t qt_meta_stringdata_MapChannel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MapChannel"
QT_MOC_LITERAL(1, 11, 17), // "mousePointChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "reloadMapClicked"
QT_MOC_LITERAL(4, 47, 8), // "taskCome"
QT_MOC_LITERAL(5, 56, 10), // "pointsCome"
QT_MOC_LITERAL(6, 67, 15), // "addPointClicked"
QT_MOC_LITERAL(7, 83, 16), // "movePointClicked"
QT_MOC_LITERAL(8, 100, 14), // "setOriginPoint"
QT_MOC_LITERAL(9, 115, 14), // "boatPosUpdated"
QT_MOC_LITERAL(10, 130, 20), // "addFencePointClicked"
QT_MOC_LITERAL(11, 151, 15), // "addFenceClicked"
QT_MOC_LITERAL(12, 167, 17), // "clearFenceClicked"
QT_MOC_LITERAL(13, 185, 21), // "clearWaypointsClicked"
QT_MOC_LITERAL(14, 207, 15), // "clearAllClicked"
QT_MOC_LITERAL(15, 223, 17), // "clearTrackClicked"
QT_MOC_LITERAL(16, 241, 12), // "panToClicked"
QT_MOC_LITERAL(17, 254, 13), // "getMousePoint"
QT_MOC_LITERAL(18, 268, 3), // "lng"
QT_MOC_LITERAL(19, 272, 3), // "lat"
QT_MOC_LITERAL(20, 276, 9), // "reloadMap"
QT_MOC_LITERAL(21, 286, 9), // "transTask"
QT_MOC_LITERAL(22, 296, 4), // "type"
QT_MOC_LITERAL(23, 301, 3), // "len"
QT_MOC_LITERAL(24, 305, 11), // "transPoints"
QT_MOC_LITERAL(25, 317, 2), // "id"
QT_MOC_LITERAL(26, 320, 8) // "clearAll"

    },
    "MapChannel\0mousePointChanged\0\0"
    "reloadMapClicked\0taskCome\0pointsCome\0"
    "addPointClicked\0movePointClicked\0"
    "setOriginPoint\0boatPosUpdated\0"
    "addFencePointClicked\0addFenceClicked\0"
    "clearFenceClicked\0clearWaypointsClicked\0"
    "clearAllClicked\0clearTrackClicked\0"
    "panToClicked\0getMousePoint\0lng\0lat\0"
    "reloadMap\0transTask\0type\0len\0transPoints\0"
    "id\0clearAll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MapChannel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  114,    2, 0x06 /* Public */,
       3,    0,  119,    2, 0x06 /* Public */,
       4,    2,  120,    2, 0x06 /* Public */,
       5,    3,  125,    2, 0x06 /* Public */,
       6,    2,  132,    2, 0x06 /* Public */,
       7,    3,  137,    2, 0x06 /* Public */,
       8,    2,  144,    2, 0x06 /* Public */,
       9,    3,  149,    2, 0x06 /* Public */,
      10,    2,  156,    2, 0x06 /* Public */,
      11,    0,  161,    2, 0x06 /* Public */,
      12,    0,  162,    2, 0x06 /* Public */,
      13,    0,  163,    2, 0x06 /* Public */,
      14,    0,  164,    2, 0x06 /* Public */,
      15,    0,  165,    2, 0x06 /* Public */,
      16,    2,  166,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    2,  171,    2, 0x0a /* Public */,
      20,    0,  176,    2, 0x0a /* Public */,
      21,    2,  177,    2, 0x0a /* Public */,
      24,    3,  182,    2, 0x0a /* Public */,
      26,    0,  189,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double,    2,    2,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double,    2,    2,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    2,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   18,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   22,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double,   25,   18,   19,
    QMetaType::Void,

       0        // eod
};

void MapChannel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MapChannel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mousePointChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->reloadMapClicked(); break;
        case 2: _t->taskCome((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->pointsCome((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 4: _t->addPointClicked((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 5: _t->movePointClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 6: _t->setOriginPoint((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 7: _t->boatPosUpdated((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 8: _t->addFencePointClicked((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 9: _t->addFenceClicked(); break;
        case 10: _t->clearFenceClicked(); break;
        case 11: _t->clearWaypointsClicked(); break;
        case 12: _t->clearAllClicked(); break;
        case 13: _t->clearTrackClicked(); break;
        case 14: _t->panToClicked((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 15: _t->getMousePoint((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 16: _t->reloadMap(); break;
        case 17: _t->transTask((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: _t->transPoints((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 19: _t->clearAll(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MapChannel::*)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapChannel::mousePointChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MapChannel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapChannel::reloadMapClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MapChannel::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapChannel::taskCome)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MapChannel::*)(int , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapChannel::pointsCome)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MapChannel::*)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapChannel::addPointClicked)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MapChannel::*)(int , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapChannel::movePointClicked)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MapChannel::*)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapChannel::setOriginPoint)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MapChannel::*)(double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapChannel::boatPosUpdated)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MapChannel::*)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapChannel::addFencePointClicked)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MapChannel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapChannel::addFenceClicked)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MapChannel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapChannel::clearFenceClicked)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MapChannel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapChannel::clearWaypointsClicked)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (MapChannel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapChannel::clearAllClicked)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (MapChannel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapChannel::clearTrackClicked)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (MapChannel::*)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MapChannel::panToClicked)) {
                *result = 14;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MapChannel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MapChannel.data,
    qt_meta_data_MapChannel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MapChannel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MapChannel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MapChannel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MapChannel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void MapChannel::mousePointChanged(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MapChannel::reloadMapClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MapChannel::taskCome(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MapChannel::pointsCome(int _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MapChannel::addPointClicked(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MapChannel::movePointClicked(int _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MapChannel::setOriginPoint(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MapChannel::boatPosUpdated(double _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MapChannel::addFencePointClicked(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MapChannel::addFenceClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void MapChannel::clearFenceClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void MapChannel::clearWaypointsClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void MapChannel::clearAllClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void MapChannel::clearTrackClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void MapChannel::panToClicked(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
