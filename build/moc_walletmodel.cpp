/****************************************************************************
** Meta object code from reading C++ file 'walletmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qt/walletmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'walletmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WalletModel_t {
    QByteArrayData data[22];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WalletModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WalletModel_t qt_meta_stringdata_WalletModel = {
    {
QT_MOC_LITERAL(0, 0, 11), // "WalletModel"
QT_MOC_LITERAL(1, 12, 14), // "balanceChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "balance"
QT_MOC_LITERAL(4, 36, 5), // "stake"
QT_MOC_LITERAL(5, 42, 18), // "unconfirmedBalance"
QT_MOC_LITERAL(6, 61, 15), // "immatureBalance"
QT_MOC_LITERAL(7, 77, 23), // "encryptionStatusChanged"
QT_MOC_LITERAL(8, 101, 6), // "status"
QT_MOC_LITERAL(9, 108, 13), // "requireUnlock"
QT_MOC_LITERAL(10, 122, 7), // "message"
QT_MOC_LITERAL(11, 130, 5), // "title"
QT_MOC_LITERAL(12, 136, 5), // "modal"
QT_MOC_LITERAL(13, 142, 5), // "style"
QT_MOC_LITERAL(14, 148, 12), // "updateStatus"
QT_MOC_LITERAL(15, 161, 17), // "updateTransaction"
QT_MOC_LITERAL(16, 179, 4), // "hash"
QT_MOC_LITERAL(17, 184, 17), // "updateAddressBook"
QT_MOC_LITERAL(18, 202, 7), // "address"
QT_MOC_LITERAL(19, 210, 5), // "label"
QT_MOC_LITERAL(20, 216, 6), // "isMine"
QT_MOC_LITERAL(21, 223, 18) // "pollBalanceChanged"

    },
    "WalletModel\0balanceChanged\0\0balance\0"
    "stake\0unconfirmedBalance\0immatureBalance\0"
    "encryptionStatusChanged\0status\0"
    "requireUnlock\0message\0title\0modal\0"
    "style\0updateStatus\0updateTransaction\0"
    "hash\0updateAddressBook\0address\0label\0"
    "isMine\0pollBalanceChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WalletModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   54,    2, 0x06 /* Public */,
       7,    1,   63,    2, 0x06 /* Public */,
       9,    0,   66,    2, 0x06 /* Public */,
      10,    4,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,   76,    2, 0x0a /* Public */,
      15,    2,   77,    2, 0x0a /* Public */,
      17,    4,   82,    2, 0x0a /* Public */,
      21,    0,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::LongLong, QMetaType::LongLong,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::UInt,   11,   10,   12,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   16,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Int,   18,   19,   20,    8,
    QMetaType::Void,

       0        // eod
};

void WalletModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WalletModel *_t = static_cast<WalletModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->balanceChanged((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4]))); break;
        case 1: _t->encryptionStatusChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->requireUnlock(); break;
        case 3: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4]))); break;
        case 4: _t->updateStatus(); break;
        case 5: _t->updateTransaction((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->updateAddressBook((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 7: _t->pollBalanceChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WalletModel::*_t)(qint64 , qint64 , qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WalletModel::balanceChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WalletModel::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WalletModel::encryptionStatusChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WalletModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WalletModel::requireUnlock)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (WalletModel::*_t)(const QString & , const QString & , bool , unsigned int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WalletModel::message)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject WalletModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WalletModel.data,
      qt_meta_data_WalletModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WalletModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WalletModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WalletModel.stringdata0))
        return static_cast<void*>(const_cast< WalletModel*>(this));
    return QObject::qt_metacast(_clname);
}

int WalletModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void WalletModel::balanceChanged(qint64 _t1, qint64 _t2, qint64 _t3, qint64 _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WalletModel::encryptionStatusChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WalletModel::requireUnlock()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void WalletModel::message(const QString & _t1, const QString & _t2, bool _t3, unsigned int _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
