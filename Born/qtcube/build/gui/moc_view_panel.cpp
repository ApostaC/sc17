/****************************************************************************
** Meta object code from reading C++ file 'view_panel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gui/view_panel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'view_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SEP__view_panel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,   59,   16,   16, 0x08,
      87,   59,   16,   16, 0x08,
     112,   59,   16,   16, 0x08,
     133,   59,   16,   16, 0x08,
     155,   59,   16,   16, 0x08,
     183,   59,   16,   16, 0x08,
     212,   59,   16,   16, 0x08,
     239,   59,   16,   16, 0x08,
     266,   59,   16,   16, 0x08,
     287,   16,   16,   16, 0x08,
     298,   59,   16,   16, 0x08,
     328,   59,   16,   16, 0x08,
     354,   59,   16,   16, 0x08,
     384,   59,   16,   16, 0x08,
     415,   59,   16,   16, 0x08,
     437,   59,   16,   16, 0x08,
     459,   59,   16,   16, 0x08,
     482,   16,   16,   16, 0x08,
     502,   16,   16,   16, 0x08,
     522,   16,   16,   16, 0x08,
     539,   16,   16,   16, 0x08,
     560,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SEP__view_panel[] = {
    "SEP::view_panel\0\0text\0"
    "actionDetected(std::vector<QString>)\0"
    "str\0display_change(QString)\0"
    "odisplay_change(QString)\0data_change(QString)\0"
    "odata_change(QString)\0perspective_change(QString)\0"
    "wiggle_color_change(QString)\0"
    "wiggle_pos_change(QString)\0"
    "wiggle_neg_change(QString)\0"
    "change_map1(QString)\0load_map()\0"
    "contour_color_change(QString)\0"
    "num_lines_change(QString)\0"
    "first_contour_change(QString)\0"
    "sample_contour_change(QString)\0"
    "change_grid1(QString)\0change_grid2(QString)\0"
    "change_jplane(QString)\0update_opactiy(int)\0"
    "roundRobinForward()\0roundRobinBack()\0"
    "oRoundRobinForward()\0oRoundRobinBack()\0"
};

void SEP::view_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        view_panel *_t = static_cast<view_panel *>(_o);
        switch (_id) {
        case 0: _t->actionDetected((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 1: _t->display_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->odisplay_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->data_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->odata_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->perspective_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->wiggle_color_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->wiggle_pos_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->wiggle_neg_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->change_map1((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->load_map(); break;
        case 11: _t->contour_color_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->num_lines_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->first_contour_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->sample_contour_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->change_grid1((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->change_grid2((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->change_jplane((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->update_opactiy((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->roundRobinForward(); break;
        case 20: _t->roundRobinBack(); break;
        case 21: _t->oRoundRobinForward(); break;
        case 22: _t->oRoundRobinBack(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SEP::view_panel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SEP::view_panel::staticMetaObject = {
    { &qcubeWidgetBasic::staticMetaObject, qt_meta_stringdata_SEP__view_panel,
      qt_meta_data_SEP__view_panel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SEP::view_panel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SEP::view_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SEP::view_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SEP__view_panel))
        return static_cast<void*>(const_cast< view_panel*>(this));
    return qcubeWidgetBasic::qt_metacast(_clname);
}

int SEP::view_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = qcubeWidgetBasic::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void SEP::view_panel::actionDetected(std::vector<QString> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
