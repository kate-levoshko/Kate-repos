#include "bucket.h"
#include <QDebug>


Bucket::Bucket(){

}

 Bucket* Bucket::getInstance(){
     static Bucket* link = new Bucket();
     return link;
 }

 void Bucket::addProduct(Product* pr){
     bk.push_back(pr);
 }

 int Bucket::getSize(){
     return bk.size();
 }

 Product* Bucket::getProduct(int index){
     return bk[index];
 }

 void Bucket::cleanBucket(){
     for(std::vector<Product*>::iterator it = bk.begin(); it != bk.end();){
         it = bk.erase(it);
     }
 }
