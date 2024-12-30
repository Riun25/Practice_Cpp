#include "Bank.h"
#include "DonationAccount.h"
#include "CreditAccount.h"

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

void Bank::CreateAccount(char _type, int _id, char* _name, int _balance)
{
	ACCOUNT_TYPE typeNum = static_cast<ACCOUNT_TYPE>(_type - '0' - 1);

	Account* newAccount = nullptr;

	switch (typeNum)
	{
	case ACCOUNT_TYPE::NORMAL:
		newAccount = new Account(_id, _name, _balance);
		break;
	case ACCOUNT_TYPE::CREDIT:
		newAccount = new CreditAccount(_id, _name, _balance);
		break;
	case ACCOUNT_TYPE::DONATION:
		newAccount = new DonationAccount(_id, _name, _balance);
		break;
	case ACCOUNT_TYPE::LAST:

		break;
	default:
		break;
	}

	// 계좌 생성 및 배열에 추가
	mAccountArr[mAccountArrIdx] = newAccount;
	mAccountArrIdx++;
}

void Bank::Deposit(char* _name, int _money)
{
	int tempIdx = BankCustomerIdx(_name);

	if (tempIdx == -1)
	{
		std::cout << "계좌가 없는 고객입니다. 계좌를 먼저 개설해주세요.\n";
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
		std::cout << "계좌가 없는 고객입니다. 계좌를 먼저 개설해주세요.\n";
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
