#pragma once
#include "Account.h"

class CreditAccount : public Account
{
public:
	CreditAccount(int _id, char* _name, int _balance);
	~CreditAccount();

	virtual void SetBalance(int _money, bool _isIn);
};

