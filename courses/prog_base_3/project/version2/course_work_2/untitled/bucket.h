#ifndef BUCKET_H
#define BUCKET_H

#include <vector>
#include "product.h"
#include <iostream>


class Bucket
{
public:
    void addProduct(Product* pr);
    int getSize();
    Product* getProduct(int index);
    void cleanBucket();
    static Bucket* getInstance();
    std::vector<Product*> bk;
private:
    Bucket();


};

#endif // BUCKET_H
