#include <stdio.h>
#include <time.h>
#include <stdlib.h>
char name[20];
int dep_amt, amt = 10000, acc_no, with_amt;
int trans_amt;
void divider();

void menu()
{
    printf("\n\n*****MAIN MENU*****\n");
    divider();
    printf("\n[1] Deposit Money\n");
    printf("[2] Withdraw Money\n");
    printf("[3] Transfer Money\n");
    printf("[4] Account Details\n");
    printf("[5] Transaction Details\n");
    printf("[6] Exit\n");
}

void deposit_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    printf("*****DEPOSITING MONEY*****\n");
    divider();
    printf("\nEnter Amount: ");
    scanf("%d", &dep_amt);

    amt += dep_amt;
    printf("MONEY DEPOSITED\n");
    printf("Current Balance: %d", amt);
    fprintf(ptr, "Rs%d has been deposited to your account \n", dep_amt);
    fprintf(ptr, "Date /time of transaction %s\n", ctime(&tm));
    fclose(ptr);
    getch();
}

void withdraw_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    printf("*****WITHDRAW MONEY*****\n");
    divider();
    printf("\nEnter Amount: ");
    scanf("%d", &with_amt);

    amt -= with_amt;
    printf("MONEY WITHDRAWED\n");
    printf("Current Balance: %d", amt);
    fprintf(ptr, "Rs%d has been withdrawed from your account \n", with_amt);
    fprintf(ptr, "Date /time of transaction %s\n", ctime(&tm));
    fclose(ptr);
    getch();
}

void transfer_money()
{

    int ac;
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    printf("*****TRANFER MONEY*****\n");
    divider();
    printf("\nEnter Amount: ");
    scanf("%d", &trans_amt);

    printf("Enter the account no. in which you want to transfer: ");
    scanf("%d", &ac);

    if (trans_amt > amt)
    {
        printf("\nYou don't have sufficient balance !!!");
    }
    else
    {
        amt -= trans_amt;
        printf("\nMoney Transfered \n");
        printf("Cuurent Balance: %d", amt);
        fprintf(ptr, "Rs%d transfered to %d account no. successfully \n", trans_amt, ac);
        fprintf(ptr, "Date /time of transaction %s\n", ctime(&tm));
    }

    fclose(ptr);
    printf("\nPress any key to continue..............\n");
    getch();
}

void account_details()
{
    printf("*****ACCOUNT DETAILS*****\n");
    divider();

    printf("\nName : %s\n", name);
    printf("Account no. : %d\n", acc_no);
    printf("Total Balance : %d\n", amt);
    printf("Press any key............");
    getch();
}

void transaction_details()
{
    FILE *ptr;
    ptr = fopen("Account.txt", "r");

    char c = fgetc(ptr);
    if (c == EOF)
    {
        printf("*****TRANSACTION DETALS*****\n");
        divider();
        printf("\nNo recent transactions\n");
    }
    else
    {
        printf("*****TRANSACTION DETALS*****\n");
        divider();
        printf("\n");
        while (c != EOF)
        {
            printf("%c", c);
            c = fgetc(ptr);
        }
    }
    printf("Press any key..............");
    getch();
}

void last_details()
{
    printf("*****DETAILS*****\n");
    divider();
    printf("\nName : %s\n", name);
    printf("Account no. : %d\n", acc_no);
    printf("Current balance : %d\n", amt);

    printf("Press any key...........");
    getch();
}

void divider()
{
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
}

int main()
{
    int choice;
    printf("*****WELCOME TO BC BANK*****\n");
    divider();
    printf("\nEnter your name: ");
    gets(name);

    printf("Enter Yout Account no: ");
    scanf("%d", &acc_no);
    printf("\n\n");
    while (1)
    {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            deposit_money();
            break;
        case 2:
            system("cls");
            withdraw_money();
            break;
        case 3:
            system("cls");
            transfer_money();
            break;
        case 4:
            system("cls");
            account_details();
            break;
        case 5:
            system("cls");
            transaction_details();
            break;
        case 6:
            system("cls");
            last_details();
            exit(0);
        default:
            printf("Invalid Choice !!!");
            break;
        }
    }
}