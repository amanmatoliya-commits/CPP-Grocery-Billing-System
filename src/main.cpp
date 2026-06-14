#include <iostream>
#include <limits>
#include "Store.hpp"
using namespace std;
int main() {
    Store store;
    int choice;
    cout << "\n=== WELCOME TO APNA GROCERY STORE ===\n";
    cout << "Discount Policy:\n";
    cout << "  Rs. 2000+  ->  5% discount\n";
    cout << "  Rs. 5000+ -> 10% discount\n";
    cout << "  Rs. 10000+ -> 15% discount\n";
    while (true) {
        cout << "\n1. Show Products\n";
        cout << "2. Add Products to Cart\n";
        cout << "3. Generate Bill\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // FIX BUFFER
        switch (choice) {
            case 1:
                store.showProducts();
                break;
            case 2:
                store.addItemToCart();
                break;
            case 3:
                store.generateBill();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}

