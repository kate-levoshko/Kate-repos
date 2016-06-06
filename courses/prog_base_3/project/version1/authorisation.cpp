#include "authorisation.h"
#include "main_window.h"
#include "ui_authorisation.h"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"

authorisation::authorisation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authorisation)
{
    ui->setupUi(this);
}

authorisation::~authorisation()
{
    delete ui;
}

void authorisation::on_pushButton_clicked()
{
    QString login = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Katya/Documents/GitHub/Kate-repos/courses/prog_base_3/project/version1/my.db);
    db.open();

    QSqlQuery query(db);
    query.exec("select * from users where users.login = '" + login + "' and users.password = '" + password + "';");
    if (query.next()){
        this->hide();
        main_window w;
        w.exec();
    }
    else {
        ui->label_3->setText("OK");
    }

}
