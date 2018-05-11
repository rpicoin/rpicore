/****************************************************************************
** Meta object code from reading C++ file 'clientmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qt/clientmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClientModel_t {
    QByteArrayData data[20];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientModel_t qt_meta_stringdata_ClientModel = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ClientModel"
QT_MOC_LITERAL(1, 12, 21), // "numConnectionsChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5), // "count"
QT_MOC_LITERAL(4, 41, 16), // "numBlocksChanged"
QT_MOC_LITERAL(5, 58, 13), // "alertsChanged"
QT_MOC_LITERAL(6, 72, 8), // "warnings"
QT_MOC_LITERAL(7, 81, 12), // "bytesChanged"
QT_MOC_LITERAL(8, 94, 12), // "totalBytesIn"
QT_MOC_LITERAL(9, 107, 13), // "totalBytesOut"
QT_MOC_LITERAL(10, 121, 7), // "message"
QT_MOC_LITERAL(11, 129, 5), // "title"
QT_MOC_LITERAL(12, 135, 5), // "modal"
QT_MOC_LITERAL(13, 141, 5), // "style"
QT_MOC_LITERAL(14, 147, 11), // "updateTimer"
QT_MOC_LITERAL(15, 159, 20), // "updateNumConnections"
QT_MOC_LITERAL(16, 180, 14), // "numConnections"
QT_MOC_LITERAL(17, 195, 11), // "updateAlert"
QT_MOC_LITERAL(18, 207, 4), // "hash"
QT_MOC_LITERAL(19, 212, 6) // "status"

    },
    "ClientModel\0numConnectionsChanged\0\0"
    "count\0numBlocksChanged\0alertsChanged\0"
    "warnings\0bytesChanged\0totalBytesIn\0"
    "totalBytesOut\0message\0title\0modal\0"
    "style\0updateTimer\0updateNumConnections\0"
    "numConnections\0updateAlert\0hash\0status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       5,    1,   60,    2, 0x06 /* Public */,
       7,    2,   63,    2, 0x06 /* Public */,
      10,    4,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,   77,    2, 0x0a /* Public */,
      15,    1,   78,    2, 0x0a /* Public */,
      17,    2,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::ULongLong, QMetaType::ULongLong,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::UInt,   11,   10,   12,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   18,   19,

       0        // eod
};

void ClientModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientModel *_t = static_cast<ClientModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->numConnectionsChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->numBlocksChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->alertsChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->bytesChanged((*reinterpret_cast< quint64(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 4: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4]))); break;
        case 5: _t->updateTimer(); break;
        case 6: _t->updateNumConnections((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->updateAlert((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ClientModel::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientModel::numConnectionsChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ClientModel::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientModel::numBlocksChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ClientModel::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientModel::alertsChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ClientModel::*_t)(quint64 , quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientModel::bytesChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ClientModel::*_t)(const QString & , const QString & , bool , unsigned int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientModel::message)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject ClientModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClientModel.data,
      qt_meta_data_ClientModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClientModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClientModel.stringdata0))
        return static_cast<void*>(const_cast< ClientModel*>(this));
    return QObject::qt_metacast(_clname);
}

int ClientModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ClientModel::numConnectionsChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientModel::numBlocksChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClientModel::alertsChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ClientModel::bytesChanged(quint64 _t1, quint64 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ClientModel::message(const QString & _t1, const QString & _t2, bool _t3, unsigned int _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
