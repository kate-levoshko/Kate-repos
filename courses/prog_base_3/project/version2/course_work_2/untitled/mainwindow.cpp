#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registration.h"
#include "personaloffice.h"
#include "cataloggui.h"
#include "database.h"
#include <QMessageBox>

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
        CatalogGUI* w = new CatalogGUI();
        this->close();
        w->show();
        db->closeDataBase();
    } else {
        QMessageBox::warning(this, tr("Error") ,tr("Неверное имя пользователя или пароль!"));
    }
}

void MainWindow::on_registerButton_clicked()
{

    Registration* w = new Registration();
    this->close();
    w->show();
}

void MainWindow::on_passwordEdit_returnPressed()
{
    ui->singInButton->click();
}

void MainWindow::on_loginEdit_returnPressed()
{
     ui->singInButton->click();
}
