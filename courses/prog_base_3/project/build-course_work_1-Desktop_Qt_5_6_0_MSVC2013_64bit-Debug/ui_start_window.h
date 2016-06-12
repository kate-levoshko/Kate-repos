/********************************************************************************
** Form generated from reading UI file 'start_window.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_WINDOW_H
#define UI_START_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_start_window
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *start_window)
    {
        if (start_window->objectName().isEmpty())
            start_window->setObjectName(QStringLiteral("start_window"));
        start_window->resize(364, 258);
        centralWidget = new QWidget(start_window);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 30, 111, 41));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 80, 111, 41));
        start_window->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(start_window);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 364, 21));
        start_window->setMenuBar(menuBar);
        mainToolBar = new QToolBar(start_window);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        start_window->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(start_window);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        start_window->setStatusBar(statusBar);

        retranslateUi(start_window);

        QMetaObject::connectSlotsByName(start_window);
    } // setupUi

    void retranslateUi(QMainWindow *start_window)
    {
        start_window->setWindowTitle(QApplication::translate("start_window", "start_window", 0));
        pushButton->setText(QApplication::translate("start_window", "\320\243\320\262\321\226\320\271\321\202\320\270", 0));
        pushButton_2->setText(QApplication::translate("start_window", "\320\227\320\260\321\200\320\265\321\224\321\201\321\202\321\200\321\203\320\262\320\260\321\202\320\270\321\201\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class start_window: public Ui_start_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_WINDOW_H
