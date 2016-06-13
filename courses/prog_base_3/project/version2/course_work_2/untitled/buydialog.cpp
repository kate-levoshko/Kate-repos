#include "buydialog.h"
#include "ui_buydialog.h"
#include "product.h"
#include "bucket.h"
#include "QDebug"

BuyDialog::BuyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuyDialog)
{
    ui->setupUi(this);
}

void BuyDialog::init(Product* pr){
    this->pr = pr;
    ui->nameLabel->setText(pr->getName());
    ui->priceLabel->setText(QString::number(pr->getPrice())+"$");
    ui->countSpinBox->setMaximum(pr->getCount());
}

BuyDialog::~BuyDialog()
{
    delete ui;
}

void BuyDialog::on_cancelButton_clicked()
{
    this->close();
}

void BuyDialog::on_countSpinBox_valueChanged(int arg1)
{
    ui->priceLabel->setText(QString::number(pr->getPrice()*arg1)+"$");
}

void BuyDialog::on_buyButton_clicked()
{
    pr->setCount(ui->countSpinBox->value());
    pr->setPrice(pr->getPrice()*pr->getCount());
    Bucket* bk = Bucket::getInstance();
    bk->addProduct(pr);
    this->close();
}
