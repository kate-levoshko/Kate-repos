/********************************************************************************
** Form generated from reading UI file 'authorisation.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORISATION_H
#define UI_AUTHORISATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_authorisation
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;

    void setupUi(QWidget *authorisation)
    {
        if (authorisation->objectName().isEmpty())
            authorisation->setObjectName(QStringLiteral("authorisation"));
        authorisation->resize(489, 341);
        lineEdit = new QLineEdit(authorisation);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 50, 151, 20));
        lineEdit_2 = new QLineEdit(authorisation);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 90, 151, 20));
        label = new QLabel(authorisation);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 50, 47, 13));
        label_2 = new QLabel(authorisation);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 90, 47, 13));
        pushButton = new QPushButton(authorisation);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 150, 75, 23));
        label_3 = new QLabel(authorisation);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(240, 220, 151, 31));

        retranslateUi(authorisation);

        QMetaObject::connectSlotsByName(authorisation);
    } // setupUi

    void retranslateUi(QWidget *authorisation)
    {
        authorisation->setWindowTitle(QApplication::translate("authorisation", "Form", 0));
        label->setText(QApplication::translate("authorisation", "\320\233\320\276\320\263\320\270\320\275", 0));
        label_2->setText(QApplication::translate("authorisation", "\320\237\320\260\321\200\320\276\320\273\321\214", 0));
        pushButton->setText(QApplication::translate("authorisation", "\320\222\320\262\321\226\320\271\321\202\320\270", 0));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class authorisation: public Ui_authorisation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORISATION_H
