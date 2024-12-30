#include "Account.h"

Account::Account(int _id, char* _name, int _balance)
	:mID(_id), mName(_name), mBalance(0)
{
	// 이름을 위한 동적 메모리 할당
	mName = new char[strlen(_name) + 1];
	strcpy_s(mName, strlen(_name) + 1, _name);
}

Account::Account(const Account& _other)
	:mID(_other.mID), mName(_other.mName), mBalance(0)

{
	// 이름을 위한 동적 메모리 할당
	mName = new char[strlen(_other.mName) + 1];
	strcpy_s(mName, strlen(_other.mName) + 1, _other.mName);
}

Account::~Account()
{
	delete[] mName;
}

int Account::GetID()
{
	return mID;
}

char* Account::GetName()
{
	return mName;
}

int Account::GetBalance()
{
	return mBalance;
}

void Account::SetBalance(int _money, bool _isIn)
{
	if (_money < 0)
	{
		std::cout << "금액은 0 이상의 숫자만 입력가능합니다.\n";
	}

	if (_isIn == true)
	{
		mBalance += _money;
	}
	else
	{
		if (mBalance - _money < 0)
		{
			std::cout << "잔액이 부족합니다.\n";
		}
		else
		{
			mBalance -= _money;
		}
	}
}

void Account::PrintAll()
{
	std::cout << "고객ID: " << mID << " 고객 이름: " << mName << " 잔액: " << mBalance << "\n";

}