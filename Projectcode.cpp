#include <iostream>
#include <iomanip>
using namespace std;

// Function declarations (prototypes)
int calculateSubtotal(int qty[], int prices[], int size);
double calculateDiscount(int subtotal);

int main() {

    // Menu items
    string items[] = {
        "Burger", "Pizza", "Sandwich",
        "Tea", "Cold Drink", "Coffee",
        "Ice Cream", "Cake", "Donut"
    };

    // Prices
    int prices[] = {300, 800, 250, 50, 100, 120, 150, 200, 180};

    // Arrays to store order quantities
    int qty[9] = {0};

    int choice, quantity;
    char continueOrder; // <-- Fixed here
    int orderNumber = 1001;

    cout << "========== Restaurant Ordering System ==========\n";
    cout << "Order Number: " << orderNumber << "\n\n";

    cout << "Menu Categories:\n";
    cout << "1-3   Fast Food\n";
    cout << "4-6   Drinks\n";
    cout << "7-9   Desserts\n\n";

    cout << "-------------- Menu --------------\n";

    for (int i = 0; i < 9; i++) {
        cout << setw(2) << (i + 1) << ". " << setw(12) << items[i]
             << "   Rs. " << prices[i] << endl;
    }

    cout << "\nEnter 0 to finish your order.\n";

    while (true) {
        cout << "\nEnter item number: ";
        cin >> choice;

        if (choice == 0)
            break;

        if (choice < 1 || choice > 9) {
            cout << "Invalid choice. Try again.";
            continue;
        }

        cout << "Enter quantity: ";
        cin >> quantity;

        qty[choice - 1] += quantity;
        cout << "Added to order.\n";

        cout << "Do you want to continue ordering? (y/n): ";
        cin >> continueOrder;

        if (continueOrder == 'n' || continueOrder == 'N')
            break;
    }

    cout << "\n\n========== BILL RECEIPT ==========\n";
    cout << left << setw(15) << "Item"
         << setw(10) << "Qty"
         << setw(10) << "Price"
         << setw(10) << "Total" << endl;

    cout << "----------------------------------------\n";

    for (int i = 0; i < 9; i++) {
        if (qty[i] > 0) {
            int total = qty[i] * prices[i];
            cout << left << setw(15) << items[i]
                 << setw(10) << qty[i]
                 << setw(10) << prices[i]
                 << setw(10) << total << endl;
        }
    }

    // Using function for subtotal
    int subtotal = calculateSubtotal(qty, prices, 9);
    cout << "----------------------------------------\n";
    cout << "Subtotal: Rs. " << subtotal << endl;

    // Using function for discount
    double discount = calculateDiscount(subtotal);
    cout << "Discount: Rs. " << discount << endl;

    // Service charges
    double service = subtotal * 0.05;
    cout << "Service Charges (5%): Rs. " << service << endl;

    // Final total
    double finalTotal = subtotal - discount + service;
    cout << "----------------------------------------\n";
    cout << "Final Amount: Rs. " << finalTotal << endl;
    cout << "========================================\n";

    cout << "Thank you for your order!\n";

    return 0;
}

// Function definitions (below main)
int calculateSubtotal(int qty[], int prices[], int size) {
    int subtotal = 0;
    for (int i = 0; i < size; i++) {
        if (qty[i] > 0) {
            subtotal += qty[i] * prices[i];
        }
    }
    return subtotal;
}

double calculateDiscount(int subtotal) {
    double discount = 0;
    if (subtotal > 4000)
        discount = subtotal * 0.15;
    else if (subtotal > 2000)
        discount = subtotal * 0.10;
    return discount;
}

