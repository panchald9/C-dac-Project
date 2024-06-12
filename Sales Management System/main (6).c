#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_ORDERS 100

typedef struct {
    int productId;
    char productName[50];
    float price;
    int quantity;
} Product;

typedef struct {
    int orderId;
    int productId;
    int quantity;
    float total;
} Order;

Product products[MAX_PRODUCTS];
int numProducts = 0;

Order orders[MAX_ORDERS];
int numOrders = 0;

void addProduct() {
    if (numProducts < MAX_PRODUCTS) {
        printf("Enter product ID: ");
        scanf("%d", &products[numProducts].productId);
        printf("Enter product name: ");
        scanf("%s", products[numProducts].productName);
        printf("Enter price: ");
        scanf("%f", &products[numProducts].price);
        printf("Enter quantity: ");
        scanf("%d", &products[numProducts].quantity);
        numProducts++;
        printf("Product added successfully!\n");
    } else {
        printf("No more products can be added.\n");
    }
}

void displayProducts() {
    if (numProducts == 0) {
        printf("No products available.\n");
    } else {
        printf("Available products:\n");
        for (int i = 0; i < numProducts; i++) {
            printf("Product ID: %d, Product Name: %s, Price: %.2f, Quantity: %d\n",
                   products[i].productId, products[i].productName, products[i].price, products[i].quantity);
        }
    }
}

void placeOrder() {
    int productId;
    printf("Enter product ID to place order: ");
    scanf("%d", &productId);
    int found = 0;
    for (int i = 0; i < numProducts; i++) {
        if (products[i].productId == productId) {
            if (products[i].quantity > 0) {
                int quantity;
                printf("Enter quantity to order: ");
                scanf("%d", &quantity);
                if (quantity <= products[i].quantity) {
                    orders[numOrders].orderId = numOrders + 1;
                    orders[numOrders].productId = productId;
                    orders[numOrders].quantity = quantity;
                    orders[numOrders].total = products[i].price * quantity;
                    numOrders++;
                    products[i].quantity -= quantity;
                    printf("Order placed successfully!\n");
                    found = 1;
                    break;
                } else {
                    printf("Not enough quantity available.\n");
                    found = 1;
                    break;
                }
            } else {
                printf("Product out of stock.\n");
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

void displayOrders() {
    if (numOrders == 0) {
        printf("No orders placed.\n");
    } else {
        printf("Orders:\n");
        for (int i = 0; i < numOrders; i++) {
            printf("Order ID: %d, Product ID: %d, Quantity: %d, Total: %.2f\n",
                   orders[i].orderId, orders[i].productId, orders[i].quantity, orders[i].total);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("Sales Management System\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Place order\n");
        printf("4. Display orders\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                placeOrder();
                break;
            case 4:
                displayOrders();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}