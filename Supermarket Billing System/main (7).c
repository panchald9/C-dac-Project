#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];
int numItems = 0;

void addItem() {
    if (numItems < MAX_ITEMS) {
        printf("Enter item name: ");
        scanf("%s", items[numItems].name);
        printf("Enter item quantity: ");
        scanf("%d", &items[numItems].quantity);
        printf("Enter item price: ");
        scanf("%f", &items[numItems].price);
        numItems++;
        printf("Item added successfully!\n");
    } else {
        printf("No more items can be added.\n");
    }
}

void displayBill() {
    float total = 0;
    printf("Bill:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s x %d = %.2f\n", items[i].name, items[i].quantity, items[i].price * items[i].quantity);
        total += items[i].price * items[i].quantity;
    }
    printf("Total: %.2f\n", total);
}

void searchItem() {
    char name[MAX_NAME];
    printf("Enter item name to search: ");
    scanf("%s", name);
    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Item found!\n");
            printf("Quantity: %d\n", items[i].quantity);
            printf("Price: %.2f\n", items[i].price);
            return;
        }
    }
    printf("Item not found!\n");
}

void deleteItem() {
    char name[MAX_NAME];
    printf("Enter item name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, name) == 0) {
            for (int j = i; j < numItems - 1; j++) {
                items[j] = items[j + 1];
            }
            numItems--;
            printf("Item deleted successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

int main() {
    while (1) {
        printf("1. Add item\n");
        printf("2. Display bill\n");
        printf("3. Search item\n");
        printf("4. Delete item\n");
        printf("5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayBill();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}