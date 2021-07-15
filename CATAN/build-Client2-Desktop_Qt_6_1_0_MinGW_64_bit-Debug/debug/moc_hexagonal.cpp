/****************************************************************************
** Meta object code from reading C++ file 'hexagonal.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Client2/hexagonal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hexagonal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_hexagonal_t {
    const uint offsetsAndSize[30];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_hexagonal_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_hexagonal_t qt_meta_stringdata_hexagonal = {
    {
QT_MOC_LITERAL(0, 9), // "hexagonal"
QT_MOC_LITERAL(10, 12), // "stateChanged"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 5), // "State"
QT_MOC_LITERAL(30, 15), // "updateHexagonal"
QT_MOC_LITERAL(46, 5), // "state"
QT_MOC_LITERAL(52, 3), // "row"
QT_MOC_LITERAL(56, 3), // "col"
QT_MOC_LITERAL(60, 6), // "desert"
QT_MOC_LITERAL(67, 5), // "wheat"
QT_MOC_LITERAL(73, 4), // "clay"
QT_MOC_LITERAL(78, 3), // "ore"
QT_MOC_LITERAL(82, 4), // "wood"
QT_MOC_LITERAL(87, 5), // "sheep"
QT_MOC_LITERAL(93, 5) // "water"

    },
    "hexagonal\0stateChanged\0\0State\0"
    "updateHexagonal\0state\0row\0col\0desert\0"
    "wheat\0clay\0ore\0wood\0sheep\0water"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hexagonal[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       3,   32, // properties
       1,   47, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   29,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    5,

 // properties: name, type, flags
       6, QMetaType::Int, 0x00015103, uint(-1), 0,
       7, QMetaType::Int, 0x00015103, uint(-1), 0,
       5, 0x80000000 | 3, 0x0001510b, uint(0), 0,

 // enums: name, alias, flags, count, data
       3,    3, 0x0,    7,   52,

 // enum data: key, value
       8, uint(hexagonal::desert),
       9, uint(hexagonal::wheat),
      10, uint(hexagonal::clay),
      11, uint(hexagonal::ore),
      12, uint(hexagonal::wood),
      13, uint(hexagonal::sheep),
      14, uint(hexagonal::water),

       0        // eod
};

void hexagonal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<hexagonal *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->stateChanged((*reinterpret_cast< State(*)>(_a[1]))); break;
        case 1: _t->updateHexagonal((*reinterpret_cast< State(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (hexagonal::*)(State );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hexagonal::stateChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<hexagonal *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->row(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->col(); break;
        case 2: *reinterpret_cast< State*>(_v) = _t->state(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<hexagonal *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRow(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setCol(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setState(*reinterpret_cast< State*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject hexagonal::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_hexagonal.offsetsAndSize,
    qt_meta_data_hexagonal,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_hexagonal_t
, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<State, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<State, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<State, std::false_type>


>,
    nullptr
} };


const QMetaObject *hexagonal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hexagonal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hexagonal.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int hexagonal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void hexagonal::stateChanged(State _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
