#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
#include <iostream>
using namespace std;

class Product {
private:
    int id;
    string name;
    double price;
    string unit;   // NEW FIELD

public:
    Product();  
    //Product(int id, const string &name, double price, const string &unit);
     Product(int id, const string &name, double price, const string &unit);

    int getId() const;
    string getName() const;
    double getPrice() const;
    string getUnit() const;

    void display() const;
};

#endif



