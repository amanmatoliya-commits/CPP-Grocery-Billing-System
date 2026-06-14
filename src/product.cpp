#include <iostream>
#include <iomanip>
#include "Product.hpp"
using namespace std;

// Default constructor
Product::Product() : id(0), name(""), price(0.0), unit("") {}

// Parameterized constructor
Product::Product(int id, const string &name, double price, const string &unit)
    : id(id), name(name), price(price), unit(unit) {}

// Getters
int Product::getId() const { return id; }
string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
string Product::getUnit() const { return unit; }

// Display function
void Product::display() const {
    cout << left << setw(5) << id
         << left << setw(20) << name
         << "Rs. " << fixed << setprecision(2) << price
         << " per " << unit << endl;
}









