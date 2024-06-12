#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[50];
    char author[50];
    int quantity;
    float price;
} Book;

Book books[MAX_BOOKS];
int numBooks = 0;

void addBook() {
    if (numBooks < MAX_BOOKS) {
        printf("Enter book title: ");
        scanf("%s", books[numBooks].title);
        printf("Enter book author: ");
        scanf("%s", books[numBooks].author);
        printf("Enter book quantity: ");
        scanf("%d", &books[numBooks].quantity);
        printf("Enter book price: ");
        scanf("%f", &books[numBooks].price);
        numBooks++;
        printf("Book added successfully!\n");
    } else {
        printf("Bookshop is full. Cannot add more books.\n");
    }
}

void displayBooks() {
    if (numBooks == 0) {
        printf("No books in the bookshop.\n");
    } else {
        printf("Books in the bookshop:\n");
        for (int i = 0; i < numBooks; i++) {
            printf("Title: %s, Author: %s, Quantity: %d, Price: %.2f\n",
                   books[i].title, books[i].author, books[i].quantity, books[i].price);
        }
    }
}

void searchBook() {
    char title[50];
    printf("Enter book title to search: ");
    scanf("%s", title);
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Book found!\n");
            printf("Title: %s, Author: %s, Quantity: %d, Price: %.2f\n",
                   books[i].title, books[i].author, books[i].quantity, books[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

void deleteBook() {
    char title[50];
    printf("Enter book title to delete: ");
    scanf("%s", title);
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            for (int j = i; j < numBooks - 1; j++) {
                books[j] = books[j + 1];
            }
            numBooks--;
            printf("Book deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("Bookshop Management System\n");
        printf("1. Add book\n");
        printf("2. Display books\n");
        printf("3. Search book\n");
        printf("4. Delete book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}