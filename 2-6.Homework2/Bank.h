#pragma once
#include "Account.h"

class Account;
class Bank
{
public:
	Bank();
	~Bank();

	void CreateAccount(int _id, char* _name, int _balance);

	void Deposit(char* name, int _money);

	void Withdraw(char* _name, int _money);

	void Inquire();


private:
	Account* mAccountArr[100] = {};
	int mAccountArrIdx = 0;

	int BankCustomerIdx(char* _name);

};

