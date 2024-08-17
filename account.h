#ifndef ACCOUNT_H
#define ACCOUNT_H

#define MAX_NAME_LENGTH 40
#define MIN_BALANCE 10.00
#define MAX_ACCOUNTS 100

typedef char string[MAX_NAME_LENGTH];

struct Account {
  string firstName;
  string lastName;
  int accountNumber;
  float accountBalance;
};

int generateAccountNumber();
int createAccount(struct Account accounts[], int numAccounts, string firstName,
                  string lastName, float initialDeposit);
void printAccountInfo(struct Account account);
struct Account* findAccount(struct Account accounts[], int numAccounts,
                            int accountNumber);
#endif
