#include <stdio.h>
#include <string.h>

struct account {
    char username[50];
    char password[50];
    long int balance;
};

struct transaction {
    char from[50];
    char to[50];
    long int amount;
};

void createAccount(struct account *acc);
void login(struct account *acc);
void deposit(struct account *acc);
void withdraw(struct account *acc);
void transfer(struct account *acc);
void checkBalance(struct account *acc);
void displayTransactions(struct transaction *trans);

int main() {
    struct account acc;
    int choice;

    printf("Welcome to Bank Management System\n");
    printf("1. Create Account\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            createAccount(&acc);
            break;
        case 2:
            login(&acc);
            break;
        case 3:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    return 0;
}

void createAccount(struct account *acc) {
    printf("Enter username: ");
    scanf("%s", acc->username);
    printf("Enter password: ");
    scanf("%s", acc->password);
    acc->balance = 0;
    printf("Account created successfully\n");
    login(acc);
}

void login(struct account *acc) {
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, acc->username) == 0 && strcmp(password, acc->password) == 0) {
        printf("Login successful\n");
        int choice;
        while (1) {
            printf("1. Deposit\n");
            printf("2. Withdraw\n");
            printf("3. Transfer\n");
            printf("4. Check Balance\n");
            printf("5. Display Transactions\n");
            printf("6. Logout\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    deposit(acc);
                    break;
                case 2:
                    withdraw(acc);
                    break;
                case 3:
                    transfer(acc);
                    break;
                case 4:
                    checkBalance(acc);
                    break;
                case 5:
                    displayTransactions(NULL); // not implemented
                    break;
                case 6:
                    printf("Logging out...\n");
                    return;
                default:
                    printf("Invalid choice\n");
            }
        }
    } else {
        printf("Invalid username or password\n");
    }
}

void deposit(struct account *acc) {
    long int amount;
    printf("Enter amount to deposit: ");
    scanf("%ld", &amount);
    acc->balance += amount;
    printf("Deposit successful\n");
}

void withdraw(struct account *acc) {
    long int amount;
    printf("Enter amount to withdraw: ");
    scanf("%ld", &amount);
    if (acc->balance >= amount) {
        acc->balance -= amount;
        printf("Withdrawal successful\n");
    } else {
        printf("Insufficient balance\n");
    }
}

void transfer(struct account *acc) {
    char to[50];
    long int amount;
    printf("Enter recipient's username: ");
    scanf("%s", to);
    printf("Enter amount to transfer: ");
    scanf("%ld", &amount);
    if (acc->balance >= amount) {
        acc->balance -= amount;
        printf("Transfer successful\n");
        // not implemented: update recipient's account
    } else {
        printf("Insufficient balance\n");
    }
}

void checkBalance(struct account *acc) {
    printf("Your balance is: %ld\n", acc->balance);
}

void displayTransactions(struct transaction *trans) {
    // not implemented
    printf("Transactions not implemented\n");
}