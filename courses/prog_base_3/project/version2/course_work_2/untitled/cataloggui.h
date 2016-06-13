#ifndef CATALOGGUI_H
#define CATALOGGUI_H

#include <QWidget>
#include "database.h"
#include <QSqlQueryModel>

namespace Ui {
class CatalogGUI;
}

class CatalogGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CatalogGUI(QWidget *parent = 0);
    ~CatalogGUI();

private slots:
    void on_personalOfficeButton_clicked();

    void on_bucketButton_clicked();

    void on_dcSearchButton_clicked();

    void on_sTable_tabBarClicked(int index);

    void on_perfumSearchButton_clicked();

    void on_skinSearchButton_clicked();

    void on_hairSearchButton_clicked();

    void on_nailsSearchButton_clicked();

    void on_decCosmeticsTable_doubleClicked(const QModelIndex &index);

    void on_perfumTable_doubleClicked(const QModelIndex &index);

    void on_skinTable_doubleClicked(const QModelIndex &index);

    void on_nailsTable_doubleClicked(const QModelIndex &index);

    void on_hairTable_doubleClicked(const QModelIndex &index);

    void on_cosmeticSearchEdit_returnPressed();

    void on_perfumSearchEdit_returnPressed();

    void on_skinSearchEdit_returnPressed();

    void on_nailsSearchEdit_returnPressed();

    void on_hairSearchEdit_returnPressed();

private:
    Ui::CatalogGUI *ui;
    DataBase* db;
    QSqlQueryModel* model;
};

#endif // CATALOGGUI_H
