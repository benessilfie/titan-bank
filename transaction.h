#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "account.h"

void deposit(struct Account* account, float amount);
int withdraw(struct Account* account, float amount);
#endif
