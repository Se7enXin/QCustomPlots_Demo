/****************************************************************************
** Meta object code from reading C++ file 'signals.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "app/signals/signals.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'signals.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SIGNALS[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      57,    9,    8,    8, 0x05,
     119,    8,    8,    8, 0x05,
     145,    8,    8,    8, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_SIGNALS[] = {
    "SIGNALS\0\0data1_x,data1_y,data2_x,data2_y,data3_x,data3_y\0"
    "update_plots_data_Signal(float,float,float,float,float,float)\0"
    "plots_data_range_signal()\0"
    "clear_plots_data_signal()\0"
};

void SIGNALS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SIGNALS *_t = static_cast<SIGNALS *>(_o);
        switch (_id) {
        case 0: _t->update_plots_data_Signal((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6]))); break;
        case 1: _t->plots_data_range_signal(); break;
        case 2: _t->clear_plots_data_signal(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SIGNALS::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SIGNALS::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SIGNALS,
      qt_meta_data_SIGNALS, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SIGNALS::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SIGNALS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SIGNALS::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SIGNALS))
        return static_cast<void*>(const_cast< SIGNALS*>(this));
    return QObject::qt_metacast(_clname);
}

int SIGNALS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SIGNALS::update_plots_data_Signal(float _t1, float _t2, float _t3, float _t4, float _t5, float _t6)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SIGNALS::plots_data_range_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void SIGNALS::clear_plots_data_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
