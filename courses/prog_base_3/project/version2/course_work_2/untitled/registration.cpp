#include "registration.h"
#include "ui_registration.h"
#include "database.h"
#include "mainwindow.h"
#include <QMessageBox>

Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_registerButton_clicked()
{
    DataBase* db = new DataBase();
    db->connectToDataBase();

    if(ui->passwordEdit->text() ==  ui->passwordEdit_2->text()){
        if(db->isUnique(ui->loginEdit->text())){
            if(db->registration(ui->loginEdit->text(),ui->passwordEdit->text(),ui->nameEdit->text(),ui->surnameEdit->text(),ui->phoneEdit->text())){
                MainWindow* w = new MainWindow();
                this->close();
                w->show();
            }
        } else {
            QMessageBox::warning(this, tr("Ошибка") ,tr("Это имя уже занято. Попробуйте другое."));
        }
    } else {
        QMessageBox::warning(this, tr("Ошибка") ,tr("Пароли не совпадают. Повторите попытку."));
        ui->passwordEdit->setText("");
        ui->passwordEdit_2->setText("");
    }

    db->closeDataBase();
}
