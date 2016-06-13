/****************************************************************************
** Meta object code from reading C++ file 'cataloggui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../untitled/cataloggui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cataloggui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CatalogGUI_t {
    QByteArrayData data[16];
    char stringdata0[385];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CatalogGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CatalogGUI_t qt_meta_stringdata_CatalogGUI = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CatalogGUI"
QT_MOC_LITERAL(1, 11, 31), // "on_personalOfficeButton_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 23), // "on_bucketButton_clicked"
QT_MOC_LITERAL(4, 68, 25), // "on_dcSearchButton_clicked"
QT_MOC_LITERAL(5, 94, 23), // "on_sTable_tabBarClicked"
QT_MOC_LITERAL(6, 118, 5), // "index"
QT_MOC_LITERAL(7, 124, 29), // "on_perfumSearchButton_clicked"
QT_MOC_LITERAL(8, 154, 27), // "on_skinSearchButton_clicked"
QT_MOC_LITERAL(9, 182, 27), // "on_hairSearchButton_clicked"
QT_MOC_LITERAL(10, 210, 28), // "on_nailsSearchButton_clicked"
QT_MOC_LITERAL(11, 239, 34), // "on_decCosmeticsTable_doubleCl..."
QT_MOC_LITERAL(12, 274, 28), // "on_perfumTable_doubleClicked"
QT_MOC_LITERAL(13, 303, 26), // "on_skinTable_doubleClicked"
QT_MOC_LITERAL(14, 330, 27), // "on_nailsTable_doubleClicked"
QT_MOC_LITERAL(15, 358, 26) // "on_hairTable_doubleClicked"

    },
    "CatalogGUI\0on_personalOfficeButton_clicked\0"
    "\0on_bucketButton_clicked\0"
    "on_dcSearchButton_clicked\0"
    "on_sTable_tabBarClicked\0index\0"
    "on_perfumSearchButton_clicked\0"
    "on_skinSearchButton_clicked\0"
    "on_hairSearchButton_clicked\0"
    "on_nailsSearchButton_clicked\0"
    "on_decCosmeticsTable_doubleClicked\0"
    "on_perfumTable_doubleClicked\0"
    "on_skinTable_doubleClicked\0"
    "on_nailsTable_doubleClicked\0"
    "on_hairTable_doubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CatalogGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    1,   82,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    1,   89,    2, 0x08 /* Private */,
      12,    1,   92,    2, 0x08 /* Private */,
      13,    1,   95,    2, 0x08 /* Private */,
      14,    1,   98,    2, 0x08 /* Private */,
      15,    1,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void, QMetaType::QModelIndex,    6,

       0        // eod
};

void CatalogGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CatalogGUI *_t = static_cast<CatalogGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_personalOfficeButton_clicked(); break;
        case 1: _t->on_bucketButton_clicked(); break;
        case 2: _t->on_dcSearchButton_clicked(); break;
        case 3: _t->on_sTable_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_perfumSearchButton_clicked(); break;
        case 5: _t->on_skinSearchButton_clicked(); break;
        case 6: _t->on_hairSearchButton_clicked(); break;
        case 7: _t->on_nailsSearchButton_clicked(); break;
        case 8: _t->on_decCosmeticsTable_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->on_perfumTable_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: _t->on_skinTable_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: _t->on_nailsTable_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 12: _t->on_hairTable_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CatalogGUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CatalogGUI.data,
      qt_meta_data_CatalogGUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CatalogGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CatalogGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CatalogGUI.stringdata0))
        return static_cast<void*>(const_cast< CatalogGUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int CatalogGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
