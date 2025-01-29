/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Task1/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[30];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 21), // "on_resetTable_clicked"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 26), // "on_tableWidget_itemChanged"
QT_MOC_LITERAL(61, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(79, 4), // "item"
QT_MOC_LITERAL(84, 18), // "on_nextDay_clicked"
QT_MOC_LITERAL(103, 22), // "on_previousDay_clicked"
QT_MOC_LITERAL(126, 19), // "on_duration_clicked"
QT_MOC_LITERAL(146, 31), // "on_daysTillYourBirthday_clicked"
QT_MOC_LITERAL(178, 21), // "on_weekNumber_clicked"
QT_MOC_LITERAL(200, 17), // "on_isLeap_clicked"
QT_MOC_LITERAL(218, 23), // "on_date_editingFinished"
QT_MOC_LITERAL(242, 18), // "on_date_textEdited"
QT_MOC_LITERAL(261, 18) // "on_addDate_clicked"

    },
    "MainWindow\0on_resetTable_clicked\0\0"
    "on_tableWidget_itemChanged\0QTableWidgetItem*\0"
    "item\0on_nextDay_clicked\0on_previousDay_clicked\0"
    "on_duration_clicked\0on_daysTillYourBirthday_clicked\0"
    "on_weekNumber_clicked\0on_isLeap_clicked\0"
    "on_date_editingFinished\0on_date_textEdited\0"
    "on_addDate_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x08,    1 /* Private */,
       1,    0,   89,    2, 0x28,    3 /* Private | MethodCloned */,
       3,    1,   90,    2, 0x08,    4 /* Private */,
       6,    0,   93,    2, 0x08,    6 /* Private */,
       7,    0,   94,    2, 0x08,    7 /* Private */,
       8,    0,   95,    2, 0x08,    8 /* Private */,
       9,    0,   96,    2, 0x08,    9 /* Private */,
      10,    0,   97,    2, 0x08,   10 /* Private */,
      11,    0,   98,    2, 0x08,   11 /* Private */,
      12,    0,   99,    2, 0x08,   12 /* Private */,
      13,    0,  100,    2, 0x08,   13 /* Private */,
      14,    0,  101,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
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

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_resetTable_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->on_resetTable_clicked(); break;
        case 2: _t->on_tableWidget_itemChanged((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        case 3: _t->on_nextDay_clicked(); break;
        case 4: _t->on_previousDay_clicked(); break;
        case 5: _t->on_duration_clicked(); break;
        case 6: _t->on_daysTillYourBirthday_clicked(); break;
        case 7: _t->on_weekNumber_clicked(); break;
        case 8: _t->on_isLeap_clicked(); break;
        case 9: _t->on_date_editingFinished(); break;
        case 10: _t->on_date_textEdited(); break;
        case 11: _t->on_addDate_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTableWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
