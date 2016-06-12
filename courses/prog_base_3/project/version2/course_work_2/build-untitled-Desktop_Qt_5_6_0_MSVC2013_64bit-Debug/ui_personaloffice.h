/********************************************************************************
** Form generated from reading UI file 'personaloffice.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONALOFFICE_H
#define UI_PERSONALOFFICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonalOffice
{
public:
    QLabel *label;
    QPushButton *backButton;
    QPushButton *logOutButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *nameLabel;
    QLabel *surnameLabel;
    QLabel *phoneLabel;
    QLabel *label_10;
    QLabel *balanceLabel;

    void setupUi(QWidget *PersonalOffice)
    {
        if (PersonalOffice->objectName().isEmpty())
            PersonalOffice->setObjectName(QStringLiteral("PersonalOffice"));
        PersonalOffice->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PersonalOffice->sizePolicy().hasHeightForWidth());
        PersonalOffice->setSizePolicy(sizePolicy);
        PersonalOffice->setMinimumSize(QSize(800, 600));
        PersonalOffice->setMaximumSize(QSize(800, 600));
        PersonalOffice->setAcceptDrops(false);
        label = new QLabel(PersonalOffice);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, -10, 411, 111));
        QFont font;
        font.setFamily(QStringLiteral("Monotype Corsiva"));
        font.setPointSize(48);
        font.setItalic(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        backButton = new QPushButton(PersonalOffice);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(10, 10, 71, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Monotype Corsiva"));
        font1.setPointSize(16);
        font1.setItalic(true);
        backButton->setFont(font1);
        logOutButton = new QPushButton(PersonalOffice);
        logOutButton->setObjectName(QStringLiteral("logOutButton"));
        logOutButton->setGeometry(QRect(710, 10, 75, 31));
        logOutButton->setFont(font1);
        layoutWidget = new QWidget(PersonalOffice);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(250, 100, 341, 281));
        QFont font2;
        font2.setFamily(QStringLiteral("Times New Roman"));
        font2.setPointSize(16);
        layoutWidget->setFont(font2);
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_6);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        nameLabel = new QLabel(layoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(nameLabel);

        surnameLabel = new QLabel(layoutWidget);
        surnameLabel->setObjectName(QStringLiteral("surnameLabel"));
        surnameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(surnameLabel);

        phoneLabel = new QLabel(layoutWidget);
        phoneLabel->setObjectName(QStringLiteral("phoneLabel"));
        phoneLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(phoneLabel);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_10);

        balanceLabel = new QLabel(layoutWidget);
        balanceLabel->setObjectName(QStringLiteral("balanceLabel"));
        balanceLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(balanceLabel);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PersonalOffice);

        QMetaObject::connectSlotsByName(PersonalOffice);
    } // setupUi

    void retranslateUi(QWidget *PersonalOffice)
    {
        PersonalOffice->setWindowTitle(QApplication::translate("PersonalOffice", "Kateflame", 0));
        label->setText(QApplication::translate("PersonalOffice", "Personal Page", 0));
        backButton->setText(QApplication::translate("PersonalOffice", "Back", 0));
        logOutButton->setText(QApplication::translate("PersonalOffice", "LogOut", 0));
        label_2->setText(QApplication::translate("PersonalOffice", "Name:", 0));
        label_3->setText(QApplication::translate("PersonalOffice", "Surname:", 0));
        label_5->setText(QApplication::translate("PersonalOffice", "Phone:", 0));
        label_6->setText(QString());
        label_4->setText(QApplication::translate("PersonalOffice", "Balance :", 0));
        nameLabel->setText(QString());
        surnameLabel->setText(QString());
        phoneLabel->setText(QString());
        label_10->setText(QString());
        balanceLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PersonalOffice: public Ui_PersonalOffice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONALOFFICE_H
