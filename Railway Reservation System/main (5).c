#include <stdio.h>
#include <string.h>

#define MAX_TRAINS 10
#define MAX_PASSENGERS 100

typedef struct {
    int trainNumber;
    char trainName[50];
    int numSeats;
    int seatsAvailable;
} Train;

typedef struct {
    int passengerId;
    char passengerName[50];
    int trainNumber;
    int seatNumber;
} Passenger;

Train trains[MAX_TRAINS];
int numTrains = 0;

Passenger passengers[MAX_PASSENGERS];
int numPassengers = 0;

void addTrain() {
    if (numTrains < MAX_TRAINS) {
        printf("Enter train number: ");
        scanf("%d", &trains[numTrains].trainNumber);
        printf("Enter train name: ");
        scanf("%s", trains[numTrains].trainName);
        printf("Enter number of seats: ");
        scanf("%d", &trains[numTrains].numSeats);
        trains[numTrains].seatsAvailable = trains[numTrains].numSeats;
        numTrains++;
        printf("Train added successfully!\n");
    } else {
        printf("No more trains can be added.\n");
    }
}

void displayTrains() {
    if (numTrains == 0) {
        printf("No trains available.\n");
    } else {
        printf("Available trains:\n");
        for (int i = 0; i < numTrains; i++) {
            printf("Train Number: %d, Train Name: %s, Seats Available: %d\n",
                   trains[i].trainNumber, trains[i].trainName, trains[i].seatsAvailable);
        }
    }
}

void bookTicket() {
    int trainNumber;
    printf("Enter train number to book ticket: ");
    scanf("%d", &trainNumber);
    int found = 0;
    for (int i = 0; i < numTrains; i++) {
        if (trains[i].trainNumber == trainNumber) {
            if (trains[i].seatsAvailable > 0) {
                printf("Enter passenger name: ");
                scanf("%s", passengers[numPassengers].passengerName);
                passengers[numPassengers].passengerId = numPassengers + 1;
                passengers[numPassengers].trainNumber = trainNumber;
                passengers[numPassengers].seatNumber = trains[i].numSeats - trains[i].seatsAvailable + 1;
                numPassengers++;
                trains[i].seatsAvailable--;
                printf("Ticket booked successfully!\n");
                found = 1;
                break;
            } else {
                printf("No seats available on this train.\n");
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        printf("Train not found.\n");
    }
}

void cancelTicket() {
    int passengerId;
    printf("Enter passenger ID to cancel ticket: ");
    scanf("%d", &passengerId);
    int found = 0;
    for (int i = 0; i < numPassengers; i++) {
        if (passengers[i].passengerId == passengerId) {
            for (int j = 0; j < numTrains; j++) {
                if (trains[j].trainNumber == passengers[i].trainNumber) {
                    trains[j].seatsAvailable++;
                    break;
                }
            }
            for (int j = i; j < numPassengers - 1; j++) {
                passengers[j] = passengers[j + 1];
            }
            numPassengers--;
            printf("Ticket cancelled successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Passenger not found.\n");
    }
}

void displayPassengers() {
    if (numPassengers == 0) {
        printf("No passengers.\n");
    } else {
        printf("Passengers:\n");
        for (int i = 0; i < numPassengers; i++) {
            printf("Passenger ID: %d, Passenger Name: %s, Train Number: %d, Seat Number: %d\n",
                   passengers[i].passengerId, passengers[i].passengerName, passengers[i].trainNumber, passengers[i].seatNumber);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("Railway Reservation System\n");
        printf("1. Add train\n");
        printf("2. Display trains\n");
        printf("3. Book ticket\n");
        printf("4. Cancel ticket\n");
        printf("5. Display passengers\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                addTrain();
                break;
            case 2:
                displayTrains();
                break;
            case 3:
                bookTicket();
                break;
            case 4:
                cancelTicket();
                break;
            case 5:
                displayPassengers();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}