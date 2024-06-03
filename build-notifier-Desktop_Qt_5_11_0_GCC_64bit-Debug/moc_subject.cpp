/****************************************************************************
** Meta object code from reading C++ file 'subject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../notifier/subject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'subject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Subject_t {
    QByteArrayData data[12];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Subject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Subject_t qt_meta_stringdata_Subject = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Subject"
QT_MOC_LITERAL(1, 8, 17), // "tryTimeoutChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "nameChanged"
QT_MOC_LITERAL(4, 39, 16), // "ipAddressChanged"
QT_MOC_LITERAL(5, 56, 11), // "portChanged"
QT_MOC_LITERAL(6, 68, 13), // "statusChanged"
QT_MOC_LITERAL(7, 82, 14), // "incidentClosed"
QT_MOC_LITERAL(8, 97, 15), // "incidentOpenned"
QT_MOC_LITERAL(9, 113, 25), // "onConnectionStatusChanged"
QT_MOC_LITERAL(10, 139, 6), // "status"
QT_MOC_LITERAL(11, 146, 18) // "onConnectionFailed"

    },
    "Subject\0tryTimeoutChanged\0\0nameChanged\0"
    "ipAddressChanged\0portChanged\0statusChanged\0"
    "incidentClosed\0incidentOpenned\0"
    "onConnectionStatusChanged\0status\0"
    "onConnectionFailed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Subject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,
       7,    0,   64,    2, 0x06 /* Public */,
       8,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   66,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,

       0        // eod
};

void Subject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Subject *_t = static_cast<Subject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tryTimeoutChanged(); break;
        case 1: _t->nameChanged(); break;
        case 2: _t->ipAddressChanged(); break;
        case 3: _t->portChanged(); break;
        case 4: _t->statusChanged(); break;
        case 5: _t->incidentClosed(); break;
        case 6: _t->incidentOpenned(); break;
        case 7: _t->onConnectionStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->onConnectionFailed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Subject::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Subject::tryTimeoutChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Subject::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Subject::nameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Subject::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Subject::ipAddressChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Subject::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Subject::portChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Subject::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Subject::statusChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Subject::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Subject::incidentClosed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Subject::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Subject::incidentOpenned)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Subject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Subject.data,
      qt_meta_data_Subject,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Subject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Subject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Subject.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Subject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Subject::tryTimeoutChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Subject::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Subject::ipAddressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Subject::portChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Subject::statusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Subject::incidentClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Subject::incidentOpenned()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
