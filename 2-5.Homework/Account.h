#pragma once
#include <iostream>


enum class ACCOUNT_TYPE
{
	NORMAL,
	CREDIT,
	DONATION,
	LAST,
};

class Account
{
public:
	// 기본 생성자
	Account(int _id, char* _name, int _balance);

	// 복사 생성자
	Account(const Account& _other);

	~Account();

	int GetID();
	char* GetName();
	int GetBalance();
	void SetBalance(int _money, bool _isIn);

	virtual void PrintAll();

protected:
	ACCOUNT_TYPE mAccountType = ACCOUNT_TYPE::NORMAL;
	int mID;
	char* mName;
	int mBalance;
};