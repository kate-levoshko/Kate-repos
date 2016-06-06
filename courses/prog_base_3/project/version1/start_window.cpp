#include "start_window.h"
#include "authorisation.h"
#include "registration.h"
#include "ui_start_window.h"

start_window::start_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::start_window)
{
    ui->setupUi(this);
}

start_window::~start_window()
{
    delete ui;
}

void start_window::on_pushButton_clicked()
{
    this->hide();
    authorisation w;
    w.exec();
}

void start_window::on_pushButton_2_clicked()
{
    this->hide();
    registration w;
    w.exec();
}
