#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql/QSql>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include "product.h"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();
    void connectToDataBase();
    void closeDataBase();
    bool authorization(QString login, QString password);
    bool registration(QString login, QString password, QString name, QString surname, QString phone);
    bool isUnique(QString login);
    QSqlDatabase getDb();
    QSqlQuery* search(QString name, QString type);
    void update(QString name, int c, double bonus);
private:
    QSqlDatabase db;

private:
    bool openDataBase();
    bool restoreDataBase();
    bool createUsersTable();
    bool createProductsTable();
    int getCountProduct(QString name);
    double getBonusUser();
};

#endif // DATABASE_H
