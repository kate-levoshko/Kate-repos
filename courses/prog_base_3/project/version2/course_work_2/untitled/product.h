#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

class Product
{
public:
    Product(QString name, double price, int count);
    QString getName();
    double getPrice();
    int getCount();
    void setCount(int count);
    void setPrice(double price);
private:
    QString name;
    double price;
    int count;
};

#endif // PRODUCT_H
