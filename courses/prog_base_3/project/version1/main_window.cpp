#include "main_window.h"
#include "ui_main_window.h"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlQueryModel"

main_window::main_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::main_window)
{
    ui->setupUi(this);
}

main_window::~main_window()
{
    delete ui;
}

void main_window::on_tableView_activated(const QModelIndex &index)
{

}

void main_window::on_tableView_clicked(const QModelIndex &index)
{

}

void main_window::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Bogdan/Documents/course_work_1/my.db");
    db.open();

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery(db);
    query->exec("select id, product_name, price, description from cosmetics where cosmetics.type = 'decorative'");

    model->setQuery(*query);
    ui->tableView->setModel(model);
}
