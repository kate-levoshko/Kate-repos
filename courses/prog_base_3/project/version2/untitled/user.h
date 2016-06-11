#ifndef USER_H
#define USER_H

#include "QString"

class User
{
public:
    User(QString name, QString surname, QString phone_number, QString bonus);
    QString getName();
    QString getSurname();
    QString getPhoneNumber();
    QString getBonus();

private:
    QString name;
    QString surname;
    QString phone_number;
    QString bonus;

    //Bucket *bucket;
};

#endif // USER_H
