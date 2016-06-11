#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registration.h"
#include "personaloffice.h"
#include "database.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_singInButton_clicked()
{
    DataBase* db = new DataBase();
    db->connectToDataBase();
    if(db->authorization(ui->loginEdit->text(), ui->passwordEdit->text())){
        PersonalOffice* w = new PersonalOffice();
        this->close();
        w->show();
        db->closeDataBase();
    } else {
        //Error
    }
}

void MainWindow::on_registerButton_clicked()
{

    Registration* w = new Registration();
    this->close();
    w->show();
}
