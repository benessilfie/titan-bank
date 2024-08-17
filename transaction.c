#include "transaction.h"

#include <stdio.h>

void deposit(struct Account* account, float amount) {
  account->accountBalance += amount;
  printf("\nDeposited GHS %.2f. New balance: GHS %.2f\n", amount,
         account->accountBalance);
}

int withdraw(struct Account* account, float amount) {
  if (amount > account->accountBalance) {
    printf("\nInsufficient funds. Withdrawal failed.\n");
    return -1;
  }
  account->accountBalance -= amount;
  printf("\nWithdrew GHS %.2f. New balance: GHS %.2f\n", amount,
         account->accountBalance);
  return 0;
}
