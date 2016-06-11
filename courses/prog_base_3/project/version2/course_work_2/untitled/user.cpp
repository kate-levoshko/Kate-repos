#include "user.h"
#include "cstring"

User::User(QString name, QString surname, QString phone_number, QString balance){
    this->name = name;
    this->surname = surname;
    this->phone_number = phone_number;
    this->balance = balance;
}

QString User::getName(){
    return name;
}

QString User::getSurname(){
    return surname;
}

QString User::getPhoneNumber(){
    return phone_number;
}

QString User::getBalance(){
    return balance;
}
