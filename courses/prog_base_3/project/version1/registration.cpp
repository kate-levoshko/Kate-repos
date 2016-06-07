#include "registration.h"
#include "ui_registration.h"
#include "start_window.h"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"

using namespace std;

registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
}

registration::~registration()
{
    delete ui;
}

void registration::on_pushButton_clicked()
{
    QString login = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString password_again = ui->lineEdit_3->text();
    QString name = ui->lineEdit_4->text();
    QString surname = ui->lineEdit_5->text();
    QString phone_number = ui->lineEdit_6->text();
/*
    if (strcmp(password, password_again)){

    }
*/
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Katya/Documents/GitHub/Kate-repos/courses/prog_base_3/project/version1/my.db");
    db.open();
    QSqlQuery query(db);
    QString query_string = "insert into users (name, surname, phone_number, login, password) values ('" + name + "', '" + surname
            + "', '" + phone_number + "', '" + login + "', '" + password + "');";
    query.exec(query_string);

    this->hide();
    start_window w;
    w.show();
}
