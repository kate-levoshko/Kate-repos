#ifndef USER_H
#define USER_H

#include "QString"

class User
{
public:
    User(QString name, QString surname, QString phone_number, QString balance);
    QString getName();
    QString getSurname();
    QString getPhoneNumber();
    QString getBalance();

private:
    QString name;
    QString surname;
    QString phone_number;
    QString balance;

    //Bucket *bucket;
};

#endif // USER_H
