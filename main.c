#include <stdio.h>

#include "account.h"
#include "transaction.h"

int main(void) {
  struct Account accounts[MAX_ACCOUNTS];
  int numAccounts = 0;
  int option;
  int accountNumber;
  float amount;
  struct Account* account;

  printf("Hi, Welcome to Bank Titan\n");

  while (1) {
    printf("\nHow may we help you today?\n");
    printf("---------------------------\n");
    printf("1. Create Account\n");
    printf("2. View Account Details\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Exit\n");

    printf("Choose an option: ");
    scanf("%d", &option);

    while (option < 1 || option > 5) {
      printf("Invalid option. Please try again.\n");
      printf("Choose an option: ");
      scanf("%d", &option);
    }

    switch (option) {
      case 1: {
        string firstName, lastName;
        float initialDeposit;

        printf("\nCreating a new account\n");
        printf("Enter first name: ");
        scanf("%s", firstName);
        printf("Enter last name: ");
        scanf("%s", lastName);
        printf("Enter initial deposit (Minimum GHS %.2f): ", MIN_BALANCE);
        scanf("%f", &initialDeposit);

        accountNumber = createAccount(accounts, numAccounts, firstName,
                                      lastName, initialDeposit);
        if (accountNumber != -1) {
          numAccounts++;
          printf("\nAccount created successfully. Your account number is %d.\n",
                 accountNumber);
        }
        break;
      }
      case 2:
        printf("\nEnter account number: ");
        scanf("%d", &accountNumber);

        account = findAccount(accounts, numAccounts, accountNumber);
        if (account) {
          printAccountInfo(*account);
        } else {
          printf("\nAccount not found.\n");
        }
        break;
      case 3:
        printf("\nEnter account number: ");
        scanf("%d", &accountNumber);

        account = findAccount(accounts, numAccounts, accountNumber);
        if (account) {
          printf("\nEnter amount to deposit: ");
          scanf("%f", &amount);
          deposit(account, amount);
        } else {
          printf("\nAccount not found.\n");
        }
        break;
      case 4:
        printf("\nEnter account number: ");
        scanf("%d", &accountNumber);

        account = findAccount(accounts, numAccounts, accountNumber);
        if (account) {
          printf("\nEnter amount to withdraw: ");
          scanf("%f", &amount);
          withdraw(account, amount);
        } else {
          printf("\nAccount not found.\n");
        }
        break;
      case 5:
        printf("\nThank you for banking with us.\n");
        return 0;
    }
  }

  return 0;
}
