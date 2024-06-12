#include <stdio.h>
#include <string.h>

#define MAX_BUSES 10
#define MAX_SEATS 50

typedef struct {
    char busNumber[10];
    char route[50];
    int seats[MAX_SEATS];
    int numSeats;
} Bus;

Bus buses[MAX_BUSES];
int numBuses = 0;

void addBus() {
    if (numBuses < MAX_BUSES) {
        printf("Enter bus number: ");
        scanf("%s", buses[numBuses].busNumber);
        printf("Enter bus route: ");
        scanf("%s", buses[numBuses].route);
        buses[numBuses].numSeats = 0;
        for (int i = 0; i < MAX_SEATS; i++) {
            buses[numBuses].seats[i] = 0;
        }
        numBuses++;
        printf("Bus added successfully!\n");
    } else {
        printf("No more buses can be added.\n");
    }
}

void displayBuses() {
    if (numBuses == 0) {
        printf("No buses available.\n");
    } else {
        printf("Available buses:\n");
        for (int i = 0; i < numBuses; i++) {
            printf("Bus Number: %s, Route: %s, Available Seats: %d\n",
                   buses[i].busNumber, buses[i].route, MAX_SEATS - buses[i].numSeats);
        }
    }
}

void reserveSeat() {
    char busNumber[10];
    printf("Enter bus number to reserve a seat: ");
    scanf("%s", busNumber);
    int found = 0;
    for (int i = 0; i < numBuses; i++) {
        if (strcmp(buses[i].busNumber, busNumber) == 0) {
            if (buses[i].numSeats < MAX_SEATS) {
                buses[i].seats[buses[i].numSeats] = 1;
                buses[i].numSeats++;
                printf("Seat reserved successfully!\n");
            } else {
                printf("No seats available on this bus.\n");
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Bus not found.\n");
    }
}

void cancelReservation() {
    char busNumber[10];
    printf("Enter bus number to cancel a reservation: ");
    scanf("%s", busNumber);
    int found = 0;
    for (int i = 0; i < numBuses; i++) {
        if (strcmp(buses[i].busNumber, busNumber) == 0) {
            if (buses[i].numSeats > 0) {
                buses[i].seats[buses[i].numSeats - 1] = 0;
                buses[i].numSeats--;
                printf("Reservation cancelled successfully!\n");
            } else {
                printf("No reservations to cancel on this bus.\n");
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Bus not found.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("Bus Reservation System\n");
        printf("1. Add bus\n");
        printf("2. Display buses\n");
        printf("3. Reserve a seat\n");
        printf("4. Cancel a reservation\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBus();
                break;
            case 2:
                displayBuses();
                break;
            case 3:
                reserveSeat();
                break;
            case 4:
                cancelReservation();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}