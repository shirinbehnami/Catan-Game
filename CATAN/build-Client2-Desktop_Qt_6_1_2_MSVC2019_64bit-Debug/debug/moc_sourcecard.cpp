/****************************************************************************
** Meta object code from reading C++ file 'sourcecard.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Client2/card/sourcecard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sourcecard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SourceCard_t {
    const uint offsetsAndSize[22];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SourceCard_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SourceCard_t qt_meta_stringdata_SourceCard = {
    {
QT_MOC_LITERAL(0, 10), // "SourceCard"
QT_MOC_LITERAL(11, 12), // "stateChanged"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 5), // "State"
QT_MOC_LITERAL(31, 10), // "updatecard"
QT_MOC_LITERAL(42, 5), // "state"
QT_MOC_LITERAL(48, 5), // "wheat"
QT_MOC_LITERAL(54, 4), // "clay"
QT_MOC_LITERAL(59, 3), // "ore"
QT_MOC_LITERAL(63, 4), // "wood"
QT_MOC_LITERAL(68, 5) // "sheep"

    },
    "SourceCard\0stateChanged\0\0State\0"
    "updatecard\0state\0wheat\0clay\0ore\0wood\0"
    "sheep"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SourceCard[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       1,   32, // properties
       1,   37, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   29,    2, 0x08,    3 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    5,

 // properties: name, type, flags
       5, 0x80000000 | 3, 0x0001510b, uint(0), 0,

 // enums: name, alias, flags, count, data
       3,    3, 0x0,    5,   42,

 // enum data: key, value
       6, uint(SourceCard::wheat),
       7, uint(SourceCard::clay),
       8, uint(SourceCard::ore),
       9, uint(SourceCard::wood),
      10, uint(SourceCard::sheep),

       0        // eod
};

void SourceCard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SourceCard *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->stateChanged((*reinterpret_cast< State(*)>(_a[1]))); break;
        case 1: _t->updatecard((*reinterpret_cast< State(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SourceCard::*)(State );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SourceCard::stateChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SourceCard *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< State*>(_v) = _t->state(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SourceCard *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setState(*reinterpret_cast< State*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject SourceCard::staticMetaObject = { {
    QMetaObject::SuperData::link<cards::staticMetaObject>(),
    qt_meta_stringdata_SourceCard.offsetsAndSize,
    qt_meta_data_SourceCard,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SourceCard_t
, QtPrivate::TypeAndForceComplete<State, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<State, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<State, std::false_type>


>,
    nullptr
} };


const QMetaObject *SourceCard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SourceCard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SourceCard.stringdata0))
        return static_cast<void*>(this);
    return cards::qt_metacast(_clname);
}

int SourceCard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = cards::qt_metacall(_c, _id, _a);
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
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void SourceCard::stateChanged(State _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
