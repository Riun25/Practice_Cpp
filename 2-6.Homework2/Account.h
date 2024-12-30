#pragma once
#include <iostream>

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

	void PrintAll();

private:
	int mID;
	char* mName;
	int mBalance;
};