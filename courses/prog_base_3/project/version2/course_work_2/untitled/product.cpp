#include "product.h"

Product::Product(QString name, double price, int count)
{
    this->name = name;
    this->price = price;
    this->count = count;
}

QString Product::getName(){
    return name;
}

double Product::getPrice(){
    return price;
}

int Product::getCount(){
    return count;
}

void Product::setPrice(double price){
    this->price = price;
}

void Product::setCount(int count){
    this->count = count;
}
