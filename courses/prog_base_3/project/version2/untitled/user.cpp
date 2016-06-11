#include "user.h"
#include "cstring"

User::User(QString name, QString surname, QString phone_number, QString bonus){
    this->name = name;
    this->surname = surname;
    this->phone_number = phone_number;
    this->bonus = bonus;
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

QString User::getBonus(){
    return bonus;
}
