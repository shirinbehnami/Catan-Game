/****************************************************************************
** Meta object code from reading C++ file 'ground.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Client2/ground/ground.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ground.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ground_t {
    const uint offsetsAndSize[20];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ground_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ground_t qt_meta_stringdata_ground = {
    {
QT_MOC_LITERAL(0, 6), // "ground"
QT_MOC_LITERAL(7, 10), // "ColorShape"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 12), // "turn_pressed"
QT_MOC_LITERAL(32, 13), // "house_created"
QT_MOC_LITERAL(46, 5), // "index"
QT_MOC_LITERAL(52, 4), // "roll"
QT_MOC_LITERAL(57, 11), // "ChangeShape"
QT_MOC_LITERAL(69, 6), // "pl_num"
QT_MOC_LITERAL(76, 17) // "next_turn_pressed"

    },
    "ground\0ColorShape\0\0turn_pressed\0"
    "house_created\0index\0roll\0ChangeShape\0"
    "pl_num\0next_turn_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ground[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    0 /* Public */,
       3,    0,   51,    2, 0x06,    1 /* Public */,
       4,    1,   52,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   55,    2, 0x0a,    4 /* Public */,
       7,    1,   56,    2, 0x0a,    5 /* Public */,
       9,    0,   59,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void ground::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ground *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ColorShape(); break;
        case 1: _t->turn_pressed(); break;
        case 2: _t->house_created((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->roll(); break;
        case 4: _t->ChangeShape((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->next_turn_pressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ground::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ground::ColorShape)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ground::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ground::turn_pressed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ground::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ground::house_created)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ground::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ground.offsetsAndSize,
    qt_meta_data_ground,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ground_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ground::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ground::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ground.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ground::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ground::ColorShape()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ground::turn_pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ground::house_created(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
