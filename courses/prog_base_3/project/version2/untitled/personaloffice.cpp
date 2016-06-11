#include "personaloffice.h"
#include "ui_personaloffice.h"
#include "mainwindow.h"
#include "currentuser.h"


PersonalOffice::PersonalOffice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalOffice)
{
    ui->setupUi(this);
    ui->nameLabel->setText(current_user->getName());
    ui->surnameLabel->setText(current_user->getSurname());
    ui->phoneLabel->setText(current_user->getPhoneNumber());
    ui->bonusLabel->setText(current_user->getBonus() + "$");
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
    w->show();
}
