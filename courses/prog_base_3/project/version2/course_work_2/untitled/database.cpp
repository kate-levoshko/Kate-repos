#include "database.h"
#include "currentuser.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

void DataBase::connectToDataBase()
{
    if(!QFile("../myDb.sqlite").exists()){
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

bool DataBase::restoreDataBase()
{
    if(this->openDataBase())
        if(this->createUsersTable())
            if(this->createProductsTable())
                return true;

    qDebug() << "Не удалось восстановить базу данных";
    return false;
}

bool DataBase::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("MyDataBase");
    db.setDatabaseName("../myDb.sqlite");

    if(db.open()){
        return true;
    } else {
        return false;
    }
}


void DataBase::closeDataBase()
{
    db.close();
}

bool DataBase::createUsersTable()
{
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE USERS ("
                        "id integer PRIMARY KEY AUTOINCREMENT,"
                        "login varchar(32) NOT NULL,"
                        "password varchar(32) NOT NULL,"
                        "name varchar(32) NOT NULL,"
                        "surname varchar(32) NOT NULL,"
                        "phone varchar(12) NOT NULL,"
                        "balance varchar(10) NOT NULL"
                    ");"
                    )){
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBase::createProductsTable()
{
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE PRODUCTS ("
                        "id integer PRIMARY KEY,"
                        "product_name varchar(30) NOT NULL,"
                        "price real(10) NOT NULL,"
                        "count integer(6) NOT NULL,"
                        "type varchar(20) NOT NULL"
                    ");"

                    )){
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBase:: authorization(QString login, QString password){
    QSqlQuery query;

    if (query.exec("SELECT name, surname, phone, balance FROM USERS WHERE LOGIN = '"+login+"' AND PASSWORD = '"+password+"';")){
        if (query.next()){
            QString name = query.value("name").toString();
            QString surname = query.value("surname").toString();
            QString phone_number = query.value("phone").toString();

            QString bonus = query.value("balance").toString();

            current_user = new User(name, surname, phone_number, bonus);
            return true;
        }
    }

    return false;
}

bool DataBase::isUnique(QString login){
    QSqlQuery query;

    if (query.exec("SELECT login FROM USERS WHERE LOGIN = '"+login+"';")){
        if (query.next()){
            if(query.value(0) == login){
                return false;
            }
        }
    }
    return true;
}

bool DataBase::registration(QString login, QString password, QString name, QString surname, QString phone){
    QSqlQuery query;

    if(query.exec("INSERT INTO USERS (login, password, name, surname, phone, balance) VALUES ('"
                +login+"','"+password+"','"+name+"','"+surname+"','"+phone+"','0.0');")){
        return true;
    }

    return false;
}
