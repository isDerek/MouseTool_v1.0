/****************************************************************************
** Meta object code from reading C++ file 'macros.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../macros.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'macros.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Macros_t {
    QByteArrayData data[18];
    char stringdata0[328];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Macros_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Macros_t qt_meta_stringdata_Macros = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Macros"
QT_MOC_LITERAL(1, 7, 13), // "macros_signal"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "data"
QT_MOC_LITERAL(4, 27, 24), // "on_keyFuc_currentChanged"
QT_MOC_LITERAL(5, 52, 5), // "index"
QT_MOC_LITERAL(6, 58, 25), // "on_startRecordBtn_clicked"
QT_MOC_LITERAL(7, 84, 21), // "on_confirmBtn_clicked"
QT_MOC_LITERAL(8, 106, 26), // "on_closeWindowsBtn_clicked"
QT_MOC_LITERAL(9, 133, 25), // "on_showWindowsBtn_clicked"
QT_MOC_LITERAL(10, 159, 21), // "on_nextWebBtn_clicked"
QT_MOC_LITERAL(11, 181, 23), // "on_beforeWebBtn_clicked"
QT_MOC_LITERAL(12, 205, 24), // "on_resetScaleBtn_clicked"
QT_MOC_LITERAL(13, 230, 17), // "on_cutBtn_clicked"
QT_MOC_LITERAL(14, 248, 18), // "on_copyBtn_clicked"
QT_MOC_LITERAL(15, 267, 19), // "on_pasteBtn_clicked"
QT_MOC_LITERAL(16, 287, 19), // "on_resetBtn_clicked"
QT_MOC_LITERAL(17, 307, 20) // "on_cancelBtn_clicked"

    },
    "Macros\0macros_signal\0\0data\0"
    "on_keyFuc_currentChanged\0index\0"
    "on_startRecordBtn_clicked\0"
    "on_confirmBtn_clicked\0on_closeWindowsBtn_clicked\0"
    "on_showWindowsBtn_clicked\0"
    "on_nextWebBtn_clicked\0on_beforeWebBtn_clicked\0"
    "on_resetScaleBtn_clicked\0on_cutBtn_clicked\0"
    "on_copyBtn_clicked\0on_pasteBtn_clicked\0"
    "on_resetBtn_clicked\0on_cancelBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Macros[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   87,    2, 0x08 /* Private */,
       6,    0,   90,    2, 0x08 /* Private */,
       7,    0,   91,    2, 0x08 /* Private */,
       8,    0,   92,    2, 0x08 /* Private */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,
      16,    0,  100,    2, 0x08 /* Private */,
      17,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Macros::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Macros *_t = static_cast<Macros *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->macros_signal((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->on_keyFuc_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_startRecordBtn_clicked(); break;
        case 3: _t->on_confirmBtn_clicked(); break;
        case 4: _t->on_closeWindowsBtn_clicked(); break;
        case 5: _t->on_showWindowsBtn_clicked(); break;
        case 6: _t->on_nextWebBtn_clicked(); break;
        case 7: _t->on_beforeWebBtn_clicked(); break;
        case 8: _t->on_resetScaleBtn_clicked(); break;
        case 9: _t->on_cutBtn_clicked(); break;
        case 10: _t->on_copyBtn_clicked(); break;
        case 11: _t->on_pasteBtn_clicked(); break;
        case 12: _t->on_resetBtn_clicked(); break;
        case 13: _t->on_cancelBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Macros::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Macros::macros_signal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Macros::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Macros.data,
    qt_meta_data_Macros,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Macros::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Macros::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Macros.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Macros::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Macros::macros_signal(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
