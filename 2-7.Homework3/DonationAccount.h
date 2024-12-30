#pragma once
#include "Account.h"

class DonationAccount :public Account
{
public:
	DonationAccount(int _id, char* _name, int _balance);
	~DonationAccount();

	virtual void SetBalance(int _money, bool _isIn);

	virtual void PrintAll() override;

private:
	int mDonation;
};

