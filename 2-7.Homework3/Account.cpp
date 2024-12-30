#include "Account.h"

Account::Account(int _id, char* _name, int _balance)
	:mID(_id), mName(_name), mBalance(0)
{
	// �̸��� ���� ���� �޸� �Ҵ�
	mName = new char[strlen(_name) + 1];
	strcpy_s(mName, strlen(_name) + 1, _name);
}

Account::Account(const Account& _other)
	:mID(_other.mID), mName(_other.mName), mBalance(0)

{
	// �̸��� ���� ���� �޸� �Ҵ�
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
		std::cout << "�ݾ��� 0 �̻��� ���ڸ� �Է°����մϴ�.\n";
	}

	if (_isIn == true)
	{
		mBalance += _money;
	}
	else
	{
		if (mBalance - _money < 0)
		{
			std::cout << "�ܾ��� �����մϴ�.\n";
		}
		else
		{
			mBalance -= _money;
		}
	}
}

void Account::PrintAll()
{
	std::cout << "��ID: " << mID << " �� �̸�: " << mName << " �ܾ�: " << mBalance << "\n";

}