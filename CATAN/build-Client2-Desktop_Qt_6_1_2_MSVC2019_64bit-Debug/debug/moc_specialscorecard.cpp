/****************************************************************************
** Meta object code from reading C++ file 'specialscorecard.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Client2/card/specialscorecard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'specialscorecard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SpecialScoreCard_t {
    const uint offsetsAndSize[8];
    char stringdata0[47];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SpecialScoreCard_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SpecialScoreCard_t qt_meta_stringdata_SpecialScoreCard = {
    {
QT_MOC_LITERAL(0, 16), // "SpecialScoreCard"
QT_MOC_LITERAL(17, 5), // "State"
QT_MOC_LITERAL(23, 11), // "LargestArmy"
QT_MOC_LITERAL(35, 11) // "RoadBuilder"

    },
    "SpecialScoreCard\0State\0LargestArmy\0"
    "RoadBuilder"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpecialScoreCard[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    2,   19,

 // enum data: key, value
       2, uint(SpecialScoreCard::LargestArmy),
       3, uint(SpecialScoreCard::RoadBuilder),

       0        // eod
};

void SpecialScoreCard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject SpecialScoreCard::staticMetaObject = { {
    QMetaObject::SuperData::link<cards::staticMetaObject>(),
    qt_meta_stringdata_SpecialScoreCard.offsetsAndSize,
    qt_meta_data_SpecialScoreCard,
    qt_static_metacall,
    nullptr,
    nullptr,
    nullptr
} };


const QMetaObject *SpecialScoreCard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpecialScoreCard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpecialScoreCard.stringdata0))
        return static_cast<void*>(this);
    return cards::qt_metacast(_clname);
}

int SpecialScoreCard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = cards::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
