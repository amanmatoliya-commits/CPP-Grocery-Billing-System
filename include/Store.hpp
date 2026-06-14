#ifndef STORE_HPP
#define STORE_HPP

#include <vector>
#include <string>
#include "Product.hpp"

class Store {
private:
    std::vector<Product> products;
    std::vector<std::pair<Product, int>> cart;

public:
    Store();

    void showProducts() const;
    void addItemToCart();
    void generateBill();

    // 🔥 REQUIRED ADDITION
    void showCart() const;

    double calculateSubtotal() const;
    void printBill() const;
    void saveBillToFile(const std::string &filename) const;
};

#endif

