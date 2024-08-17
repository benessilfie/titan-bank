#include <stdio.h>

#define MAX_NAME_LENGTH 40
typedef char string[MAX_NAME_LENGTH];

struct Account {
  string firstName;
  string lastName;
  int accountNumber;
  int accountBalance;
};

int main(void) {
  struct Account accounts[] = {{"Abena", "Ayebea", 1234, 1500},
                               {"Kwame", "Bio", 5678, 1000},
                               {"Abdul", "Aziz", 9012, 50000},
                               {"Emmanuel", "Sane", 9101, 2000}};

  int option;
  int accountNumber;
  float depositAmount;
  float withdrawAmount;
  int numAccounts = sizeof(accounts) / sizeof(accounts[0]);

  struct Account account;

  printf("Hi, welcome to Bank Titan\n");
  putchar('\n');

  printf("How may we help you today?\n");
  printf("---------------------------\n");
  printf("1. View account details\n");
  printf("2. Check account balance\n");
  printf("3. Deposit\n");
  printf("4. Withdraw\n");
  putchar('\n');

  while (1) {
    printf("Select an option (1, 2, 3, 4): ");
    scanf("%d", &option);

    if (option > 0 && option < 4) {
      break;
    } else {
      printf("Invalid Option\n");
    }
  }

  putchar('\n');
  printf("Enter your account number: ");
  scanf("%d", &accountNumber);

  int found = 0;
  for (int i = 0; i < numAccounts; i++) {
    if (accountNumber == accounts[i].accountNumber) {
      account = accounts[i];
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Sorry, you do not have an account with us\n");
    return 1;
  }

  putchar('\n');

  switch (option) {
    case 1:
      printf("Hi, %s\n", account.firstName);
      printf("Account Number: %d\n", account.accountNumber);
      printf("Account Balance: GHS %d\n", account.accountBalance);
      break;
    case 2:
      printf("Hi, %s\n", account.firstName);
      printf("Your account balance is GHS %d\n", account.accountBalance);
      break;
    case 3:
      printf("Hi, %s\n", account.firstName);
      printf("Enter amount to deposit: ");
      scanf("%f", &depositAmount);
      account.accountBalance += depositAmount;
      printf("Your account balance is GHS %d\n", account.accountBalance);
      break;
    case 4:
      printf("Hi, %s\n", account.firstName);
      printf("Enter amount to withdraw: ");
      scanf("%f", &withdrawAmount);
      if (withdrawAmount > account.accountBalance) {
        printf("Insufficient funds\n");
      } else {
        account.accountBalance -= withdrawAmount;
        printf("Your account balance is GHS %d\n", account.accountBalance);
      }
      break;
  }

  return 0;
}
