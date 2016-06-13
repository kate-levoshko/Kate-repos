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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CatalogGUI
{
public:
    QTabWidget *sTable;
    QWidget *cosmeticTab;
    QPushButton *dcSearchButton;
    QLineEdit *cosmeticSearchEdit;
    QTableView *decCosmeticsTable;
    QWidget *perfumTab;
    QLineEdit *perfumSearchEdit;
    QTableView *perfumTable;
    QPushButton *perfumSearchButton;
    QWidget *skinTab;
    QPushButton *skinSearchButton;
    QTableView *skinTable;
    QLineEdit *skinSearchEdit;
    QWidget *nailsTab;
    QLineEdit *nailsSearchEdit;
    QTableView *nailsTable;
    QPushButton *nailsSearchButton;
    QWidget *hairTab;
    QLineEdit *hairSearchEdit;
    QTableView *hairTable;
    QPushButton *hairSearchButton;
    QPushButton *personalOfficeButton;
    QPushButton *bucketButton;
    QLabel *label;

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
        CatalogGUI->setFocusPolicy(Qt::TabFocus);
        sTable = new QTabWidget(CatalogGUI);
        sTable->setObjectName(QStringLiteral("sTable"));
        sTable->setGeometry(QRect(20, 60, 761, 521));
        cosmeticTab = new QWidget();
        cosmeticTab->setObjectName(QStringLiteral("cosmeticTab"));
        dcSearchButton = new QPushButton(cosmeticTab);
        dcSearchButton->setObjectName(QStringLiteral("dcSearchButton"));
        dcSearchButton->setGeometry(QRect(650, 10, 91, 23));
        cosmeticSearchEdit = new QLineEdit(cosmeticTab);
        cosmeticSearchEdit->setObjectName(QStringLiteral("cosmeticSearchEdit"));
        cosmeticSearchEdit->setGeometry(QRect(10, 10, 631, 20));
        decCosmeticsTable = new QTableView(cosmeticTab);
        decCosmeticsTable->setObjectName(QStringLiteral("decCosmeticsTable"));
        decCosmeticsTable->setGeometry(QRect(10, 40, 732, 441));
        decCosmeticsTable->setFocusPolicy(Qt::TabFocus);
        decCosmeticsTable->setLineWidth(1);
        decCosmeticsTable->setAutoScrollMargin(16);
        decCosmeticsTable->setEditTriggers(QAbstractItemView::DoubleClicked);
        decCosmeticsTable->setSelectionMode(QAbstractItemView::SingleSelection);
        decCosmeticsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        decCosmeticsTable->setGridStyle(Qt::DashLine);
        decCosmeticsTable->setSortingEnabled(true);
        decCosmeticsTable->horizontalHeader()->setDefaultSectionSize(237);
        decCosmeticsTable->horizontalHeader()->setHighlightSections(false);
        decCosmeticsTable->verticalHeader()->setVisible(false);
        decCosmeticsTable->verticalHeader()->setDefaultSectionSize(30);
        decCosmeticsTable->verticalHeader()->setHighlightSections(false);
        sTable->addTab(cosmeticTab, QString());
        perfumTab = new QWidget();
        perfumTab->setObjectName(QStringLiteral("perfumTab"));
        perfumSearchEdit = new QLineEdit(perfumTab);
        perfumSearchEdit->setObjectName(QStringLiteral("perfumSearchEdit"));
        perfumSearchEdit->setGeometry(QRect(10, 10, 631, 20));
        perfumTable = new QTableView(perfumTab);
        perfumTable->setObjectName(QStringLiteral("perfumTable"));
        perfumTable->setGeometry(QRect(10, 40, 731, 441));
        perfumTable->setFocusPolicy(Qt::TabFocus);
        perfumTable->setSelectionMode(QAbstractItemView::SingleSelection);
        perfumTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        perfumTable->setSortingEnabled(true);
        perfumTable->horizontalHeader()->setDefaultSectionSize(243);
        perfumTable->horizontalHeader()->setHighlightSections(false);
        perfumTable->verticalHeader()->setVisible(false);
        perfumTable->verticalHeader()->setHighlightSections(false);
        perfumSearchButton = new QPushButton(perfumTab);
        perfumSearchButton->setObjectName(QStringLiteral("perfumSearchButton"));
        perfumSearchButton->setGeometry(QRect(650, 10, 91, 23));
        sTable->addTab(perfumTab, QString());
        skinTab = new QWidget();
        skinTab->setObjectName(QStringLiteral("skinTab"));
        skinSearchButton = new QPushButton(skinTab);
        skinSearchButton->setObjectName(QStringLiteral("skinSearchButton"));
        skinSearchButton->setGeometry(QRect(650, 10, 91, 23));
        skinTable = new QTableView(skinTab);
        skinTable->setObjectName(QStringLiteral("skinTable"));
        skinTable->setGeometry(QRect(10, 40, 731, 441));
        skinTable->setFocusPolicy(Qt::TabFocus);
        skinTable->setSelectionMode(QAbstractItemView::SingleSelection);
        skinTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        skinTable->setSortingEnabled(true);
        skinTable->horizontalHeader()->setDefaultSectionSize(243);
        skinTable->horizontalHeader()->setHighlightSections(false);
        skinTable->verticalHeader()->setVisible(false);
        skinTable->verticalHeader()->setHighlightSections(false);
        skinSearchEdit = new QLineEdit(skinTab);
        skinSearchEdit->setObjectName(QStringLiteral("skinSearchEdit"));
        skinSearchEdit->setGeometry(QRect(10, 10, 631, 20));
        sTable->addTab(skinTab, QString());
        nailsTab = new QWidget();
        nailsTab->setObjectName(QStringLiteral("nailsTab"));
        nailsSearchEdit = new QLineEdit(nailsTab);
        nailsSearchEdit->setObjectName(QStringLiteral("nailsSearchEdit"));
        nailsSearchEdit->setGeometry(QRect(10, 10, 631, 20));
        nailsTable = new QTableView(nailsTab);
        nailsTable->setObjectName(QStringLiteral("nailsTable"));
        nailsTable->setGeometry(QRect(10, 40, 731, 441));
        nailsTable->setFocusPolicy(Qt::TabFocus);
        nailsTable->setSelectionMode(QAbstractItemView::SingleSelection);
        nailsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        nailsTable->setSortingEnabled(true);
        nailsTable->horizontalHeader()->setDefaultSectionSize(243);
        nailsTable->horizontalHeader()->setHighlightSections(false);
        nailsTable->verticalHeader()->setVisible(false);
        nailsTable->verticalHeader()->setHighlightSections(false);
        nailsSearchButton = new QPushButton(nailsTab);
        nailsSearchButton->setObjectName(QStringLiteral("nailsSearchButton"));
        nailsSearchButton->setGeometry(QRect(650, 10, 91, 23));
        sTable->addTab(nailsTab, QString());
        hairTab = new QWidget();
        hairTab->setObjectName(QStringLiteral("hairTab"));
        hairSearchEdit = new QLineEdit(hairTab);
        hairSearchEdit->setObjectName(QStringLiteral("hairSearchEdit"));
        hairSearchEdit->setGeometry(QRect(10, 10, 631, 20));
        hairTable = new QTableView(hairTab);
        hairTable->setObjectName(QStringLiteral("hairTable"));
        hairTable->setGeometry(QRect(10, 40, 731, 441));
        hairTable->setFocusPolicy(Qt::TabFocus);
        hairTable->setSelectionMode(QAbstractItemView::SingleSelection);
        hairTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        hairTable->setSortingEnabled(true);
        hairTable->horizontalHeader()->setDefaultSectionSize(243);
        hairTable->horizontalHeader()->setHighlightSections(false);
        hairTable->verticalHeader()->setVisible(false);
        hairTable->verticalHeader()->setHighlightSections(false);
        hairSearchButton = new QPushButton(hairTab);
        hairSearchButton->setObjectName(QStringLiteral("hairSearchButton"));
        hairSearchButton->setGeometry(QRect(650, 10, 91, 23));
        sTable->addTab(hairTab, QString());
        personalOfficeButton = new QPushButton(CatalogGUI);
        personalOfficeButton->setObjectName(QStringLiteral("personalOfficeButton"));
        personalOfficeButton->setGeometry(QRect(700, 10, 81, 31));
        QFont font;
        font.setFamily(QStringLiteral("Monotype Corsiva"));
        font.setPointSize(14);
        font.setItalic(true);
        personalOfficeButton->setFont(font);
        bucketButton = new QPushButton(CatalogGUI);
        bucketButton->setObjectName(QStringLiteral("bucketButton"));
        bucketButton->setGeometry(QRect(20, 10, 101, 31));
        bucketButton->setFont(font);
        label = new QLabel(CatalogGUI);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 20, 471, 16));
        label->setOpenExternalLinks(true);

        retranslateUi(CatalogGUI);

        sTable->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CatalogGUI);
    } // setupUi

    void retranslateUi(QWidget *CatalogGUI)
    {
        CatalogGUI->setWindowTitle(QApplication::translate("CatalogGUI", "Kateflame", 0));
        dcSearchButton->setText(QApplication::translate("CatalogGUI", "Search", 0));
        sTable->setTabText(sTable->indexOf(cosmeticTab), QApplication::translate("CatalogGUI", "\320\224\320\265\320\272\320\276\321\200\320\260\321\202\320\270\320\262\320\275\320\260 \320\272\320\276\321\201\320\274\320\265\321\202\320\270\320\272\320\260", 0));
        perfumSearchButton->setText(QApplication::translate("CatalogGUI", "Search", 0));
        sTable->setTabText(sTable->indexOf(perfumTab), QApplication::translate("CatalogGUI", "\320\237\320\260\321\200\321\204\321\203\320\274\320\265\321\200\320\275\321\226 \320\267\320\260\321\201\320\276\320\261\320\270", 0));
        skinSearchButton->setText(QApplication::translate("CatalogGUI", "Search", 0));
        sTable->setTabText(sTable->indexOf(skinTab), QApplication::translate("CatalogGUI", "\320\224\320\276\320\263\320\273\321\217\320\264 \320\267\320\260 \321\210\320\272\321\226\321\200\320\276\321\216/\320\276\320\261\320\273\320\270\321\207\321\207\321\217\320\274", 0));
        nailsSearchButton->setText(QApplication::translate("CatalogGUI", "Search", 0));
        sTable->setTabText(sTable->indexOf(nailsTab), QApplication::translate("CatalogGUI", "\320\224\320\276\320\263\320\273\321\217\320\264 \320\267\320\260 \320\275\321\226\320\263\321\202\321\217\320\274\320\270", 0));
        hairSearchButton->setText(QApplication::translate("CatalogGUI", "Search", 0));
        sTable->setTabText(sTable->indexOf(hairTab), QApplication::translate("CatalogGUI", "\320\224\320\276\320\263\320\273\321\217\320\264 \320\267\320\260 \320\262\320\276\320\273\320\276\321\201\321\201\321\217\320\274", 0));
        personalOfficeButton->setText(QApplication::translate("CatalogGUI", "Personal", 0));
        bucketButton->setText(QApplication::translate("CatalogGUI", "Bucket", 0));
        label->setText(QApplication::translate("CatalogGUI", "<A HREF='https://vk.com/katelevoshko'>Developer</A>", 0));
    } // retranslateUi

};

namespace Ui {
    class CatalogGUI: public Ui_CatalogGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATALOGGUI_H
