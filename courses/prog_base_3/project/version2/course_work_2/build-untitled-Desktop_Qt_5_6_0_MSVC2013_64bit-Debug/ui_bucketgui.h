/********************************************************************************
** Form generated from reading UI file 'bucketgui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUCKETGUI_H
#define UI_BUCKETGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BucketGUI
{
public:
    QTableWidget *buyTable;
    QPushButton *cleanButton;
    QPushButton *buyButton;
    QPushButton *backButton;
    QLabel *label;

    void setupUi(QWidget *BucketGUI)
    {
        if (BucketGUI->objectName().isEmpty())
            BucketGUI->setObjectName(QStringLiteral("BucketGUI"));
        BucketGUI->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BucketGUI->sizePolicy().hasHeightForWidth());
        BucketGUI->setSizePolicy(sizePolicy);
        BucketGUI->setMinimumSize(QSize(800, 600));
        BucketGUI->setMaximumSize(QSize(800, 600));
        BucketGUI->setFocusPolicy(Qt::TabFocus);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../../../../../../Desktop/Makeup_1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        BucketGUI->setWindowIcon(icon);
        buyTable = new QTableWidget(BucketGUI);
        if (buyTable->columnCount() < 3)
            buyTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        buyTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        buyTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        buyTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        buyTable->setObjectName(QStringLiteral("buyTable"));
        buyTable->setGeometry(QRect(20, 50, 761, 481));
        buyTable->setFocusPolicy(Qt::NoFocus);
        buyTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        buyTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        buyTable->setRowCount(0);
        buyTable->horizontalHeader()->setDefaultSectionSize(253);
        buyTable->horizontalHeader()->setHighlightSections(false);
        buyTable->verticalHeader()->setVisible(false);
        buyTable->verticalHeader()->setHighlightSections(false);
        cleanButton = new QPushButton(BucketGUI);
        cleanButton->setObjectName(QStringLiteral("cleanButton"));
        cleanButton->setGeometry(QRect(620, 550, 75, 31));
        QFont font;
        font.setFamily(QStringLiteral("Monotype Corsiva"));
        font.setPointSize(16);
        font.setItalic(true);
        cleanButton->setFont(font);
        buyButton = new QPushButton(BucketGUI);
        buyButton->setObjectName(QStringLiteral("buyButton"));
        buyButton->setGeometry(QRect(710, 550, 75, 31));
        buyButton->setFont(font);
        backButton = new QPushButton(BucketGUI);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(20, 10, 75, 31));
        backButton->setFont(font);
        label = new QLabel(BucketGUI);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, -10, 801, 591));
        label->setPixmap(QPixmap(QString::fromUtf8("../../bucket.jpg")));
        label->setScaledContents(true);
        label->raise();
        buyTable->raise();
        cleanButton->raise();
        buyButton->raise();
        backButton->raise();

        retranslateUi(BucketGUI);

        QMetaObject::connectSlotsByName(BucketGUI);
    } // setupUi

    void retranslateUi(QWidget *BucketGUI)
    {
        BucketGUI->setWindowTitle(QApplication::translate("BucketGUI", "Kateflame", 0));
        QTableWidgetItem *___qtablewidgetitem = buyTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BucketGUI", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0));
        QTableWidgetItem *___qtablewidgetitem1 = buyTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BucketGUI", "\320\246\320\265\320\275\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem2 = buyTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BucketGUI", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", 0));
        cleanButton->setText(QApplication::translate("BucketGUI", "Clean", 0));
        buyButton->setText(QApplication::translate("BucketGUI", "Buy", 0));
        backButton->setText(QApplication::translate("BucketGUI", "Back", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BucketGUI: public Ui_BucketGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUCKETGUI_H
