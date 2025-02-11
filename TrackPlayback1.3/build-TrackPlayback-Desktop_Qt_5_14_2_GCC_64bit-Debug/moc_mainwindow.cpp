/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../TrackPlayback/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[406];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 6), // "update"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "updateTrack"
QT_MOC_LITERAL(4, 31, 9), // "reloadMap"
QT_MOC_LITERAL(5, 41, 18), // "clear_target_point"
QT_MOC_LITERAL(6, 60, 19), // "updaterealtimetrack"
QT_MOC_LITERAL(7, 80, 31), // "on_pushButton_open_file_clicked"
QT_MOC_LITERAL(8, 112, 27), // "on_pushButton_start_clicked"
QT_MOC_LITERAL(9, 140, 41), // "on_comboBox_times_vel_current..."
QT_MOC_LITERAL(10, 182, 5), // "index"
QT_MOC_LITERAL(11, 188, 16), // "socket_Read_Data"
QT_MOC_LITERAL(12, 205, 19), // "socket_Disconnected"
QT_MOC_LITERAL(13, 225, 38), // "on_pushButton_realtime_displa..."
QT_MOC_LITERAL(14, 264, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(15, 286, 33), // "on_pushButton_connect_tcp_cli..."
QT_MOC_LITERAL(16, 320, 31), // "on_pushButton_send_data_clicked"
QT_MOC_LITERAL(17, 352, 31), // "on_pushButton_control_s_clicked"
QT_MOC_LITERAL(18, 384, 21) // "on_play_video_clicked"

    },
    "MainWindow\0update\0\0updateTrack\0reloadMap\0"
    "clear_target_point\0updaterealtimetrack\0"
    "on_pushButton_open_file_clicked\0"
    "on_pushButton_start_clicked\0"
    "on_comboBox_times_vel_currentIndexChanged\0"
    "index\0socket_Read_Data\0socket_Disconnected\0"
    "on_pushButton_realtime_display_clicked\0"
    "on_pushButton_clicked\0"
    "on_pushButton_connect_tcp_clicked\0"
    "on_pushButton_send_data_clicked\0"
    "on_pushButton_control_s_clicked\0"
    "on_play_video_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   97,    2, 0x08 /* Private */,
       4,    0,   98,    2, 0x08 /* Private */,
       5,    0,   99,    2, 0x08 /* Private */,
       6,    0,  100,    2, 0x08 /* Private */,
       7,    0,  101,    2, 0x08 /* Private */,
       8,    0,  102,    2, 0x08 /* Private */,
       9,    1,  103,    2, 0x08 /* Private */,
      11,    0,  106,    2, 0x08 /* Private */,
      12,    0,  107,    2, 0x08 /* Private */,
      13,    0,  108,    2, 0x08 /* Private */,
      14,    0,  109,    2, 0x08 /* Private */,
      15,    0,  110,    2, 0x08 /* Private */,
      16,    0,  111,    2, 0x08 /* Private */,
      17,    0,  112,    2, 0x08 /* Private */,
      18,    0,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateTrack(); break;
        case 2: _t->reloadMap(); break;
        case 3: _t->clear_target_point(); break;
        case 4: _t->updaterealtimetrack(); break;
        case 5: _t->on_pushButton_open_file_clicked(); break;
        case 6: _t->on_pushButton_start_clicked(); break;
        case 7: _t->on_comboBox_times_vel_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->socket_Read_Data(); break;
        case 9: _t->socket_Disconnected(); break;
        case 10: _t->on_pushButton_realtime_display_clicked(); break;
        case 11: _t->on_pushButton_clicked(); break;
        case 12: _t->on_pushButton_connect_tcp_clicked(); break;
        case 13: _t->on_pushButton_send_data_clicked(); break;
        case 14: _t->on_pushButton_control_s_clicked(); break;
        case 15: _t->on_play_video_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::update)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::update(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
