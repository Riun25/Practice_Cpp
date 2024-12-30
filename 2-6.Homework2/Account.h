#pragma once
#include <iostream>

class Account
{
public:
	// �⺻ ������
	Account(int _id, char* _name, int _balance);

	// ���� ������
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