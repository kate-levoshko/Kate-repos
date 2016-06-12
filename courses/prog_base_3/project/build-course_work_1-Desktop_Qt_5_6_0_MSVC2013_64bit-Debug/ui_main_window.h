/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableView;
    QPushButton *pushButton;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;

    void setupUi(QDialog *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QStringLiteral("main_window"));
        main_window->resize(721, 465);
        tabWidget = new QTabWidget(main_window);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 40, 681, 371));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 20, 501, 281));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(550, 210, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());

        retranslateUi(main_window);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QDialog *main_window)
    {
        main_window->setWindowTitle(QApplication::translate("main_window", "Dialog", 0));
        pushButton->setText(QApplication::translate("main_window", "Load table", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("main_window", "\320\224\320\265\320\272\320\276\321\200\320\260\321\202\320\270\320\262\320\275\320\260 \320\272\320\276\321\201\320\274\320\265\321\202\320\270\320\272\320\260", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("main_window", "\320\237\320\260\321\200\321\204\321\203\320\274\320\265\321\200\320\275\321\226 \320\267\320\260\321\201\320\276\320\261\320\270", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("main_window", "\320\224\320\276\320\263\320\273\321\217\320\264 \320\267\320\260 \321\210\320\272\321\226\321\200\320\276\321\216/\320\276\320\261\320\273\320\270\321\207\321\207\321\217\320\274", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("main_window", "\320\224\320\276\320\263\320\273\321\217\320\264 \320\267\320\260 \320\262\320\276\320\273\320\276\321\201\321\201\321\217\320\274", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("main_window", "\320\224\320\276\320\263\320\273\321\217\320\264 \320\267\320\260 \320\275\321\226\320\263\321\202\321\217\320\274\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
