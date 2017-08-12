/****************************************************************************
** Meta object code from reading C++ file 'pick_panel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gui/pick_panel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pick_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SEP__pick_panel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,   59,   16,   16, 0x08,
      85,   59,   16,   16, 0x08,
     106,   16,   16,   16, 0x08,
     123,   16,   16,   16, 0x08,
     138,   16,   16,   16, 0x08,
     153,   59,   16,   16, 0x08,
     176,   16,   16,   16, 0x08,
     189,   16,   16,   16, 0x08,
     209,  202,   16,   16, 0x08,
     230,   59,   16,   16, 0x08,
     252,   16,   16,   16, 0x08,
     268,   16,   16,   16, 0x08,
     284,   59,   16,   16, 0x08,
     305,   16,   16,   16, 0x08,
     315,   16,   16,   16, 0x08,
     329,   16,   16,   16, 0x08,
     344,   16,   16,   16, 0x08,
     358,   59,   16,   16, 0x08,
     379,   59,   16,   16, 0x08,
     398,   59,   16,   16, 0x08,
     416,   59,   16,   16, 0x08,
     435,   59,   16,   16, 0x08,
     455,   59,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SEP__pick_panel[] = {
    "SEP::pick_panel\0\0coms\0"
    "actionDetected(std::vector<QString>)\0"
    "txt\0group_change(QString)\0"
    "view_change(QString)\0display_points()\0"
    "display_line()\0display_text()\0"
    "single_change(QString)\0load_picks()\0"
    "save_picks()\0change\0distance_change(int)\0"
    "extra_change(QString)\0increase_size()\0"
    "decrease_size()\0change_text(QString)\0"
    "auto_do()\0auto_accept()\0auto_decline()\0"
    "auto_extend()\0auto_method(QString)\0"
    "auto_type(QString)\0auto_len(QString)\0"
    "auto_maxd(QString)\0auto_error(QString)\0"
    "auto_direction(QString)\0"
};

void SEP::pick_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        pick_panel *_t = static_cast<pick_panel *>(_o);
        switch (_id) {
        case 0: _t->actionDetected((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 1: _t->group_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->view_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->display_points(); break;
        case 4: _t->display_line(); break;
        case 5: _t->display_text(); break;
        case 6: _t->single_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->load_picks(); break;
        case 8: _t->save_picks(); break;
        case 9: _t->distance_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->extra_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->increase_size(); break;
        case 12: _t->decrease_size(); break;
        case 13: _t->change_text((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->auto_do(); break;
        case 15: _t->auto_accept(); break;
        case 16: _t->auto_decline(); break;
        case 17: _t->auto_extend(); break;
        case 18: _t->auto_method((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->auto_type((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->auto_len((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->auto_maxd((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->auto_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: _t->auto_direction((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SEP::pick_panel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SEP::pick_panel::staticMetaObject = {
    { &qcubeWidgetBasic::staticMetaObject, qt_meta_stringdata_SEP__pick_panel,
      qt_meta_data_SEP__pick_panel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SEP::pick_panel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SEP::pick_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SEP::pick_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SEP__pick_panel))
        return static_cast<void*>(const_cast< pick_panel*>(this));
    return qcubeWidgetBasic::qt_metacast(_clname);
}

int SEP::pick_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = qcubeWidgetBasic::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void SEP::pick_panel::actionDetected(std::vector<QString> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
