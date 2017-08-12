/****************************************************************************
** Meta object code from reading C++ file 'navigate_panel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gui/navigate_panel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'navigate_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SEP__navigate_panel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   21,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,   20,   20,   20, 0x08,
      79,   20,   20,   20, 0x08,
      95,   20,   20,   20, 0x08,
     111,   20,   20,   20, 0x08,
     127,   20,   20,   20, 0x08,
     143,   20,   20,   20, 0x08,
     159,   20,   20,   20, 0x08,
     172,   20,   20,   20, 0x08,
     187,   20,   20,   20, 0x08,
     204,   20,   20,   20, 0x08,
     223,  219,   20,   20, 0x08,
     244,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SEP__navigate_panel[] = {
    "SEP::navigate_panel\0\0text\0"
    "actionDetected(std::vector<QString>)\0"
    "x_neg_clicked()\0x_pos_clicked()\0"
    "y_neg_clicked()\0y_pos_clicked()\0"
    "z_neg_clicked()\0z_pos_clicked()\0"
    "go_clicked()\0stop_clicked()\0"
    "update_clicked()\0step_clicked()\0txt\0"
    "inc_changed(QString)\0speed_changed(int)\0"
};

void SEP::navigate_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        navigate_panel *_t = static_cast<navigate_panel *>(_o);
        switch (_id) {
        case 0: _t->actionDetected((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 1: _t->x_neg_clicked(); break;
        case 2: _t->x_pos_clicked(); break;
        case 3: _t->y_neg_clicked(); break;
        case 4: _t->y_pos_clicked(); break;
        case 5: _t->z_neg_clicked(); break;
        case 6: _t->z_pos_clicked(); break;
        case 7: _t->go_clicked(); break;
        case 8: _t->stop_clicked(); break;
        case 9: _t->update_clicked(); break;
        case 10: _t->step_clicked(); break;
        case 11: _t->inc_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->speed_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SEP::navigate_panel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SEP::navigate_panel::staticMetaObject = {
    { &qcubeWidgetBasic::staticMetaObject, qt_meta_stringdata_SEP__navigate_panel,
      qt_meta_data_SEP__navigate_panel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SEP::navigate_panel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SEP::navigate_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SEP::navigate_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SEP__navigate_panel))
        return static_cast<void*>(const_cast< navigate_panel*>(this));
    return qcubeWidgetBasic::qt_metacast(_clname);
}

int SEP::navigate_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = qcubeWidgetBasic::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void SEP::navigate_panel::actionDetected(std::vector<QString> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
