#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 100

typedef struct {
    int roomNumber;
    char guestName[50];
    char guestAddress[100];
    char guestPhone[20];
    int stayDays;
    float roomRate;
} Room;

Room rooms[MAX_ROOMS];
int numRooms = 0;

void addRoom() {
    if (numRooms < MAX_ROOMS) {
        printf("Enter room number: ");
        scanf("%d", &rooms[numRooms].roomNumber);
        printf("Enter guest name: ");
        scanf("%s", rooms[numRooms].guestName);
        printf("Enter guest address: ");
        scanf("%s", rooms[numRooms].guestAddress);
        printf("Enter guest phone: ");
        scanf("%s", rooms[numRooms].guestPhone);
        printf("Enter number of stay days: ");
        scanf("%d", &rooms[numRooms].stayDays);
        printf("Enter room rate: ");
        scanf("%f", &rooms[numRooms].roomRate);
        numRooms++;
        printf("Room added successfully!\n");
    } else {
        printf("No more rooms available.\n");
    }
}

void displayRooms() {
    if (numRooms == 0) {
        printf("No rooms available.\n");
    } else {
        printf("Available rooms:\n");
        for (int i = 0; i < numRooms; i++) {
            printf("Room Number: %d, Guest Name: %s, Stay Days: %d, Room Rate: %.2f\n",
                   rooms[i].roomNumber, rooms[i].guestName, rooms[i].stayDays, rooms[i].roomRate);
        }
    }
}

void searchRoom() {
    int roomNumber;
    printf("Enter room number to search: ");
    scanf("%d", &roomNumber);
    int found = 0;
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            printf("Room found!\n");
            printf("Room Number: %d, Guest Name: %s, Stay Days: %d, Room Rate: %.2f\n",
                   rooms[i].roomNumber, rooms[i].guestName, rooms[i].stayDays, rooms[i].roomRate);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Room not found.\n");
    }
}

void deleteRoom() {
    int roomNumber;
    printf("Enter room number to delete: ");
    scanf("%d", &roomNumber);
    int found = 0;
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            for (int j = i; j < numRooms - 1; j++) {
                rooms[j] = rooms[j + 1];
            }
            numRooms--;
            printf("Room deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Room not found.\n");
    }
}

void calculateBill() {
    int roomNumber;
    printf("Enter room number to calculate bill: ");
    scanf("%d", &roomNumber);
    int found = 0;
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            float totalBill = rooms[i].stayDays * rooms[i].roomRate;
            printf("Total bill: %.2f\n", totalBill);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Room not found.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("Hotel Management System\n");
        printf("1. Add room\n");
        printf("2. Display rooms\n");
        printf("3. Search room\n");
        printf("4. Delete room\n");
        printf("5. Calculate bill\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRoom();
                break;
            case 2:
                displayRooms();
                break;
            case 3:
                searchRoom();
                break;
            case 4:
                deleteRoom();
                break;
            case 5:
                calculateBill();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}