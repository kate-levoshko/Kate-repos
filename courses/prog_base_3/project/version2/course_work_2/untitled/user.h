#ifndef USER_H
#define USER_H

#include "QString"

class User
{
public:
    User(QString login,QString name, QString surname, QString phone_number, QString bonus);
    QString getLogin();
    QString getName();
    QString getSurname();
    QString getPhoneNumber();
    QString getBonus();
    void setBonus(QString bonus);

private:
    QString login;
    QString name;
    QString surname;
    QString phone_number;
    QString bonus;
};

#endif // USER_H
