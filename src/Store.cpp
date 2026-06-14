#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include <chrono>
#include <ctime>
#include <string>
#include <cctype>
#include <algorithm>

#include <sstream>   // REQUIRED
#include "Store.hpp"

using namespace std;
/*  Constructor*/

Store::Store() {
    products.push_back(Product(1, "Sugar", 45, "kg"));
    products.push_back(Product(2, "Milk", 65, "litre"));
    products.push_back(Product(3, "Poha", 55, "kg"));
    products.push_back(Product(4, "Tea", 40, "packet(100g)"));
    products.push_back(Product(5, "Coffee", 120, "packet(100g)"));
    products.push_back(Product(6, "Tata Salt", 26, "kg"));
    products.push_back(Product(7, "Refined Oil", 155, "litre"));
    products.push_back(Product(8, "Maida", 30, "kg"));
    products.push_back(Product(9, "Amul Butter", 56, "packet(100g)"));
    products.push_back(Product(10, "Eggs", 6, "piece"));
}

/* Show Products */

void Store::showProducts() const {
    cout << "\nAvailable Products:\n";
    cout << left << setw(5) << "ID"
         << left << setw(20) << "Name"
         << "Price (Rs.)\n";
    cout << "----------------------------------------\n";
    for (const auto &p : products) {
        p.display();
    }
}

/* Add Item to Cart */

void Store::addItemToCart() {
    while (true) {

        showProducts();  // show products first

        cout << "\nEnter Product and Quantity  or type '0': ";
        string line;
        getline(cin, line);

        if (line == "0") {
            cout << "\nReturning to menu...\n";
            return;
        }

        stringstream ss(line);
        string productInput;
        int qty;
        ss >> productInput >> qty;

        if (ss.fail() || qty <= 0) {
            cout << "Invalid format. Use: Product Quantity\n";
            continue;
        }

        bool isNumber = all_of(productInput.begin(), productInput.end(), ::isdigit);
        bool found = false;

        if (isNumber) {
            int id = stoi(productInput);
            for (const auto &p : products) {
                if (p.getId() == id) {
                    cart.push_back({p, qty});
                    cout << "[OK] Item added.\n";
                    found = true;
                    break;
                }
            }
        } else {
            transform(productInput.begin(), productInput.end(),
                      productInput.begin(), ::tolower);

            for (const auto &p : products) {
                string pname = p.getName();
                transform(pname.begin(), pname.end(),
                          pname.begin(), ::tolower);

                if (pname == productInput) {
                    cart.push_back({p, qty});
                    cout << "[OK] Item added.\n";
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            cout << "Product not found.\n";
            continue;
        }

        // ✅ SHOW CART IMMEDIATELY AFTER ADDING
        showCart();
    }
}


/* Calculate Subtotal */

double Store::calculateSubtotal() const {
    double total = 0;
    for (const auto &item : cart) {
        total += item.first.getPrice() * item.second;
    }
    return total;
}

void Store::showCart() const {
    if (cart.empty()) {
        cout << "\n🛒 Cart is currently empty.\n";
        return;
    }

    cout << "\n🛒 Current Cart Items:\n";
    cout << left << setw(20) << "Product"
         << setw(10) << "Qty"
         << "Unit\n";
    cout << "-----------------------------------\n";

    for (const auto &item : cart) {
        cout << left << setw(20) << item.first.getName()
             << setw(10) << item.second
             << item.first.getUnit() << "\n";
    }

    cout << "-----------------------------------\n";
}


/* Save Bill to File */

void Store::saveBillToFile(const string &filename) const {
    ofstream file(filename, ios::app);
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm *local = localtime(&now_time);

    file << "=========== APNA GROCERY STORE BILL ===========\n";
    file << "Date: " << put_time(local, "%d-%m-%Y")
         << "   Time: " << put_time(local, "%H:%M:%S") << "\n";
    file << "-----------------------------------------------\n";

    for (const auto &item : cart) {
        file << left << setw(20) << item.first.getName()
             << "Qty: " << item.second << " " << item.first.getUnit()
             << "   Price: Rs. "
             << item.first.getPrice() * item.second << "\n";
    }

    double subtotal = calculateSubtotal();
    double discount = 0;

    if (subtotal >= 10000) discount = subtotal * 0.15;
    else if (subtotal >= 5000) discount = subtotal * 0.10;
    else if (subtotal >= 2000) discount = subtotal * 0.05;

    file << "-----------------------------------------------\n";
    file << "Subtotal: Rs. " << subtotal << "\n";
    file << "Discount: Rs. " << discount << "\n";
    file << "Grand Total: Rs. " << subtotal - discount << "\n";
    file << "===============================================\n\n";

    file.close();
    cout << "Bill saved to file: " << filename << endl;
}

/* Print Bill on Screen */

void Store::printBill() const {
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm *local = localtime(&now_time);

    cout << "\n=========== APNA GROCERY STORE BILL ===========\n";
    cout << "Date: " << put_time(local, "%d-%m-%Y")
         << "   Time: " << put_time(local, "%I:%M:%S %p") << "\n";
    cout << "-----------------------------------------------\n";

    for (const auto &item : cart) {
        cout << left << setw(20) << item.first.getName()
             << "Qty: " << item.second << " " << item.first.getUnit()
             << "   Price: Rs. "
             << item.first.getPrice() * item.second << endl;
    }

    double subtotal = calculateSubtotal();
    double discount = 0;

    if (subtotal >= 10000) discount = subtotal * 0.15;
    else if (subtotal >= 5000) discount = subtotal * 0.10;
    else if (subtotal >= 2000) discount = subtotal * 0.05;

    cout << "-----------------------------------------------\n";
    cout << "Subtotal: Rs. " << subtotal << endl;
    cout << "Discount: Rs. " << discount << endl;
    cout << "Grand Total: Rs. " << subtotal - discount << endl;
    cout << "===============================================\n";
}

/* Generate Bill */

void Store::generateBill() {
    if (cart.empty()) {
        cout << "Cart is empty. Add items first.\n";
        return;
    }

    printBill();
    saveBillToFile("bill.txt");
    cart.clear();
}










