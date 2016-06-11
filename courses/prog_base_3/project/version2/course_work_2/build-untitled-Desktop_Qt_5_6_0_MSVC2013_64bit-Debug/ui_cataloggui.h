/********************************************************************************
** Form generated from reading UI file 'cataloggui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATALOGGUI_H
#define UI_CATALOGGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CatalogGUI
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableView;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QWidget *tab_2;
    QLineEdit *lineEdit_6;
    QTableView *tableView_6;
    QPushButton *pushButton_3;
    QWidget *tab_3;
    QPushButton *pushButton_4;
    QTableView *tableView_3;
    QLineEdit *lineEdit_3;
    QWidget *tab_4;
    QLineEdit *lineEdit_7;
    QTableView *tableView_7;
    QPushButton *pushButton_8;
    QWidget *tab_5;
    QLineEdit *lineEdit_8;
    QTableView *tableView_8;
    QPushButton *pushButton_9;
    QPushButton *personalOfficeButton;

    void setupUi(QWidget *CatalogGUI)
    {
        if (CatalogGUI->objectName().isEmpty())
            CatalogGUI->setObjectName(QStringLiteral("CatalogGUI"));
        CatalogGUI->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CatalogGUI->sizePolicy().hasHeightForWidth());
        CatalogGUI->setSizePolicy(sizePolicy);
        CatalogGUI->setMinimumSize(QSize(800, 600));
        CatalogGUI->setMaximumSize(QSize(800, 600));
        tabWidget = new QTabWidget(CatalogGUI);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 60, 761, 521));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 40, 731, 441));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(650, 10, 91, 23));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 631, 20));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        lineEdit_6 = new QLineEdit(tab_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(10, 10, 631, 20));
        tableView_6 = new QTableView(tab_2);
        tableView_6->setObjectName(QStringLiteral("tableView_6"));
        tableView_6->setGeometry(QRect(10, 40, 731, 441));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(650, 10, 91, 23));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(650, 10, 91, 23));
        tableView_3 = new QTableView(tab_3);
        tableView_3->setObjectName(QStringLiteral("tableView_3"));
        tableView_3->setGeometry(QRect(10, 40, 731, 441));
        lineEdit_3 = new QLineEdit(tab_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 10, 631, 20));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        lineEdit_7 = new QLineEdit(tab_4);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(10, 10, 631, 20));
        tableView_7 = new QTableView(tab_4);
        tableView_7->setObjectName(QStringLiteral("tableView_7"));
        tableView_7->setGeometry(QRect(10, 40, 731, 441));
        pushButton_8 = new QPushButton(tab_4);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(650, 10, 91, 23));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        lineEdit_8 = new QLineEdit(tab_5);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(10, 10, 631, 20));
        tableView_8 = new QTableView(tab_5);
        tableView_8->setObjectName(QStringLiteral("tableView_8"));
        tableView_8->setGeometry(QRect(10, 40, 731, 441));
        pushButton_9 = new QPushButton(tab_5);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(650, 10, 91, 23));
        tabWidget->addTab(tab_5, QString());
        personalOfficeButton = new QPushButton(CatalogGUI);
        personalOfficeButton->setObjectName(QStringLiteral("personalOfficeButton"));
        personalOfficeButton->setGeometry(QRect(700, 10, 75, 31));

        retranslateUi(CatalogGUI);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(CatalogGUI);
    } // setupUi

    void retranslateUi(QWidget *CatalogGUI)
    {
        CatalogGUI->setWindowTitle(QApplication::translate("CatalogGUI", "Kateflame", 0));
        pushButton->setText(QApplication::translate("CatalogGUI", "Search", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CatalogGUI", "\320\224\320\265\320\272\320\276\321\200\320\260\321\202\320\270\320\262\320\275\320\260 \320\272\320\276\321\201\320\274\320\265\321\202\320\270\320\272\320\260", 0));
        pushButton_3->setText(QApplication::translate("CatalogGUI", "Search", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("CatalogGUI", "\320\237\320\260\321\200\321\204\321\203\320\274\320\265\321\200\320\275\321\226 \320\267\320\260\321\201\320\276\320\261\320\270", 0));
        pushButton_4->setText(QApplication::translate("CatalogGUI", "Search", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("CatalogGUI", "\320\224\320\276\320\263\320\273\321\217\320\264 \320\267\320\260 \321\210\320\272\321\226\321\200\320\276\321\216/\320\276\320\261\320\273\320\270\321\207\321\207\321\217\320\274", 0));
        pushButton_8->setText(QApplication::translate("CatalogGUI", "Search", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("CatalogGUI", "\320\224\320\276\320\263\320\273\321\217\320\264 \320\267\320\260 \320\262\320\276\320\273\320\276\321\201\321\201\321\217\320\274", 0));
        pushButton_9->setText(QApplication::translate("CatalogGUI", "Search", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("CatalogGUI", "\320\224\320\276\320\263\320\273\321\217\320\264 \320\267\320\260 \320\275\321\226\320\263\321\202\321\217\320\274\320\270", 0));
        personalOfficeButton->setText(QApplication::translate("CatalogGUI", "Personal", 0));
    } // retranslateUi

};

namespace Ui {
    class CatalogGUI: public Ui_CatalogGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATALOGGUI_H
