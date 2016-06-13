#include "bucketgui.h"
#include "ui_bucketgui.h"
#include "cataloggui.h"
#include "bucket.h"

BucketGUI::BucketGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BucketGUI)
{
    ui->setupUi(this);
    Bucket* bk = Bucket::getInstance();
    ui->buyTable->setRowCount(bk->getSize());
    QStringList l;
    l << "Name" <<"Price" << "Count";
    ui->buyTable->setHorizontalHeaderLabels(l);
    QTableWidgetItem* item1 = new QTableWidgetItem();
    QTableWidgetItem* item2 = new QTableWidgetItem();
    QTableWidgetItem* item3 = new QTableWidgetItem();

    Product* pr;
    for(int i = 0; i < bk->getSize(); i++){
        pr = bk->getProduct(i);
        item1 = new QTableWidgetItem();
        item2 = new QTableWidgetItem();
        item3 = new QTableWidgetItem();

        item1->setText(pr->getName());
        ui->buyTable->setItem(i,0,item1);
        item2->setText(QString::number(pr->getPrice()));
        ui->buyTable->setItem(i,1,item2);
        item3->setText(QString::number(pr->getCount()));
        ui->buyTable->setItem(i,2,item3);
    }

}

BucketGUI::~BucketGUI()
{
    delete ui;
}

void BucketGUI::on_backButton_clicked()
{
    CatalogGUI* w = new CatalogGUI();
    this->close();
    w->show();
}

void BucketGUI::on_cleanButton_clicked()
{
    Bucket::getInstance()->cleanBucket();
    ui->buyTable->clear();
    QStringList l;
    l << "Name" <<"Price" << "Count";
    ui->buyTable->setHorizontalHeaderLabels(l);
    ui->buyTable->setRowCount(Bucket::getInstance()->getSize());

}
