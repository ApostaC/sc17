/****************************************************************************
** Meta object code from reading C++ file 'ano_panel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gui/ano_panel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ano_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SEP__ano_panel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   15,   15,   15, 0x08,
      72,   15,   15,   15, 0x08,
      87,   15,   15,   15, 0x08,
     103,   15,   15,   15, 0x08,
     118,   15,   15,   15, 0x08,
     139,  135,   15,   15, 0x08,
     161,  135,   15,   15, 0x08,
     183,  135,   15,   15, 0x08,
     204,  135,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SEP__ano_panel[] = {
    "SEP::ano_panel\0\0coms\0"
    "actionDetected(std::vector<QString>)\0"
    "sbox_change()\0stext_change()\0"
    "sarrow_change()\0sline_change()\0"
    "selipse_change()\0txt\0color_change(QString)\0"
    "thick_change(QString)\0text_change(QString)\0"
    "font_change(QString)\0"
};

void SEP::ano_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ano_panel *_t = static_cast<ano_panel *>(_o);
        switch (_id) {
        case 0: _t->actionDetected((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 1: _t->sbox_change(); break;
        case 2: _t->stext_change(); break;
        case 3: _t->sarrow_change(); break;
        case 4: _t->sline_change(); break;
        case 5: _t->selipse_change(); break;
        case 6: _t->color_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->thick_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->text_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->font_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SEP::ano_panel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SEP::ano_panel::staticMetaObject = {
    { &qcubeWidgetBasic::staticMetaObject, qt_meta_stringdata_SEP__ano_panel,
      qt_meta_data_SEP__ano_panel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SEP::ano_panel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SEP::ano_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SEP::ano_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SEP__ano_panel))
        return static_cast<void*>(const_cast< ano_panel*>(this));
    return qcubeWidgetBasic::qt_metacast(_clname);
}

int SEP::ano_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = qcubeWidgetBasic::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void SEP::ano_panel::actionDetected(std::vector<QString> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
