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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BucketGUI
{
public:

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

        retranslateUi(BucketGUI);

        QMetaObject::connectSlotsByName(BucketGUI);
    } // setupUi

    void retranslateUi(QWidget *BucketGUI)
    {
        BucketGUI->setWindowTitle(QApplication::translate("BucketGUI", "Kateflame", 0));
    } // retranslateUi

};

namespace Ui {
    class BucketGUI: public Ui_BucketGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUCKETGUI_H
