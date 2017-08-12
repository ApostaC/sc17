/****************************************************************************
** Meta object code from reading C++ file 'orient_panel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gui/orient_panel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'orient_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SEP__orient_panel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   19,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      61,   18,   18,   18, 0x08,
      70,   18,   18,   18, 0x08,
      90,   18,   18,   18, 0x08,
      99,   18,   18,   18, 0x08,
     108,   18,   18,   18, 0x08,
     117,   18,   18,   18, 0x08,
     128,  124,   18,   18, 0x08,
     151,  147,   18,   18, 0x08,
     166,  124,   18,   18, 0x08,
     185,  124,   18,   18, 0x08,
     206,   18,   18,   18, 0x08,
     223,   18,   18,   18, 0x08,
     241,   18,   18,   18, 0x08,
     253,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SEP__orient_panel[] = {
    "SEP::orient_panel\0\0text\0"
    "actionDetected(std::vector<QString>)\0"
    "flip_1()\0reset_orientation()\0flip_2()\0"
    "flip_3()\0center()\0edge()\0com\0"
    "transpose(QString)\0ang\0angle_int(int)\0"
    "angle_str(QString)\0rotate_axes(QString)\0"
    "reset_rotation()\0set_rotation_pt()\0"
    "true_prop()\0false_prop()\0"
};

void SEP::orient_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        orient_panel *_t = static_cast<orient_panel *>(_o);
        switch (_id) {
        case 0: _t->actionDetected((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 1: _t->flip_1(); break;
        case 2: _t->reset_orientation(); break;
        case 3: _t->flip_2(); break;
        case 4: _t->flip_3(); break;
        case 5: _t->center(); break;
        case 6: _t->edge(); break;
        case 7: _t->transpose((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->angle_int((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->angle_str((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->rotate_axes((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->reset_rotation(); break;
        case 12: _t->set_rotation_pt(); break;
        case 13: _t->true_prop(); break;
        case 14: _t->false_prop(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SEP::orient_panel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SEP::orient_panel::staticMetaObject = {
    { &qcubeWidgetBasic::staticMetaObject, qt_meta_stringdata_SEP__orient_panel,
      qt_meta_data_SEP__orient_panel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SEP::orient_panel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SEP::orient_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SEP::orient_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SEP__orient_panel))
        return static_cast<void*>(const_cast< orient_panel*>(this));
    return qcubeWidgetBasic::qt_metacast(_clname);
}

int SEP::orient_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = qcubeWidgetBasic::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void SEP::orient_panel::actionDetected(std::vector<QString> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
