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

private:
    QSqlDatabase    db;

private:
    bool openDataBase();
    bool restoreDataBase();
    bool createUsersTable();
    bool createProductsTable();
};

#endif // DATABASE_H
