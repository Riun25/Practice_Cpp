#include "DonationAccount.h"


DonationAccount::DonationAccount(int _id, char* _name, int _balance)
	:Account(_id, _name, _balance), mDonation(0)
{
	mAccountType = ACCOUNT_TYPE::DONATION;
	int tempDonation = static_cast<int>(_balance * 0.01f);
	mDonation += tempDonation;
	mBalance += (_balance - tempDonation);
}

DonationAccount::~DonationAccount()
{
}

void DonationAccount::SetBalance(int _money, bool _isIn)
{
	if (_money < 0)
	{
		std::cout << "금액은 0 이상의 숫자만 입력가능합니다.\n";
	}

	if (_isIn == true)
	{
		int tempDonation = static_cast<int>(_money * 0.01f);
		mDonation += tempDonation;
		mBalance += (_money - tempDonation);
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

void DonationAccount::PrintAll()
{
	std::cout << "고객ID: " << mID << " 고객 이름: " << mName << " 잔액: " << mBalance <<
		" 기부금액 : " << mDonation << "\n";
}