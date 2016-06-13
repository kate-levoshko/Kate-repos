#include "cataloggui.h"
#include "ui_cataloggui.h"
#include "personaloffice.h"
#include "bucketgui.h"
#include "QMessageBox"
#include "product.h"
#include "buydialog.h"
#include "bucket.h"
#include <QSortFilterProxyModel>

CatalogGUI::CatalogGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CatalogGUI)
{
    ui->setupUi(this);


    db = new DataBase();

    model = new QSqlQueryModel();
    db->connectToDataBase();
    QSqlQuery* qry = new QSqlQuery(db->getDb());

    qry->exec("SELECT product_name,price,count FROM PRODUCTS WHERE type = 'cosmetic'");
    model->setQuery(*qry);
    ui->decCosmeticsTable->setModel(model);
    db->closeDataBase();
}

CatalogGUI::~CatalogGUI()
{
    delete ui;
}

void CatalogGUI::on_personalOfficeButton_clicked()
{
    PersonalOffice* w = new PersonalOffice();
    this->close();
    w->show();
}

void CatalogGUI::on_bucketButton_clicked()
{
    BucketGUI* w = new BucketGUI();
    this->close();
    w->show();
}

void CatalogGUI::on_sTable_tabBarClicked(int index)
{
    switch(index){
        case 0: {
            ui->cosmeticSearchEdit->setText("");
            db->connectToDataBase();
            QSqlQuery* qry = new QSqlQuery(db->getDb());

            qry->exec("SELECT product_name,price,count FROM PRODUCTS WHERE type = 'cosmetic'");
            model->setQuery(*qry);

            ui->decCosmeticsTable->setModel(model);
            db->closeDataBase();
            break;
        }
        case 1: {
            ui->perfumSearchEdit->setText("");
            db->connectToDataBase();
            QSqlQuery* qry = new QSqlQuery(db->getDb());

            qry->exec("SELECT product_name,price,count FROM PRODUCTS WHERE type = 'perfum'");
            model->setQuery(*qry);

            ui->perfumTable->setModel(model);
            db->closeDataBase();
            break;
        }
        case 2: {
            ui->skinSearchEdit->setText("");
            db->connectToDataBase();
            QSqlQuery* qry = new QSqlQuery(db->getDb());

            qry->exec("SELECT product_name,price,count FROM PRODUCTS WHERE type = 'skin'");
            model->setQuery(*qry);

            ui->skinTable->setModel(model);
            db->closeDataBase();
            break;
        }
        case 3: {
            ui->hairSearchEdit->setText("");
            db->connectToDataBase();
            QSqlQuery* qry = new QSqlQuery(db->getDb());

            qry->exec("SELECT product_name,price,count FROM PRODUCTS WHERE type = 'hair'");
            model->setQuery(*qry);

            ui->hairTable->setModel(model);
            db->closeDataBase();
            break;
        }
        case 4: {
            ui->nailsSearchEdit->setText("");
            db->connectToDataBase();
            QSqlQuery* qry = new QSqlQuery(db->getDb());

            qry->exec("SELECT product_name,price,count FROM PRODUCTS WHERE type = 'nails'");
            model->setQuery(*qry);

            ui->nailsTable->setModel(model);
            db->closeDataBase();
            break;
        }
    }
}


void CatalogGUI::on_dcSearchButton_clicked()
{
    db->connectToDataBase();
    QSqlQuery* query = db->search(ui->cosmeticSearchEdit->text(), "cosmetic");

    if(query != NULL){
        model->setQuery(*query);
        ui->decCosmeticsTable->setModel(model);
    }
    db->closeDataBase();
}

void CatalogGUI::on_perfumSearchButton_clicked()
{
    db->connectToDataBase();
    QSqlQuery* query = db->search(ui->perfumSearchEdit->text(), "perfum");

    if(query != NULL){
        model->setQuery(*query);
        ui->perfumTable->setModel(model);
    }
    db->closeDataBase();
}

void CatalogGUI::on_skinSearchButton_clicked()
{
    db->connectToDataBase();
    QSqlQuery* query = db->search(ui->skinSearchEdit->text(), "skin");

    if(query != NULL){
        model->setQuery(*query);
        ui->skinTable->setModel(model);
    }
    db->closeDataBase();
}

void CatalogGUI::on_hairSearchButton_clicked()
{
    db->connectToDataBase();
    QSqlQuery* query = db->search(ui->hairSearchEdit->text(), "hair");

    if(query != NULL){
        model->setQuery(*query);
        ui->hairTable->setModel(model);
    }
    db->closeDataBase();
}

void CatalogGUI::on_nailsSearchButton_clicked()
{
    db->connectToDataBase();
    QSqlQuery* query = db->search(ui->nailsSearchEdit->text(), "nails");

    if(query != NULL){
        model->setQuery(*query);
        ui->nailsTable->setModel(model);
    }
    db->closeDataBase();
}

void CatalogGUI::on_decCosmeticsTable_doubleClicked(const QModelIndex &index)
{
    QModelIndexList data = ui->decCosmeticsTable->selectionModel()->selectedIndexes();
    Product* pr = new Product(data.value(0).data().toString(),data.value(1).data().toDouble(),data.value(2).data().toInt());
    BuyDialog* dialog = new BuyDialog();
    dialog->init(pr);
    dialog->show();
}

void CatalogGUI::on_perfumTable_doubleClicked(const QModelIndex &index)
{
    QModelIndexList data = ui->perfumTable->selectionModel()->selectedIndexes();
    Product* pr = new Product(data.value(0).data().toString(),data.value(1).data().toDouble(),data.value(2).data().toInt());
    BuyDialog* dialog = new BuyDialog();
    dialog->init(pr);
    dialog->show();
}

void CatalogGUI::on_skinTable_doubleClicked(const QModelIndex &index)
{
    QModelIndexList data = ui->skinTable->selectionModel()->selectedIndexes();
    Product* pr = new Product(data.value(0).data().toString(),data.value(1).data().toDouble(),data.value(2).data().toInt());
    BuyDialog* dialog = new BuyDialog();
    dialog->init(pr);
    dialog->show();
}

void CatalogGUI::on_nailsTable_doubleClicked(const QModelIndex &index)
{
    QModelIndexList data = ui->nailsTable->selectionModel()->selectedIndexes();
    Product* pr = new Product(data.value(0).data().toString(),data.value(1).data().toDouble(),data.value(2).data().toInt());
    BuyDialog* dialog = new BuyDialog();
    dialog->init(pr);
    dialog->show();
}

void CatalogGUI::on_hairTable_doubleClicked(const QModelIndex &index)
{
    QModelIndexList data = ui->hairTable->selectionModel()->selectedIndexes();
    Product* pr = new Product(data.value(0).data().toString(),data.value(1).data().toDouble(),data.value(2).data().toInt());
    BuyDialog* dialog = new BuyDialog();
    dialog->init(pr);
    dialog->show();
}
