/****************************************************************************
** Meta object code from reading C++ file 'centerwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gui/centerwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'centerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SEP__MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      27,   16,   16,   16, 0x08,
      34,   16,   16,   16, 0x08,
      41,   16,   16,   16, 0x08,
      52,   16,   16,   16, 0x08,
      64,   16,   16,   16, 0x08,
      75,   16,   16,   16, 0x08,
      87,   16,   16,   16, 0x08,
      99,   16,   16,   16, 0x08,
     110,   16,   16,   16, 0x08,
     121,   16,   16,   16, 0x08,
     133,   16,   16,   16, 0x08,
     145,   16,   16,   16, 0x08,
     158,   16,   16,   16, 0x08,
     172,   16,   16,   16, 0x08,
     189,   16,   16,   16, 0x08,
     205,   16,   16,   16, 0x08,
     218,   16,   16,   16, 0x08,
     230,   16,   16,   16, 0x08,
     246,   16,   16,   16, 0x08,
     260,   16,   16,   16, 0x08,
     275,   16,   16,   16, 0x08,
     291,   16,   16,   16, 0x08,
     303,   16,   16,   16, 0x08,
     315,   16,   16,   16, 0x08,
     329,   16,   16,   16, 0x08,
     350,   16,   16,   16, 0x08,
     366,   16,   16,   16, 0x08,
     383,   16,   16,   16, 0x08,
     419,   16,   16,   16, 0x08,
     458,   16,   16,   16, 0x08,
     471,   16,   16,   16, 0x08,
     479,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SEP__MainWindow[] = {
    "SEP::MainWindow\0\0newFile()\0open()\0"
    "save()\0openPick()\0closePick()\0openData()\0"
    "closeData()\0closeHelp()\0openHelp()\0"
    "openAnno()\0closeAnno()\0openColor()\0"
    "closeColor()\0statusMouse()\0statusPosition()\0"
    "statusOverlay()\0statusPick()\0mousePick()\0"
    "mouseNavigate()\0mouseRegion()\0"
    "mouseOverlay()\0mouseAnnotate()\0"
    "mouseZoom()\0lockViews()\0unlockViews()\0"
    "create_mouse_funcs()\0create_panels()\0"
    "create_windows()\0actionRespond(std::vector<QString>)\0"
    "secondaryRespond(std::vector<QString>)\0"
    "connect_it()\0about()\0aboutQt()\0"
};

void SEP::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->newFile(); break;
        case 1: _t->open(); break;
        case 2: _t->save(); break;
        case 3: _t->openPick(); break;
        case 4: _t->closePick(); break;
        case 5: _t->openData(); break;
        case 6: _t->closeData(); break;
        case 7: _t->closeHelp(); break;
        case 8: _t->openHelp(); break;
        case 9: _t->openAnno(); break;
        case 10: _t->closeAnno(); break;
        case 11: _t->openColor(); break;
        case 12: _t->closeColor(); break;
        case 13: _t->statusMouse(); break;
        case 14: _t->statusPosition(); break;
        case 15: _t->statusOverlay(); break;
        case 16: _t->statusPick(); break;
        case 17: _t->mousePick(); break;
        case 18: _t->mouseNavigate(); break;
        case 19: _t->mouseRegion(); break;
        case 20: _t->mouseOverlay(); break;
        case 21: _t->mouseAnnotate(); break;
        case 22: _t->mouseZoom(); break;
        case 23: _t->lockViews(); break;
        case 24: _t->unlockViews(); break;
        case 25: _t->create_mouse_funcs(); break;
        case 26: _t->create_panels(); break;
        case 27: _t->create_windows(); break;
        case 28: _t->actionRespond((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 29: _t->secondaryRespond((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 30: _t->connect_it(); break;
        case 31: _t->about(); break;
        case 32: _t->aboutQt(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SEP::MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SEP::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SEP__MainWindow,
      qt_meta_data_SEP__MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SEP::MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SEP::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SEP::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SEP__MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SEP::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
