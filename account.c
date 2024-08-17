#include "account.h"

#include <stdio.h>
#include <string.h>

static int currentAccountNumber = 1000;

int generateAccountNumber() { return currentAccountNumber++; }

int createAccount(struct Account accounts[], int numAccounts, string firstName,
                  string lastName, float initialDeposit) {
  if (initialDeposit < MIN_BALANCE) {
    printf("\nInitial deposit must be at least GHS %.2f\n", MIN_BALANCE);
    return -1;
  }

  if (numAccounts >= MAX_ACCOUNTS) {
    printf("\nCannot create more accounts. Maximum number reached.\n");
    return -1;
  }

  struct Account newAccount;
  strcpy(newAccount.firstName, firstName);
  strcpy(newAccount.lastName, lastName);
  newAccount.accountNumber = generateAccountNumber();
  newAccount.accountBalance = initialDeposit;

  accounts[numAccounts] = newAccount;
  return newAccount.accountNumber;
}

void printAccountInfo(struct Account account) {
  printf("\nAccount Details\n");
  printf("----------------\n");
  printf("Account Number: %d\n", account.accountNumber);
  printf("Name: %s %s\n", account.firstName, account.lastName);
  printf("Balance: GHS %.2f\n", account.accountBalance);
}

struct Account* findAccount(struct Account accounts[], int numAccounts,
                            int accountNumber) {
  for (int i = 0; i < numAccounts; i++) {
    if (accounts[i].accountNumber == accountNumber) {
      return &accounts[i];
    }
  }

  return NULL;
}
