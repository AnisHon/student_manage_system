/****************************************************************************
** Meta object code from reading C++ file 'scorewidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../scorewidget.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scorewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSScoreWidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSScoreWidgetENDCLASS = QtMocHelpers::stringData(
    "ScoreWidget",
    "on_sortMethod_activated",
    "",
    "index",
    "on_sortColumn_activated",
    "on_lineEdit_textChanged",
    "arg1",
    "on_changeBtn_clicked",
    "on_refreshBtn_clicked",
    "changeRow",
    "QModelIndex",
    "current",
    "previous"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSScoreWidgetENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[12];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[24];
    char stringdata5[24];
    char stringdata6[5];
    char stringdata7[21];
    char stringdata8[22];
    char stringdata9[10];
    char stringdata10[12];
    char stringdata11[8];
    char stringdata12[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSScoreWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSScoreWidgetENDCLASS_t qt_meta_stringdata_CLASSScoreWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "ScoreWidget"
        QT_MOC_LITERAL(12, 23),  // "on_sortMethod_activated"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 5),  // "index"
        QT_MOC_LITERAL(43, 23),  // "on_sortColumn_activated"
        QT_MOC_LITERAL(67, 23),  // "on_lineEdit_textChanged"
        QT_MOC_LITERAL(91, 4),  // "arg1"
        QT_MOC_LITERAL(96, 20),  // "on_changeBtn_clicked"
        QT_MOC_LITERAL(117, 21),  // "on_refreshBtn_clicked"
        QT_MOC_LITERAL(139, 9),  // "changeRow"
        QT_MOC_LITERAL(149, 11),  // "QModelIndex"
        QT_MOC_LITERAL(161, 7),  // "current"
        QT_MOC_LITERAL(169, 8)   // "previous"
    },
    "ScoreWidget",
    "on_sortMethod_activated",
    "",
    "index",
    "on_sortColumn_activated",
    "on_lineEdit_textChanged",
    "arg1",
    "on_changeBtn_clicked",
    "on_refreshBtn_clicked",
    "changeRow",
    "QModelIndex",
    "current",
    "previous"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSScoreWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x08,    1 /* Private */,
       4,    1,   53,    2, 0x08,    3 /* Private */,
       5,    1,   56,    2, 0x08,    5 /* Private */,
       7,    0,   59,    2, 0x08,    7 /* Private */,
       8,    0,   60,    2, 0x08,    8 /* Private */,
       9,    2,   61,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 10,   11,   12,

       0        // eod
};

Q_CONSTINIT const QMetaObject ScoreWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSScoreWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSScoreWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSScoreWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ScoreWidget, std::true_type>,
        // method 'on_sortMethod_activated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_sortColumn_activated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_lineEdit_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_changeBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_refreshBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeRow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>
    >,
    nullptr
} };

void ScoreWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScoreWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_sortMethod_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_sortColumn_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_lineEdit_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->on_changeBtn_clicked(); break;
        case 4: _t->on_refreshBtn_clicked(); break;
        case 5: _t->changeRow((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject *ScoreWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScoreWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSScoreWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ScoreWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
