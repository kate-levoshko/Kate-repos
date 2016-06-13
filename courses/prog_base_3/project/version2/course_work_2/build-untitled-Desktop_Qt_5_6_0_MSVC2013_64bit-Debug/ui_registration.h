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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_6;
    QVBoxLayout *verticalLayout;
    QLineEdit *loginEdit;
    QLineEdit *passwordEdit;
    QLineEdit *passwordEdit_2;
    QLineEdit *nameEdit;
    QLineEdit *surnameEdit;
    QLineEdit *phoneEdit;
    QPushButton *registerButton;

    void setupUi(QWidget *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName(QStringLiteral("Registration"));
        Registration->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Registration->sizePolicy().hasHeightForWidth());
        Registration->setSizePolicy(sizePolicy);
        Registration->setMinimumSize(QSize(800, 600));
        Registration->setMaximumSize(QSize(800, 600));
        Registration->setFocusPolicy(Qt::TabFocus);
        label = new QLabel(Registration);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 0, 501, 111));
        QFont font;
        font.setFamily(QStringLiteral("Monotype Corsiva"));
        font.setPointSize(48);
        font.setItalic(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(Registration);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(150, 110, 521, 311));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(14);
        label_2->setFont(font1);

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        verticalLayout_2->addWidget(label_5);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        verticalLayout_2->addWidget(label_7);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        verticalLayout_2->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        loginEdit = new QLineEdit(layoutWidget);
        loginEdit->setObjectName(QStringLiteral("loginEdit"));
        loginEdit->setMinimumSize(QSize(0, 25));
        loginEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(loginEdit, 0, Qt::AlignVCenter);

        passwordEdit = new QLineEdit(layoutWidget);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setMinimumSize(QSize(0, 25));
        passwordEdit->setEchoMode(QLineEdit::Password);
        passwordEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(passwordEdit, 0, Qt::AlignVCenter);

        passwordEdit_2 = new QLineEdit(layoutWidget);
        passwordEdit_2->setObjectName(QStringLiteral("passwordEdit_2"));
        passwordEdit_2->setMinimumSize(QSize(0, 25));
        passwordEdit_2->setEchoMode(QLineEdit::Password);
        passwordEdit_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(passwordEdit_2, 0, Qt::AlignVCenter);

        nameEdit = new QLineEdit(layoutWidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setMinimumSize(QSize(0, 25));
        nameEdit->setFrame(true);
        nameEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        nameEdit->setClearButtonEnabled(false);

        verticalLayout->addWidget(nameEdit, 0, Qt::AlignVCenter);

        surnameEdit = new QLineEdit(layoutWidget);
        surnameEdit->setObjectName(QStringLiteral("surnameEdit"));
        surnameEdit->setMinimumSize(QSize(0, 25));
        surnameEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(surnameEdit, 0, Qt::AlignVCenter);

        phoneEdit = new QLineEdit(layoutWidget);
        phoneEdit->setObjectName(QStringLiteral("phoneEdit"));
        phoneEdit->setMinimumSize(QSize(0, 25));
        phoneEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(phoneEdit, 0, Qt::AlignVCenter);


        horizontalLayout->addLayout(verticalLayout);

        registerButton = new QPushButton(Registration);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(550, 430, 121, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Monotype Corsiva"));
        font2.setPointSize(16);
        font2.setItalic(true);
        registerButton->setFont(font2);

        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QWidget *Registration)
    {
        Registration->setWindowTitle(QApplication::translate("Registration", "Kateframe", 0));
        label->setText(QApplication::translate("Registration", "Registration", 0));
        label_2->setText(QApplication::translate("Registration", "Login", 0));
        label_3->setText(QApplication::translate("Registration", "Password", 0));
        label_4->setText(QApplication::translate("Registration", "Confirm Password", 0));
        label_5->setText(QApplication::translate("Registration", "Name", 0));
        label_7->setText(QApplication::translate("Registration", "Surname", 0));
        label_6->setText(QApplication::translate("Registration", "Phone", 0));
        nameEdit->setInputMask(QString());
        registerButton->setText(QApplication::translate("Registration", "Register", 0));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
