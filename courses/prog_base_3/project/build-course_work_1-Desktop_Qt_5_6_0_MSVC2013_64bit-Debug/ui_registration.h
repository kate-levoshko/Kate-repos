/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_registration
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *registration)
    {
        if (registration->objectName().isEmpty())
            registration->setObjectName(QStringLiteral("registration"));
        registration->resize(599, 401);
        lineEdit = new QLineEdit(registration);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 40, 201, 20));
        lineEdit_2 = new QLineEdit(registration);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 80, 201, 20));
        lineEdit_3 = new QLineEdit(registration);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(140, 120, 201, 20));
        lineEdit_4 = new QLineEdit(registration);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(140, 160, 201, 20));
        lineEdit_5 = new QLineEdit(registration);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(140, 200, 201, 20));
        lineEdit_6 = new QLineEdit(registration);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(140, 240, 201, 20));
        label = new QLabel(registration);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 40, 31, 21));
        label_2 = new QLabel(registration);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 80, 41, 20));
        label_3 = new QLabel(registration);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 120, 101, 20));
        label_4 = new QLabel(registration);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 160, 21, 21));
        label_5 = new QLabel(registration);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 200, 51, 21));
        label_6 = new QLabel(registration);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 230, 91, 31));
        pushButton = new QPushButton(registration);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 330, 111, 31));
        pushButton_2 = new QPushButton(registration);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(440, 330, 111, 31));

        retranslateUi(registration);

        QMetaObject::connectSlotsByName(registration);
    } // setupUi

    void retranslateUi(QDialog *registration)
    {
        registration->setWindowTitle(QApplication::translate("registration", "Dialog", 0));
        label->setText(QApplication::translate("registration", "\320\233\320\276\320\263\321\226\320\275", 0));
        label_2->setText(QApplication::translate("registration", "\320\237\320\260\321\200\320\276\320\273\321\214", 0));
        label_3->setText(QApplication::translate("registration", "\320\237\320\276\320\262\321\202\320\276\321\200\321\226\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", 0));
        label_4->setText(QApplication::translate("registration", "\320\206'\320\274\321\217", 0));
        label_5->setText(QApplication::translate("registration", "\320\237\321\200\321\226\320\267\320\262\320\270\321\211\320\265", 0));
        label_6->setText(QApplication::translate("registration", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\321\203", 0));
        pushButton->setText(QApplication::translate("registration", "\320\227\320\260\321\200\320\265\321\224\321\201\321\202\321\200\321\203\320\262\320\260\321\202\320\270\321\201\321\214", 0));
        pushButton_2->setText(QApplication::translate("registration", "\320\235\320\260\320\267\320\260\320\264", 0));
    } // retranslateUi

};

namespace Ui {
    class registration: public Ui_registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
