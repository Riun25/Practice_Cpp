#include "Bank.h"

Bank::Bank()
{
}

Bank::~Bank()
{
	for (int i = 0; i < 100; i++)
	{
		if (mAccountArr[i] == nullptr)
		{
			continue;
		}

		delete[] mAccountArr[i]->GetName();
		delete mAccountArr[i];
	}
}

void Bank::CreateAccount(int _id, char* _name, int _balance)
{
	// ���� ���� �� �迭�� �߰�
	Account* newAccount = new Account(_id, _name, _balance);
	mAccountArr[mAccountArrIdx] = newAccount;
	mAccountArrIdx++;
}

void Bank::Deposit(char* _name, int _money)
{
	int tempIdx = BankCustomerIdx(_name);

	if (tempIdx == -1)
	{
		std::cout << "���°� ���� ���Դϴ�. ���¸� ���� �������ּ���.\n";
	}
	else
	{
		mAccountArr[tempIdx]->SetBalance(_money, true);
	}
}

void Bank::Withdraw(char* _name, int _money)
{
	int tempIdx = BankCustomerIdx(_name);

	if (tempIdx == -1)
	{
		std::cout << "���°� ���� ���Դϴ�. ���¸� ���� �������ּ���.\n";
	}
	else
	{
		mAccountArr[tempIdx]->SetBalance(_money, false);
	}
}

void Bank::Inquire()
{
	for (int i = 0; i < 100; i++)
	{
		if (mAccountArr[i] == nullptr)
		{
			continue;
		}

		mAccountArr[i]->PrintAll();
	}
}

int Bank::BankCustomerIdx(char* _name)
{
	for (int i = 0; i < 100; i++)
	{
		if (std::strcmp(mAccountArr[i]->GetName(), _name) == 0)
		{
			return i;
		}
	}
	return -1;
}
