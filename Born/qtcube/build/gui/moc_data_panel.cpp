/****************************************************************************
** Meta object code from reading C++ file 'data_panel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gui/data_panel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'data_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SEP__data_panel[] = {

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
      22,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      59,   17,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SEP__data_panel[] = {
    "SEP::data_panel\0\0text\0"
    "actionDetected(std::vector<QString>)\0"
    "actionRespond(std::vector<QString>)\0"
};

void SEP::data_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        data_panel *_t = static_cast<data_panel *>(_o);
        switch (_id) {
        case 0: _t->actionDetected((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 1: _t->actionRespond((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SEP::data_panel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SEP::data_panel::staticMetaObject = {
    { &qcubeTabBasic::staticMetaObject, qt_meta_stringdata_SEP__data_panel,
      qt_meta_data_SEP__data_panel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SEP::data_panel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SEP::data_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SEP::data_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SEP__data_panel))
        return static_cast<void*>(const_cast< data_panel*>(this));
    return qcubeTabBasic::qt_metacast(_clname);
}

int SEP::data_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SEP::data_panel::actionDetected(std::vector<QString> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_SEP__add_dataset[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   18,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      60,   17,   17,   17, 0x08,
      73,   17,   17,   17, 0x08,
      90,   17,   17,   17, 0x08,
     107,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SEP__add_dataset[] = {
    "SEP::add_dataset\0\0text\0"
    "actionDetected(std::vector<QString>)\0"
    "create_sep()\0create_seispak()\0"
    "create_surface()\0create_flatten()\0"
};

void SEP::add_dataset::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        add_dataset *_t = static_cast<add_dataset *>(_o);
        switch (_id) {
        case 0: _t->actionDetected((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 1: _t->create_sep(); break;
        case 2: _t->create_seispak(); break;
        case 3: _t->create_surface(); break;
        case 4: _t->create_flatten(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SEP::add_dataset::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SEP::add_dataset::staticMetaObject = {
    { &qcubeTabBasic::staticMetaObject, qt_meta_stringdata_SEP__add_dataset,
      qt_meta_data_SEP__add_dataset, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SEP::add_dataset::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SEP::add_dataset::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SEP::add_dataset::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SEP__add_dataset))
        return static_cast<void*>(const_cast< add_dataset*>(this));
    return qcubeTabBasic::qt_metacast(_clname);
}

int SEP::add_dataset::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = qcubeTabBasic::qt_metacall(_c, _id, _a);
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
void SEP::add_dataset::actionDetected(std::vector<QString> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_SEP__data_sub_panel[] = {

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
      26,   21,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,   21,   20,   20, 0x08,
     103,   99,   20,   20, 0x08,
     123,   99,   20,   20, 0x08,
     152,  143,   20,   20, 0x08,
     173,   20,   20,   20, 0x08,
     188,   20,   20,   20, 0x08,
     202,   20,   20,   20, 0x08,
     215,   20,   20,   20, 0x08,
     232,   20,   20,   20, 0x08,
     249,   20,   20,   20, 0x08,
     265,   20,   20,   20, 0x08,
     282,   20,   20,   20, 0x08,
     299,   20,   20,   20, 0x08,
     317,   20,   20,   20, 0x08,
     334,   99,   20,   20, 0x08,
     356,   99,   20,   20, 0x08,
     378,   99,   20,   20, 0x08,
     400,   99,   20,   20, 0x08,
     422,   99,   20,   20, 0x08,
     444,   99,   20,   20, 0x08,
     466,   99,   20,   20, 0x08,
     488,   20,   20,   20, 0x08,
     505,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SEP__data_sub_panel[] = {
    "SEP::data_sub_panel\0\0text\0"
    "actionDetected(std::vector<QString>)\0"
    "actionRespond(std::vector<QString>)\0"
    "txt\0change_beg(QString)\0change_end(QString)\0"
    "contrast\0change_contrast(int)\0"
    "symetric_yes()\0symetric_no()\0clip_clear()\0"
    "set_strat_prop()\0set_strat_base()\0"
    "set_strat_top()\0set_strat_pres()\0"
    "set_strat_prog()\0set_strat_vflat()\0"
    "set_strat_best()\0change_axis2(QString)\0"
    "change_axis3(QString)\0change_axis4(QString)\0"
    "change_axis5(QString)\0change_axis6(QString)\0"
    "change_axis7(QString)\0change_axis8(QString)\0"
    "update_surface()\0save_strat()\0"
};

void SEP::data_sub_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        data_sub_panel *_t = static_cast<data_sub_panel *>(_o);
        switch (_id) {
        case 0: _t->actionDetected((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 1: _t->actionRespond((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 2: _t->change_beg((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->change_end((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->change_contrast((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->symetric_yes(); break;
        case 6: _t->symetric_no(); break;
        case 7: _t->clip_clear(); break;
        case 8: _t->set_strat_prop(); break;
        case 9: _t->set_strat_base(); break;
        case 10: _t->set_strat_top(); break;
        case 11: _t->set_strat_pres(); break;
        case 12: _t->set_strat_prog(); break;
        case 13: _t->set_strat_vflat(); break;
        case 14: _t->set_strat_best(); break;
        case 15: _t->change_axis2((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->change_axis3((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->change_axis4((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->change_axis5((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->change_axis6((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->change_axis7((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->change_axis8((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->update_surface(); break;
        case 23: _t->save_strat(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SEP::data_sub_panel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SEP::data_sub_panel::staticMetaObject = {
    { &qcubeTabBasic::staticMetaObject, qt_meta_stringdata_SEP__data_sub_panel,
      qt_meta_data_SEP__data_sub_panel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SEP::data_sub_panel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SEP::data_sub_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SEP::data_sub_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SEP__data_sub_panel))
        return static_cast<void*>(const_cast< data_sub_panel*>(this));
    return qcubeTabBasic::qt_metacast(_clname);
}

int SEP::data_sub_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = qcubeTabBasic::qt_metacall(_c, _id, _a);
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
void SEP::data_sub_panel::actionDetected(std::vector<QString> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
