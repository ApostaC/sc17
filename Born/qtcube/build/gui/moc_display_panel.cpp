/****************************************************************************
** Meta object code from reading C++ file 'display_panel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gui/display_panel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'display_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SEP__display_panel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   20,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      67,   62,   19,   19, 0x08,
      92,   88,   19,   19, 0x08,
     114,   19,   19,   19, 0x08,
     129,   19,   19,   19, 0x08,
     143,   19,   19,   19, 0x08,
     155,   19,   19,   19, 0x08,
     172,  166,   19,   19, 0x08,
     186,   19,   19,   19, 0x08,
     198,   19,   19,   19, 0x08,
     209,   19,   19,   19, 0x08,
     221,   19,   19,   19, 0x08,
     232,   19,   19,   19, 0x08,
     244,   19,   19,   19, 0x08,
     255,   19,   19,   19, 0x08,
     267,   19,   19,   19, 0x08,
     278,   19,   19,   19, 0x08,
     289,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SEP__display_panel[] = {
    "SEP::display_panel\0\0text\0"
    "actionDetected(std::vector<QString>)\0"
    "font\0change_font(QString)\0col\0"
    "change_color(QString)\0yes_colorbar()\0"
    "no_colorbar()\0yes_title()\0no_title()\0"
    "alpha\0draw_pos(int)\0yes_axis1()\0"
    "no_axis1()\0yes_axis2()\0no_axis2()\0"
    "yes_axis3()\0no_axis3()\0yes_picks()\0"
    "no_picks()\0yes_grid()\0no_grid()\0"
};

void SEP::display_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        display_panel *_t = static_cast<display_panel *>(_o);
        switch (_id) {
        case 0: _t->actionDetected((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 1: _t->change_font((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->change_color((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->yes_colorbar(); break;
        case 4: _t->no_colorbar(); break;
        case 5: _t->yes_title(); break;
        case 6: _t->no_title(); break;
        case 7: _t->draw_pos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->yes_axis1(); break;
        case 9: _t->no_axis1(); break;
        case 10: _t->yes_axis2(); break;
        case 11: _t->no_axis2(); break;
        case 12: _t->yes_axis3(); break;
        case 13: _t->no_axis3(); break;
        case 14: _t->yes_picks(); break;
        case 15: _t->no_picks(); break;
        case 16: _t->yes_grid(); break;
        case 17: _t->no_grid(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SEP::display_panel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SEP::display_panel::staticMetaObject = {
    { &qcubeWidgetBasic::staticMetaObject, qt_meta_stringdata_SEP__display_panel,
      qt_meta_data_SEP__display_panel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SEP::display_panel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SEP::display_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SEP::display_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SEP__display_panel))
        return static_cast<void*>(const_cast< display_panel*>(this));
    return qcubeWidgetBasic::qt_metacast(_clname);
}

int SEP::display_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = qcubeWidgetBasic::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void SEP::display_panel::actionDetected(std::vector<QString> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
