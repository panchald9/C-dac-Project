#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phoneNumber[20];
    char email[50];
} Contact;

Contact contacts[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    if (numContacts < MAX_CONTACTS) {
        printf("Enter name: ");
        scanf("%s", contacts[numContacts].name);
        printf("Enter phone number: ");
        scanf("%s", contacts[numContacts].phoneNumber);
        printf("Enter email: ");
        scanf("%s", contacts[numContacts].email);
        numContacts++;
        printf("Contact added successfully!\n");
    } else {
        printf("Phonebook is full. Cannot add more contacts.\n");
    }
}

void displayContacts() {
    if (numContacts == 0) {
        printf("Phonebook is empty.\n");
    } else {
        printf("Contacts:\n");
        for (int i = 0; i < numContacts; i++) {
            printf("Name: %s, Phone Number: %s, Email: %s\n",
                   contacts[i].name, contacts[i].phoneNumber, contacts[i].email);
        }
    }
}

void searchContact() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found!\n");
            printf("Name: %s, Phone Number: %s, Email: %s\n",
                   contacts[i].name, contacts[i].phoneNumber, contacts[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void deleteContact() {
    char name[50];
    printf("Enter name to delete: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < numContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            numContacts--;
            printf("Contact deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("Phonebook Management System\n");
        printf("1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
