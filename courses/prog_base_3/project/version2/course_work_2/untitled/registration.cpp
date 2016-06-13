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

bool Registration::isCorrectData(){
    QString login = ui->loginEdit->text();
    QString password1 = ui->passwordEdit->text();
    QString password2 = ui->passwordEdit_2->text();
    QString name = ui->nameEdit->text();
    QString surname = ui->surnameEdit->text();
    QString phone = ui->phoneEdit->text();

    if (login.size() == 0 || password1.size() == 0 || password2 == 0 || name.size() == 0 || surname.size() == 0 || phone.size() == 0) return false;

    for (int i = 0; i < login.size(); i++){
        if (!(isalnum(login[i].toLatin1()))) return false;
    }

    for (int i = 0; i < password1.size(); i++){
            if (!(isalnum(password1[i].toLatin1()))) return false;
    }

    for (int i = 0; i < password2.size(); i++){
            if (!(isalnum(password2[i].toLatin1()))) return false;
    }

    for (int i = 0; i < name.size(); i++){
            if (!(isalpha(name[i].toLatin1()))) return false;
    }

    for (int i = 0; i < surname.size(); i++){
            if (!(isalpha(surname[i].toLatin1()))) return false;
    }
    for (int i = 0; i < phone.size(); i++){
            if (!(isdigit(phone[i].toLatin1()))) return false;
    }
    return true;
}


void Registration::on_registerButton_clicked()
{
    DataBase* db = new DataBase();
    db->connectToDataBase();

    if (isCorrectData()){
        if(ui->passwordEdit->text() ==  ui->passwordEdit_2->text()){
            if(db->isUnique(ui->loginEdit->text())){
                if(db->registration(ui->loginEdit->text(),ui->passwordEdit->text(),ui->nameEdit->text(),ui->surnameEdit->text(),ui->phoneEdit->text())){
                   MainWindow* w = new MainWindow();
                   this->close();
                   w->show();
                }
            } else {
                QMessageBox::warning(this, tr("Error") ,tr("Это имя уже занято. Попробуйте другое."));
            }
         } else {
            QMessageBox::warning(this, tr("Error") ,tr("Пароли не совпадают. Повторите попытку."));
            ui->passwordEdit->setText("");
            ui->passwordEdit_2->setText("");
          }
    } else {
        QMessageBox::warning(this, tr("Error") ,tr("Неккоректные данные!"));
    }

    db->closeDataBase();
}
