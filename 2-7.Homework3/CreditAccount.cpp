#include "CreditAccount.h"

CreditAccount::CreditAccount(int _id, char* _name, int _balance)
	:Account(_id, _name, _balance)
{
	mAccountType = ACCOUNT_TYPE::CREDIT;
	int tempInterest = static_cast<int>(_balance * 0.01f);
	mBalance += (_balance + tempInterest);
}

CreditAccount::~CreditAccount()
{
}

void CreditAccount::SetBalance(int _money, bool _isIn)
{
	if (_money < 0)
	{
		std::cout << "�ݾ��� 0 �̻��� ���ڸ� �Է°����մϴ�.\n";
	}

	if (_isIn == true)
	{
		int tempInterest = static_cast<int>(_money * 0.01f);
		mBalance += (_money + tempInterest);
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
