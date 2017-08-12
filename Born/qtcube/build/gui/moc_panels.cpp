/****************************************************************************
** Meta object code from reading C++ file 'panels.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gui/panels.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'panels.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SEP__panels[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   13,   12,   12, 0x05,
      55,   13,   12,   12, 0x05,
      95,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     112,   13,   12,   12, 0x08,
     148,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SEP__panels[] = {
    "SEP::panels\0\0text\0"
    "actionDetected(std::vector<QString>)\0"
    "secondaryDetected(std::vector<QString>)\0"
    "windows_update()\0actionRespond(std::vector<QString>)\0"
    "update_movie()\0"
};

void SEP::panels::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        panels *_t = static_cast<panels *>(_o);
        switch (_id) {
        case 0: _t->actionDetected((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 1: _t->secondaryDetected((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 2: _t->windows_update(); break;
        case 3: _t->actionRespond((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 4: _t->update_movie(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SEP::panels::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SEP::panels::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SEP__panels,
      qt_meta_data_SEP__panels, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SEP::panels::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SEP::panels::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SEP::panels::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SEP__panels))
        return static_cast<void*>(const_cast< panels*>(this));
    return QObject::qt_metacast(_clname);
}

int SEP::panels::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SEP::panels::actionDetected(std::vector<QString> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SEP::panels::secondaryDetected(std::vector<QString> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SEP::panels::windows_update()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
