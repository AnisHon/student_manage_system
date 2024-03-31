/****************************************************************************
** Meta object code from reading C++ file 'studentwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../studentwidget.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'studentwidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSStudentWidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSStudentWidgetENDCLASS = QtMocHelpers::stringData(
    "StudentWidget",
    "on_genderBox_currentTextChanged",
    "",
    "arg1",
    "on_searchEdit_editingFinished",
    "on_searchEdit_textChanged",
    "on_searchMethod_currentIndexChanged",
    "index",
    "on_addStudent_clicked",
    "on_deleteStudent_clicked",
    "on_submitBtn_clicked",
    "on_pushButton_clicked",
    "on_pushButton_2_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSStudentWidgetENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[14];
    char stringdata1[32];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[30];
    char stringdata5[26];
    char stringdata6[36];
    char stringdata7[6];
    char stringdata8[22];
    char stringdata9[25];
    char stringdata10[21];
    char stringdata11[22];
    char stringdata12[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSStudentWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSStudentWidgetENDCLASS_t qt_meta_stringdata_CLASSStudentWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "StudentWidget"
        QT_MOC_LITERAL(14, 31),  // "on_genderBox_currentTextChanged"
        QT_MOC_LITERAL(46, 0),  // ""
        QT_MOC_LITERAL(47, 4),  // "arg1"
        QT_MOC_LITERAL(52, 29),  // "on_searchEdit_editingFinished"
        QT_MOC_LITERAL(82, 25),  // "on_searchEdit_textChanged"
        QT_MOC_LITERAL(108, 35),  // "on_searchMethod_currentIndexC..."
        QT_MOC_LITERAL(144, 5),  // "index"
        QT_MOC_LITERAL(150, 21),  // "on_addStudent_clicked"
        QT_MOC_LITERAL(172, 24),  // "on_deleteStudent_clicked"
        QT_MOC_LITERAL(197, 20),  // "on_submitBtn_clicked"
        QT_MOC_LITERAL(218, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(240, 23)   // "on_pushButton_2_clicked"
    },
    "StudentWidget",
    "on_genderBox_currentTextChanged",
    "",
    "arg1",
    "on_searchEdit_editingFinished",
    "on_searchEdit_textChanged",
    "on_searchMethod_currentIndexChanged",
    "index",
    "on_addStudent_clicked",
    "on_deleteStudent_clicked",
    "on_submitBtn_clicked",
    "on_pushButton_clicked",
    "on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSStudentWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x08,    1 /* Private */,
       4,    0,   71,    2, 0x08,    3 /* Private */,
       5,    1,   72,    2, 0x08,    4 /* Private */,
       6,    1,   75,    2, 0x08,    6 /* Private */,
       8,    0,   78,    2, 0x08,    8 /* Private */,
       9,    0,   79,    2, 0x08,    9 /* Private */,
      10,    0,   80,    2, 0x08,   10 /* Private */,
      11,    0,   81,    2, 0x08,   11 /* Private */,
      12,    0,   82,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject StudentWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSStudentWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSStudentWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSStudentWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<StudentWidget, std::true_type>,
        // method 'on_genderBox_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_searchEdit_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_searchEdit_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_searchMethod_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_addStudent_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_deleteStudent_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_submitBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void StudentWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StudentWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_genderBox_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->on_searchEdit_editingFinished(); break;
        case 2: _t->on_searchEdit_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->on_searchMethod_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_addStudent_clicked(); break;
        case 5: _t->on_deleteStudent_clicked(); break;
        case 6: _t->on_submitBtn_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *StudentWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StudentWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSStudentWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int StudentWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
