#include "personaloffice.h"
#include "ui_personaloffice.h"
#include "mainwindow.h"
#include "cataloggui.h"
#include "currentuser.h"
#include "bucket.h"


PersonalOffice::PersonalOffice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalOffice)
{
    ui->setupUi(this);
    ui->nameLabel->setText(current_user->getName());
    ui->surnameLabel->setText(current_user->getSurname());
    ui->phoneLabel->setText(current_user->getPhoneNumber());
    ui->balanceLabel->setText(current_user->getBalance() + "$");
}

PersonalOffice::~PersonalOffice()
{
    delete ui;
}

void PersonalOffice::on_logOutButton_clicked()
{
    MainWindow* w = new MainWindow();
    this->close();
    current_user = NULL;
    Bucket* bk = Bucket::getInstance();
    bk->cleanBucket();
    w->show();
}

void PersonalOffice::on_backButton_clicked()
{
    CatalogGUI* w = new CatalogGUI();
    this->close();
    w->show();
}
