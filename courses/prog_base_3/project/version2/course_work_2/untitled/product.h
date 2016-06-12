#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

class Product
{
public:
    Product(QString name, QString price, QString count);

private:
    QString name;
    QString price;
    QString count;
};

#endif // PRODUCT_H
