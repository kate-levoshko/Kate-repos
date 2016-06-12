/********************************************************************************
** Form generated from reading UI file 'buydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYDIALOG_H
#define UI_BUYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BuyDialog
{
public:
    QLabel *nameLabel;
    QLabel *priceLabel;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *countSpinBox;
    QPushButton *buyButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *BuyDialog)
    {
        if (BuyDialog->objectName().isEmpty())
            BuyDialog->setObjectName(QStringLiteral("BuyDialog"));
        BuyDialog->resize(300, 180);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BuyDialog->sizePolicy().hasHeightForWidth());
        BuyDialog->setSizePolicy(sizePolicy);
        BuyDialog->setMinimumSize(QSize(300, 180));
        BuyDialog->setMaximumSize(QSize(300, 180));
        nameLabel = new QLabel(BuyDialog);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(60, 10, 231, 31));
        priceLabel = new QLabel(BuyDialog);
        priceLabel->setObjectName(QStringLiteral("priceLabel"));
        priceLabel->setGeometry(QRect(60, 50, 241, 31));
        priceLabel->setMidLineWidth(0);
        label_3 = new QLabel(BuyDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 20, 47, 13));
        label_4 = new QLabel(BuyDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 60, 47, 13));
        countSpinBox = new QSpinBox(BuyDialog);
        countSpinBox->setObjectName(QStringLiteral("countSpinBox"));
        countSpinBox->setGeometry(QRect(10, 100, 271, 22));
        countSpinBox->setLayoutDirection(Qt::LeftToRight);
        countSpinBox->setMinimum(1);
        buyButton = new QPushButton(BuyDialog);
        buyButton->setObjectName(QStringLiteral("buyButton"));
        buyButton->setGeometry(QRect(130, 140, 75, 23));
        cancelButton = new QPushButton(BuyDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(210, 140, 75, 23));

        retranslateUi(BuyDialog);

        QMetaObject::connectSlotsByName(BuyDialog);
    } // setupUi

    void retranslateUi(QDialog *BuyDialog)
    {
        BuyDialog->setWindowTitle(QApplication::translate("BuyDialog", "Dialog", 0));
        nameLabel->setText(QString());
        priceLabel->setText(QString());
        label_3->setText(QApplication::translate("BuyDialog", "Name:", 0));
        label_4->setText(QApplication::translate("BuyDialog", "Price", 0));
        buyButton->setText(QApplication::translate("BuyDialog", "Buy", 0));
        cancelButton->setText(QApplication::translate("BuyDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class BuyDialog: public Ui_BuyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYDIALOG_H
