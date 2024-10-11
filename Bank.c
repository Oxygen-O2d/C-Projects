#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char name[20]; // Variable to store user's name
int dep_amt, amt = 10000, acc_no, with_amt; // Variables for deposit amount, balance, account number, and withdrawal amount
int trans_amt; // Variable for transaction amount

void divider(); // Function prototype for creating a visual divider

// Function to display the main menu
void menu() {
    printf("\n\n*****MAIN MENU*****\n");
    divider(); // Call to the divider function
    printf("\n[1] Deposit Money\n");
    printf("[2] Withdraw Money\n");
    printf("[3] Transfer Money\n");
    printf("[4] Account Details\n");
    printf("[5] Transaction Details\n");
    printf("[6] Exit\n");
}

// Function to handle money deposits
void deposit_money() {
    time_t tm; // Variable to store the current time
    time(&tm); // Get the current time
    FILE *ptr = fopen("Account.txt", "a"); // Open the file in append mode
    printf("*****DEPOSITING MONEY*****\n");
    divider(); // Call to the divider function
    printf("\nEnter Amount: ");
    scanf("%d", &dep_amt); // Get the deposit amount from the user

    amt += dep_amt; // Update the account balance
    printf("MONEY DEPOSITED\n");
    printf("Current Balance: %d", amt); // Display the updated balance
    // Log the transaction details in the file
    fprintf(ptr, "Rs%d has been deposited to your account \n", dep_amt);
    fprintf(ptr, "Date /time of transaction %s\n", ctime(&tm));
    fclose(ptr); // Close the file
    getch(); // Wait for user input (requires <conio.h> for getch)
}

// Function to handle money withdrawals
void withdraw_money() {
    time_t tm; // Variable to store the current time
    time(&tm); // Get the current time
    FILE *ptr = fopen("Account.txt", "a"); // Open the file in append mode
    printf("*****WITHDRAW MONEY*****\n");
    divider(); // Call to the divider function
    printf("\nEnter Amount: ");
    scanf("%d", &with_amt); // Get the withdrawal amount from the user

    amt -= with_amt; // Update the account balance
    printf("MONEY WITHDRAWED\n");
    printf("Current Balance: %d", amt); // Display the updated balance
    // Log the transaction details in the file
    fprintf(ptr, "Rs%d has been withdrawed from your account \n", with_amt);
    fprintf(ptr, "Date /time of transaction %s\n", ctime(&tm));
    fclose(ptr); // Close the file
    getch(); // Wait for user input
}

// Function to handle money transfers
void transfer_money() {
    int ac; // Variable to store the target account number
    time_t tm; // Variable to store the current time
    time(&tm); // Get the current time
    FILE *ptr = fopen("Account.txt", "a"); // Open the file in append mode
    printf("*****TRANSFER MONEY*****\n");
    divider(); // Call to the divider function
    printf("\nEnter Amount: ");
    scanf("%d", &trans_amt); // Get the transfer amount from the user

    printf("Enter the account no. in which you want to transfer: ");
    scanf("%d", &ac); // Get the target account number from the user

    if (trans_amt > amt) { // Check for sufficient balance
        printf("\nYou don't have sufficient balance !!!");
    } else {
        amt -= trans_amt; // Update the account balance
        printf("\nMoney Transferred\n");
        printf("Current Balance: %d", amt); // Display the updated balance
        // Log the transaction details in the file
        fprintf(ptr, "Rs%d transferred to %d account no. successfully \n", trans_amt, ac);
        fprintf(ptr, "Date /time of transaction %s\n", ctime(&tm));
    }

    fclose(ptr); // Close the file
    printf("\nPress any key to continue..............\n");
    getch(); // Wait for user input
}

// Function to display account details
void account_details() {
    printf("*****ACCOUNT DETAILS*****\n");
    divider(); // Call to the divider function

    printf("\nName : %s\n", name); // Display user's name
    printf("Account no. : %d\n", acc_no); // Display account number
    printf("Total Balance : %d\n", amt); // Display current balance
    printf("Press any key............");
    getch(); // Wait for user input
}

// Function to display transaction details
void transaction_details() {
    FILE *ptr;
    ptr = fopen("Account.txt", "r"); // Open the file in read mode

    char c = fgetc(ptr); // Read the first character from the file
    if (c == EOF) { // Check if the file is empty
        printf("*****TRANSACTION DETAILS*****\n");
        divider(); // Call to the divider function
        printf("\nNo recent transactions\n");
    } else {
        printf("*****TRANSACTION DETAILS*****\n");
        divider(); // Call to the divider function
        printf("\n");
        while (c != EOF) { // Read until the end of the file
            printf("%c", c); // Print each character
            c = fgetc(ptr); // Read the next character
        }
    }
    printf("Press any key..............");
    getch(); // Wait for user input
}

// Function to display last details of the account
void last_details() {
    printf("*****DETAILS*****\n");
    divider(); // Call to the divider function
    printf("\nName : %s\n", name); // Display user's name
    printf("Account no. : %d\n", acc_no); // Display account number
    printf("Current balance : %d\n", amt); // Display current balance

    printf("Press any key...........");
    getch(); // Wait for user input
}

// Function to print a visual divider
void divider() {
    for (int i = 0; i < 50; i++) {
        printf("-"); // Print 50 dashes
    }
}

// Main function to execute the program
int main() {
    int choice; // Variable to store user's menu choice
    printf("*****WELCOME TO BC BANK*****\n");
    divider(); // Call to the divider function
    printf("\nEnter your name: ");
    gets(name); // Get the user's name (deprecated, consider using fgets)

    printf("Enter Your Account no: ");
    scanf("%d", &acc_no); // Get the account number
    printf("\n\n");

    while (1) { // Infinite loop for menu options
        menu(); // Display the menu
        printf("Enter your choice: ");
        scanf("%d", &choice); // Get user's choice

        // Switch statement to handle user choices
        switch (choice) {
        case 1:
            system("cls"); // Clear the screen
            deposit_money(); // Call the deposit function
            break;
        case 2:
            system("cls"); // Clear the screen
            withdraw_money(); // Call the withdraw function
            break;
        case 3:
            system("cls"); // Clear the screen
            transfer_money(); // Call the transfer function
            break;
        case 4:
            system("cls"); // Clear the screen
            account_details(); // Call the account details function
            break;
        case 5:
            system("cls"); // Clear the screen
            transaction_details(); // Call the transaction details function
            break;
        case 6:
            system("cls"); // Clear the screen
            last_details(); // Call the last details function
            exit(0); // Exit the program
        default:
            printf("Invalid Choice !!!"); // Handle invalid input
            break;
        }
    }
}
