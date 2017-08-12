/****************************************************************************
** Meta object code from reading C++ file 'panel_panel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gui/panel_panel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'panel_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SEP__panel_panel[] = {

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
      23,   18,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      60,   18,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SEP__panel_panel[] = {
    "SEP::panel_panel\0\0text\0"
    "actionDetected(std::vector<QString>)\0"
    "actionRespond(std::vector<QString>)\0"
};

void SEP::panel_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        panel_panel *_t = static_cast<panel_panel *>(_o);
        switch (_id) {
        case 0: _t->actionDetected((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 1: _t->actionRespond((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SEP::panel_panel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SEP::panel_panel::staticMetaObject = {
    { &qcubeTabBasic::staticMetaObject, qt_meta_stringdata_SEP__panel_panel,
      qt_meta_data_SEP__panel_panel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SEP::panel_panel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SEP::panel_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SEP::panel_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SEP__panel_panel))
        return static_cast<void*>(const_cast< panel_panel*>(this));
    return qcubeTabBasic::qt_metacast(_clname);
}

int SEP::panel_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SEP::panel_panel::actionDetected(std::vector<QString> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_SEP__sub_panel_panel[] = {

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
      27,   22,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      64,   22,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SEP__sub_panel_panel[] = {
    "SEP::sub_panel_panel\0\0text\0"
    "actionDetected(std::vector<QString>)\0"
    "actionRespond(std::vector<QString>)\0"
};

void SEP::sub_panel_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        sub_panel_panel *_t = static_cast<sub_panel_panel *>(_o);
        switch (_id) {
        case 0: _t->actionDetected((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 1: _t->actionRespond((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SEP::sub_panel_panel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SEP::sub_panel_panel::staticMetaObject = {
    { &qcubeTabBasic::staticMetaObject, qt_meta_stringdata_SEP__sub_panel_panel,
      qt_meta_data_SEP__sub_panel_panel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SEP::sub_panel_panel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SEP::sub_panel_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SEP::sub_panel_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SEP__sub_panel_panel))
        return static_cast<void*>(const_cast< sub_panel_panel*>(this));
    return qcubeTabBasic::qt_metacast(_clname);
}

int SEP::sub_panel_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SEP::sub_panel_panel::actionDetected(std::vector<QString> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
