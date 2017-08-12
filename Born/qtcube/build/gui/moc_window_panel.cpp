/****************************************************************************
** Meta object code from reading C++ file 'window_panel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gui/window_panel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SEP__window_panel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   19,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      61,   19,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SEP__window_panel[] = {
    "SEP::window_panel\0\0text\0"
    "actionDetected(std::vector<QString>)\0"
    "actionRespond(std::vector<QString>)\0"
};

void SEP::window_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        window_panel *_t = static_cast<window_panel *>(_o);
        switch (_id) {
        case 0: _t->actionDetected((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 1: _t->actionRespond((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SEP::window_panel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SEP::window_panel::staticMetaObject = {
    { &qcubeTabBasic::staticMetaObject, qt_meta_stringdata_SEP__window_panel,
      qt_meta_data_SEP__window_panel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SEP::window_panel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SEP::window_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SEP::window_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SEP__window_panel))
        return static_cast<void*>(const_cast< window_panel*>(this));
    return qcubeTabBasic::qt_metacast(_clname);
}

int SEP::window_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = qcubeTabBasic::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void SEP::window_panel::actionDetected(std::vector<QString> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_SEP__sub_window_panel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   23,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      65,   22,   22,   22, 0x08,
      76,   22,   22,   22, 0x08,
      93,   89,   22,   22, 0x08,
     110,   89,   22,   22, 0x08,
     127,   89,   22,   22, 0x08,
     152,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SEP__sub_window_panel[] = {
    "SEP::sub_window_panel\0\0text\0"
    "actionDetected(std::vector<QString>)\0"
    "save_big()\0save_small()\0com\0"
    "split_x(QString)\0split_y(QString)\0"
    "boundary_change(QString)\0close_window()\0"
};

void SEP::sub_window_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        sub_window_panel *_t = static_cast<sub_window_panel *>(_o);
        switch (_id) {
        case 0: _t->actionDetected((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 1: _t->save_big(); break;
        case 2: _t->save_small(); break;
        case 3: _t->split_x((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->split_y((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->boundary_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->close_window(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SEP::sub_window_panel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SEP::sub_window_panel::staticMetaObject = {
    { &qcubeWidgetBasic::staticMetaObject, qt_meta_stringdata_SEP__sub_window_panel,
      qt_meta_data_SEP__sub_window_panel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SEP::sub_window_panel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SEP::sub_window_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SEP::sub_window_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SEP__sub_window_panel))
        return static_cast<void*>(const_cast< sub_window_panel*>(this));
    return qcubeWidgetBasic::qt_metacast(_clname);
}

int SEP::sub_window_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = qcubeWidgetBasic::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SEP::sub_window_panel::actionDetected(std::vector<QString> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
